#pragma once
#include "Arp/System/Core/Arp.h"
#include "Arp/System/Core/AppDomain.hpp"
#include "Arp/System/Core/Singleton.hxx"
#include "Arp/System/Core/Library.h"
#include "Arp/Plc/Commons/Meta/MetaLibraryBase.hpp"
#include "Arp/Plc/Commons/Meta/TypeSystem/TypeDomain.hpp"

namespace WAPI_v3
{

using namespace Arp::System::Acf;
using namespace Arp::Plc::Commons::Meta;
using namespace Arp::Plc::Commons::Meta::TypeSystem;

class WAPI_v3Library : public MetaLibraryBase, public Singleton<WAPI_v3Library>
{
public: // typedefs
    typedef Singleton<WAPI_v3Library> SingletonBase;

public: // construction/destruction
    WAPI_v3Library(AppDomain& appDomain);
    virtual ~WAPI_v3Library() = default;

public: // static operations (called through reflection)
    static void Main(AppDomain& appDomain);

private: // methods
    void InitializeTypeDomain();

private: // deleted methods
    WAPI_v3Library(const WAPI_v3Library& arg) = delete;
    WAPI_v3Library& operator= (const WAPI_v3Library& arg) = delete;

private:  // fields
    TypeDomain typeDomain;
};

extern "C" ARP_CXX_SYMBOL_EXPORT ILibrary& ArpDynamicLibraryMain(AppDomain& appDomain);

///////////////////////////////////////////////////////////////////////////////
// inline methods of class WAPI_v3Library

} // end of namespace WAPI_v3
