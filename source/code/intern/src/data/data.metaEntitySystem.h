#pragma once

#include <tinyxml2.h>
#include "../core/core_id_manager.h"
#include "../core/core_item_manager.h"
#include "data.metaEntity.h"

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
		void Initialize(tinyxml2::XMLDocument& doc);
		MetaEntity& CreateMetaEntity(const string _pName);
		MetaEntity& GetMetaEntity(CIDManager::BID _ID);
		void DestroyAllMetaEntities();
		bool ContainsMetaEntity(string& _pName);

		MetaEntity& SearchMetaEntity(std::string name);

		bool ContainsMetaEntity(std::string name);

		Core::CIDManager::BID GetMetaEntityID(std::string name);

	private:
		Core::CIDManager m_idManger;
		Core::CItemManager <MetaEntity> m_itemManager;
	
	};

}
