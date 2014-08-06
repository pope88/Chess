#ifndef _POKE_H_
#define _POKE_H_
#include "../Common/PlayCard.h"
class Poke
{
public:
	Poke();
	~Poke();
public:
	void ShuffleCards();
	void NewRound();
	void SetDefaultLord();
	Card& GetCard(int nPos);
	Card& GetCard();
	inline UInt32 getTotalChips() { return _totalChips; }
	inline void setTotalChips(UInt32 c) {_totalChips = c;}
	inline UInt32 getBaseChips() { return _baseChips; }
	inline void setBaseChips(UInt32 c) { _baseChips = c; }
public:
	std::vector<Card> m_AllCards;	    //ȫ����54��
	UInt8 _bigBlind;                    //��äע
	UInt32 _totalChips;                 //�ܳ���
	UInt32 _baseChips;                  //��������
	UInt8 _finishNum;				//��������Ƿ������
};

#endif // !

