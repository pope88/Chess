#ifndef _MONGOEXECUTOR_H_
#define _MONGOEXECUTOR_H_


struct mongo;
struct mongo_cursor;

namespace Database
{

	class MongoAction;
	class MongoActionBson;

	struct MongoBind
	{
		inline MongoBind(void * d, const void * def): data(d), dataDef(def), isSet(false) {}
		virtual ~MongoBind() { } 
		virtual void extract(int, const void *) = 0;
		virtual void setDefault() = 0;
		void * data;
		const void * dataDef;
		bool isSet;
	};

	enum {
		BSON_EOO = 0,
		BSON_DOUBLE = 1,
		BSON_STRING = 2,
		BSON_OBJECT = 3,
		BSON_ARRAY = 4,
		BSON_BINDATA = 5,
		BSON_UNDEFINED = 6,
		BSON_OID = 7,
		BSON_BOOL = 8,
		BSON_DATE = 9,
		BSON_NULL = 10,
		BSON_REGEX = 11,
		BSON_DBREF = 12, /**< Deprecated. */
		BSON_CODE = 13,
		BSON_SYMBOL = 14,
		BSON_CODEWSCOPE = 15,
		BSON_INT = 16,
		BSON_TIMESTAMP = 17,
		BSON_LONG = 18
	};

	template<typename T, bool ISFLOAT=false>
	class MongoBindNumber: public MongoBind
	{
	public:
		MongoBindNumber(void * d, const void * def): MongoBind(d, new T(* reinterpret_cast<const T *>(def))) {}
		virtual ~MongoBindNumber()
		{
			delete (T*)dataDef;
		}
		inline void extract(int type, const void * src)
		{
			switch(type)
			{
			case BSON_INT:
				*reinterpret_cast<T*>(data) = static_cast<T>(*reinterpret_cast<const Int32 *>(src));
				break;
			case BSON_LONG:
				*reinterpret_cast<T*>(data) = static_cast<T>(*reinterpret_cast<const Int64 *>(src));
				break;
			case BSON_DOUBLE:
				*reinterpret_cast<T*>(data) = static_cast<T>(*reinterpret_cast<const double *>(src));
				break;
			case BSON_BOOL:
				*reinterpret_cast<T*>(data) = static_cast<T>(*reinterpret_cast<const Int8 *>(src));
				break;
			case BSON_STRING:
				*reinterpret_cast<T*>(data) = ISFLOAT ? static_cast<T>(atof(reinterpret_cast<const char *>(src))) : static_cast<T>(strtoll(reinterpret_cast<const char *>(src), NULL, 10));
				break;
			default:
				return;
			}
			isSet = true;
		}
		inline void setDefault()
		{
			*reinterpret_cast<T*>(data) = *reinterpret_cast<const T*>(dataDef);
		}
	};

	class MongoBindString: public MongoBind
	{
	public:
		MongoBindString(void * d, const void * def): MongoBind(d, new std::string(*reinterpret_cast<const std::string *>(def))) {}
		virtual ~MongoBindString() { delete (std::string *)dataDef; }
		inline void extract(int type, const void * src)
		{
			char v[32];
			switch(type)
			{
			case BSON_INT:
				sprintf(v, "%d", *reinterpret_cast<const Int32 *>(src));
				*reinterpret_cast<std::string*>(data) = v;
				break;
			case BSON_LONG:
				sprintf(v, "%" I64_FMT "d", *reinterpret_cast<const Int64 *>(src));
				*reinterpret_cast<std::string*>(data) = v;
				break;
			case BSON_DOUBLE:
				sprintf(v, "%g", *reinterpret_cast<const double *>(src));
				*reinterpret_cast<std::string*>(data) = v;
				break;
			case BSON_BOOL:
				*reinterpret_cast<std::string*>(data) = *reinterpret_cast<const Int32 *>(src) ? "true" : "false";
				break;
			case BSON_STRING:
				*reinterpret_cast<std::string*>(data) = reinterpret_cast<const char *>(src);
				break;
			default:
				return;
			}
			isSet = true;
		}
		inline void setDefault()
		{
			*reinterpret_cast<std::string*>(data) = *reinterpret_cast<const std::string *>(dataDef);
		}
	};

