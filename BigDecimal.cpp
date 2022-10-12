#include "BigDecimal.h"


// ------------------------> Fill the rest of the string with zeros
void BigDecimalInt::fillZeros(int maxSize, string& str1, string& str2)
{
    int diff;

    if (str1.length() > str2.length())
    {
        diff = maxSize - str2.length();
        for (int i = 0; i < diff; i++)
        {
            str2 = '0' + str2;
        }
    }
    else if (str1.length() < str2.length())
    {
        diff = maxSize - str1.length();
        for (int i = 0; i < diff; i++)
        {
            str1 = '0' + str1;
        }
    }
}

// ------------------------> Constructors
BigDecimalInt::BigDecimalInt(string decStr):
    str {decStr} {}

BigDecimalInt::BigDecimalInt(int decInt = 0):
    str {to_string(decInt)} {}


// -------------------> Operator + overloading <-------------------- \\



// -------------------> Operator - overloading <-------------------- \\

BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec)
{
    string first = str;
    string second = anotherDec.str;

    if (first[0] == '+')
        first = first.substr(1);
    if (second[0] == '+')
        second = second.substr(1);

        
    if (first[0] == '-' && second[0] == '-')
    {
        first = first.substr(1);
        second = second.substr(1);
        swap(first, second);
    }
    else if (first[0] == '-')
    {
        //(if the first is negative, then call + and add -ve sign to the result (-123 - 200) = -(123+200)

        first = first.substr(1);
        BigDecimalInt temp(first);
        BigDecimalInt sum = temp + anotherDec;

        sum.str = "-" + sum.str;
        return sum;
    }
    else if (second[0] == '-')
    {
        //(if the second is negative, then call Add (100 - (-100) = 100+100)
        BigDecimalInt negative(second.substr(1)); // removing the -ve sign;
        
        BigDecimalInt thisStr(first);

        return thisStr + negative;
    }

    int maxSize = (first.length() > second.length()) ? first.length() : second.length();
    fillZeros(maxSize, first, second);

    bool secondIsGreater = false;
    if (second[0] > first[0])
    {
        // swap the two numbers and add -ve sign to the result
        swap(first, second);

        secondIsGreater = true;
    }
    string result = "";
    int temp;
    bool borrow = false;

    for (int i = maxSize - 1; i >= 0; i--)
    {
        temp = first[i];

        if (borrow)
        {
            temp = first[i] - 1;
            borrow = false;
        }
        if (temp >= second[i])
        {
            result = (char)(temp - second[i] + 48) + result;
            borrow = false;
        }
        else if (temp < second[i]) // borrow
        {
            temp += 10;
            borrow = true;
            result = (char)(temp - second[i] + 48) + result;
        }
    }
    if (secondIsGreater)
        result = "-" + result;

    BigDecimalInt sum(result);
    return sum;
}



// -------------------> Operator < overloading <-------------------- \\

bool BigDecimalInt::operator< (BigDecimalInt anotherDec)
{
    string first = str;
    string second = anotherDec.str;

    if (first[0] == '+')
        first = first.substr(1);
    if (second[0] == '+')
        second = second.substr(1);


    if (first[0] != '-' and second[0] == '-')
        return false;

    else if (first[0] == '-' and second[0] != '-')
        return true;
        
    else {
        BigDecimalInt frst (first);
        BigDecimalInt result = (frst - second);
        string rslt = result.str;

        if (rslt[0] == '-')
            return true;
        else if (first == second)
            return false;
        else
            return false;
    }
}


// -------------------> Operator > overloading <-------------------- \\


// -------------------> Operator == overloading <-------------------- \\



// -------------------> Operator = overloading <-------------------- \\



// Size Function



// Sign Function




// -------------------> A friend Ostream function to print out the requested value <-------------------- \\

ostream& operator<<(ostream& out, BigDecimalInt printStr)
{
    out << printStr.str;
    return out;
}