#include "WAPI_v3Com.hpp"
#include "Arp/Plc/Commons/Esm/ProgramComponentBase.hpp"
#include "WAPI_v3Library.hpp"

namespace WAPI_v3
{

WAPI_v3Com::WAPI_v3Com(IApplication& application, const String& name)
: ComponentBase(application, ::WAPI_v3::WAPI_v3Library::GetInstance(), name, ComponentCategory::Custom)
, programProvider(*this)
, ProgramComponentBase(::WAPI_v3::WAPI_v3Library::GetInstance().GetNamespace(), programProvider)
{
}

void WAPI_v3Com::Initialize()
{
    // never remove next line
    ProgramComponentBase::Initialize();

    // subscribe events from the event system (Nm) here
}

void WAPI_v3Com::LoadConfig()
{
    // load project config here
}

void WAPI_v3Com::SetupConfig()
{
    // never remove next line
    ProgramComponentBase::SetupConfig();

    // setup project config here
}

void WAPI_v3Com::ResetConfig()
{
    // never remove next line
    ProgramComponentBase::ResetConfig();

    // implement this inverse to SetupConfig() and LoadConfig()
}

} // end of namespace WAPI_v3
