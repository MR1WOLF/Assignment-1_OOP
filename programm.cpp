#include <iostream>
#include <string>

using namespace std;

class BigDecimalInt
{
private:
    string bigint;

public:
    BigDecimalInt(){
        bigint = "";
    }
    BigDecimalInt(string biginteger)
    {
        this->bigint = biginteger;
    }
    BigDecimalInt(int biginteger)
    {
        this->bigint = to_string(biginteger);
    }
    BigDecimalInt operator=(BigDecimalInt num)
    {
        this->bigint = num.bigint;
        return *this;
    }
    bool operator>(BigDecimalInt num)
    {
        int n = bigint.size(), s = num.bigint.size();
        if (n > s)
        {
            return true;
        }
        else if (n < s)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (num.bigint[i] > bigint[i])
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    bool operator<(BigDecimalInt num)
    {
        int n = bigint.size(), s = num.bigint.size();
        if (n < s)
        {
            return true;
        }
        else if (n > s)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (num.bigint[i] < bigint[i])
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    bool operator==(BigDecimalInt num)
    {
        return bigint == num.bigint;
    }
    BigDecimalInt operator+(BigDecimalInt num){
        BigDecimalInt digits;
        int n = bigint.size();
        int res;
        if (n > num.bigint.size()){
            for (int i = num.bigint.size(); i < n; i++){
                num.bigint.insert(0, "0");
            }

        }
        else if (n < num.bigint.size()){
            for (int i = n; i < num.bigint.size(); i++){
                bigint.insert(0, "0");
            }
        }
        while(n){
            res = int(bigint[n - 1]) - 48 + int(num.bigint[n - 1]) - 48;
            if (res > 9){
                digits.bigint.insert(0, to_string(res % 10));
                bigint[n - 2]++;
                n--;
                continue;
            }
            digits.bigint.insert(0, to_string(res));
            n--;
        }
        return digits;
    }
    int size()
    {
        return bigint.size();
    }
    int sign()
    {
        if (bigint.at(0) != '+' || bigint.at(0) != '-' && isdigit(bigint.at(0)))
        {
            cout << "the sign is postive" << endl;
        }
        else if (bigint.at(0) == '+')
        {
            cout << "the sign is postive" << endl;
        }
        return 0;
    }
    friend ostream &operator<<(ostream &os, const BigDecimalInt a)
    {
        os << a.bigint;
        return os;
    }
};

int main()
{

    BigDecimalInt num1("10000");
    BigDecimalInt num2("6000");

    cout << num1 + num2;

    return 0;
}