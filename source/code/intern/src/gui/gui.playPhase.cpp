#include "gui.playPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#include <logic/logic.inputSystem.h>

#include <data/data.eventSystem.h>
#include "gui/gui.commandSystem.h"
#include "gui.commandType.h"

#include <iostream>

using namespace std;

namespace Gui
{
	void CPlayPhase::OnEnter()
	{
		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();
		
		rEventSystem.Register(Data::CEvent::BTypeID(4), CPlayPhase::RegisterEvent);

	}


	void CPlayPhase::OnRun()
	{
		CCommandSystem& rCommandSystem = CCommandSystem::GetInstance();
		Logic::CInputSystem& rLogicInputSystem = Logic::CInputSystem::GetInstance();

		SCommendType::Enum currentInput;

		while (rCommandSystem.HasCommands())
		{
			currentInput = (rCommandSystem.GetNextCommand());

			switch (currentInput)
			{
			break;
			case SCommendType::Enum::MoveUp:
				rLogicInputSystem.AddInput(Logic::SInputType::MoveUp);
				break;
			case SCommendType::Enum::MoveDown:
				rLogicInputSystem.AddInput(Logic::SInputType::MoveDown);
				break;
			case SCommendType::Enum::MoveRight:
				rLogicInputSystem.AddInput(Logic::SInputType::MoveRight);
				break;
			case SCommendType::Enum::MoveLeft:
				rLogicInputSystem.AddInput(Logic::SInputType::MoveLeft);

				break;
			default:
				break;
			}

			rCommandSystem.RemoveNextCommand();
		}


	}

	void CPlayPhase::RegisterEvent(Data::CEvent& _Event)
	{
		CCommandSystem& rCommandSystem = CCommandSystem::GetInstance();
		
		switch (_Event.GetData())
		{
		case 71:
			rCommandSystem.AddCommand(SCommendType::Enum::MoveLeft);
			break;

		case 72:
			rCommandSystem.AddCommand(SCommendType::Enum::MoveRight);
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

	void CPlayPhase::OnLeave()
	{
		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();
		rEventSystem.Unregister(Data::CEvent::BTypeID(4), CPlayPhase::GetInstance().RegisterEvent);

	}
}