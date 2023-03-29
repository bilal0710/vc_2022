#include "game.phase.h"

int Game::CPhase::OnEnter()
{
	return InternOnEnter();
}

int Game::CPhase::OnRun()
{
	return InternOnRun();
}

int Game::CPhase::OnLeave()
{
	return InternOnLeave();
}