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
		void Initialize(tinyxml2::XMLDocument& doc);
		CMetaEntity& CreateMetaEntity(const string _pName);
		CMetaEntity& GetMetaEntity(CIDManager::BID _ID);
		void DestroyAllMetaEntities();
		bool ContainsMetaEntity(string& _pName);

		CMetaEntity& SearchMetaEntity(std::string name);

		bool ContainsMetaEntity(std::string name);

		Core::CIDManager::BID GetMetaEntityID(std::string name);

	private:
		Core::CIDManager m_idManger;
		Core::CItemManager <CMetaEntity> m_itemManager;
	
	};

}
