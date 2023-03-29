#include "data.metaEntity.h"

Data::CMetaEntity::CMetaEntity(int _id, string _name, float _size) :id(_id), name(_name), size(_size)
{
}

Data::CMetaEntity::CMetaEntity(): id(0), name("") {}
