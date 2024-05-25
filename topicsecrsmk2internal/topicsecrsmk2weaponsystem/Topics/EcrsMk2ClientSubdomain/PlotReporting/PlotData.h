#ifndef PLOT_DATA
#define PLOT_DATA

#include "SIDecibelsPerSquareMeter.h"
#include "SIDecibel.h"
#include "SIDegree.h"

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
    namespace PlotReporting
    {
        
        /**
         * @brief enumeration for the plot type
         */
        enum class PLOT_TYPE_ENUM : uint8_t
        {
            NORMAL_PLOT_DATA = 0x00,
            VECTORED_PLOT_DATA = 0x01
        };

        /**
         * @brief enumeration for the plot correlation state
         */
        enum class PLOT_CORRELATION_STATE_ENUM : uint8_t
        {
            UNCORRELATED = 0x00,
            CORRELATED = 0x01
        };

        /**
         * @brief enumeration for the plot realm
         */
        enum class PLOT_TGT_REALM_ENUM : uint8_t
        {
            INVALID = 0x00,
            AIR = 0x01,
            SURFACE_INDETERMINATE = 0x02,
            SURFACE_LAND = 0x03,
            SURFACE_SEA = 0x04
        };

        /**
         * @brief enumeration for the plot data age
         */
        enum class PLOT_TGT_DATA_AGE_ENUM : uint8_t
        {
            X02 = 0x00,
            X04 = 0x01,
            X06 = 0x02,
            X08 = 0x03,
            X10 = 0x04
        };

        /**
         * @brief enumeration for the plot jammer code
         */
        enum class PLOT_TGT_CODE_JAM_ENUM : uint8_t
        {
            NOT_JAMMER = 0x00,
            JAMMER = 0x01
        };

        /**
         * @brief enumeration for the plot chaff code
         */
        enum class PLOT_TGT_CODE_CHAFF_ENUM : uint8_t
        {
            NOT_CHAFF = 0x00,
            CHAFF = 0x01
        };

        /**
         * @brief enumeration for the validity fields. These validity fields are specified in the ICD and are suffexed with VAL 
         */
        enum class VALIDITY : uint8_t
        {
            INVALID = 0x00,
            VALID = 0x01
        };

        /**
         * @brief enumeration for the plot jammer id code type 1
         */
        enum class PLOT_JAMMER_ID_CODE_TYPE_1_ENUM : uint8_t
        {
            JID_Type1 = 0x00,
            JID_Type2 = 0x01
        };

        /**
         * @brief enumeration for the plot jammer id code type 2
         */
        enum class PLOT_JAMMER_ID_CODE_TYPE_2_ENUM : uint8_t
        {
            JID_Type3 = 0x00,
            JID_Type4 = 0x01
        };

        /**
         * @brief enumeration for the plot jammer id code type 3
         */
        enum class PLOT_JAMMER_ID_CODE_TYPE_3_ENUM : uint8_t
        {
            JID_Type5 = 0x00,
            JID_Type6 = 0x01
        };

        /**
         * @brief class encapsulating the plot data
         */
        class PlotData
        {
            public:
                /**
                 * @brief default constructor, sets all values to ICD defaults
                 */
                PlotData() : PlotData (PLOT_CORRELATION_STATE_ENUM::UNCORRELATED, 0, PLOT_TGT_DATA_AGE_ENUM::X02, SI::SIDegree(0.0), SI::SIDegree(0.0), 0.0, 0, VALIDITY::INVALID, VALIDITY::INVALID, VALIDITY::INVALID, VALIDITY::INVALID)
                {}
                /**
                 * @brief constructor allows definition of the correlation state, plot Id and plot possitional information, associated validity flags will be set to valid
                 * all values should be given in frame 1p
                 */
                PlotData(PLOT_CORRELATION_STATE_ENUM correlationState,
                         int16_t plotIdent,
                         PLOT_TGT_DATA_AGE_ENUM plotAge,
                         SI::SIDegree azimuth,
                         SI::SIDegree elevation,
                         float range,
                         int16_t rangeRate) : PlotData (correlationState, plotIdent, plotAge, azimuth, elevation, range, rangeRate, VALIDITY::VALID, VALIDITY::VALID, VALIDITY::VALID, VALIDITY::VALID)
                        {}
                
                /**
                 * @brief getter for the plot type
                 * @returns the plot data detection type
                 */
                const PLOT_TYPE_ENUM getPlotType() const
                {
                    return PLOT_TYPE;
                }

                /**
                 * @brief getter for the plot correlation state
                 * @returns the plot correlation state
                 */
                const PLOT_CORRELATION_STATE_ENUM getCorrelationState() const
                {
                    return PLOT_CORRELATION_STATE;
                }

                /**
                 * @brief getter for the plot realm
                 * @returns the plot realm
                 */
                const PLOT_TGT_REALM_ENUM getTargetRealm() const
                {
                    return PLOT_TGT_REALM;
                }

                /**
                 * @brief getter for the plot data age
                 * @returns the plot data age
                 */
                const PLOT_TGT_DATA_AGE_ENUM getTargetAge() const
                {
                    return PLOT_TGT_DATA_AGE;
                }

                /**
                 * @brief getter for the plot jammer code
                 * @returns the plot jammer code
                 */
                const PLOT_TGT_CODE_JAM_ENUM getJammerCode() const
                {
                    return PLOT_TGT_CODE_JAM;
                }

                /**
                 * @brief getter for the plot data chaff code
                 * @returns the plot chaff code
                 */
                const PLOT_TGT_CODE_CHAFF_ENUM getChaffCode() const
                {
                    return PLOT_TGT_CODE_CHAFF;
                }

                /**
                 * @brief getter for the plot target size validity
                 * @returns the plot target size validity
                 */
                const VALIDITY getTargetSizeValidity() const
                {
                    return PLOT_TGT_SIZE_VAL;
                }

                /**
                 * @brief getter for the plot signal to noise validity
                 * @returns the plot signal to noise validity
                 */
                const VALIDITY getSnrValidity() const
                {
                    return PLOT_TGT_SIGNAL_TO_NOISE_VAL;
                }

                /**
                 * @brief getter for the plot azimuth validity
                 * @returns the plot azimuth validity
                 */
                const VALIDITY getAzimuthValidity() const
                {
                    return PLOT_TGT_AZIMUTH_VAL;
                }

                /**
                 * @brief getter for the plot elevation validity
                 * @returns the plot elevation validity
                 */
                const VALIDITY getElevationValidity() const
                {
                    return PLOT_TGT_ELEVATION_VAL;
                }

                /**
                 * @brief getter for the plot range validity
                 * @returns the plot range validity
                 */
                const VALIDITY getRangeValidity() const
                {
                    return PLOT_TGT_RNG_VAL;
                }

                /**
                 * @brief getter for the plot range rate validity
                 * @returns the plot range rate validity
                 */
                const VALIDITY getRangeRateValidity() const
                {
                    return PLOT_TGT_RDOT_VAL;
                }

                /**
                 * @brief getter for the plot Id
                 * @returns the plot Id
                 */
                const int16_t getPlotId() const
                {
                    return PLOT_IDENTIFIER;
                }

                /**
                 * @brief getter for the plot jammer id code type 1
                 * @returns the plot jammer id code type 1
                 */
                const PLOT_JAMMER_ID_CODE_TYPE_1_ENUM getJammerIdCodeType1() const
                {
                    return PLOT_JAMMER_ID_CODE_TYPE_1;
                }

                /**
                 * @brief getter for the plot jammer id code type 2
                 * @returns the plot jammer id code type 2
                 */
                const PLOT_JAMMER_ID_CODE_TYPE_2_ENUM getJammerIdCodeType2() const
                {
                    return PLOT_JAMMER_ID_CODE_TYPE_2;
                }
                
                /**
                 * @brief getter for the plot jammer id code type 3
                 * @returns the plot jammer id code type 3
                 */
                const PLOT_JAMMER_ID_CODE_TYPE_3_ENUM getJammerIdCodeType3() const
                {
                    return PLOT_JAMMER_ID_CODE_TYPE_3;
                }

                /**
                 * @brief getter for the plot target size
                 * @returns the plot target size
                 */
                const SI::SIDecibelsPerSquareMeter getTargetSize() const
                {
                    return PLOT_TGT_SIZE;
                }

                /**
                 * @brief getter for the plot signal to noise ratio
                 * @returns the plot signal to noise ratio
                 */
                const SI::SIDecibel getSnr() const
                {
                    return PLOT_TGT_SIGNAL_TO_NOISE;
                }

                /**
                 * @brief getter for the plot NCI type
                 * @returns the plot NCI type
                 */
                const uint8_t getNciType() const
                {
                    return PLOT_TGT_NCI_TYPE;
                }

                /**
                 * @brief getter for the plot NCI confidence
                 * @returns the plot NCI confidence 
                 */
                const float getNciConfidence() const
                {
                    return PLOT_TGT_NCI_CONFIDENCE;
                }

                /**
                 * @brief getter for the plot azimuth
                 * @returns the plot azimuth
                 */
                const SI::SIDegree getAzimuth() const
                {
                    return PLOT_TGT_AZIMUTH;
                }

                /**
                 * @brief getter for the plot elevation
                 * @returns the plot elevation
                 */
                const SI::SIDegree getElevation() const
                {
                    return PLOT_TGT_ELEVATION;
                }

                /**
                 * @brief getter for the plot range
                 * @returns the plot range
                 */
                const float getRange()
                {
                    return PLOT_TGT_RNG;
                }

                /**
                 * @brief getter for the plot range rate
                 * @returns the plot range rate
                 */
                const int16_t getRangeRate() const
                {
                    return PLOT_TGT_RDOT;
                }

                /**
                 * @brief equality operator
                 * @returns true if other has the same plot data detection type, false otherwise
                 */
                bool operator==(const PlotData& other) const
                {
                    return this->PLOT_TYPE == other.PLOT_TYPE &&
                        this->PLOT_CORRELATION_STATE == other.PLOT_CORRELATION_STATE &&
                        this->PLOT_TGT_REALM == other.PLOT_TGT_REALM &&
                        this->PLOT_TGT_DATA_AGE == other.PLOT_TGT_DATA_AGE &&
                        this->PLOT_TGT_CODE_JAM == other.PLOT_TGT_CODE_JAM &&
                        this->PLOT_TGT_CODE_CHAFF == other.PLOT_TGT_CODE_CHAFF &&
                        this->PLOT_TGT_SIZE_VAL == other.PLOT_TGT_SIZE_VAL &&
                        this->PLOT_TGT_SIGNAL_TO_NOISE_VAL == other.PLOT_TGT_SIGNAL_TO_NOISE_VAL &&
                        this->PLOT_TGT_AZIMUTH_VAL == other.PLOT_TGT_AZIMUTH_VAL &&
                        this->PLOT_TGT_ELEVATION_VAL == other.PLOT_TGT_ELEVATION_VAL &&
                        this->PLOT_TGT_RNG_VAL == other.PLOT_TGT_RNG_VAL &&
                        this->PLOT_TGT_RDOT_VAL == other.PLOT_TGT_RDOT_VAL &&
                        this->PLOT_IDENTIFIER == other.PLOT_IDENTIFIER &&
                        this->PLOT_JAMMER_ID_CODE_TYPE_1 == other.PLOT_JAMMER_ID_CODE_TYPE_1 &&
                        this->PLOT_JAMMER_ID_CODE_TYPE_2 == other.PLOT_JAMMER_ID_CODE_TYPE_2 &&
                        this->PLOT_JAMMER_ID_CODE_TYPE_3 == other.PLOT_JAMMER_ID_CODE_TYPE_3 &&
                        this->PLOT_TGT_SIZE == other.PLOT_TGT_SIZE &&
                        this->PLOT_TGT_SIGNAL_TO_NOISE() == other.PLOT_TGT_SIGNAL_TO_NOISE() &&
                        this->PLOT_TGT_NCI_TYPE == other.PLOT_TGT_NCI_TYPE &&
                        this->PLOT_TGT_NCI_CONFIDENCE == other.PLOT_TGT_NCI_CONFIDENCE &&
                        this->PLOT_TGT_AZIMUTH == other.PLOT_TGT_AZIMUTH &&
                        this->PLOT_TGT_ELEVATION == other.PLOT_TGT_ELEVATION &&
                        this->PLOT_TGT_RNG == other.PLOT_TGT_RNG &&
                        this->PLOT_TGT_RDOT == other.PLOT_TGT_RDOT;
                }

                /**
                 * @brief inequality operator
                 * @returns the negative of the equality operator
                 */
                bool operator!=(const PlotData& other) const
                {
                    return !operator==(other);
                }

                /**
                * @brief Serialise function required for communications
                */
                template <class T>
                void Serialise(T& archive) 
                {
                    double targetSizeDouble { PLOT_TGT_SIZE() };
                    double targetSnrDouble { PLOT_TGT_SIGNAL_TO_NOISE() };
                    double targetAzimuthDouble { PLOT_TGT_AZIMUTH() };
                    double targetElevationDouble { PLOT_TGT_ELEVATION() };

                    archive.Serialise(PLOT_TYPE, "PLOT_TYPE");
                    archive.Serialise(PLOT_CORRELATION_STATE, "PLOT_CORRELATION_STATE");
                    archive.Serialise(PLOT_TGT_REALM, "PLOT_TGT_REALM");
                    archive.Serialise(PLOT_TGT_DATA_AGE, "PLOT_TGT_DATA_AGE");
                    archive.Serialise(PLOT_TGT_CODE_JAM, "PLOT_TGT_CODE_JAM");
                    archive.Serialise(PLOT_TGT_CODE_CHAFF, "PLOT_TGT_CODE_CHAFF");
                    archive.Serialise(PLOT_TGT_SIZE_VAL, "PLOT_TGT_SIZE_VAL");
                    archive.Serialise(PLOT_TGT_SIGNAL_TO_NOISE_VAL, "PLOT_TGT_SIGNAL_TO_NOISE_VAL");
                    archive.Serialise(PLOT_TGT_AZIMUTH_VAL, "PLOT_TGT_AZIMUTH_VAL");
                    archive.Serialise(PLOT_TGT_ELEVATION_VAL, "PLOT_TGT_ELEVATION_VAL");
                    archive.Serialise(PLOT_TGT_RNG_VAL, "PLOT_TGT_RNG_VAL");
                    archive.Serialise(PLOT_TGT_RDOT_VAL, "PLOT_TGT_RDOT_VAL");
                    archive.Serialise(PLOT_IDENTIFIER, "PLOT_IDENTIFIER");
                    archive.Serialise(PLOT_JAMMER_ID_CODE_TYPE_1, "PLOT_JAMMER_ID_CODE_TYPE_1");
                    archive.Serialise(PLOT_JAMMER_ID_CODE_TYPE_2, "PLOT_JAMMER_ID_CODE_TYPE_2");
                    archive.Serialise(PLOT_JAMMER_ID_CODE_TYPE_3, "PLOT_JAMMER_ID_CODE_TYPE_3");
                    archive.Serialise(targetSizeDouble, "PLOT_TGT_SIZE");
                    archive.Serialise(targetSnrDouble, "PLOT_TGT_SIGNAL_TO_NOISE");
                    archive.Serialise(PLOT_TGT_NCI_TYPE, "PLOT_TGT_NCI_TYPE");
                    archive.Serialise(PLOT_TGT_NCI_CONFIDENCE, "PLOT_TGT_NCI_CONFIDENCE");
                    archive.Serialise(targetAzimuthDouble, "PLOT_TGT_AZIMUTH");
                    archive.Serialise(targetElevationDouble, "PLOT_TGT_ELEVATION");
                    archive.Serialise(PLOT_TGT_RNG, "PLOT_TGT_RNG");
                    archive.Serialise(PLOT_TGT_RDOT, "PLOT_TGT_RDOT");

                    PLOT_TGT_SIZE = targetSizeDouble; 
                    PLOT_TGT_SIGNAL_TO_NOISE = targetSnrDouble; 
                    PLOT_TGT_AZIMUTH = targetAzimuthDouble; 
                    PLOT_TGT_ELEVATION = targetElevationDouble; 
                }

                LCA_TOPIC("PlotData", 1, 0);

            private:
                PlotData(PLOT_CORRELATION_STATE_ENUM correlationState,
                         int16_t plotIdent,
                         PLOT_TGT_DATA_AGE_ENUM plotAge,
                         SI::SIDegree azimuth,
                         SI::SIDegree elevation,
                         float range,
                         int16_t rangeRate,
                         VALIDITY azValidity,
                         VALIDITY elValidity,
                         VALIDITY rangeValidity,
                         VALIDITY rangeRateValidity) :
                        PLOT_TYPE { PLOT_TYPE_ENUM::NORMAL_PLOT_DATA },
                        PLOT_CORRELATION_STATE { correlationState },
                        PLOT_IDENTIFIER { plotIdent },
                        PLOT_TGT_AZIMUTH_VAL { azValidity },
                        PLOT_TGT_ELEVATION_VAL { elValidity },
                        PLOT_TGT_RNG_VAL { rangeValidity },
                        PLOT_TGT_RDOT_VAL { rangeRateValidity },
                        PLOT_TGT_AZIMUTH { azimuth },
                        PLOT_TGT_ELEVATION { elevation },
                        PLOT_TGT_RNG { range },
                        PLOT_TGT_RDOT { rangeRate },
                        PLOT_TGT_REALM { PLOT_TGT_REALM_ENUM::INVALID },
                        PLOT_TGT_DATA_AGE { plotAge },
                        PLOT_TGT_CODE_JAM { PLOT_TGT_CODE_JAM_ENUM::NOT_JAMMER },
                        PLOT_TGT_CODE_CHAFF { PLOT_TGT_CODE_CHAFF_ENUM::NOT_CHAFF },
                        PLOT_TGT_SIZE_VAL { VALIDITY::INVALID },
                        PLOT_TGT_SIGNAL_TO_NOISE_VAL { VALIDITY::INVALID },
                        PLOT_JAMMER_ID_CODE_TYPE_1 { PLOT_JAMMER_ID_CODE_TYPE_1_ENUM::JID_Type1 },
                        PLOT_JAMMER_ID_CODE_TYPE_2 { PLOT_JAMMER_ID_CODE_TYPE_2_ENUM::JID_Type3 },
                        PLOT_JAMMER_ID_CODE_TYPE_3 { PLOT_JAMMER_ID_CODE_TYPE_3_ENUM::JID_Type5 },
                        PLOT_TGT_SIZE { 0.0 },
                        PLOT_TGT_SIGNAL_TO_NOISE { 0.0 },
                        PLOT_TGT_NCI_TYPE { 0 },
                        PLOT_TGT_NCI_CONFIDENCE { 0 }
                    {}
                        

                /**
                * @brief represents the plot as being either a normal or vectored plot
                */
                PLOT_TYPE_ENUM PLOT_TYPE;
                /**
                * @brief represents the plot as being uncorrelated or correlated with any existing Track(s)
                */
                PLOT_CORRELATION_STATE_ENUM PLOT_CORRELATION_STATE;
                /**
                * @brief represents the realm in which the plot data was gathered
                */
                PLOT_TGT_REALM_ENUM PLOT_TGT_REALM;
                /**
                * @brief represents one of 5 possible plot ages, when  RDRC-F-PLOT-DATA-AGE-DMD is set to AUTOMATIC X = 2.5 where the plot age is x * the achieved frame time
                */
                PLOT_TGT_DATA_AGE_ENUM PLOT_TGT_DATA_AGE;
                /**
                * @brief represents if the target is a jammer and validates the following fields : 
                *       * PLOT_JAMMER_ID_CODE_TYPE_1
                *       * PLOT_JAMMER_ID_CODE_TYPE_2
                *       * PLOT_JAMMER_ID_CODE_TYPE_3
                */
                PLOT_TGT_CODE_JAM_ENUM PLOT_TGT_CODE_JAM;
                /**
                * @brief represents weather the target is chaff or not
                */
                PLOT_TGT_CODE_CHAFF_ENUM PLOT_TGT_CODE_CHAFF;
                /**
                * @brief provides validity for the target size field
                */
                VALIDITY PLOT_TGT_SIZE_VAL;
                /**
                * @brief provides validity for the signal to noise field
                */
                VALIDITY PLOT_TGT_SIGNAL_TO_NOISE_VAL;
                /**
                * @brief provides validity for the azimuth field
                */
                VALIDITY PLOT_TGT_AZIMUTH_VAL;
                /**
                * @brief provides validity for the elevation field
                */
                VALIDITY PLOT_TGT_ELEVATION_VAL;
                /**
                * @brief provides validity for the range field
                */
                VALIDITY PLOT_TGT_RNG_VAL;
                /**
                * @brief provides validity for the range rate field
                */
                VALIDITY PLOT_TGT_RDOT_VAL;
                /**
                * @brief unique Id of the plot
                */
                int16_t PLOT_IDENTIFIER;
                /**
                * @brief See ICD-J-947-B-2596-PART-4
                */
                PLOT_JAMMER_ID_CODE_TYPE_1_ENUM PLOT_JAMMER_ID_CODE_TYPE_1;
                /**
                * @brief See ICD-J-947-B-2596-PART-4
                */
                PLOT_JAMMER_ID_CODE_TYPE_2_ENUM PLOT_JAMMER_ID_CODE_TYPE_2;
                /**
                * @brief See ICD-J-947-B-2596-PART-4
                */
                PLOT_JAMMER_ID_CODE_TYPE_3_ENUM PLOT_JAMMER_ID_CODE_TYPE_3;
                /**
                * @brief represents the estimated size of the target, should be ignored if PLOT-TGT-SIZE-VAL is invalid
                */
                SI::SIDecibelsPerSquareMeter PLOT_TGT_SIZE;
                /**
                * @brief represents the estimated signal to noise for the search target, should be ignored if PLOT-TGT-SIZE-VAL is invalid
                */
                SI::SIDecibel PLOT_TGT_SIGNAL_TO_NOISE;
                /**
                * @brief See ICD-J-947-B-2596-PART-4, Sections 6.1.2.1.2.1 and 6.5.1.4.3.1.
                */
                uint8_t PLOT_TGT_NCI_TYPE;
                /**
                * @brief See ICD-J-947-B-2596-PART-4, Sections 6.1.2.1.2.1 and 6.5.1.4.3.1.
                */
                float PLOT_TGT_NCI_CONFIDENCE;
                /**
                * @brief represents the azimuth of the target, should be ignored if PLOT-TGT-AZIMUTH-VAL is invalid
                */
                SI::SIDegree PLOT_TGT_AZIMUTH;
                /**
                * @brief represents the elevation of the target, should be ignored if PLOT-TGT-ELEVATION-VAL is invalid
                */
                SI::SIDegree PLOT_TGT_ELEVATION;
                /**
                * @brief represents the range of the target in nautical miles, should be ignored if PLOT-TGT-RNG-VAL is invalid
                */
                float PLOT_TGT_RNG;
                /**
                * @brief represents the range rate of the target in knots, should be ignored if PLOT-TGT-RDOT-VAL is invalid
                */
                int16_t PLOT_TGT_RDOT;

        };
    } // namespace PlotReporting
} // namespace Topics


#endif 