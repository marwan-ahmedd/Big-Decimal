#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <iostream>
#include <cstring>
#include <cstring>
#include <sstream>

using namespace std;

class BigDecimalInt
{
    string str;
    void fillZeros(int maxSize, string&, string&);

    public:
        BigDecimalInt(string decStr);
        BigDecimalInt(int decInt);

        BigDecimalInt operator- (BigDecimalInt anotherDec);
        bool operator< (BigDecimalInt anotherDec);
        
        friend ostream& operator<< (ostream& out, BigDecimalInt b);
};

#endif