#pragma once

#include <tinyxml2.h>
#include "../core/core_id_manager.h"
#include "../core/core_item_manager.h"
#include "data.metaEntity.h"

using namespace Core;
namespace Data
{
	class CMetaEntitySystem
	{
	public:
		static CMetaEntitySystem& GetInstance()
		{
			static CMetaEntitySystem instance;
			return instance;
		};

		CMetaEntitySystem(const CMetaEntitySystem&) = delete;
		CMetaEntitySystem& operator = (const CMetaEntitySystem&) = delete;

	private:
		CMetaEntitySystem()
		{};

	public:
		void Initialize(tinyxml2::XMLDocument& _rMetaEntity);
		CMetaEntity& CreateMetaEntity(const string _Name);
		CMetaEntity& GetMetaEntity(CIDManager::BID _ID);
		void DestroyAllMetaEntities();
		bool ContainsMetaEntity(string& _rName);

		CMetaEntity& SearchMetaEntity(std::string _Name);

		bool ContainsMetaEntity(std::string _Name);

		Core::CIDManager::BID GetMetaEntityID(std::string _Name);

	private:
		Core::CIDManager m_IdManger;
		Core::CItemManager <CMetaEntity> m_ItemManager;
	
	};

}
