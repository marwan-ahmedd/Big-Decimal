#include "BigDecimal.h"
#include "BigDecimal.cpp"

int main()
{
    BigDecimalInt num1("+123456789012345678901234567890");
    BigDecimalInt num2("+113456789011345678901134567890");
    BigDecimalInt num3("-200000000000000000000000000000");
    BigDecimalInt num4 = num2 + num1;
    BigDecimalInt num5 = num2 - num1;
    BigDecimalInt num6 = num1 < num2;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num3 = " << num3 << endl;
    cout << "num2 + num1 = " << num4 << endl;
    cout << "num2 - num1 = " << num5 << endl;
    cout << "num1 < num2 = " << num6 << endl;




}