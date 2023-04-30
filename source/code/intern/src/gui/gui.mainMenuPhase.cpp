#include "gui.mainMenuPhase.h"

#include "graphics/gfx.mainMenuPhase.h"
#include <data/data.eventSystem.h>

#include "gui/gui.commandSystem.h"
#include "gui.commandType.h"
#include <iostream>


using namespace Gfx;
using namespace std;
using namespace sf;

namespace Gui
{
	void CMainMenuPhase::OnEnter()
	{
		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();

		CMainMenuPhase MainMenuPhaseClass;
		rEventSystem.Register(Data::CEvent::BTypeID(4), MainMenuPhaseClass.RegisterEvent);
	}


	void CMainMenuPhase::OnRun()
	{

		Gfx::CMainMenuPhase& rGfxMainMenuPhase = Gfx::CMainMenuPhase::GetInstance();
		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();

		CCommandSystem& rCommandSystem = CCommandSystem::GetInstance();
		SCommendType::Enum currentInput;

		while (rCommandSystem.HasCommands())
		{
			currentInput = (rCommandSystem.GetNextCommand());

			switch (currentInput)
			{
				break;
			case SCommendType::Enum::MoveUp:
				rEventSystem.FireEvent(1);
				break;
			case SCommendType::Enum::MoveDown:
				rEventSystem.FireEvent(1);
				break;
			case SCommendType::Enum::Enter:
				rEventSystem.FireEvent(0, rGfxMainMenuPhase.GetMainMenuSelected());
				break;
			
			default:
				break;
			}

			rCommandSystem.RemoveNextCommand();
		}
	}

	void CMainMenuPhase::RegisterEvent(Data::CEvent& _Event)
	{

		CCommandSystem& rCommandSystem = CCommandSystem::GetInstance();

		switch (_Event.GetData())
		{
		case 58:
			rCommandSystem.AddCommand(SCommendType::Enum::Enter);
			break;
		case 73:
			rCommandSystem.AddCommand(SCommendType::Enum::MoveUp);
			break;
		case 74:
			rCommandSystem.AddCommand(SCommendType::Enum::MoveDown);
			break;
		default:
			break;

		}

	}

	void CMainMenuPhase::OnLeave()
	{
		CMainMenuPhase MainMenuPhaseClass;
		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();
		rEventSystem.Unregister(Data::CEvent::BTypeID(4), MainMenuPhaseClass.RegisterEvent);
	}
}