#pragma once
#include "data.metaEntity.h"
#include "../core/core_id_manager.h"
#include "../core/core_item_manager.h"

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
		void Initialize();
		MetaEntity& createMetaEntity(const string _pName);

	private:
		Core::CIDManager m_idManger;
		Core::CItemManager <MetaEntity> m_itemManager;
	};

}
