#ifndef _MONGOACTION_H_
#define _MONGOACTION_H_

#include "mongo/bson.h"
#include <sstream>

namespace Database
{

	class MongoAction
	{
	public:
		MongoAction(const char *, UInt8 = 0xFF);
		virtual ~MongoAction();
		inline const char * table() { return _table; }
		inline UInt8 type() { return _type; }
	protected:
		const char * _table;
		UInt8 _type;
	};

	class MongoActionBson: public MongoAction
	{
		friend class MongoExecutor;
		friend class MongoFinder;
	public:
		MongoActionBson(const char *, UInt8 = 0xFF);
		virtual ~MongoActionBson();
		bool dump(std::ostringstream& ss);

	public:
		inline MongoActionBson& begin( const char * name = NULL )
		{
			leaveCond();
			if(name != NULL)
			{
				++ _level;
				bson_append_start_object(_bson, name);
			}
			return *this;
		}

		inline MongoActionBson& end()
		{
			if(_level == 0)
				return *this;
			-- _level;
			if(_inCond)
			{
				bson_append_finish_object(_cond);
				if(_level == 0)
					_inCond = false;
			}
			else
				bson_append_finish_object(_bson);
			return *this;
		}

		inline MongoActionBson& condBegin( const char * name = NULL )
		{
			gotoCond();
			if(name != NULL)
			{
				++ _level;
				bson_append_start_object(_cond, name);
			}
			return *this;
		}

		inline MongoActionBson& regex(const char * field, const char * regstr)
		{
			if(_inCond)
				bson_append_regex(_cond, field, regstr, "");
			else
				bson_append_regex(_bson, field, regstr, "");
			return *this;
		}

		inline MongoActionBson& push( const char * name )
		{
			if(_inCond)
				bson_append_int(_cond, name, 1);
			else
				bson_append_int(_bson, name, 1);
			return *this;
		}

		inline MongoActionBson& push( const char * name, const char * val )
		{
			if(_inCond)
				bson_append_string(_cond, name, val);
			else
				bson_append_string(_bson, name, val);
			return *this;
		}

		inline MongoActionBson& push( const char * name, const std::string& val )
		{
			if(_inCond)
				bson_append_string(_cond, name, val.c_str());
			else
				bson_append_string(_bson, name, val.c_str());
			return *this;
		}

		inline MongoActionBson& push( const char * name, Int8 val )
		{
			if(_inCond)
				bson_append_int(_cond, name, val);
			else
				bson_append_int(_bson, name, val);
			return *this;
		}

		inline MongoActionBson& push( const char * name, UInt8 val )
		{
			if(_inCond)
				bson_append_int(_cond, name, val);
			else
				bson_append_int(_bson, name, val);
			return *this;
		}

		inline MongoActionBson& push( const char * name, Int16 val )
		{
			if(_inCond)
				bson_append_int(_cond, name, val);
			else
				bson_append_int(_bson, name, val);
			return *this;
		}

		inline MongoActionBson& push( const char * name, UInt16 val )
		{
			if(_inCond)
				bson_append_int(_cond, name, val);
			else
				bson_append_int(_bson, name, val);
			return *this;
		}

		inline MongoActionBson& push( const char * name, Int32 val )
		{
			if(_inCond)
				bson_append_int(_cond, name, val);
			else
				bson_append_int(_bson, name, val);
			return *this;
		}

		inline MongoActionBson& push( const char * name, UInt32 val )
		{
			if(_inCond)
				bson_append_int(_cond, name, val);
			else
				bson_append_int(_bson, name, val);
			return *this;
		}

		inline MongoActionBson& push( const char * name, Int64 val )
		{
			if(_inCond)
				bson_append_long(_cond, name, val);
			else
				bson_append_long(_bson, name, val);
			return *this;
		}

		inline MongoActionBson& push( const char * name, UInt64 val )
		{
			if(_inCond)
				bson_append_long(_cond, name, val);
			else
				bson_append_long(_bson, name, val);
			return *this;
		}

		inline MongoActionBson& push( const char * name, double val )
		{
			if(_inCond)
				bson_append_double(_cond, name, val);
			else
				bson_append_double(_bson, name, val);
			return *this;
		}

		inline MongoActionBson& push( const char * name, float val )
		{
			if(_inCond)
				bson_append_double(_cond, name, val);
			else
				bson_append_double(_bson, name, val);
			return *this;
		}

		inline MongoActionBson& finish()
		{
			if(_finished)
				return *this;
			_finished = true;
			if(_inCond)
			{
				while(_level > 0)
				{
					bson_append_finish_object(_cond);
					-- _level;
				}
			}
			else
			{
				while(_level > 0)
				{
					bson_append_finish_object(_bson);
					-- _level;
				}
			}
			bson_finish(_bson);
			if(_hasCond)
				bson_finish(_cond);
			return *this;
		}

		inline MongoActionBson& query()
		{
			_queried = true;
			return condBegin("$query");
		}

