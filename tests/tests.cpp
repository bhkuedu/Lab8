#include <gtest/gtest.h>

#include "matrix.hpp"

TEST(MatrixImplementation, GetSize_3) {
    Matrix matrix({
        { 25, 35, 45 },
        { 15, 45, 45 },
        { 80, 80, 80 },
    });

    EXPECT_EQ(matrix.get_size(), 3);
}

TEST(MatrixImplementation, GetSize_4) {
    Matrix matrix({
        { 25, 35, 45, 28 },
        { 15, 45, 45, 34 },
        { 80, 80, 80, 11 },
        { 4,   8,  9, 11 },
    });

    EXPECT_EQ(matrix.get_size(), 4);
}

TEST(MatrixImplementation, GetValue_Basic) {
    std::vector<std::vector<int>> expected = {
        { 0, 1, 2 },
        { 3, 4, 5 },
        { 6, 7, 8 },
    };

    Matrix matrix(expected);

    for (int i = 0; i < expected.size(); i++) {
        for (int j = 0; i < expected.size(); i++) {
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, GetValue_Random) {
    std::vector<std::vector<int>> expected = {
        { 25, 35, 45, 28 },
        { 15, 45, 45, 34 },
        { 80, 80, 80, 11 },
        { 4,   8,  9, 11 },
    };

    Matrix matrix(expected);

    for (int i = 0; i < expected.size(); i++) {
        for (int j = 0; i < expected.size(); i++) {
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, SetValue_Basic) {
    std::vector<std::vector<int>> initial = {
        { 0, 0, 0 },
        { 0, 0, 0 },
        { 0, 0, 0 },
    };
    std::vector<std::vector<int>> expected = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 },
    };

    Matrix matrix(initial);

    for (int i = 0; i < expected.size(); i++) {
        for (int j = 0; i < expected.size(); i++) {
            matrix.set_value(i, j, expected[i][j]);
        }
    }

    for (int i = 0; i < expected.size(); i++) {
        for (int j = 0; i < expected.size(); i++) {
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, SetValue_Random) {
    std::vector<std::vector<int>> initial = {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
    };
    std::vector<std::vector<int>> expected = {
        { 15, 22, 33, 44},
        { 55, 22, 33, 44},
        { 45, 22, 33, 11},
        { 15, 22, 37, 44},
    };

    Matrix matrix(initial);

    for (int i = 0; i < expected.size(); i++) {
        for (int j = 0; i < expected.size(); i++) {
            matrix.set_value(i, j, expected[i][j]);
        }
    }

    for (int i = 0; i < expected.size(); i++) {
        for (int j = 0; i < expected.size(); i++) {
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, Addition_Basic) {
    std::vector<std::vector<int>> initial = {
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 },
    };

    Matrix matrix1(initial);
    Matrix matrix2(initial);
    auto result = matrix1 + matrix2;

    for (int i = 0; i < initial.size(); i++) {
        for (int j = 0; j < initial.size(); j++) {
            EXPECT_EQ(result.get_value(i, j), 2);
        }
    }
}

TEST(MatrixImplementation, Addition_Random) {
    std::vector<std::vector<int>> initial1 = {
        { 0, 0, 8 },
        { 6, 7, 8 },
        { 4, 1, 6 },
    };
    std::vector<std::vector<int>> initial2 = {
        { 6, 3, 7 },
        { 8, 6, 6 },
        { 3, 3, 5 },
    };
    std::vector<std::vector<int>> expected = {
        { 6,  3,  15 },
        { 14, 13, 14 },
        { 7,  4,  11 },
    };

    Matrix matrix1(initial1);
    Matrix matrix2(initial2);
    auto result = matrix1 + matrix2;

    for (int i = 0; i < initial1.size(); i++) {
        for (int j = 0; j < initial1.size(); j++) {
            EXPECT_EQ(result.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, Multiplication_Basic) {
    std::vector<std::vector<int>> initial = {
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 },
    };

    Matrix matrix1(initial);
    Matrix matrix2(initial);
    auto result = matrix1 * matrix2;

    for (int i = 0; i < initial.size(); i++) {
        for (int j = 0; j < initial.size(); j++) {
            EXPECT_EQ(result.get_value(i, j), 3);
        }
    }
}

TEST(MatrixImplementation, Multiplication_Random) {
    std::vector<std::vector<int>> initial1 = {
        { 0, 0, 8 },
        { 6, 7, 8 },
        { 4, 1, 6 },
    };
    std::vector<std::vector<int>> initial2 = {
        { 6, 3, 7 },
        { 8, 6, 6 },
        { 3, 3, 5 },
    };
    std::vector<std::vector<int>> expected = {
        { 24,  24, 40  },
        { 116, 84, 124 },
        { 50,  36, 64  },
    };

    Matrix matrix1(initial1);
    Matrix matrix2(initial2);
    auto result = matrix1 * matrix2;

    for (int i = 0; i < initial1.size(); i++) {
        for (int j = 0; j < initial1.size(); j++) {
            EXPECT_EQ(result.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, DiagonalSumMajor) {
    std::vector<std::vector<int>> initial = {
        { 0, 0, 8 },
        { 6, 7, 8 },
        { 4, 1, 6 },
    };

    Matrix matrix(initial);
    EXPECT_EQ(matrix.sum_diagonal_major(), 13);
}

TEST(MatrixImplementation, DiagonalSumMinor) {
    std::vector<std::vector<int>> initial = {
        { 0, 0, 8 },
        { 6, 7, 8 },
        { 4, 1, 6 },
    };

    Matrix matrix(initial);
    EXPECT_EQ(matrix.sum_diagonal_minor(), 19);
}

TEST(MatrixImplementation, SwapRows_Basic) {
    std::vector<std::vector<int>> initial = {
        { 1, 1, 1 },
        { 2, 2, 2 },
        { 3, 3, 3 },
    };

    std::vector<std::vector<int>> expected = {
        { 2, 2, 2 },
        { 1, 1, 1 },
        { 3, 3, 3 },
    };

    Matrix matrix(initial);
    matrix.swap_rows(0, 1);

    for (int i = 0; i < initial.size(); i++) {
        for (int j = 0; j < initial.size(); j++) {
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, SwapRows_Random) {
    std::vector<std::vector<int>> initial = {
        { 3, 1, 4, 1 },
        { 5, 9, 2, 6 },
        { 5, 3, 5, 8 },
        { 9, 7, 9, 3 }
    };
    std::vector<std::vector<int>> expected = {
        { 5, 3, 5, 8 },
        { 5, 9, 2, 6 },
        { 3, 1, 4, 1 },
        { 9, 7, 9, 3 }
    };

    Matrix matrix(initial);
    matrix.swap_rows(0, 2);

    for (int i = 0; i < initial.size(); i++) {
        for (int j = 0; j < initial.size(); j++) {
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, SwapCols_Basic) {
    std::vector<std::vector<int>> initial = {
        { 1, 2, 3 },
        { 1, 2, 3 },
        { 1, 2, 3 },
    };

    std::vector<std::vector<int>> expected = {
        { 3, 2, 1 },
        { 3, 2, 1 },
        { 3, 2, 1 },
    };

    Matrix matrix(initial);
    matrix.swap_cols(0, 2);

    for (int i = 0; i < initial.size(); i++) {
        for (int j = 0; j < initial.size(); j++) {
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, SwapCols_Random) {
    std::vector<std::vector<int>> initial = {
        { 3, 1, 4, 1 },
        { 5, 9, 2, 6 },
        { 5, 3, 5, 8 },
        { 9, 7, 9, 3 }
    };

    std::vector<std::vector<int>> expected = {
        { 1, 1, 4, 3 },
        { 6, 9, 2, 5 },
        { 8, 3, 5, 5 },
        { 3, 7, 9, 9 }
    };

    Matrix matrix(initial);
    matrix.swap_cols(0, 3);

    for (int i = 0; i < initial.size(); i++) {
        for (int j = 0; j < initial.size(); j++) {
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, OutOfBoundsThrowsException) {
    Matrix matrix({
        { 25, 35, 45 },
        { 15, 45, 45 },
        { 80, 80, 80 },
    });

    EXPECT_THROW(matrix.get_value(4, 4), std::out_of_range);
}

// 1. Read values from a file into the matrix:
// Implement a function to load matrix data from a user-specified file. The first line of the file should contain an integer N indicating the size of the matrices, followed by two N × N matrices. After reading the file, print the matrices with proper formatting, such as aligned columns. Note that N can be any valid positive integer.
// 2. Add two matrices and display the result:
// Implement a function that adds two matrices and displays the resulting matrix.
// 3. Multiply two matrices and display the result:
// Implement a function that multiplies two matrices and displays the resulting matrix.
// Please refer to the link for the matrix multiplication: https://www.mathsisfun.com/algebra/matrix-multiplying.html
// 4. Get the sum of matrix diagonal elements:
// Implement a function to calculate and display the sum of the main and secondary diagonal elements of a matrix.
// 5. Swap matrix rows and display the result:
// Implement a function that takes a matrix and two-row indices as input (with indexing starting at 0). If both indices are within valid bounds, swap the specified rows and output the resulting matrix.
// 6. Swap matrix columns and display the result:
// Implement a function that takes a matrix and two-column indices as input (with indexing starting at 0). If both indices are within valid bounds, swap the specified rows and output the resulting matrix.
// 7. Update matrix rows and display the result:
// Implement a function that accepts a matrix, a row index, a column index, and a new value. If both indices are valid (with indexing starting at 0), update the element at the specified position and display the resulting matrix.

// ADDITIONAL TESTS

TEST(MatrixImplementation, AddMatrices_Basic) {
    std::vector<std::vector<int>> initial1 = {
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 },
    };
    std::vector<std::vector<int>> initial2 = {
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 },
    };

    Matrix matrix1(initial1);
    Matrix matrix2(initial2);
    auto result = matrix1.add_matrices(matrix2);

    std::vector<std::vector<int>> expected = {
        { 2, 2, 2 },
        { 2, 2, 2 },
        { 2, 2, 2 },
    };

    for (int i = 0; i < expected.size(); i++) {
        for (int j = 0; j < expected.size(); j++) {
            EXPECT_EQ(result.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, MultiplyMatrices_Basic) {
    std::vector<std::vector<int>> initial1 = {
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 },
    };
    std::vector<std::vector<int>> initial2 = {
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 },
    };

    Matrix matrix1(initial1);
    Matrix matrix2(initial2);
    auto result = matrix1.multiply_matrices(matrix2);

    std::vector<std::vector<int>> expected = {
        { 3, 3, 3 },
        { 3, 3, 3 },
        { 3, 3, 3 },
    };

    for (int i = 0; i < expected.size(); i++) {
        for (int j = 0; j < expected.size(); j++) {
            EXPECT_EQ(result.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, DiagonalSum_Basic) {
    std::vector<std::vector<int>> initial = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 },
    };

    Matrix matrix(initial);
    EXPECT_EQ(matrix.sum_diagonal_major(), 15);
    EXPECT_EQ(matrix.sum_diagonal_minor(), 15);
}
