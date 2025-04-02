#include "matrix.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    std::ifstream file;
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    file.open(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    
    int N;
    file >> N;

    file.ignore(); // ignore newline after matrix size decided

    
    Matrix matrix1(N);
    Matrix matrix2(N);

    
    for (int i = 0; i < N; i++) {
        int num;
        file >> num;

        for (int j = 0; j < N; j++) {
            matrix1.set_value(i, j, num);
        }
    }

    file.ignore(); // ignore the newline character after the first matrix

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int num;
            file >> num;

            matrix2.set_value(i, j, num);
        }
    }

    file.close();

    std::cout << "Matrix 1:" << std::endl;
    matrix1.print_matrix();

    std::cout << "Matrix 2:" << std::endl;
    matrix2.print_matrix();

    return 0;
}