		inline MongoActionBson& orderby()
		{
			if(!_queried)
			{
				_queried = true;
				condBegin("$query").end();
			}
			return condBegin("$orderby");
		}

		template <typename T>
		inline MongoActionBson& cond(const char * field, const T& data)
		{
			gotoCond();
			return push(field, data);
		}

		template <typename T>
		inline MongoActionBson& cond(const char * field, const char * op, const T& data)
		{
			return condBegin(field).push(op, data).end();
		}

		template <typename T>
		inline MongoActionBson& inc(const char * field, const T& data)
		{
			return begin("$inc").push(field, data).end();
		}

		template <typename T>
		inline MongoActionBson& bit(const char * field, const char * op, const T& data)
		{
			return begin("$bit").begin(field).push(op, data).end().end();
		}

		template <typename T1, typename T2>
		inline MongoActionBson& bit(const char * field, const char * op1, const T1& data1, const char * op2, const T2& data2)
		{
			return begin("$bit").begin(field).push(op1, data1).push(op2, data2).end().end();
		}

		inline MongoActionBson& unset(const char * field)
		{
			return begin("$unset").push(field, 1).end();
		}

		inline MongoActionBson& unset(const char * field1, const char * field2)
		{
			return begin("$unset").push(field1, 1).push(field2, 1).end();
		}

		inline MongoActionBson& unset(const char * field1, const char * field2, const char * field3)
		{
			return begin("$unset").push(field1, 1).push(field2, 1).push(field3, 1).end();
		}

		inline MongoActionBson& unset(const char * field1, const char * field2, const char * field3, const char * field4)
		{
			return begin("$unset").push(field1, 1).push(field2, 1).push(field3, 1).push(field4, 1).end();
		}

		inline MongoActionBson& unset(const char * field1, const char * field2, const char * field3, const char * field4, const char * field5)
		{
			return begin("$unset").push(field1, 1).push(field2, 1).push(field3, 1).push(field4, 1).push(field5, 1).end();
		}

		inline MongoActionBson& unset(const char * field1, const char * field2, const char * field3, const char * field4, const char * field5, const char * field6)
		{
			return begin("$unset").push(field1, 1).push(field2, 1).push(field3, 1).push(field4, 1).push(field5, 1).push(field6, 1).end();
		}

		inline MongoActionBson& unset(const char * field1, const char * field2, const char * field3, const char * field4, const char * field5, const char * field6, const char * field7)
		{
			return begin("$unset").push(field1, 1).push(field2, 1).push(field3, 1).push(field4, 1).push(field5, 1).push(field6, 1).push(field7, 1).end();
		}

		template <typename T1>
		inline MongoActionBson& set(const char * field1, const T1& data1)
		{
			leaveCond();
			if(_type == 0)
				return push(field1, data1);
			return begin("$set").push(field1, data1).end();
		}

		template <typename T1, typename T2>
		inline MongoActionBson& set(const char * field1, const T1& data1, const char * field2, const T2& data2)
		{
			leaveCond();
			if(_type == 0)
				return push(field1, data1).push(field2, data2);
			return begin("$set").push(field1, data1).push(field2, data2).end();
		}

		template <typename T1, typename T2, typename T3>
		inline MongoActionBson& set(const char * field1, const T1& data1, const char * field2, const T2& data2, const char * field3, const T3& data3)
		{
			leaveCond();
			if(_type == 0)
				return push(field1, data1).push(field2, data2).push(field3, data3);
			return begin("$set").push(field1, data1).push(field2, data2).push(field3, data3).end();
		}

