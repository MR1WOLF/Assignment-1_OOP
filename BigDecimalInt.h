#ifndef _BIGDECIMALINT_H_
#define _BIGDECIMALINT_H_

using namespace std;

class BigDecimalInt{
    private:
        string bigint;
    public:
        BigDecimalInt();
        BigDecimalInt(string bigint);
        BigDecimalInt(int bigint);
        BigDecimalInt operator+(BigDecimalInt num);
        BigDecimalInt operator-(BigDecimalInt num);
        bool operator>(BigDecimalInt num);
        bool operator<(BigDecimalInt num);
        bool operator==(BigDecimalInt num);
        BigDecimalInt operator=(BigDecimalInt num);
        friend ostream& operator<<(ostream& os, const BigDecimalInt& num);
        int size();
        int sign();
};

#endif
