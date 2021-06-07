#include "WAPI_v3ComProgramProvider.hpp"
#include "WAPI_v3Pro.hpp"

namespace WAPI_v3
{

IProgram::Ptr WAPI_v3ComProgramProvider::CreateProgramInternal(const String& programName, const String& programType)
{
    if (programType == "WAPI_v3Pro")
    { 
        return std::make_shared<::WAPI_v3::WAPI_v3Pro>(this->wAPI_v3Com, programName);
    }

    // else unknown program
    return nullptr;
}

} // end of namespace WAPI_v3
