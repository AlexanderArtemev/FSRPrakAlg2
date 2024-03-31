#ifndef PARSER_H
#define PARSER_H

#include <string>

struct Th {
    int val;
    int wei;
    int n;
};

class Parser {
private:
    int N;
    int W;
    Th* arr;

public:
    Parser(const std::string& fileName);
    ~Parser();
    int getN() const;
    int getW() const;
    Th* getA() const;
};

#endif /* PARSER_H */