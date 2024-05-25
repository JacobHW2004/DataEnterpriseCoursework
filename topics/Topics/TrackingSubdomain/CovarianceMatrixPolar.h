#ifndef COVARIANCE_MATRIX_POLAR_H
#define COVARIANCE_MATRIX_POLAR_H
#include "Fabric/Utils/LCA_Macros.h"
#include "FrameOfReference.h"
#include "MatrixInFrame.h"

namespace { 
	static constexpr std::uint32_t polarMatrixSize = 81; 
          }

namespace Topics {
	class CovarianceMatrixPolar{
		/* This class provides an interface to access elements of the gold tracker 9x9 covariance matrix in polar format. 
		   The units used for the Polar elements are:
				- Range: Metres
				- Azimuth: Radians 
				- Elevation: Radians 
				- Range Rate: Metres per second
				- Azimuth Rate: Radians per second
				- Elevation Rate: Radians per second
				- Range Acceleration: Metres per second squared
				- Azimuth Acceleration: Metres per second squared
				- Elevation Acceleration: Metres per second squared

			These units are combined when calculating the values of the variances and covariances. 			
			The structure of the polar covariance matrix, within the gold tracker, is shown below (the table has only been partially filled for readability, in reality each table entry has a corresponding getter):			
			
			Note: Accleration has been abbreviated to Acc for the purposes of clarity in this table.
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------                       
				| 			-			    | Range      |   Range Rate           |   Azimuth     |   Elevation      |  Azimuth Rate     |   Elevation Rate  |   Azimuth Acc   |   Elevation Acc  |   Range Acc   |   
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           | Range      |   Range-RangeRate      |               |                  |                   |                   |                 |                  |               |     
				|   Range                   | Variance   |   Covariance           |               |                  |                   |                   |                 |                  |               |
				|                           |            |                        |               |                  |                   |                   |                 |                  |               |
                ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           | RangeRate  |   Range Rate           |               |                  |                   | Range Rate        |                 |                  |               |
				|   Range Rate              | Range      |   Variance             |               |                  |                   | Elevation Rate    |                 |                  |               |
				|                           | Covariance |                        |               |                  |                   | Covariance        |                 |                  |               | 
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           |            |                        | Azimuth       |                  |                   |                   |                 |                  |               |    
				|  Azimuth                  |            |                        | Variance      |                  |                   |                   |                 |                  |               |
				|                           |            |                        |               |                  |                   |                   |                 |                  |               |    
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           |            |                        |               | Elevation        |                   |                   |                 |                  |               |
				|  Elevation                |            |                        |               | Variance         |                   |                   |                 |                  |               |
				|                           |            |                        |               |                  |                   |                   |                 |                  |               |
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           |            |                        |               |                  | Azimuth Rate      |                   |                 |                  | Azimuth Rate  |
				|  Azimuth Rate             |            |                        |               |                  | Variance          |                   |                 |                  | Range Acc     |
				|                           |            |                        |               |                  |                   |                   |                 |                  | Covariance    |
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           |            |                        |               |                  |                   | Elevation Rate    |                 |                  |               |  
				|  Elevation Rate           |            |                        |               |                  |                   | Variance          |                 |                  |               | 
				|                           |            |                        |               |                  |                   |                   |                 |                  |               |    
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           |            |  Azimuth Acc           |               |                  |                   |                   | Azimuth Acc     |                  |               |  
				|  Azimuth Acc              |            |  Range Rate            |               |                  |                   |                   | Variance        |                  |               |
				|                           |            |  Covariance            |               |                  |                   |                   |                 |                  |               |
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           |            |                        |               |                  |                   |                   |                 | Elevation Acc    |               |
				|  Elevation Acc            |            |                        |               |                  |                   |                   |                 | Variance         |               |
				|                           |            |                        |               |                  |                   |                   |                 |                  |               |
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           |            |                        |               |                  |                   |                   |                 |                  | Range Acc     |
				|  Range Acc                |            |                        |               |                  |                   |                   |                 |                  | Variance      |
				|                           |            |                        |               |                  |                   |                   |                 |                  |               |
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		Each getter below corresponds to a certain position in the matrix above and will access the variance or covariance value at that location. 
		The naming convention calls the getter get<ColumnName><RowName>Variance for diagonal elements and get<ColumnName><RowName>Covariance for off diagonal elements. 
		*/
		public:
			MatrixInFrame matrixInFrame;

			CovarianceMatrixPolar() = default;

			CovarianceMatrixPolar(MatrixInFrame outputMatrix):
				matrixInFrame(outputMatrix)
			{
				assert(matrixInFrame.matrix.data.size() == polarMatrixSize);
			}

