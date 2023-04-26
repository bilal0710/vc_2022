#pragma once
namespace Data
{
	class CEvent;
}

namespace Data
{
	// Function pointer to a static method of a class or a global C method
	using CEventListener = void (*) (CEvent& event);
		
}

