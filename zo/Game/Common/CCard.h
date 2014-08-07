#ifndef _CCARD_H_ 
#define _CCARD_H_

struct CCardsType
{
public:
	CCardsType()
	{
		m_nTypeBomb = 0;
		m_nTypeNum = 0;
		m_nTypeValue = 0;
	}
	void SetValue(int nBomb, int nNum, int nValue)
	{
		m_nTypeBomb = nBomb;
		m_nTypeNum = nNum;
		m_nTypeValue = nValue;
	}
public:
	int m_nTypeBomb;	// 0:不是炸弹 1:软炸弹 2:硬炸弹
	int m_nTypeNum;		//牌的数量
	int m_nTypeValue;	//牌的值
};

class CCard
{
public:
	CCard():m_nValue(0), m_nColor(0) {}
	CCard(UInt8 c, UInt8 v) { m_nColor = c; m_nValue = v; }
	~CCard(){}
public:
	CCard(const CCard &srcCard)
	{
		if (this == &srcCard)
			return;
		m_nValue = srcCard.m_nValue;
		m_nColor = srcCard.m_nColor;
	}
	CCard& operator =(CCard &srcCard)
	{
		if (this == &srcCard)
			return *this;
		m_nValue = srcCard.m_nValue;
		m_nColor = srcCard.m_nColor;
		return *this;
	}

	bool operator == (CCard &srcCard)
	{
		return (m_nColor == srcCard.m_nColor && m_nValue == srcCard.m_nValue);
	}
public:
	UInt8 m_nValue;
	UInt8 m_nColor;
};

/*
struct CCard
{
public:
	CCard():m_nValue(0), m_nColor(0) {}
	CCard(UInt8 nColor, UInt8 nValue) : m_nColor(nColor), m_nValue(nValue) {}
public:
	CCard(const CCard &srcCard)
	{
		if(this == &srcCard)
			return;
		m_nColor = srcCard.color();
		m_nValue = srcCard.cvalue();
	}
	CCard& operator = (const CCard &srcCard)
	{
		if (this == &srcCard)
			return *this;
		m_nColor = srcCard.color();
		m_nValue = srcCard.cvalue();
		return *this;
	}
	bool operator == (const CCard &srcCard)
	{
		return (m_nColor == srcCard.color() && m_nValue == srcCard.cvalue());
	}
public:
	UInt8 color()
	{
		return m_nColor;
	}
	void setcolor(UInt8 c)
	{
		m_nColor = c;
	}
	UInt8 cvalue()
	{
		return m_nValue;
	}
	void setcvalue(UInt8 v)
	{
		m_nValue = v;
	}
private:
	UInt8 m_nColor;  //花色,-1表示没有任意花色
	UInt8 m_nValue;  //数值,-1表示还没有牌
};*/

#endif