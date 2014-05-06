#include "Config.h"
#include "MongoAction.h"

namespace Database
{

	void bson_dump( std::ostringstream& ss, const char *data ) {
		bson_iterator i;
		const char *key;
		bson_timestamp_t ts;
		char oidhex[25];
		bson scope;
		bson_iterator_from_buffer( &i, data );

		ss << '{';
		bool first = true;
		while ( bson_iterator_next( &i ) ) {
			bson_type t = bson_iterator_type( &i );
			if ( t == 0 )
				break;
			key = bson_iterator_key( &i );

			if(first)
			{
				first = false;
				ss << key << ':';
			}
			else
				ss << ',' << key << ':';
			switch ( t ) {
			case BSON_DOUBLE:
				ss << bson_iterator_double( &i );
				break;
			case BSON_STRING:
				ss << '"' << bson_iterator_string( &i ) << '"';
				break;
			case BSON_SYMBOL:
				ss << "SYMBOL(\"" << bson_iterator_string( &i ) << "\")";
				break;
			case BSON_OID:
				bson_oid_to_string( bson_iterator_oid( &i ), oidhex );
				ss << "ObjectId(\"" << oidhex << "\")";
				break;
			case BSON_BOOL:
				ss << (bson_iterator_bool( &i ) ? "true" : "false" );
				break;
			case BSON_DATE:
				ss << ( long int )bson_iterator_date( &i );
				break;
			case BSON_BINDATA:
				ss << "BINDATA";
				break;
			case BSON_UNDEFINED:
				ss << "UNDEFINED";
				break;
			case BSON_NULL:
				ss << "NULL";
				break;
			case BSON_REGEX:
				ss << "REGEX(\"" << bson_iterator_regex( &i ) << "\")";
				break;
			case BSON_CODE:
				ss << "CODE(\"" << bson_iterator_code( &i ) << "\")";
				break;
			case BSON_CODEWSCOPE:
				ss << "CODE_W_SCOPE(\"" << bson_iterator_code( &i ) << "\")[";
				bson_init( &scope );
				bson_iterator_code_scope_init( &i, &scope, false); //--
				bson_dump( ss, scope.data );
				ss << ']';
				break;
			case BSON_INT:
				ss << bson_iterator_int( &i );
				break;
			case BSON_LONG:
				ss << "NumberLong(" << (uint64_t)bson_iterator_long( &i ) << ')';
				break;
			case BSON_TIMESTAMP:
				ts = bson_iterator_timestamp( &i );
				ss << "{i:" << ts.i << ",t:" << ts.t << '}';
				break;
			case BSON_OBJECT:
			case BSON_ARRAY:
				bson_dump( ss, bson_iterator_value( &i ) );
				break;
			default:
				ss << "UNKNOWN_TYPE";
			}
		}
		ss << "}";
	}

	MongoAction::MongoAction( const char * table, UInt8 type ): _table(table), _type(type)
	{
	}

	MongoAction::~MongoAction()
	{
	}

	MongoActionBson::MongoActionBson( const char * table, UInt8 type ): MongoAction(table, type), _inCond(false), _level(0), _hasCond(false), _queried(false), _finished(false)
	{
		bson_init(_bson);
		switch(type)
		{
		case 0xFF:
			bson_append_int(_bson, "_id", 0);
			break;
		}
	}

	MongoActionBson::~MongoActionBson()
	{
		bson_destroy(_bson);
		if(_hasCond)
			bson_destroy(_cond);
	}

	bool MongoActionBson::dump( std::ostringstream& ss )
	{
		switch(_type)
		{
		case 0:
			ss << "db." << _table << ".insert(";
			bson_dump(ss, _bson->data);
			if(_hasCond)
			{
				ss << " Condition ";
				bson_dump(ss, _cond->data);
			}
			ss << ')';
			break;
		case 1:
			ss << "db." << _table << ".remove(";
			if(_hasCond)
				bson_dump(ss, _cond->data);
			else
				ss << "{}";
			ss << ')';
			break;
		case 2:
			ss << "db." << _table << ".update(";
			if(_hasCond)
				bson_dump(ss, _cond->data);
			else
				ss << "{}";
			ss << ',';
			bson_dump(ss, _bson->data);
			ss << ",false,true)";
			break;
		case 3:
			ss << "db." << _table << ".update(";
			if(_hasCond)
				bson_dump(ss, _cond->data);
			else
				ss << "{}";
			ss << ',';
			bson_dump(ss, _bson->data);
			ss << ",true,false)";
			break;
		case 15:
			ss << "db.runCommand(";
			bson_dump(ss, _bson->data);
			ss << ')';
			break;
		case 0xFE:
		case 0xFF:
			ss << "db." << _table << ".find(";
			if(_hasCond)
				bson_dump(ss, _cond->data);
			else
				ss << "{}";
			ss << ',';
			bson_dump(ss, _bson->data);
			ss << ')';
			break;
		default:
			return false;
		}
		return true;
	}


	MongoActionGridFS::MongoActionGridFS( const char * table, const char * name, const void * buf, size_t sz ): MongoAction(table, 0x10), _name(name), _buf(buf), _size(sz)
	{
	}

}
