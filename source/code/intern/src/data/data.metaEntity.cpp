#include "data.metaEntity.h"

Data::MetaEntity::MetaEntity(int _id, string _name, float _size) :id(_id), name(_name), size(_size)
{
}

Data::MetaEntity::MetaEntity(): id(0), name("") {}
