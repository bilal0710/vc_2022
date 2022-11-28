#pragma once
#include <string>

using namespace std;

namespace Data
{
	class MetaEntity
	{
	public:
		MetaEntity(int _id, string _name);
		MetaEntity();


	public:
		int id;
		string name;

	};

}
