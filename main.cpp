#include <iostream>
#include "parser.h"
#include "solver.h"

int main() {
    std::string inputFileName = "input.txt";
    Parser parser(inputFileName);
    int W = parser.getW();
    Th* arr = parser.getA();
    int N = parser.getN();
    Solver::answer(W, arr, N);
    return 0;
}