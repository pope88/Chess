#include "Config.h"
#include "GameTable.h"
#include "../../Model/Object/GameTimer.h"

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
	Object::gameTimer.addPresetTimer(Data::Define::Chess, this, 1000);
	//GAMETIMER.addPresetTimer(Data::Define::Chess, this, 1000);
}
