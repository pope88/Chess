#ifndef _NAMEGEN_H_
#define _NAMEGEN_H_

namespace Data
{

	class NameGen
	{
		friend class CsvLoader;
	public:
		std::string gen(bool);
		void clear();
	private:
		void add(int, const std::string&);
	private:
		std::vector<std::string> firstNames[4];
		std::vector<std::string> lastNames[2];
	};

	extern NameGen nameGen;

}

#endif // _NAMEGEN_H_
