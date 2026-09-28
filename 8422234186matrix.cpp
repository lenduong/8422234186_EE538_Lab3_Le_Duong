/*
Q1 Pseudocode
1. Construct matrix A and matrix B; the constructor fills every element with 0.
2. Read 100 integers into A, followed by 100 integers into B.
3. Create matrix sum by calling A.mat_add(B).
4. In mat_add, use nested loops to add corresponding private elements.
5. Write sum as 10 rows, placing one space between adjacent values.
*/

#include <iostream>

class Matrix{
private:
    int value[10][10];

public:
    Matrix();
    void read(std::istream& in);
    Matrix mat_add(const Matrix& other) const;
    void write(std::ostream& out) const;
};

Matrix::Matrix(){
    for (int row = 0; row < 10; ++row){
        for (int column = 0; column < 10; ++column){
            value[row][column] = 0;
        }
    }
}

void Matrix::read(std::istream& in){
    for (int row = 0; row < 10; ++row){
        for (int column = 0; column < 10; ++column){
            in >> value[row][column];
        }
    }
}

Matrix Matrix::mat_add(const Matrix& other) const{
    Matrix sum;

    for (int row = 0; row < 10; ++row){
        for (int column = 0; column < 10; ++column){
            sum.value[row][column] =
                value[row][column] + other.value[row][column];
        }
    }

    return sum;
}

void Matrix::write(std::ostream& out) const{
    for (int row = 0; row < 10; ++row){
        for (int column = 0; column < 10; ++column){
            if (column > 0){
                out << ' ';
            }
            out << value[row][column];
        }
        out << '\n';
    }
}

int main(){
    Matrix matrixA;
    Matrix matrixB;

    matrixA.read(std::cin);
    matrixB.read(std::cin);

    Matrix sum = matrixA.mat_add(matrixB);
    sum.write(std::cout);

    return 0;
}
