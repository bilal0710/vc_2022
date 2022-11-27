#pragma once

namespace Data
{
	class EntitySystem
	{
	public:
		static EntitySystem& GetInstance()
		{
			static EntitySystem instance;
			return instance;
		};

		EntitySystem(const EntitySystem&) = delete;
		EntitySystem& operator = (const EntitySystem&) = delete;

	private:
		EntitySystem()
		{};

	public:
		void test();
	};

}
