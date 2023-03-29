#pragma once
#include <string>
#include "../core/core_aabb.h"

using namespace std;

namespace Data
{
	class CMetaEntity
	{
	public:
		CMetaEntity(int _id, string _name, float _size);
			

		CMetaEntity();


	public:
		int id;
		string name;
		float size;
		Core::AABB3Float aabb;

		void* facetes[2];

	};

}
