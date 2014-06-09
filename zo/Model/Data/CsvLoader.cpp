#include "Config.h"
#include "CsvLoader.h"
#include "System/CsvParser.h"
#include "ZoCfg.h"

#include "Model/Data/NameGen.h"
#include "Model/Data/ItemMgr.h"

namespace Data
{
	void CsvLoader::load()
	{
		std::string path;
		System::CsvParser parser(';', '"');
		bool result;
		const System::CsvParser::Row *rowp;

#define CSV_LOAD_LOOP(fn) \
	result = false; \
	if(zocfg.useOldData) \
		{ \
		path = zocfg.dataPath + fn + "_old.csv"; \
		result = parser.load(path.c_str()); \
		} \
		if(!result) \
		{ \
			path = zocfg.dataPath + fn + ".csv"; \
			if(!parser.load(path.c_str())) \
				return ; \
		}\
			parser.skip(1); \
			fprintf(stdout, "Loading %s...\n", path.c_str()); \
			fflush(stdout); \
			while((rowp = parser.next()) != NULL)

#define row (*rowp)
#define ROW_UINT(n) System::toUInt32(row[n].c_str())
#define ROW_UINT64(n) System::toUInt64(row[n].c_str())
#define ROW_INT(n) System::toInt32(row[n].c_str())
#define ROW_FLOAT(n) System::toDouble(row[n].c_str())

		/*load random names*/
		nameGen.clear();
		CSV_LOAD_LOOP("random_name")
		{
			if (row[0].empty())
			{
				continue;
			}
			nameGen.add(atoi(row[0].c_str()), row[1]);
		}

		/*load item*/
		itemMgr.clear();
		CSV_LOAD_LOOP("item")
		{
			if (row[0].empty())
			{
				continue;
			}
			UInt32 id = atoi(row[0].c_str());
			if (id >= 200000)
			{
				continue;
			}
			ItemData &idata = itemMgr[id];
			idata.exists = true;
			idata.type = atoi(row[2].c_str());
			idata.level = atoi(row[3].c_str());
			idata.quality = atoi(row[4].c_str());
			idata.stack = atoi(row[6].c_str());
			if (idata.stack == 0)
			{
				idata.stack = 99;
			}
			idata.price = atoi(row[7].c_str());
			int b = atoi(row[9].c_str());
			idata.bound_policy = b & 3;
			idata.record = (b & 4) == 0;
			idata.marktype = atoi(row[10].c_str());
		}
	}

	void CsvLoader::unload()
	{

	}

}
