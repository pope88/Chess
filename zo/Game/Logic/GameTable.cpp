#include "Config.h"
#include "GameTable.h"


void GameTable::onGameStart()
{
	NewRound();

	m_Poke.NewRound();

	Dealing();

	SetBaseMoney();

	//DealingTask();

	SvrStartGameNot();
}

void GameTable::NewRound()
{

}

void GameTable::Dealing()
{
	//timer
	this->addInterValTimer(eANIMATE_EVENT, 100);
}

void GameTable::onTimer()
{
	switch (timerId())
	{
	case eANIMATE_EVENT:
		{
			printf("eANIMATE_EVENT");
		}
		break;
	case eCALLSCORE_EVENT:
		{
		}
		break;
	default:
		break;
	}
}
