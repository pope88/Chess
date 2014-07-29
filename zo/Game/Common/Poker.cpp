#include "Config.h"
#include "Poker.h"

void Poker::newRound()
{
	mVecCards.clear();
	mVecSortCards.clear();
	mVecPicCards.clear();
	mVecTotalCards.clear();
}

int Poker::getCardType()
{
	return 0;
}

void Poker::sortPlayerCards(std::vector<CCard> &vecSortCrads)
{
	std::vector<CCard> vecTemp = vecSortCrads;
	sort(vecTemp.begin(), vecTemp.end(), dcardCompare());
	UInt8 nScanTable[16];
	memset(nScanTable, 0, sizeof(nScanTable));
	for (size_t i = 0; i < vecTemp.size(); ++i)
	{
		if (vecTemp[i].m_nValue >= 3 && vecTemp[i].m_nValue <= 15)
		{
			nScanTable[vecTemp[i].m_nValue]++;
		}
	}
}

bool Poker::isStraight(std::vector<CCard> &vecSortCards) const
{
	bool isStraight = true;
	for (size_t i = 0; i < vecSortCards.size(); ++i)
	{
		if (vecSortCards[0].m_nValue + i != vecSortCards[i].m_nValue)
		{
			isStraight = false;
			break;
		}
	}
	return isStraight;
}

bool Poker::isFlush(std::vector<CCard> &vecSortCards)
{
	bool isflush = true;
	for (size_t i = 1; i < vecSortCards.size(); ++i)
	{
		if (vecSortCards[i].m_nColor != vecSortCards[i-1].m_nColor)
		{
			isflush = false;
			return isflush;

		}
	}
	return isflush;
}

int Poker::getCardType()
{
	if (mVecSortCards.size() != 5)
	{
		return 0;
	}
	bool isflush = false;
	bool isstraight = false;
	isflush = isFlush(mVecSortCards);
	isstraight = isStraight(mVecSortCards);
	UInt8 mFirst = 0;
	UInt8 mSecond = 0;
	UInt8 mThird = 0;
	UInt8 mFourth = 0;
	UInt8 mScanTable[16];
	memset(mScanTable, 0, sizeof(mScanTable));
	for (size_t i = 0; i < mVecSortCards.size(); ++i)
	{
		if (mVecSortCards[i].m_nValue >= 3 && mVecSortCards[i].m_nValue <= 15)
		{
			mScanTable[mVecSortCards[i].m_nValue]++;
		}
	}

	for (int i = 0; i < 16; ++i)
	{
		if (mScanTable[i] == 1)
			++mFirst;
		else if (mScanTable[i] == 2)
			++mSecond;
		else if (mScanTable[i] == 3)
			++mThird;
		else if (mScanTable[i] == 4)
			++mFourth;
	}

	if (mVecSortCards[0].m_nValue == 10 && isflush && isstraight)
	{
		return 10;  
	}
	else if (mVecSortCards[0].m_nValue != 10 && isflush && isstraight)
	{
		return 9;
	}
	else if(mFourth == 1 && mFirst == 1)
	{
		return 8;
	}
	else if (mThird == 1 && mSecond == 1)
	{
		return 7;
	}
	else if (isflush)
	{
		return 6;
	}
	else if (isstraight)
	{
		return 5;
	}
	else if (mThird == 1 && mFirst == 2)
	{
		return 4;
	}
	else if (mSecond == 2 && mFirst == 1)
	{
		return 3;
	}
	else if (mSecond == 1 && mFirst == 3)
	{
		return 2;
	}
	else if (mFirst == 5)
	{
		return 1;
	}
	return 0;
}

void Poker::setCards(const std::vector<CCard> &vecCards)
{
	mVecCards = vecCards;
	mVecSortCards = vecCards;
}