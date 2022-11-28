#include "gfx.startupPhase.h"
#include <iostream>

void Gfx::StartupPhase::OnEnter()
{
	std::cout << "Gfx::StartupPhase::InternOnEnter" << std::endl;
}

void Gfx::StartupPhase::OnRun()
{}

void Gfx::StartupPhase::OnLeave()
{}
