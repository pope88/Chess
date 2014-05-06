#include "Config.h"
#include "MongoExecutor.h"
#include "MongoAction.h"

#include "mongo/mongo.h"
MONGO_EXTERN_C_START
#include "mongo/gridfs.h"
MONGO_EXTERN_C_END


	namespace Database
{

	MongoExecutor::MongoExecutor( const std::string& host, UInt16 port, const char * dbname ): _dbname(dbname)
	{
		_conn = (struct mongo *)malloc(sizeof(struct mongo));
		if(_conn == NULL)
		{
			_connected = false;
			return;
		}
		_connected = mongo_client(_conn, host.c_str(), port) == MONGO_OK;
	}

	MongoExecutor::~MongoExecutor()
	{
		freeConn();
	}

	bool MongoExecutor::ensureConn()
	{
		if(_connected)
			return true;
		if(_conn == NULL)
		{
			_conn = (struct mongo *)malloc(sizeof(struct mongo));
			if(_conn == NULL)
			{
				_connected = false;
				return false;
			}
		}
		_connected = mongo_reconnect(_conn) == MONGO_OK;
		return _connected;
	}

	void MongoExecutor::freeConn()
	{
		if(_conn == NULL)
			return;
		mongo_destroy(_conn);
		free(_conn);
	}

	MongoResult MongoExecutor::run( MongoAction& mab )
	{
		if(!ensureConn())
			return ConnLost;

		if(mab.type() < 0x10)
		{
			MongoActionBson& ma = static_cast<MongoActionBson&>(mab);

			ma.finish();
			char dbname[128];
			sprintf(dbname, "%s.%s", _dbname.c_str(), mab.table());
			switch(mab.type())
			{
			case 0:
				if(mongo_insert(_conn, dbname, ma._bson, NULL) == MONGO_OK)
					return OK;
				if(_conn->err == MONGO_IO_ERROR)
				{
					_connected = false;
					return ConnLost;
				}
				return Failed;
			case 1:
				if(ma._hasCond)
				{
					if(mongo_remove(_conn, dbname, ma._cond, NULL) == MONGO_OK)
						return OK;
				}
				else
				{
					//--bson b[1];
					if(mongo_remove(_conn, dbname, bson_shared_empty( ), NULL) == MONGO_OK)
						return OK;
				}
				if(_conn->err == MONGO_IO_ERROR)
				{
					_connected = false;
					return ConnLost;
				}
				return Failed;
			case 2:
				if(ma._hasCond)
				{
					if(mongo_update(_conn, dbname, ma._cond, ma._bson, MONGO_UPDATE_MULTI, NULL) == MONGO_OK)
						return OK;
				}
				else
				{
					//--bson b[1];
					if(mongo_update(_conn, dbname, bson_shared_empty(), ma._bson, MONGO_UPDATE_MULTI, NULL) == MONGO_OK)
						return OK;
				}
				if(_conn->err == MONGO_IO_ERROR)
				{
					_connected = false;
					return ConnLost;
				}
				return Failed;
			case 3:
				if(ma._hasCond)
				{
					if(mongo_update(_conn, dbname, ma._cond, ma._bson, MONGO_UPDATE_UPSERT, NULL) == MONGO_OK)
						return OK;
				}
				else
				{
					//--bson b[1];
					if(mongo_update(_conn, dbname, bson_shared_empty( ), ma._bson, MONGO_UPDATE_UPSERT, NULL) == MONGO_OK)
						return OK;
				}
				if(_conn->err == MONGO_IO_ERROR)
				{
					_connected = false;
					return ConnLost;
				}
				return Failed;
			case 15:
				if(mongo_run_command(_conn, _dbname.c_str(), ma._bson, NULL) == MONGO_OK)
					return OK;
				return Failed;
			}
		}
		else if(mab.type() < 0x20)
		{
			MongoActionGridFS& ma = static_cast<MongoActionGridFS&>(mab);
			switch(mab.type())
			{
			case 0x10:
				{
					gridfs gfs[1];
					gridfile gfile[1];

					gridfs_init( _conn, _dbname.c_str(), ma._table, gfs );
					gridfile_writer_init( gfile, gfs, ma._name, "application/octet-stream", GRIDFILE_DEFAULT );  //--
					gridfile_write_buffer( gfile, (const char *)ma._buf, ma._size );
					gridfile_writer_done( gfile );

					gridfs_destroy( gfs );
				}
				break;
			}
		}
		return OK;
	}