			double getRangeVariance() {
				return matrixInFrame.matrix.data[0];
			}
			double getAzimuthVariance() {
				return matrixInFrame.matrix.data[20];
			}
			double getElevationVariance() {
				return matrixInFrame.matrix.data[30];
			}
			double getRangeAzimuthCovariance() {
				return matrixInFrame.matrix.data[2];
			}
			double getAzimuthRangeCovariance() {
				return matrixInFrame.matrix.data[18];
			}
			double getRangeElevationCovariance() {				
				return matrixInFrame.matrix.data[3];
			}
			double getElevationRangeCovariance() {				
				return matrixInFrame.matrix.data[27];
			}
			double getAzimuthElevationCovariance() {				
				return matrixInFrame.matrix.data[21];
			}
			double getElevationAzimuthCovariance() {				
				return matrixInFrame.matrix.data[29];
			}
			double getRangeRateVariance() {				
				return matrixInFrame.matrix.data[10];
			}
			double getAzimuthRateVariance() {				
				return matrixInFrame.matrix.data[40];
			}
			double getElevationRateVariance() {			
				return matrixInFrame.matrix.data[50];
			}
			double getRangeRangeRateCovariance() {				
				return matrixInFrame.matrix.data[1];
			}
			double getRangeRateRangeCovariance() {				
				return matrixInFrame.matrix.data[9];
			}
			double getRangeAzimuthRateCovariance() {				
				return matrixInFrame.matrix.data[4];
			}
			double getAzimuthRateRangeCovariance() {				
				return matrixInFrame.matrix.data[36];
			}
			double getRangeElevationRateCovariance() {				
				return matrixInFrame.matrix.data[5];
			}
			double getElevationRateRangeCovariance() {				
				return matrixInFrame.matrix.data[45];
			}
			double getAzimuthRangeRateCovariance() {				
				return matrixInFrame.matrix.data[19];
			}
			double getRangeRateAzimuthCovariance() {				
				return matrixInFrame.matrix.data[11];
			}
			double getAzimuthAzimuthRateCovariance() {				
				return matrixInFrame.matrix.data[22];
			}
			double getAzimuthRateAzimuthCovariance() {
				return matrixInFrame.matrix.data[38];
			}
			double getAzimuthElevationRateCovariance() {				
				return matrixInFrame.matrix.data[23];
			}
			double getElevationRateAzimuthCovariance() {				
				return matrixInFrame.matrix.data[47];
			}
			double getElevationRangeRateCovariance() {				
				return matrixInFrame.matrix.data[28];
			}
			double getRangeRateElevationCovariance() {				
				return matrixInFrame.matrix.data[12];
			}
			double getElevationAzimuthRateCovariance() {				
				return matrixInFrame.matrix.data[31];
			}
			double getAzimuthRateElevationCovariance() {				
				return matrixInFrame.matrix.data[39];
			}
			double getElevationElevationRateCovariance() {				
				return matrixInFrame.matrix.data[32];
			}
			double getElevationRateElevationCovariance() {				
				return matrixInFrame.matrix.data[48];
			}
			double getRangeRateAzimuthRateCovariance() {				
				return matrixInFrame.matrix.data[13];
			}
			double getAzimuthRateRangeRateCovariance() {				
				return matrixInFrame.matrix.data[37];
			}
			double getRangeRateElevationRateCovariance() {				
				return matrixInFrame.matrix.data[14];
			}
			double getElevationRateRangeRateCovariance() {				
				return matrixInFrame.matrix.data[46];
			}
			double getAzimuthRateElevationRateCovariance() {				
				return matrixInFrame.matrix.data[41];
			}
			double getElevationRateAzimuthRateCovariance() {				
				return matrixInFrame.matrix.data[49];
			}
			double getRangeAccelerationVariance() {				
				return matrixInFrame.matrix.data[80];
			}
			double getAzimuthAccelerationVariance() {				
				return matrixInFrame.matrix.data[60];
			}
			double getElevationAccelerationVariance() {				
				return matrixInFrame.matrix.data[70];
			}
			double getRangeRangeAccelerationCovariance() {			
				return matrixInFrame.matrix.data[8];
			}
			double getRangeAccelerationRangeCovariance() {			
				return matrixInFrame.matrix.data[72];
			}
			double getRangeAzimuthAccelerationCovariance() {				
				return matrixInFrame.matrix.data[6];
			}
			double getAzimuthAccelerationRangeCovariance() {				
				return matrixInFrame.matrix.data[54];
			}
			double getRangeElevationAccelerationCovariance() {				
				return matrixInFrame.matrix.data[7];
			}
			double getElevationAccelerationRangeCovariance() {				
				return matrixInFrame.matrix.data[63];
			}
			double getAzimuthRangeAccelerationCovariance() {				
				return matrixInFrame.matrix.data[26];
			}
			double getRangeAccelerationAzimuthCovariance() {				
				return matrixInFrame.matrix.data[74];
			}
			double getAzimuthAzimuthAccelerationCovariance() {				
				return matrixInFrame.matrix.data[24];
			}
			double getAzimuthAccelerationAzimuthCovariance() {				
				return matrixInFrame.matrix.data[56];
			}
			double getAzimuthElevationAccelerationCovariance() {				
				return matrixInFrame.matrix.data[25];
			}
			double getElevationAccelerationAzimuthCovariance() {				
				return matrixInFrame.matrix.data[65];
			}
			double getElevationRangeAccelerationCovariance() {				
				return matrixInFrame.matrix.data[35];
			}
			double getRangeAccelerationElevationCovariance() {				
				return matrixInFrame.matrix.data[75];
			}
			double getElevationAzimuthAccelerationCovariance() {				
				return matrixInFrame.matrix.data[33];
			}
			double getAzimuthAccelerationElevationCovariance() {				
				return matrixInFrame.matrix.data[57];
			}
			double getElevationElevationAccelerationCovariance() {				
				return matrixInFrame.matrix.data[34];
			}
			double getElevationAccelerationElevationCovariance() {				
				return matrixInFrame.matrix.data[66];
			}
			double getRangeRateRangeAccelerationCovariance() {				
				return matrixInFrame.matrix.data[17];
			}
			double getRangeAccelerationRangeRateCovariance() {				
				return matrixInFrame.matrix.data[73];
			}
			double getRangeRateAzimuthAccelerationCovariance() {				
				return matrixInFrame.matrix.data[15];
			}
			double getAzimuthAccelerationRangeRateCovariance() {				
				return matrixInFrame.matrix.data[55];
			}
			double getRangeRateElevationAccelerationCovariance() {				
				return matrixInFrame.matrix.data[16];
			}
			double getElevationAccelerationRangeRateCovariance() {				
				return matrixInFrame.matrix.data[64];
			}
			double getAzimuthRateRangeAccelerationCovariance() {				
				return matrixInFrame.matrix.data[44];
			}
			double getRangeAccelerationAzimuthRateCovariance() {				
				return matrixInFrame.matrix.data[76];
			}
			double getAzimuthRateAzimuthAccelerationCovariance() {				
				return matrixInFrame.matrix.data[42];
			}
			double getAzimuthAccelerationAzimuthRateCovariance() {				
				return matrixInFrame.matrix.data[58];
			}
			double getAzimuthRateElevationAccelerationCovariance() {				
				return matrixInFrame.matrix.data[43];
			}
			double getElevationAccelerationAzimuthRateCovariance() {				
				return matrixInFrame.matrix.data[67];
			}
			double getElevationRateRangeAccelerationCovariance() {				
				return matrixInFrame.matrix.data[53];
			}
			double getRangeAccelerationElevationRateCovariance() {				
				return matrixInFrame.matrix.data[77];
			}
			double getElevationRateAzimuthAccelerationCovariance() {				
				return matrixInFrame.matrix.data[51];
			}
			double getAzimuthAccelerationElevationRateCovariance() {				
				return matrixInFrame.matrix.data[59];
			}
			double getElevationRateElevationAccelerationCovariance() {				
				return matrixInFrame.matrix.data[52];
			}
			double getElevationAccelerationElevationRateCovariance() {				
				return matrixInFrame.matrix.data[68];
			}
			double getRangeAccelerationAzimuthAccelerationCovariance() {				
				return matrixInFrame.matrix.data[78];
			}
			double getAzimuthAccelerationRangeAccelerationCovariance() {				
				return matrixInFrame.matrix.data[62];
			}
			double getRangeAccelerationElevationAccelerationCovariance() {				
				return matrixInFrame.matrix.data[79];
			}
			double getElevationAccelerationRangeAccelerationCovariance() {				
				return matrixInFrame.matrix.data[71];
			}
			double getAzimuthAccelerationElevationAccelerationCovariance() {				
				return matrixInFrame.matrix.data[61];
			}
			double getElevationAccelerationAzimuthAccelerationCovariance() {				
				return matrixInFrame.matrix.data[69];
			}

			template <class T>
			void Serialise(T& archive) {
				archive.Serialise(matrixInFrame, "matrixInFrame");
			}

			LCA_TOPIC("CovarianceMatrixPolar", 1, 0);
	};
}
#endif