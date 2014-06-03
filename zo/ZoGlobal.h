#ifndef _ZOGLOBAL_H_
#define _ZOGLOBAL_H

class ZoGlobal
{
public:
	enum READYMODE
	{
		MODEZERO = 0, //among users full and all users hands up 
		MODEONE = 1,  //among at lease two user hands up
		MODETWO = 2,  //among at lease three user hands up
	};
public:
	void init();
	inline UInt8 roomNum() { return _roomNum; }
	inline void roomNum(UInt8 r)  { _roomNum = r; }
	inline UInt16 tableNum() { return _tableNum;}
	inline void tableNum(UInt16 t) { _tableNum = t; }
	inline UInt8 playerNum() { return _playerNum; } 
	inline void playerNum(UInt8 pn) { _playerNum = pn; }
	inline UInt8 getReadyMode() { return _readyMode; }
private:
	std::string _serverVer;  //version
	UInt8 _roomNum;         //max room num
	UInt16 _tableNum;        // one room contain max table num
	UInt8 _playerNum;       //one table contain max player num
	UInt8 _readyMode;       //
};

extern ZoGlobal zoGlobal;

#endif