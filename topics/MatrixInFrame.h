#ifndef MATRIX_IN_FRAME_H
#define MATRIX_IN_FRAME_H

#include "FrameOfReference.h"
#include "Matrix.h"

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {
    class MatrixInFrame {
    public:

        FrameOfReference referenceFrame{ FrameOfReference::FRAME_0 };
        Matrix           matrix{};

        MatrixInFrame() = default;

        MatrixInFrame(FrameOfReference referenceFrame, Matrix matrix) :
            referenceFrame(referenceFrame),
            matrix(matrix)
        {}

        bool operator==(const MatrixInFrame& other) const
        {
            return referenceFrame == other.referenceFrame &&
                matrix == other.matrix;
        }

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(referenceFrame, "referenceFrame");
            archive.Serialise(matrix,         "matrix");
        }

        LCA_TOPIC("MatrixInFrame", 1, 0);
    };
}

#endif
