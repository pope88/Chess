#include "Config.h"
#include "Poker.h"

void Poker::newRound()
{
	mVecCards.clear();
	mVecCommonCards.clear();
	m_ctype.clear();
}

void Poker::sortPlayerCards(std::vector<CCard> &vecSortCrads)
{
	std::vector<CCard> vecTemp = vecSortCrads;
	sort(vecTemp.begin(), vecTemp.end(), dcardCompare());
}


bool Poker::isStraight(std::vector<CCard> &vecSortCards) const
{
	bool isStraight = true;
	for (size_t i = 0; i < vecSortCards.size(); ++i)
	{
		if (vecSortCards[0].m_nValue - i != vecSortCards[i].m_nValue)
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

void Poker::getCardType(std::vector<CCard> &mVecSortCards, CardType &ct)
{
	if (mVecSortCards.size() != 5)
	{
		return;
	}
	ct.clear();
	bool isflush = false;
	bool isstraight = false;
	isflush = isFlush(mVecSortCards);
	isstraight = isStraight(mVecSortCards);
	UInt8 mFirst = 0;
	UInt8 mSecond = 0;
	UInt8 mThird = 0;
	UInt8 mFourth = 0;
	UInt8 mScanTable[16];
	UInt8 keyvalue = 0;
	UInt8 type = 0;
	memset(mScanTable, 0, sizeof(mScanTable));
	for (size_t i = 0; i < mVecSortCards.size(); ++i)
	{
		if (mVecSortCards[i].m_nValue >= 3 && mVecSortCards[i].m_nValue <= 15)
		{
			mScanTable[mVecSortCards[i].m_nValue]++;
		}
	}

	for (int i = 2; i < 14; ++i)
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

	for (int i = 2; i < 14; ++i)
	{
		if (mScanTable[i] == 1)
			keyvalue = i;
		else if (mScanTable[i] == 2)
			++mSecond;
		else if (mScanTable[i] == 3)
			++mThird;
		else if (mScanTable[i] == 4)
			++mFourth;
	}

	if (mVecSortCards[0].m_nValue == 14 && isflush && isstraight)
	{
		type = 10;
		keyvalue = 14;
		return;
	}
	else if (mVecSortCards[0].m_nValue != 14 && isflush && isstraight)
	{
		type = 9;
		keyvalue = mVecSortCards[0].m_nValue;
		return;
	}
	else if(mFourth == 1 && mFirst == 1)
	{
		type = 8;
	}
	else if (mThird == 1 && mSecond == 1)
	{
		type = 7;
	}
	else if (isflush)
	{
		type = 6;
	}
	else if (isstraight)
	{
		type = 5;
	}
	else if (mThird == 1 && mFirst == 2)
	{
		type = 4;
	}
	else if (mSecond == 2 && mFirst == 1)
	{
		type = 3;
	}
	else if (mSecond == 1 && mFirst == 3)
	{
		type = 2;
	}
	else if (mFirst == 5)
	{
		type = 1;
	}
	type = 0;

	for (int i = 2; i < 14; ++i)
	{
		if (mScanTable[i] == 1 && type == 1)
		{
			keyvalue = i;
		}
		else if (mScanTable[i] == 2 && (type == 2 || type == 3) )
		{
			keyvalue = i;
		}
		else if (mScanTable[i] == 3 && (type == 4 || type == 7))
		{
			keyvalue = i;
			break;
		}
		else if (mScanTable[i] == 4)
		{
			keyvalue = i;
		}
	}
}

void Poker::setCards(const std::vector<CCard> &vecCards)
{
	mVecCards = vecCards;
}

void Poker::setCommonCards(const std::vector<CCard> &vecCards)
{
	mVecCommonCards = vecCards;
}

bool Poker::getBiggestCards()
{
	std::vector<std::vector<CCard> > allcards;
	std::vector<CardType> allcardtypes;
	if (mVecCommonCards.size() != 5)
	{
		return false;
	}

	for (size_t i = 0; i < mVecCommonCards.size()-2; ++i)
	{
		for (size_t j = i+1; j < mVecCommonCards.size()-1; ++j)
		{
			std::vector<CCard> cvec;
			cvec.push_back(mVecCards[0]);
			cvec.push_back(mVecCards[1]);
			cvec.push_back(mVecCommonCards[i]);
			cvec.push_back(mVecCommonCards[j]);
			cvec.push_back(mVecCommonCards[j+1]);
			sortPlayerCards(cvec);
			allcards.push_back(cvec);
		}
	}
	
	for (size_t i = 0; i < allcards.size(); ++i)
	{
		CardType ct;
		getCardType(allcards[i], ct);
		allcardtypes.push_back(ct);
	}
	
	sort(allcardtypes.begin(), allcardtypes.end(), typeCompare());
	m_ctype = allcardtypes[0];
	return true;
}