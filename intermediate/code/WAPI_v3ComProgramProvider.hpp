#pragma once
#include "Arp/System/Core/Arp.h"
#include "Arp/Plc/Commons/Esm/ProgramProviderBase.hpp"

namespace WAPI_v3
{

using namespace Arp;
using namespace Arp::Plc::Commons::Esm;

//forwards
class WAPI_v3Com;

class WAPI_v3ComProgramProvider : public ProgramProviderBase
{

public:   // construction/destruction
    WAPI_v3ComProgramProvider(WAPI_v3Com& wAPI_v3ComArg);
    virtual ~WAPI_v3ComProgramProvider() = default;

public:   // IProgramProvider operations
    IProgram::Ptr CreateProgramInternal(const String& programName, const String& programType) override;

private:   // deleted methods
    WAPI_v3ComProgramProvider(const WAPI_v3ComProgramProvider& arg) = delete;
    WAPI_v3ComProgramProvider& operator=(const WAPI_v3ComProgramProvider& arg) = delete;

private: // fields
    WAPI_v3Com& wAPI_v3Com;
};

///////////////////////////////////////////////////////////////////////////////
// inline methods of class WAPI_v3ComProgramProvider

inline WAPI_v3ComProgramProvider::WAPI_v3ComProgramProvider(WAPI_v3Com& wAPI_v3ComArg)
    : wAPI_v3Com(wAPI_v3ComArg)
{
}

} // end of namespace WAPI_v3
