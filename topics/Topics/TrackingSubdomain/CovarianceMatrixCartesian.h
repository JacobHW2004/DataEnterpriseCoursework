#ifndef COVARIANCE_MATRIX_CARTESIAN_H
#define COVARIANCE_MATRIX_CARTESIAN_H
#include "Fabric/Utils/LCA_Macros.h"
#include "FrameOfReference.h"
#include "MatrixInFrame.h"

namespace { 
	static constexpr std::uint32_t cartesianMatrixSize = 81; 
          }

namespace Topics {
	class CovarianceMatrixCartesian{
		/* This class provides an interface to access elements of the gold tracker covariance matrix in cartesian format. 
		   The units used for the Cartesian elements are:
				- North Position: Metres
				- East Position: Metres
				- Down Position: Metres
				- North Velocity: Metres per second
				- East Velocity: Metres per second
				- Down Velocity: Metres per second
				- North Acceleration: Metres per second squared
				- East Acceleration: Metres per second squared
				- Down Acceleration: Metres per second squared

			These units are combined when calculating the values of the variances and covariances.
			The structure of the cartesian covariance matrix in the gold tracker is shown below (the table has only been partially filled for readability, in reality each table entry has a corresponding getter):

			Note: Position has been abbreviated to Pos, velocity to Vel and accleration to Acc for the purposes of clarity in this table.
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				| 			-			    | North Pos  |  East Pos              |   Down Pos    |   North Vel      |  East Vel         |   Down Vel        |   North Acc     |   East Acc       |   Down Acc    |
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           | North Pos  |   NorthPos-EastPos     |               |                  |                   |                   |                 |                  |               |
				|   North Pos               | Variance   |   Covariance           |               |                  |                   |                   |                 |                  |               |
				|                           |            |                        |               |                  |                   |                   |                 |                  |               |
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           | East Pos   |   East Pos             |               |                  |                   | East Pos          |                 |                  |               |
				|   East Pos                | North Pos  |   Variance             |               |                  |                   | Down Vel          |                 |                  |               |
				|                           | Covariance |                        |               |                  |                   | Covariance        |                 |                  |               |
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           |            |                        | Down Pos      |                  |                   |                   |                 |                  |               |
				|  Down Pos                 |            |                        | Variance      |                  |                   |                   |                 |                  |               |
				|                           |            |                        |               |                  |                   |                   |                 |                  |               |
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           |            |                        |               | North Vel        |                   |                   |                 |                  |               |
				|  North Vel                |            |                        |               | Variance         |                   |                   |                 |                  |               |
				|                           |            |                        |               |                  |                   |                   |                 |                  |               |
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           |            |                        |               |                  | East Vel          |                   |                 |                  | East Vel      |
				|  East Vel                 |            |                        |               |                  | Variance          |                   |                 |                  | Down Acc      |
				|                           |            |                        |               |                  |                   |                   |                 |                  | Covariance    |
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           |            |                        |               |                  |                   | Down Vel          |                 |                  |               |
				|  Down Vel                 |            |                        |               |                  |                   | Variance          |                 |                  |               |
				|                           |            |                        |               |                  |                   |                   |                 |                  |               |
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           |            |  North Acc             |               |                  |                   |                   | North Acc       |                  |               |
				|  North Acc                |            |  East Pos              |               |                  |                   |                   | Variance        |                  |               |
				|                           |            |  Covariance            |               |                  |                   |                   |                 |                  |               |
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           |            |                        |               |                  |                   |                   |                 | East Acc         |               |
				|  East Acc                 |            |                        |               |                  |                   |                   |                 | Variance         |               |
				|                           |            |                        |               |                  |                   |                   |                 |                  |               |
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				|                           |            |                        |               |                  |                   |                   |                 |                  | Down Acc      |
				|  Down Acc                 |            |                        |               |                  |                   |                   |                 |                  | Variance      |
				|                           |            |                        |               |                  |                   |                   |                 |                  |               |
				---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		Each getter below corresponds to a certain position in the matrix above and will access the variance or covariance value at that location.
		The naming convention calls the getter get<ColumnName><RowName>Variance for diagonal elements and get<ColumnName><RowName>Covariance for off diagonal elements.
		*/

		public:
			MatrixInFrame matrixInFrame;

			CovarianceMatrixCartesian() = default;

			CovarianceMatrixCartesian(MatrixInFrame outputMatrix) :
				matrixInFrame(outputMatrix)
			{
				assert(matrixInFrame.matrix.data.size() == cartesianMatrixSize);
			}