	template <typename T> struct MongoBindTraits { typedef MongoBind BindType; };
	template <> struct MongoBindTraits<bool> { typedef MongoBindNumber<Int8> BindType; };
	template <> struct MongoBindTraits<wchar_t> { typedef MongoBindNumber<Int16> BindType; };
	template <> struct MongoBindTraits<Int8> { typedef MongoBindNumber<Int8> BindType; };
	template <> struct MongoBindTraits<Int16> { typedef MongoBindNumber<Int16> BindType; };
	template <> struct MongoBindTraits<Int32> { typedef MongoBindNumber<Int32> BindType; };
	template <> struct MongoBindTraits<Int64> { typedef MongoBindNumber<Int64> BindType; };
	template <> struct MongoBindTraits<UInt8> { typedef MongoBindNumber<UInt8> BindType; };
	template <> struct MongoBindTraits<UInt16> { typedef MongoBindNumber<UInt16> BindType; };
	template <> struct MongoBindTraits<UInt32> { typedef MongoBindNumber<UInt32> BindType; };
	template <> struct MongoBindTraits<UInt64> { typedef MongoBindNumber<UInt64> BindType; };
	template <> struct MongoBindTraits<float> { typedef MongoBindNumber<float, true> BindType; };
	template <> struct MongoBindTraits<double> { typedef MongoBindNumber<double, true> BindType; };
	template <> struct MongoBindTraits<std::string> { typedef MongoBindString BindType; };


	enum MongoResult
	{
		OK = 0,
		Failed = 1,
		ConnLost = 2
	};

	class MongoExecutor
	{
	public:
		MongoExecutor(const std::string&, UInt16, const char * dbname);
		virtual ~MongoExecutor();
		inline bool connected() { return _connected; }
		MongoResult run(MongoAction&);
		void ensureIndex(const char * tbl, const char * name, bool unique);
		void ensureIndex(const char * tbl, const char * name1, const char * name2, bool unique);
		void ensureIndex(const char * tbl, const char * name1, const char * name2, const char * name3, bool unique);
		void dropIndexes(const char * tbl);
		char * getGridFS(const char * tbl, const char * name, size_t& sz, UInt32& tm);
	protected:
		bool ensureConn();
		void freeConn();
	protected:
		std::string _dbname;
		bool _connected;

		struct mongo * _conn;
	};

	class MongoFinder: public MongoExecutor
	{
	public:
		MongoFinder(const std::string&, UInt16, const char * dbname);
		virtual ~MongoFinder();
		template<typename T>
		inline MongoResult findOne(MongoActionBson& ma, T& data)
		{
			doFindFinish();
			bind(data);
			return findOne(ma);
		}
		template<typename T>
		inline MongoResult findPrepare(MongoActionBson& ma, T& data, bool output = true)
		{
			MongoResult mr = findPrepare(ma, output);
			if(mr != OK) return mr;
			bind(data);
			return OK;
		}
		template<typename T>
		inline MongoResult findPrepare(const char * tbl, T& data, bool output = true)
		{
			MongoResult mr = findPrepare(tbl, output);
			if(mr != OK) return mr;
			bind(data);
			return OK;
		}
		MongoResult findNext();

		template <typename T>
		void bind(T& data);
		template <typename T>
		inline void bind(const std::string& name, T& data)
		{
			const T defVal = T();
			_binds[name] = new(std::nothrow) typename MongoBindTraits<T>::BindType(&data, &defVal);
		}
		template <typename T, typename DT>
		inline void bind(const std::string& name, T& data, const DT& defVal)
		{
			const T& defVal2 = static_cast<const T&>(defVal);
			_binds[name] = new(std::nothrow) typename MongoBindTraits<T>::BindType(&data, &defVal2);
		}
	private:
		MongoResult findOne(MongoActionBson& ma);
		MongoResult findPrepare(MongoActionBson& ma, bool output = true);
		MongoResult findPrepare(const char * tbl, bool output = true);
		void doFindFinish();
	private:
		struct mongo_cursor * _cursor;
		std::unordered_map<std::string, MongoBind *> _binds;
	};

	template<typename T>
	class MongoTypeHandler
	{
	public:
		static void bind(MongoFinder * me, const std::string& n, T& data, const T& defval)
		{
			me->bind(n, data, defval);
		}
	};

	template <typename T>
	inline void MongoFinder::bind(T& data)
	{
		MongoTypeHandler<T>::bind(this, data);
		std::unordered_map<std::string, MongoBind *>::iterator iter;
		for(iter = _binds.begin(); iter != _binds.end(); ++ iter)
			iter->second->isSet = false;
	}

#define MBINDBEGIN(StructType)	\
	template <>	\
	class MongoTypeHandler<StructType >	\
	{	\
	typedef StructType SpecialType;	\
	public: \
	static void bind(MongoFinder * me, SpecialType& data) \
	{

#define MBINDEND() \
	} \
	};

#define MBIND(FN) \
	me->bind(#FN, data.FN)

#define MBINDDEF(FN, DEFVAL) \
	me->bind(#FN, data.FN, DEFVAL)

}

#endif // _MONGOEXECUTOR_H_
