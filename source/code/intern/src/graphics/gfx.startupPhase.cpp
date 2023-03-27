#include "gfx.startupPhase.h"
#include <iostream>

void Gfx::StartupPhase::OnEnter()
{
	std::cout << "Gfx::StartupPhase::OnEnter" << std::endl;
}

void Gfx::StartupPhase::OnRun()
{
	std::cout << "Gfx::StartupPhase::OnRun" << std::endl;
}

void Gfx::StartupPhase::OnLeave()
{
	std::cout << "Gfx::StartupPhase::OnLeave" << std::endl;
}
