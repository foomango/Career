// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/13/2013 08:29:25 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>
#include <cassert>

#include <stdlib.h>

/**
 * Calculate the nth item of Fibonacci Series iteratively
 **/
long long FibonacciSolution1(unsigned n) 
{
    int result[2] = {0, 1};
    if (n < 2) {
        return result[n];
    }

    long long fib_n_minus_one = 1;
    long long fib_n_minus_two = 0;
    long long fib_n = 1;

    for (int i = 0; i < n - 1; i++) {
        fib_n = fib_n_minus_one + fib_n_minus_two;
        fib_n_minus_two = fib_n_minus_one;
        fib_n_minus_one = fib_n;
    }

    return fib_n;
}

/**
 * A 2 by 2 matrix
 **/
struct Matrix2By2 
{
    Matrix2By2
        (
         long long m00 = 0, 
         long long m01 = 0, 
         long long m10 = 0, 
         long long m11 = 0
         )
        :m_00(m00), m_01(m01), m_10(m10), m_11(m11)
        {
        }
    long long m_00;
    long long m_01;
    long long m_10;
    long long m_11;
};

/**
 * Multiply two matixes
 * Input: matrix1 - the first matrix
 *        matrix2 - the second matrix
 * Output: the production of two matrixes
 **/
Matrix2By2 MatrixMultiply
(
 const Matrix2By2& matrix1, 
 const Matrix2By2& matrix2
 )
{
    return Matrix2By2(
            matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10, 
            matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11, 
            matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10, 
            matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11);
}

/**
 * The nth power of matrix
 * 1 1
 * 1 0
 **/
Matrix2By2 MatrixPower(unsigned int n) 
{
    assert(n > 0);

    Matrix2By2 matrix;
    if (n == 1) {
        matrix = Matrix2By2(1, 1, 1, 0);
    } else if (n % 2 == 0) {
        matrix = MatrixPower(n / 2);
        matrix = MatrixMultiply(matrix, matrix);
    } else {
        matrix = MatrixPower((n - 1) / 2);
        matrix = MatrixMultiply(matrix, matrix);
        matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
    }

    return matrix;
}

/**
 * Calculate the nth Fabonacci series using devide and 
 */
long long FibonacciSolution2(unsigned int n) 
{
    int result[2] = {0, 1};
    if (n < 2) {
        return result[n];
    }

    Matrix2By2 matrix = MatrixPower(n - 1);
    return matrix.m_00;
}

int main(int argc, char* argv[]) 
{
    if (argc < 3) {
        std::cout << "usage: " 
            << argv[0] 
            << " [12] n"
            << std::endl;
        return -1;
    }

    int n = atoi(argv[2]);

    if (atoi(argv[1]) == 1) {
        std::cout << FibonacciSolution1(n) << std::endl;
    } else {
        std::cout << FibonacciSolution2(n) << std::endl;
    }

    return 0;
}
