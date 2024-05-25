#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"
#include <cassert>

namespace Topics {

    class Matrix {
    public:
        // Vector representing matrix in (row, column) order
        std::vector<double> data{};
        uint16_t            columns{ 0 };
        uint16_t            rows{ 0 };

        Matrix() = default;

        Matrix(const std::uint16_t width, const std::uint16_t height)
            : data(),
              columns(width),
              rows(height)
        {
            for (std::int32_t i{ 0 }; i < (width * height); i++)
            {
                data.push_back(0.0);
            }
        }

        Matrix(const std::vector<double>& data, uint16_t width, uint16_t height) 
            : data(data), 
              columns(width), 
              rows(height)
        {
            std::int32_t sizeOfMatrix{ width * height };
            assert(data.size() == sizeOfMatrix);
        }

        // Get a value by row and column number, assumes first index is (1,1)
        bool atRowColumn(double& foundValue, const uint16_t row, const uint16_t column) const noexcept
        {

            if ((row == 0) || (column == 0) || (row > rows) || (column > columns) || (data.size() < ((row - 1) * columns + (column - 1)))) {
                return false;
            }

            else {
                foundValue = data.at((row - 1U) * columns + (column - 1U));
                return true;
            }
        }

        // Get a value by row and column number, assumes first index is (1,1), Will return zero if no data is found
        double atRowColumn(const uint16_t row, const uint16_t column) const noexcept
        {
            double foundValue{0.0};

            if (!((row == 0) || (column == 0) || (row > rows) || (column > columns) || (data.size() < ((row - 1) * columns + (column - 1))))) {
                foundValue = data.at(((row - 1U) * columns) + (column - 1U));
            }

            return foundValue;
        }

        // Set a value by row and column number, assumes first index is (1,1), No value will be set if column and row are out of bounds
        void updateAtRowColumn(const uint16_t row, const uint16_t column, const double& value) noexcept
        {
            if (!((row == 0) || (column == 0) || (row > rows) || (column > columns) || (data.size() < ((row - 1) * columns + (column - 1))))) {
                data.at(((row - 1U) * columns) + (column - 1U)) = value;
            }
        }


        bool operator==(const Matrix& other) const noexcept
        {
            return (columns  == other.columns &&
                    rows     == other.rows &&
                    data     == other.data);
        }

        template <class T>
        void Serialise(T& archive)
        {
            archive.Serialise(data,    "element", "data");
            archive.Serialise(columns,            "width");
            archive.Serialise(rows,               "height");
        }

        LCA_TOPIC("Matrix", 1, 0)
    };
}

#endif