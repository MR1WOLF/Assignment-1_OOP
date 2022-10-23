#include <iostream>
#include "BigDecimalInt.h"
#include <string>

using namespace std;
// Constructor
BigDecimalInt::BigDecimalInt(){
    bigint = "";
}


// Constructor
BigDecimalInt::BigDecimalInt(string bigint){
    this->bigint = bigint;
}

// Constructor
BigDecimalInt::BigDecimalInt(int bigint){
    (*this).bigint = to_string(bigint);
}

bool BigDecimalInt::operator>(BigDecimalInt num){
    if(bigint[0] == '-' && num.bigint[0] != '-'){
        return false;
    }
    else if(bigint[0] != '-' && num.bigint[0] == '-'){
        return true;
    }
    else if(bigint[0] == '-' && num.bigint[0] == '-'){
        if(bigint.length() > num.bigint.length()){
            return false;
        }
        else if(bigint.length() < num.bigint.length()){
            return true;
        }
        else{
            for(int i = 1; i < bigint.length(); i++){
                if(bigint[i] > num.bigint[i]){
                    return false;
                }
                else if(bigint[i] < num.bigint[i]){
                    return true;
                }
            }
        }
    }
    else{
        if(bigint.length() > num.bigint.length()){
            return true;
        }
        else if(bigint.length() < num.bigint.length()){
            return false;
        }
        else{
            for(int i = 0; i < bigint.length(); i++){
                if(bigint[i] > num.bigint[i]){
                    return true;
                }
                else if(bigint[i] < num.bigint[i]){
                    return false;
                }
            }
        }
    }
    return false;
}

// Overload < operator
bool BigDecimalInt::operator<(BigDecimalInt num){
    if (bigint[0] == '-' && num.bigint[0] != '-'){
        return true;
    }
    else if (bigint[0] != '-' && num.bigint[0] == '-'){
        return false;
    }
    else if(bigint[0] == '-' && num.bigint[0] == '-'){
        if (bigint.length() > num.bigint.length()){
            return true;
        }
        else{
            return false;
        }
        for (int i = 1; i < bigint.length(); i++){
            if (bigint[i] > num.bigint[i]){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else{
        for (int i = 0; i < bigint.length(); i++){
            if (bigint[i] > num.bigint[i]){
                return false;
            }
            else{
                return true;
            }
        }
    }
    return false;
}

// Overload == operator
bool BigDecimalInt::operator==(BigDecimalInt num){
    if (bigint == num.bigint){
        return true;
    }
    else{
        return false;
    }
}

// Overload = operator
BigDecimalInt BigDecimalInt::operator=(BigDecimalInt num){
    bigint = num.bigint;
    return *this;
}

// Overload << operator
ostream& operator<<(ostream& os, const BigDecimalInt& num){
    os << num.bigint;
    return os;
}

// Return the size of the bigint
int BigDecimalInt::size(){
    return bigint.length();
}

// Return the sign of the bigint
int BigDecimalInt::sign(){
    if (bigint[0] == '-'){
        return -1;
    }
    else{
        return 1;
    }
}
