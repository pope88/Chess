#ifndef _DBOBJECT_H_
#define _DBOBJECT_H_

#include "Database/MongoAction.h"

namespace Object
{

	class DBObject
	{
	public:
		template<typename DT>
		inline void writeData(const char * tableName, const char * fieldName, const DT& data)
		{
			Database::MongoActionBson * ma = new Database::MongoActionBson(tableName, 2);
			(*ma).set(fieldName, data);
			addUpdateCondition(*ma);
			pushAction(ma);
		}
		template<typename DT1, typename DT2>
		inline void writeData(const char * tableName, const char * fieldName1, const DT1& data1, const char * fieldName2, const DT2& data2)
		{
			Database::MongoActionBson * ma = new Database::MongoActionBson(tableName, 2);
			(*ma).set(fieldName1, data1, fieldName2, data2);
			addUpdateCondition(*ma);
			pushAction(ma);
		}
		template<typename DT1, typename DT2, typename DT3>
		inline void writeData(const char * tableName, const char * fieldName1, const DT1& data1, const char * fieldName2, const DT2& data2, const char * fieldName3, const DT3& data3)
		{
			Database::MongoActionBson * ma = new Database::MongoActionBson(tableName, 2);
			(*ma).set(fieldName1, data1, fieldName2, data2, fieldName3, data3);
			addUpdateCondition(*ma);
			pushAction(ma);
		}

		inline void delRecord(const char * tableName)
		{
			Database::MongoActionBson * ma = new Database::MongoActionBson(tableName, 1);
			addUpdateCondition(*ma);
			pushAction(ma);
		}
	protected:
		void pushAction(Database::MongoAction * sql);
		virtual void addUpdateCondition(Database::MongoActionBson&) = 0;
	};

#define DB_PROP_UPDATE_COND(t1, n1) \
	virtual void addUpdateCondition(Database::MongoActionBson& ma) \
	{ \
	ma.condBegin().push(#t1, n1).end(); \
	}

#define DB_PROP_UPDATE_COND2(t1, n1, t2, n2) \
	virtual void addUpdateCondition(Database::MongoActionBson& ma) \
	{ \
	ma.condBegin().push(#t1, n1).push(#t2, n2).end(); \
	}


#define DB_PROP_SET(t, n) \
public: \
	inline t n() const { return _##n; } \
	inline void set##n(t data, bool w = true) { \
	if(_##n == data) \
	return; \
	if(w) writeData(getTableName(), #n, data); \
	_##n = data; \
	} \

#define DB_PROP_WRITEONLY(t, n) \
public: \
	inline void set##n(t data, bool w = true) { \
	if(_##n == data) \
	return; \
	if(w) writeData(getTableName(), #n, data); \
	_##n = data; \
	} \

#define DB_PROP_ADD(t, n) \
	DB_PROP_SET(t, n) \
private: \
	t _##n; \

#define DB_PROP_ADD_WRITEONLY(t, n) \
	DB_PROP_WRITEONLY(t, n) \
private: \
	t _##n; \

#define DB_MERGE_PROP2(t1, n1, t2, n2) \
public: \
	inline void n1##n2(t1 data1, t2 data2, bool w = true) { \
	if(_##n1 == data1 && _##n2 == data2) \
	return; \
	if(w) writeData(getTableName(), #n1, data1, #n2, data2); \
	_##n1 = data1; \
	_##n2 = data2; \
	} \

#define DB_MERGE_PROP3(t1, n1, t2, n2, t3, n3) \
public: \
	inline void n1##n2##n3(t1 data1, t2 data2, t3 data3, bool w = true) { \
	if(_##n1 == data1 && _##n2 == data2 && _##n3 == data3) \
	return; \
	if(w) writeData(getTableName(), #n1, data1, #n2, data2, #n3, data3); \
	_##n1 = data1; \
	_##n2 = data2; \
	_##n3 = data3; \
	} \

#define DB_PROP_ADD_REF(t, n) \
public: \
	inline const t& n() const { return _##n; } \
	inline void n(const t& data, bool w = true) { \
	if(_##n == data) \
	return; \
	if(w) writeData(getTableName(), #n, data); \
	_##n = data; \
	} \
private: \
	t _##n; \

#define DB_PUSH_INSERT(db, cmd) { Database::MongoActionBson * ma = new(std::nothrow) Database::MongoActionBson(db, 0); if(ma != NULL) { ma->cmd; pushAction(ma); } }
#define DB_PUSH_DELETE(db, cmd) { Database::MongoActionBson * ma = new(std::nothrow) Database::MongoActionBson(db, 1); if(ma != NULL) { ma->cmd; pushAction(ma); } }
#define DB_PUSH_UPDATE(db, cmd) { Database::MongoActionBson * ma = new(std::nothrow) Database::MongoActionBson(db, 2); if(ma != NULL) { ma->cmd; pushAction(ma); } }
#define DB_PUSH_UPSERT(db, cmd) { Database::MongoActionBson * ma = new(std::nothrow) Database::MongoActionBson(db, 3); if(ma != NULL) { ma->cmd; pushAction(ma); } }

}

#endif // _DBOBJECT_H_
