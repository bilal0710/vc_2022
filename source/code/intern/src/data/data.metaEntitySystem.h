#pragma once

namespace Data
{
	class MetaEntitySystem
	{
	public:
		static MetaEntitySystem& GetInstance()
		{
			static MetaEntitySystem instance;
			return instance;
		};

		MetaEntitySystem(const MetaEntitySystem&) = delete;
		MetaEntitySystem& operator = (const MetaEntitySystem&) = delete;

	private:
		MetaEntitySystem()
		{};

	public:
		void test();
	};

}
