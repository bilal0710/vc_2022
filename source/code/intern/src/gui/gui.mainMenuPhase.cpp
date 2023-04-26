#include "gui.mainMenuPhase.h"

#include "graphics/gfx.mainMenuPhase.h"
#include <data/data.eventSystem.h>

#include <gui/gui.choiceSystem.h>
#include <gui/gui.choiceType.h>

#include <iostream>


using namespace Gfx;
using namespace std;
using namespace sf;

namespace Gui
{
	void CMainMenuPhase::OnEnter()
	{
		std::cout << "Gui::MainMenuPhase::OnEnter" << std::endl;
	}


	void CMainMenuPhase::OnRun()
	{

		Gfx::CMainMenuPhase& rGfxMainMenuPhase = Gfx::CMainMenuPhase::GetInstance();
		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();
		Gui::CChoiceSystem& rGuiChoiceSystem = Gui::CChoiceSystem::GetInstance();
		Gui::SChoiceType::Enum currentChoice;

		while (rGuiChoiceSystem.HasInputs())
		{
			currentChoice = (rGuiChoiceSystem.GetNextInput());

			switch (currentChoice)
			{
			case SChoiceType::Enum::Move:

				rEventSystem.FireEvent(1);
				break;

			case SChoiceType::Enum::Enter:
				rEventSystem.FireEvent(0, rGfxMainMenuPhase.GetMainMenuSelected());
				break;

			default:
				break;
			}

			rGuiChoiceSystem.RemoveNextInput();
		}
	}

	void CMainMenuPhase::OnLeave()
	{}
}