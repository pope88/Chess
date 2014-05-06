#include "Config.h"
#include "ValidateName.h"

namespace Object
{

	static inline int char_type(UInt8 p)
	{
		if(p < 0x20) return -1;
		if(p >= 0xFE) return -1;
		if(p >= 0xFC) return 6;
		if(p >= 0xF8) return 5;
		if(p >= 0xF0) return 4;
		if(p >= 0xE0) return 3;
		if(p >= 0xC0) return 2;
		if(p >= 0x80) return -1;
		return 1;
	}

#if defined(__GNUC__)
	struct SubName
	{
		SubName(): isLeaf(false) {}
		bool isLeaf;
		std::map<std::string, SubName> name;
	};
#endif

	void ValidateName::trimName( std::string& str )
	{
		static bool inited = false;
		static std::map<UInt8, std::set<UInt8> > charAllowed2;
		typedef std::map<UInt8, std::map<UInt8, std::set<UInt8> > > CAMapMap;
		static CAMapMap charAllowed3;
		if(!inited)
		{
			inited = true;
            #include "ValidChars.inl"
			for(const CharRange2 * cr2 = charRange2; cr2->c1 != 0; ++ cr2)
			{
				for(UInt8 v = cr2->c2l; v <= cr2->c2h; ++ v)
					charAllowed2[cr2->c1].insert(v);
			}
			for(const CharRange3 * cr3 = charRange3; cr3->c1 != 0; ++ cr3)
			{
				for(UInt8 v = cr3->c3l; v <= cr3->c3h; ++ v)
					charAllowed3[cr3->c1][cr3->c2].insert(v);
			}
		}

		size_t len = str.length();
		size_t i = 0;
		while(i < len)
		{
			if(str[i] >= 0 && str[i] <= ' ')
				++ i;
			else if(i + 2 < len && static_cast<UInt8>(str[i]) == 0xE3 && static_cast<UInt8>(str[i + 1]) == 0x80 && static_cast<UInt8>(str[i + 2]) == 0x80)
				i += 3;
			else
				break;
		}
		size_t j = len;
		while(j > 0)
		{
			if(str[j - 1] >= 0 && str[j - 1] <= ' ')
				-- j;
			else if(j > 2 && static_cast<UInt8>(str[j - 3]) == 0xE3 && static_cast<UInt8>(str[j - 2]) == 0x80 && static_cast<UInt8>(str[j - 1]) == 0x80)
				j -= 3;
			else
				break;
		}
		if(i < j)
			str = std::string(str.begin() + i, str.begin() + j);
		else
			str.clear();
		len = str.length();
		i = 0;
		bool valid = true;
		while(valid && i < len)
		{
			int cur = char_type(str[i]);
			if(cur < 0)
			{
				str.erase(str.begin() + i);
				-- len;
			}
			else
			{
				size_t nl = i + static_cast<size_t>(cur);
				if(nl > len)
				{
					valid = false;
					break;
				}
				switch(cur)
				{
				case 1:
					if(str[i] < 0x20 || str[i] > 0x7E || str[i] == '<' || str[i] == '>' || str[i] == '[' || str[i] == ']')
						valid = false;
					break;
				case 2:
					{
						std::map<UInt8, std::set<UInt8> >::const_iterator it = charAllowed2.find(static_cast<UInt8>(str[i]));
						if(it == charAllowed2.end())
							valid = false;
						else
						{
							std::set<UInt8>::const_iterator it2 = it->second.find(static_cast<UInt8>(str[i + 1]));
							if(it2 == it->second.end())
								valid = false;
						}
					}
					break;
				case 3:
					{
						std::map<UInt8, std::map<UInt8, std::set<UInt8> > >::const_iterator it = charAllowed3.find(static_cast<UInt8>(str[i]));
						if(it == charAllowed3.end())
							valid = false;
						else
						{
							std::map<UInt8, std::set<UInt8> >::const_iterator it2 = it->second.find(static_cast<UInt8>(str[i + 1]));
							if(it2 == it->second.end())
								valid = false;
							else
							{
								std::set<UInt8>::const_iterator it3 = it2->second.find(static_cast<UInt8>(str[i + 2]));
								if(it3 == it2->second.end())
									valid = false;
							}
						}
					}
					break;
				default:
					valid = false;
					break;
				}
				i = nl;
			}
		}

		valid = true;
		if(!valid || i > len)
		{
			str.clear();
			return;
		}

#if defined(__GNUC__)
		static SubName root;
		static bool snInited = false;
		if(!snInited)
		{
			snInited = true;
#include "ValidWords.inl"
		}
		size_t spos = 0;
		while(spos < str.length())
		{
			SubName * sn = &root;
			bool match = true;
			size_t pos = spos;
			while(!sn->isLeaf)
			{
				if(pos >= str.length())
				{ match = false; break; }
				std::map<std::string, SubName>::iterator it1;
				if((unsigned char)str[pos] >= 0xE0)
					it1 = sn->name.find(str.substr(pos, 3));
				else
					it1 = sn->name.find(str.substr(pos, 1));
				if(it1 == sn->name.end())
				{ match = false; break; }
				sn = &it1->second;
				pos += it1->first.length();
			}
			if(match)
			{
				str.clear();
				return;
			}
			if((unsigned char)str[spos] >= 0xE0)
				spos += 3;
			else
				spos += 1;
		}
#endif
	}

}