			double getNorthPositionVariance() {				
				return matrixInFrame.matrix.data[0];
			}
			double getEastPositionVariance() {				
				return matrixInFrame.matrix.data[10];
			}
			double getDownPositionVariance() {				
				return matrixInFrame.matrix.data[20];
			}
			double getNorthPositionEastPositionCovariance() {				
				return matrixInFrame.matrix.data[1];
			}
			double getEastPositionNorthPositionCovariance() {				
				return matrixInFrame.matrix.data[9];
			}
			double getNorthPositionDownPositionCovariance() {				
				return matrixInFrame.matrix.data[2];
			}
			double getDownPositionNorthPositionCovariance() {				
				return matrixInFrame.matrix.data[18];
			}
			double getEastPositionDownPositionCovariance() {				
				return matrixInFrame.matrix.data[11];
			}
			double getDownPositionEastPositionCovariance() {				
				return matrixInFrame.matrix.data[19];
			}
			double getNorthVelocityVariance() {				
				return matrixInFrame.matrix.data[30];
			}
			double getEastVelocityVariance() {				
				return matrixInFrame.matrix.data[40];
			}
			double getDownVelocityVariance() {				
				return matrixInFrame.matrix.data[50];
			}
			double getNorthPositionNorthVelocityCovariance() {				
				return matrixInFrame.matrix.data[3];
			}
			double getNorthVelocityNorthPositionCovariance() {				
				return matrixInFrame.matrix.data[27];
			}
			double getNorthPositionEastVelocityCovariance() {				
				return matrixInFrame.matrix.data[4];
			}
			double getEastVelocityNorthPositionCovariance() {				
				return matrixInFrame.matrix.data[36];
			}
			double getNorthPositionDownVelocityCovariance() {				
				return matrixInFrame.matrix.data[5];
			}
			double getDownVelocityNorthPositionCovariance() {				
				return matrixInFrame.matrix.data[45];
			}
			double getEastPositionNorthVelocityCovariance() {				
				return matrixInFrame.matrix.data[12];
			}
			double getNorthVelocityEastPositionCovariance() {				
				return matrixInFrame.matrix.data[28];
			}
			double getEastPositionEastVelocityCovariance() {				
				return matrixInFrame.matrix.data[13];
			}
			double getEastVelocityEastPositionCovariance() {				
				return matrixInFrame.matrix.data[37];
			}
			double getEastPositionDownVelocityCovariance() {				
				return matrixInFrame.matrix.data[14];
			}
			double getDownVelocityEastPositionCovariance() {				
				return matrixInFrame.matrix.data[46];
			}
			double getDownPositionNorthVelocityCovariance() {				
				return matrixInFrame.matrix.data[21];
			}
			double getNorthVelocityDownPositionCovariance() {				
				return matrixInFrame.matrix.data[29];
			}
			double getDownPositionEastVelocityCovariance() {				
				return matrixInFrame.matrix.data[22];
			}
			double getEastVelocityDownPositionCovariance() {				
				return matrixInFrame.matrix.data[38];
			}
			double getDownPositionDownVelocityCovariance() {				
				return matrixInFrame.matrix.data[23];
			}
			double getDownVelocityDownPositionCovariance() {				
				return matrixInFrame.matrix.data[47];
			}
			double getNorthVelocityEastVelocityCovariance() {				
				return matrixInFrame.matrix.data[31];
			}
			double getEastVelocityNorthVelocityCovariance() {				
				return matrixInFrame.matrix.data[39];
			}
			double getNorthVelocityDownVelocityCovariance() {				
				return matrixInFrame.matrix.data[32];
			}
			double getDownVelocityNorthVelocityCovariance() {				
				return matrixInFrame.matrix.data[48];
			}
			double getEastVelocityDownVelocityCovariance() {				
				return matrixInFrame.matrix.data[41];
			}
			double getDownVelocityEastVelocityCovariance() {				
				return matrixInFrame.matrix.data[49];
			}
			double getNorthAccelerationVariance() {				
				return matrixInFrame.matrix.data[60];
			}
			double getEastAccelerationVariance() {				
				return matrixInFrame.matrix.data[70];
			}
			double getDownAccelerationVariance() {				
				return matrixInFrame.matrix.data[80];
			}
			double getNorthPositionNorthAccelerationCovariance() {				
				return matrixInFrame.matrix.data[6];
			}
			double getNorthAccelerationNorthPositionCovariance() {				
				return matrixInFrame.matrix.data[54];
			}
			double getNorthPositionEastAccelerationCovariance() {				
				return matrixInFrame.matrix.data[7];
			}
			double getEastAccelerationNorthPositionCovariance() {				
				return matrixInFrame.matrix.data[63];
			}
			double getNorthPositionDownAccelerationCovariance() {				
				return matrixInFrame.matrix.data[8];
			}
			double getDownAccelerationNorthPositionCovariance() {				
				return matrixInFrame.matrix.data[72];
			}
			double getEastPositionNorthAccelerationCovariance() {
				return matrixInFrame.matrix.data[15];
			}
			double getNorthAccelerationEastPositionCovariance() {				
				return matrixInFrame.matrix.data[55];
			}
			double getEastPositionEastAccelerationCovariance() {				
				return matrixInFrame.matrix.data[16];
			}
			double getEastAccelerationEastPositionCovariance() {				
				return matrixInFrame.matrix.data[64];
			}
			double getEastPositionDownAccelerationCovariance() {				
				return matrixInFrame.matrix.data[17];
			}
			double getDownAccelerationEastPositionCovariance() {				
				return matrixInFrame.matrix.data[73];
			}
			double getDownPositionNorthAccelerationCovariance() {				
				return matrixInFrame.matrix.data[24];
			}
			double getNorthAccelerationDownPositionCovariance() {				
				return matrixInFrame.matrix.data[56];
			}
			double getDownPositionEastAccelerationCovariance() {				
				return matrixInFrame.matrix.data[25];
			}
			double getEastAccelerationDownPositionCovariance() {				
				return matrixInFrame.matrix.data[65];
			}
			double getDownPositionDownAccelerationCovariance() {				
				return matrixInFrame.matrix.data[26];
			}
			double getDownAccelerationDownPositionCovariance() {				
				return matrixInFrame.matrix.data[74];
			}
			double getNorthVelocityNorthAccelerationCovariance() {				
				return matrixInFrame.matrix.data[33];
			}
			double getNorthAccelerationNorthVelocityCovariance() {				
				return matrixInFrame.matrix.data[57];
			}
			double getNorthVelocityEastAccelerationCovariance() {				
				return matrixInFrame.matrix.data[34];
			}
			double getEastAccelerationNorthVelocityCovariance() {				
				return matrixInFrame.matrix.data[66];
			}
			double getNorthVelocityDownAccelerationCovariance() {				
				return matrixInFrame.matrix.data[35];
			}
			double getDownAccelerationNorthVelocityCovariance() {				
				return matrixInFrame.matrix.data[75];
			}
			double getEastVelocityNorthAccelerationCovariance() {				
				return matrixInFrame.matrix.data[42];
			}
			double getNorthAccelerationEastVelocityCovariance() {				
				return matrixInFrame.matrix.data[58];
			}
			double getEastVelocityEastAccelerationCovariance() {				
				return matrixInFrame.matrix.data[43];
			}
			double getEastAccelerationEastVelocityCovariance() {				
				return matrixInFrame.matrix.data[67];
			}
			double getEastVelocityDownAccelerationCovariance() {				
				return matrixInFrame.matrix.data[44];
			}
			double getDownAccelerationEastVelocityCovariance() {				
				return matrixInFrame.matrix.data[76];
			}
			double getDownVelocityNorthAccelerationCovariance() {				
				return matrixInFrame.matrix.data[51];
			}
			double getNorthAccelerationDownVelocityCovariance() {				
				return matrixInFrame.matrix.data[59];
			}
			double getDownVelocityEastAccelerationCovariance() {				
				return matrixInFrame.matrix.data[52];
			}
			double getEastAccelerationDownVelocityCovariance() {				
				return matrixInFrame.matrix.data[68];
			}
			double getDownVelocityDownAccelerationCovariance() {				
				return matrixInFrame.matrix.data[53];
			}
			double getDownAccelerationDownVelocityCovariance() {				
				return matrixInFrame.matrix.data[77];
			}
			double getNorthAccelerationEastAccelerationCovariance() {				
				return matrixInFrame.matrix.data[61];
			}
			double getEastAccelerationNorthAccelerationCovariance() {				
				return matrixInFrame.matrix.data[69];
			}
			double getNorthAccelerationDownAccelerationCovariance() {				
				return matrixInFrame.matrix.data[62];
			}
			double getDownAccelerationNorthAccelerationCovariance() {				
				return matrixInFrame.matrix.data[78];
			}
			double getEastAccelerationDownAccelerationCovariance() {				
				return matrixInFrame.matrix.data[71];
			}
			double getDownAccelerationEastAccelerationCovariance() {				
				return matrixInFrame.matrix.data[79];
			}

			template <class T>
			void Serialise(T& archive) {
				archive.Serialise(matrixInFrame , "matrixInFrame");
			}

			LCA_TOPIC("CovarianceMatrixCartesian", 1, 0);

	};
}
#endif