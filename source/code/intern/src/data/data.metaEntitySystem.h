#pragma once
#include "data.metaEntity.h"
#include "../core/core_id_manager.h"
#include "../core/core_item_manager.h"

using namespace Core;
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
		MetaEntity& CreateMetaEntity(const string _pName);
		MetaEntity& GetMetaEntity(CIDManager::BID _ID);
		void DestroyAllMetaEntities();
		bool ContainsMEtaEntity(string& _pName);

	private:
		Core::CIDManager m_idManger;
		Core::CItemManager <MetaEntity> m_itemManager;
	
	};

}
