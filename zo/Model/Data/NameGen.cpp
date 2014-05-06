#include "Config.h"
#include "NameGen.h"
#include "Worker/Base.h"

namespace Data
{

	NameGen nameGen;

	std::string NameGen::gen( bool isMale )
	{
		System::Random& rnd = Randomizer();
		UInt32 n = rnd.next(10);
		std::string name;
		if(n < 3)
			name = firstNames[0][rnd.next(firstNames[0].size())];
		else if(n < 5)
			name = firstNames[1][rnd.next(firstNames[1].size())];
		else if(n < 7)
			name = firstNames[2][rnd.next(firstNames[2].size())];
		else
			name = firstNames[3][rnd.next(firstNames[3].size())];
		if(isMale)
			return name + lastNames[0][rnd.next(lastNames[0].size())];
		else
			return name + lastNames[1][rnd.next(lastNames[1].size())];
	}

	void NameGen::add( int idx, const std::string& n )
	{
		if(idx < 4)
		{
			firstNames[idx].push_back(n);
		}
		else if(idx < 6)
		{
			lastNames[idx - 4].push_back(n);
		}
		else
		{
			lastNames[0].push_back(n);
			lastNames[1].push_back(n);
		}
	}

	void NameGen::clear()
	{
		for(int i = 0; i < 4; ++ i)
			firstNames[i].clear();
		for(int i = 0; i < 2; ++ i)
			lastNames[i].clear();
	}

}
