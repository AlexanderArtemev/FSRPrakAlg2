#include "parser.h"
#include <fstream>

Parser::Parser(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    int i;
    inputFile >> N >> W;
    arr = new Th[N];
    for (i = 0; i < N; i++) {
        inputFile >> arr[i].val >> arr[i].wei;
    }
    inputFile.close();
}

Parser::~Parser() {
    delete[] arr;
}

int Parser::getN() const { return N; }

int Parser::getW() const { return W; }

Th* Parser::getA() const { return arr; }
