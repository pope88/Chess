#ifndef _ITEMMGR_H_
#define _ITEMMGR_H_

namespace Data
{
	struct ItemData
	{
		bool exists;
		UInt16 type;
		UInt16 level;
		UInt16 stack;
		UInt16 price;
		UInt8 quality;
		UInt8 marktype;
		UInt8 bound_policy;
		bool record;
	};
	class ItemMgr
	{
	public:
		ItemMgr()
		{
			memset(_datas, 0, sizeof(_datas));
		}
		virtual ~ItemMgr() {}
		inline ItemData& operator[](UInt16 id)
		{
			return _datas[id];
		}
		inline void clear()
		{
			memset(_datas, 0, sizeof(_datas));
		}
	private:
		ItemData _datas[0x8000];
	};
	extern ItemMgr itemMgr;
}
#endif