	void MongoExecutor::ensureIndex( const char * tbl, const char * name, bool unique )
	{
		if(!ensureConn())
			return;
		char dbname[128];
		sprintf(dbname, "%s.%s", _dbname.c_str(), tbl);
		if(mongo_create_simple_index(_conn, dbname, name, unique ? MONGO_INDEX_UNIQUE : 0, NULL) == MONGO_OK)
			return;
		if(_conn->err == MONGO_IO_ERROR)
			_connected = false;
	}

	void MongoExecutor::ensureIndex( const char * tbl, const char * name1, const char * name2, bool unique )
	{
		if(!ensureConn())
			return;
		char dbname[128];
		sprintf(dbname, "%s.%s", _dbname.c_str(), tbl);
		bson index[1];
		bson_init(index);
		bson_append_int(index, name1, 1);
		bson_append_int(index, name2, 1);
		bson_finish(index);
		if(mongo_create_index(_conn, dbname, index, NULL, unique ? MONGO_INDEX_UNIQUE : 0, -1, NULL) == MONGO_OK)
		{
			bson_destroy(index);
			return;
		}
		if(_conn->err == MONGO_IO_ERROR)
			_connected = false;
		bson_destroy(index);
	}

	void MongoExecutor::ensureIndex( const char * tbl, const char * name1, const char * name2, const char * name3, bool unique )
	{
		if(!ensureConn())
			return;
		char dbname[128];
		sprintf(dbname, "%s.%s", _dbname.c_str(), tbl);
		bson index[1];
		bson_init(index);
		bson_append_int(index, name1, 1);
		bson_append_int(index, name2, 1);
		bson_append_int(index, name3, 1);
		bson_finish(index);
		if(mongo_create_index(_conn, dbname, index, NULL, unique ? MONGO_INDEX_UNIQUE : 0, -1, NULL) == MONGO_OK) //--
		{
			bson_destroy(index);
			return;
		}
		if(_conn->err == MONGO_IO_ERROR)
			_connected = false;
		bson_destroy(index);
	}

	void MongoExecutor::dropIndexes(const char * tbl)
	{
		if(!ensureConn())
			return;

		bson cmd;
		bson out = {NULL, 0};

		bson_init( &cmd );
		bson_append_string( &cmd, "deleteIndexes", tbl );
		bson_append_string( &cmd, "index", "*" );
		bson_finish( &cmd );

		mongo_run_command( _conn, _dbname.c_str(), &cmd, &out );

		bson_destroy( &cmd );
		bson_destroy( &out );
	}

	char * MongoExecutor::getGridFS( const char * tbl, const char * name, size_t& size, UInt32& tm )
	{
		if(!ensureConn())
			return NULL;

		gridfs gfs[1];
		gridfile gfile[1];

		char *data = NULL;
		size = 0;
		gridfs_init( _conn, _dbname.c_str(), tbl, gfs );
		if(gridfs_find_filename( gfs, name, gfile ) == MONGO_OK)
		{
			tm = static_cast<UInt32>(gridfile_get_uploaddate(gfile) / 1000);
			gridfs_offset sz = gridfile_get_contentlength(gfile);
			data = new(std::nothrow) char[(int)sz];
			if(data != NULL)
			{
				gridfile_read_buffer(gfile,  data, sz);
				size = static_cast<size_t>(sz);
			}
			gridfile_destroy( gfile );
		}
		gridfs_destroy( gfs );
		return data;
	}

	MongoFinder::MongoFinder(const std::string& host, UInt16 port, const char * dbname): MongoExecutor(host, port, dbname), _cursor(NULL)
	{
	}

	MongoFinder::~MongoFinder()
	{
		doFindFinish();
	}

	Database::MongoResult MongoFinder::findOne( MongoActionBson& ma )
	{
		if(!ensureConn())
			return ConnLost;

		ma.finish();
		char dbname[128];
		sprintf(dbname, "%s.%s", _dbname.c_str(), ma._table);
		if(_cursor != NULL)
		{
			mongo_cursor_destroy(_cursor);
			_cursor = NULL;
		}

		bson out;
		if(mongo_find_one(_conn, dbname, ma._hasCond ? ma._cond : NULL, ma._bson, &out) == MONGO_OK)
		{
			bson_iterator it[1];
			bson_iterator_init( it, &out );
			std::unordered_map<std::string, MongoBind *>::iterator iter;
			while( bson_iterator_next( it ) )
			{
				iter = _binds.find(bson_iterator_key( it ));
				if(iter == _binds.end())
					continue;
				switch(bson_iterator_type(it))
				{
				case BSON_INT:
					{
						Int32 i = bson_iterator_int(it);
						iter->second->extract(BSON_INT, &i);
					}
					break;
				case BSON_LONG:
					{
						Int64 i = bson_iterator_long(it);
						iter->second->extract(BSON_LONG, &i);
					}
					break;
				case BSON_DOUBLE:
					{
						double i = bson_iterator_double(it);
						iter->second->extract(BSON_DOUBLE, &i);
					}
					break;
				case BSON_BOOL:
					{
						int i = bson_iterator_bool(it);
						iter->second->extract(BSON_BOOL, &i);
					}
					break;
				case BSON_STRING:
					iter->second->extract(BSON_STRING, bson_iterator_string(it));
					break;
				default:
					break;
				}
			}

			for(iter = _binds.begin(); iter != _binds.end(); ++ iter)
			{
				if(iter->second->isSet)
					iter->second->isSet = false;
				else
					iter->second->setDefault();
			}

			bson_destroy(&out);
			return OK;
		}

		if(_conn->err == MONGO_IO_ERROR)
		{
			_connected = false;
			return ConnLost;
		}
		return Failed;
	}

