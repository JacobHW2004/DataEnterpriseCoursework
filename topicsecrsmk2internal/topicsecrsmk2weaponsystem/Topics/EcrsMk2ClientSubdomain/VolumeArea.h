#ifndef VOLUME_AREA
#define VOLUME_AREA

#include "CommonWeaponSystemValues.h"
#include "SIDegree.h"
#include "NSINauticalMile.h"

namespace Topics
{
    namespace EcrsMK2
    {
        namespace WeaponSystem
        {
            namespace Common
            {
                class VolumeArea
                {
                public:
                    VolumeArea(/* args */) : 
                    CenterLine{0},
                    AzHalfwidth{0},
                    PlanMin{0},
                    PlanMax{0}
                    {}
                
                    const SI::SIDegree getAzCenterLine() const noexcept
                    {
                        return CenterLine;
                    }

                    const SI::SIDegree getAzHalfwidth() const noexcept
                    {
                        return AzHalfwidth;
                    }

                    const NSI::NSINauticalMile getPlanMin() const noexcept
                    {
                        return PlanMin;
                    }


                    const NSI::NSINauticalMile getPlanMax() const noexcept
                    {
                        return PlanMax;
                    }

                    void setAzCenterLine(const SI::SIDegree& arg) noexcept
                    {
                        CenterLine = arg;
                    }

                    void setAzHalfwidth(const SI::SIDegree& arg) noexcept
                    {
                        AzHalfwidth = arg;
                    }

                    void setPlanMin(const NSI::NSINauticalMile& arg) noexcept
                    {
                        PlanMin = arg;
                    }


                    void setPlanMax(const NSI::NSINauticalMile& arg) noexcept
                    {
                        PlanMax = arg;
                    }

                    void setToIcdDefault() noexcept
                    {
                        CenterLine = IcdDefaults::CENTER_LINE_DEFAULT;
                        AzHalfwidth = IcdDefaults::AZ_HALF_DEFAULT;
                        PlanMin = IcdDefaults::PLAN_MIN_DEFAULT;
                        PlanMax = IcdDefaults::PLAN_MAX_DEFAULT;
                    }

                    bool operator==(const VolumeArea& other) const
                    {
                        return this->CenterLine == other.CenterLine &&
                        this->AzHalfwidth == other.AzHalfwidth &&
                        this->PlanMin == other.PlanMin &&
                        this->PlanMax == other.PlanMax;
                    }
                
                protected:
                    
                    SI::SIDegree CenterLine {IcdDefaults::CENTER_LINE_DEFAULT};

                    SI::SIDegree AzHalfwidth {IcdDefaults::AZ_HALF_DEFAULT};

                    NSI::NSINauticalMile PlanMin {IcdDefaults::PLAN_MIN_DEFAULT};

                    NSI::NSINauticalMile PlanMax {IcdDefaults::PLAN_MAX_DEFAULT};

                    
                };    
            } // namespace Common
        } // namespace WeaponSystem
    } // namespace EcrsMK2
} // namespace Topics

#endif
