#include "Arp/System/Core/Arp.h"
#include "Arp/Plc/Commons/Meta/TypeSystem/TypeSystem.h"
#include "WAPI_v3Pro.hpp"
#include "WAPI_v3Library.hpp"

namespace WAPI_v3
{

using namespace Arp::Plc::Commons::Meta;

    void WAPI_v3Library::InitializeTypeDomain()
    {
        this->typeDomain.AddTypeDefinitions
        (
            // Begin TypeDefinitions
            {
                {   // ProgramDefinition: WAPI_v3::WAPI_v3Pro
                    DataType::Program, CTN<WAPI_v3::WAPI_v3Pro>(), sizeof(::WAPI_v3::WAPI_v3Pro), alignof(::WAPI_v3::WAPI_v3Pro), StandardAttribute::None,
                    {
                        // FieldDefinitions:
                        { "key", offsetof(::WAPI_v3::WAPI_v3Pro, key), DataType::StaticString, String::Empty, sizeof(StaticString<80>), alignof(StaticString<80>), {  }, StandardAttribute::Input },
                        { "city", offsetof(::WAPI_v3::WAPI_v3Pro, city), DataType::StaticString, String::Empty, sizeof(StaticString<80>), alignof(StaticString<80>), {  }, StandardAttribute::Input },
                        { "temperature", offsetof(::WAPI_v3::WAPI_v3Pro, temperature), DataType::Float32, String::Empty, sizeof(float32), alignof(float32), {  }, StandardAttribute::Output },
                        { "errorBit", offsetof(::WAPI_v3::WAPI_v3Pro, errorBit), DataType::Boolean, String::Empty, sizeof(boolean), alignof(boolean), {  }, StandardAttribute::Output },
                    }
                },
            }
            // End TypeDefinitions
        );
    }

} // end of namespace WAPI_v3