	MongoResult MongoFinder::findPrepare( MongoActionBson& ma, bool output )
	{
		if(!ensureConn())
			return ConnLost;

		doFindFinish();

		ma.finish();
		char dbname[128];
		sprintf(dbname, "%s.%s", _dbname.c_str(), ma._table);
		if(output)
		{
			fprintf(stdout, "MongoDB reading %s...\n", dbname);
			fflush(stdout);
		}
		if(_cursor != NULL)
		{
			mongo_cursor_destroy(_cursor);
			_cursor = NULL;
		}
		_cursor = mongo_find(_conn, dbname, ma._hasCond ? ma._cond : NULL, ma._bson, 0, 0, 0);
		if(_cursor != NULL)
			return OK;
		if(_conn->err == MONGO_IO_ERROR)
		{
			_connected = false;
			return ConnLost;
		}
		return Failed;
	}

	MongoResult MongoFinder::findPrepare( const char * tbl, bool output )
	{
		if(!ensureConn())
			return ConnLost;

		char dbname[128];
		sprintf(dbname, "%s.%s", _dbname.c_str(), tbl);
		if(output)
		{
			fprintf(stdout, "MongoDB reading %s...\n", dbname);
			fflush(stdout);
		}
		if(_cursor != NULL)
		{
			mongo_cursor_destroy(_cursor);
			_cursor = NULL;
		}
		_cursor = mongo_find(_conn, dbname, NULL, NULL, 0, 0, 0);
		if(_cursor != NULL)
			return OK;
		if(_conn->err == MONGO_IO_ERROR)
		{
			_connected = false;
			return ConnLost;
		}
		return OK;
	}

	MongoResult MongoFinder::findNext()
	{
		if(mongo_cursor_next(_cursor) != MONGO_OK)
		{
			if(_conn->err == MONGO_IO_ERROR)
			{
				_connected = false;
				return ConnLost;
			}
			doFindFinish();
			return Failed;
		}

		bson_iterator it[1];
		bson_iterator_init( it, (bson *)mongo_cursor_bson(_cursor) );
		std::unordered_map<std::string, MongoBind *>::iterator iter;
		while( bson_iterator_next( it ) )
		{
			iter = _binds.find(bson_iterator_key( it ));
			if(iter == _binds.end())
				continue;
			switch(bson_iterator_type(it))
			{
			case BSON_INT:
				{
					Int32 i = bson_iterator_int(it);
					iter->second->extract(BSON_INT, &i);
				}
				break;
			case BSON_LONG:
				{
					Int64 i = bson_iterator_long(it);
					iter->second->extract(BSON_LONG, &i);
				}
				break;
			case BSON_DOUBLE:
				{
					double i = bson_iterator_double(it);
					iter->second->extract(BSON_DOUBLE, &i);
				}
				break;
			case BSON_BOOL:
				{
					int i = bson_iterator_bool(it);
					iter->second->extract(BSON_BOOL, &i);
				}
				break;
			case BSON_STRING:
				iter->second->extract(BSON_STRING, bson_iterator_string(it));
				break;
			default:
				break;
			}
		}

		for(iter = _binds.begin(); iter != _binds.end(); ++ iter)
		{
			if(iter->second->isSet)
				iter->second->isSet = false;
			else
				iter->second->setDefault();
		}

		return OK;
	}

	void MongoFinder::doFindFinish()
	{
		if(_cursor != NULL)
		{
			mongo_cursor_destroy(_cursor);
			_cursor = NULL;
		}

		std::unordered_map<std::string, MongoBind *>::iterator iter;
		for(iter = _binds.begin(); iter != _binds.end(); ++ iter)
			delete iter->second;
		_binds.clear();
	}

}