		template <typename T1, typename T2, typename T3, typename T4>
		inline MongoActionBson& set(const char * field1, const T1& data1, const char * field2, const T2& data2, const char * field3, const T3& data3, const char * field4, const T4& data4)
		{
			leaveCond();
			if(_type == 0)
				return push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4);
			return begin("$set").push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).end();
		}

		template <typename T1, typename T2, typename T3, typename T4, typename T5>
		inline MongoActionBson& set(const char * field1, const T1& data1, const char * field2, const T2& data2, const char * field3, const T3& data3, const char * field4, const T4& data4, const char * field5, const T5& data5)
		{
			leaveCond();
			if(_type == 0)
				return push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).push(field5, data5);
			return begin("$set").push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).push(field5, data5).end();
		}

		template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
		inline MongoActionBson& set(const char * field1, const T1& data1, const char * field2, const T2& data2, const char * field3, const T3& data3, const char * field4, const T4& data4, const char * field5, const T5& data5, const char * field6, const T6& data6)
		{
			leaveCond();
			if(_type == 0)
				return push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).push(field5, data5).push(field6, data6);
			return begin("$set").push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).push(field5, data5).push(field6, data6).end();
		}

		template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
		inline MongoActionBson& set(const char * field1, const T1& data1, const char * field2, const T2& data2, const char * field3, const T3& data3, const char * field4, const T4& data4, const char * field5, const T5& data5, const char * field6, const T6& data6, const char * field7, const T7& data7)
		{
			leaveCond();
			if(_type == 0)
				return push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).push(field5, data5).push(field6, data6).push(field7, data7);
			return begin("$set").push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).push(field5, data5).push(field6, data6).push(field7, data7).end();
		}

		template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
		inline MongoActionBson& set(const char * field1, const T1& data1, const char * field2, const T2& data2, const char * field3, const T3& data3, const char * field4, const T4& data4, const char * field5, const T5& data5, const char * field6, const T6& data6, const char * field7, const T7& data7, const char * field8, const T8& data8)
		{
			leaveCond();
			if(_type == 0)
				return push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).push(field5, data5).push(field6, data6).push(field7, data7).push(field8, data8);
			return begin("$set").push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).push(field5, data5).push(field6, data6).push(field7, data7).push(field8, data8).end();
		}


		template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
		inline MongoActionBson& set(const char * field1, const T1& data1, const char * field2, const T2& data2, const char * field3, const T3& data3, const char * field4, const T4& data4, const char * field5, const T5& data5, const char * field6, const T6& data6, const char * field7, const T7& data7, const char * field8, const T8& data8, const char * field9, const T9& data9)
		{
			leaveCond();
			if(_type == 0)
				return push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).push(field5, data5).push(field6, data6).push(field7, data7).push(field8, data8).push(field9, data9);
			return begin("$set").push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).push(field5, data5).push(field6, data6).push(field7, data7).push(field8, data8).push(field9, data9).end();
		}

		template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
		inline MongoActionBson& set(const char * field1, const T1& data1, const char * field2, const T2& data2, const char * field3, const T3& data3, const char * field4, const T4& data4, const char * field5, const T5& data5, const char * field6, const T6& data6, const char * field7, const T7& data7, const char * field8, const T8& data8, const char * field9, const T9& data9, const char * field10, const T10& data10)
		{
			leaveCond();
			if(_type == 0)
				return push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).push(field5, data5).push(field6, data6).push(field7, data7).push(field8, data8).push(field9, data9).push(field10, data10);
			return begin("$set").push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).push(field5, data5).push(field6, data6).push(field7, data7).push(field8, data8).push(field9, data9).push(field10, data10).end();
		}

		template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
		inline MongoActionBson& set(const char * field1, const T1& data1, const char * field2, const T2& data2, const char * field3, const T3& data3, const char * field4, const T4& data4, const char * field5, const T5& data5, const char * field6, const T6& data6, const char * field7, const T7& data7, const char * field8, const T8& data8, const char * field9, const T9& data9, const char * field10, const T10& data10, const char * field11, const T11& data11)
		{
			leaveCond();
			if(_type == 0)
				return push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).push(field5, data5).push(field6, data6).push(field7, data7).push(field8, data8).push(field9, data9).push(field10, data10).push(field11, data11);
			return begin("$set").push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).push(field5, data5).push(field6, data6).push(field7, data7).push(field8, data8).push(field9, data9).push(field10, data10).push(field11, data11).end();
		}

		template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
		inline MongoActionBson& set(const char * field1, const T1& data1, const char * field2, const T2& data2, const char * field3, const T3& data3, const char * field4, const T4& data4, const char * field5, const T5& data5, const char * field6, const T6& data6, const char * field7, const T7& data7, const char * field8, const T8& data8, const char * field9, const T9& data9, const char * field10, const T10& data10, const char * field11, const T11& data11, const char * field12, const T12& data12)
		{
			leaveCond();
			if(_type == 0)
				return push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).push(field5, data5).push(field6, data6).push(field7, data7).push(field8, data8).push(field9, data9).push(field10, data10).push(field11, data11).push(field12, data12);
			return begin("$set").push(field1, data1).push(field2, data2).push(field3, data3).push(field4, data4).push(field5, data5).push(field6, data6).push(field7, data7).push(field8, data8).push(field9, data9).push(field10, data10).push(field11, data11).push(field12, data12).end();
		}

	private:
		inline void gotoCond()
		{
			if(!_inCond)
			{
				while(_level > 0)
				{
					bson_append_finish_object(_bson);
					-- _level;
				}
				_inCond = true;
				if(!_hasCond)
				{
					bson_init(_cond);
					_hasCond = true;
				}
			}
		}
		inline void leaveCond()
		{
			if(_inCond)
			{
				while(_level > 0)
				{
					bson_append_finish_object(_cond);
					-- _level;
				}
				_inCond = false;
			}
		}

	private:
		bool _inCond;
		UInt8 _level;
		bool _hasCond;
		bool _queried;
		bool _finished;
		bson _bson[1];
		bson _cond[1];
	};

	class MongoActionGridFS: public MongoAction
	{
		friend class MongoExecutor;
	public:
		MongoActionGridFS(const char *, const char *, const void *, size_t);
	private:
		const char * _name;
		const void * _buf;
		size_t _size;
	};

}

#endif // _MONGOACTION_H_
