#pragma once
#include <string>
#include "../core/core_aabb.h"

using namespace std;

namespace Data
{
	class MetaEntity
	{
	public:
		MetaEntity(int _id, string _name, float _size);
			

		MetaEntity();


	public:
		int id;
		string name;
		float size;
		Core::AABB3Float aabb;

		void* facetes[2];

	};

}
