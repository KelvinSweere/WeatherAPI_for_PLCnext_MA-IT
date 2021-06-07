#include "WAPI_v3Library.hpp"
#include "Arp/System/Core/CommonTypeName.hxx"
#include "Arp/Plc/Commons/Meta/TypeSystem/TypeSystem.h"
#include "WAPI_v3Com.hpp"

namespace WAPI_v3
{

WAPI_v3Library::WAPI_v3Library(AppDomain& appDomain)
    : MetaLibraryBase(appDomain, ARP_VERSION_CURRENT, typeDomain)
    , typeDomain(CommonTypeName<WAPI_v3Library>().GetNamespace())
{
    this->componentFactory.AddFactoryMethod(CommonTypeName<::WAPI_v3::WAPI_v3Com>(), &::WAPI_v3::WAPI_v3Com::Create);
    this->InitializeTypeDomain();
}

void WAPI_v3Library::Main(AppDomain& appDomain)
{
    SingletonBase::CreateInstance(appDomain);
}

extern "C" ARP_CXX_SYMBOL_EXPORT ILibrary& ArpDynamicLibraryMain(AppDomain& appDomain)
{
    WAPI_v3Library::Main(appDomain);
    return  WAPI_v3Library::GetInstance();
}

} // end of namespace WAPI_v3
