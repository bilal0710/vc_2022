#include "gui.playPhase.h"
#include <iostream>

#include <SFML/Graphics.hpp>




namespace Gui
{
	void CPlayPhase::OnEnter()
	{


	}

	static void EventCallBack(Data::CEvent& data) {
		// std::cout << "ABC" << std::endl;

	}

	void CPlayPhase::OnRun()
	{
		//std::cout << "Gui::PlayPhase::OnRun" << std::endl;
		//std::cout << "------------------------" << std::endl;


	}

	void CPlayPhase::OnLeave()
	{}
}