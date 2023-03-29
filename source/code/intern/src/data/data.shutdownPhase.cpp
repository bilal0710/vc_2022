#include "data.shutdownPhase.h"

#include <iostream>

#include "data.metaEntitySystem.h"

namespace Data
{
    void CShutdownPhase::OnEnter()
    {}

    void CShutdownPhase::OnRun()
    {
        std::cout << "DATA::SHUTDOWN::Run::Clearing MetaEntity System" << std::endl;

       // MetaEntitySystem::GetInstance().DestoryAllMetaEntities();
    }

    void CShutdownPhase::OnLeave()
    {}
}