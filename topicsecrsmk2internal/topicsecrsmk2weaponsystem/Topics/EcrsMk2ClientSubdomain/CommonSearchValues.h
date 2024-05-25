#ifndef COMMON_SEARCH_VALUES
#define COMMON_SEARCH_VALUES

#include <stdint.h>

namespace Topics
{
    namespace EcrsMK2
    {
        namespace WeaponSystem
        {
            namespace Search
            {
                /**
                 * @brief enumeration for PAT T
                 */
                enum class PAT_T_ENUM : uint8_t
                {
                    AUTO = 0x00,
                    INVALID = 0x00,
                    PATT1 = 0x01,
                    PATT2 = 0x02,
                    PATT3 = 0x03,
                    PATT4 = 0x04,
                    PATT5 = 0x05,
                    PATT6 = 0x06,
                    PATT7 = 0x07
                };

                /**
                 * @brief enumeration for PAT D
                 */
                enum class PAT_D_ENUM : uint8_t
                {
                    AUTO = 0x00,
                    INVALID = 0x00,
                    PATD1 = 0x01,
                    PATD2 = 0x02,
                    PATD3 = 0x03,
                };

                /**
                 * @brief enumeration for PAT I
                 */
                enum class PAT_I_ENUM : uint8_t
                {
                    AUTO = 0x00,
                    INVALID = 0x00,
                    PATI1 = 0x01,
                    PATI2 = 0x02,
                    PATI3 = 0x03,
                    PATI4 = 0x04,
                    PATI5 = 0x05,
                    PATI6 = 0x06,
                    PATI7 = 0x07
                };

            } // namespace Search
        } // namespace WeaponSystem
    } // namespace EcrsMK2
} // namespace Topics


#endif
