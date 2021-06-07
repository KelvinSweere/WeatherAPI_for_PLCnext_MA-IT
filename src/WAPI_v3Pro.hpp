#pragma once
#include "Arp/System/Core/Arp.h"
#include "Arp/Plc/Commons/Esm/ProgramBase.hpp"
#include "Arp/System/Commons/Logging.h"
#include "WAPI_v3Com.hpp"

namespace WAPI_v3
{

using namespace Arp;
using namespace Arp::System::Commons::Diagnostics::Logging;
using namespace Arp::Plc::Commons::Esm;

//#program
//#component(WAPI_v3::WAPI_v3Com)
class WAPI_v3Pro : public ProgramBase, private Loggable<WAPI_v3Pro>
{
public: // typedefs

public: // construction/destruction
    WAPI_v3Pro(WAPI_v3::WAPI_v3Com& wAPI_v3ComArg, const String& name);
    WAPI_v3Pro(const WAPI_v3Pro& arg) = delete;
    virtual ~WAPI_v3Pro() = default;

public: // operators
    WAPI_v3Pro&  operator=(const WAPI_v3Pro& arg) = delete;

public: // properties

public: // operations
    void    Execute() override;

public: /* Ports
           =====
           Ports are defined in the following way:
           //#port
           //#attributes(Input|Retain)
           //#name(NameOfPort)
           boolean portField;

           The attributes comment define the port attributes and is optional.
           The name comment defines the name of the port and is optional. Default is the name of the field.
        */
    //#port
    //#attributes(Input)
    //#name(key)
    StaticString<80> key = "";

    //#port
    //#attributes(Input)
    //#name(city)
    StaticString<80> city = "";

	//#port
	//#attributes(Output)
	//#name(temperature)
	float32 temperature;


private: // fields
    WAPI_v3::WAPI_v3Com& wAPI_v3Com;

};

///////////////////////////////////////////////////////////////////////////////
// inline methods of class ProgramBase
inline WAPI_v3Pro::WAPI_v3Pro(WAPI_v3::WAPI_v3Com& wAPI_v3ComArg, const String& name)
: ProgramBase(name)
, wAPI_v3Com(wAPI_v3ComArg)
{
}

} // end of namespace WAPI_v3
