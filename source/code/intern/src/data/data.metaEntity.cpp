#include "data.metaEntity.h"

Data::MetaEntity::MetaEntity(int _id, string _name) :name(_name), id(_id)
{
}

Data::MetaEntity::MetaEntity(): id(0), name("") {}
