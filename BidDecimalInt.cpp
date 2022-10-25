#include <iostream>
#include "BigDecimalInt.h"
#include <string>
#include <regex>

using namespace std;

string add_zeros(string& var1,string& var2) {

    if (var1.length() > var2.length()) {

        int zeros_num = var1.length() - var2.length();
        stringstream buffer1;

        if(var1[0]=='-'&&var2[0]!='-'){
            zeros_num -=1;
            for (int i = 0; i < zeros_num; ++i) {
                buffer1 << '0';
            }
            buffer1 << var2.substr(0);
            var2 = buffer1.str();
            return var1,var2;
        }
        else if(var1[0]!='-'&&var2[0]=='-'){
            zeros_num +=1;
            buffer1 << '-';
            for (int i = 0; i < zeros_num; ++i) {
                buffer1 << '0';
            }
            buffer1 << var2.substr(1);
            var2 = buffer1.str();
            return var1,var2;
        }
        else if (var1[0]=='-'&&var2[0]=='-'){

            buffer1 << '-';
            for (int i = 0; i < zeros_num; ++i) {
                buffer1 << '0';
            }
            buffer1 << var2.substr(1);
            var2 = buffer1.str();
            return var1,var2;
        }
        //if the string has a sign add the sign to the buffer before adding zeros//
        else{
            for (int i = 0; i < zeros_num; ++i) {
                buffer1 << '0';
            }
            buffer1 << var2.substr(0);
            var2 = buffer1.str();
            return var1,var2;
        }


    }
    else if  (var2.length() > var1.length()) {

            int zeros_num = var2.length() - var1.length();
            stringstream buffer1;

            if(var2[0]=='-'&&var1[0]!='-'){
                zeros_num -=1;
                for (int i = 0; i < zeros_num; ++i) {
                    buffer1 << '0';
                }
                buffer1 << var1.substr(0);
                var1 = buffer1.str();
                return var1,var2;
            }
            else if(var2[0]!='-'&&var1[0]=='-'){
                zeros_num +=1;
                buffer1 << '-';
                for (int i = 0; i < zeros_num; ++i) {
                    buffer1 << '0';
                }
                buffer1 << var1.substr(1);
                var1 = buffer1.str();
                return var1,var2;                           //if we have - in the less length num we add - in buffer
                                                            // And we add 1 to the substr position
            }
            else if (var2[0]=='-'&&var1[0]=='-'){

                buffer1 << '-';
                for (int i = 0; i < zeros_num; ++i) {
                    buffer1 << '0';
                }
                buffer1 << var1.substr(1);
                var1 = buffer1.str();
                return var1,var2;
            }
                //if the string has a sign add the sign to the buffer before adding zeros//
            else{
                for (int i = 0; i < zeros_num; ++i) {
                    buffer1 << '0';
                }
                buffer1 << var1.substr(0);
                var1 = buffer1.str();
                return var1,var2;
            }


        }
    else if(var1.size()==var2.size()){

        stringstream buffer1;
        if(var2[0]=='-'&&var1[0]!='-'){
            buffer1<<'-';
            for (int i = 0; i < 1; ++i) {
                buffer1 << '0';
            }
            buffer1 << var2.substr(1);
            var2 = buffer1.str();
            return var1,var2;
        }
        else if(var1[0]=='-'&&var2[0]!='-'){
            buffer1<<'-';
            for (int i = 0; i < 1; ++i) {
                buffer1 << '0';
            }
            buffer1 << var1.substr(1);
            var1 = buffer1.str();
            return var1,var2;
        }
    }
}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt num){


    string result;
    int carry=0;

    // case 1 of var1 positive and var2 positive ---->addition//
    if(bigint[0]!='-'&&num.bigint[0]!='-'){
            add_zeros(bigint,num.bigint);
            stringstream buffer ;
            for(int i=bigint.length()-1;i>=0;i--){
                char chr1=bigint[i];                          //if both are +//
                char chr2=num.bigint[i];
                char chr3;
                int num1=(chr1-'0');;
                int num2=(chr2-'0');
                int sum=num1+num2+carry;
                carry=0;
                if(sum>=10){
                    carry++;
                    sum=sum-10;
                    chr3=sum+'0';
                    buffer<<chr3;
                }
                else{
                    chr3='0'+sum;
                    buffer<<chr3;
                }
            }
            if(carry==1){
                buffer<<'1';
            }
            result=buffer.str();
            reverse(result.begin(),result.end());

        }

        // case 2 normal subtraction first num positive and second num is negative//
    else if((bigint[0]!='-'&&num.bigint[0]=='-')&& (bigint.size()>num.bigint.size()-1 )){
            add_zeros(bigint,num.bigint);
        stringstream buffer ;
            int borrow=0;
            for(int i=bigint.size()-1;i>=0;i--){
            char chr1=bigint[i];
            char chr2=num.bigint[i+1];
            char chr3;
            int num1=(chr1-'0');;
            int num2=(chr2-'0');
            int sum=0;
            sum=num1-num2-borrow;
            if(sum<0){
                borrow=1;
                chr3='0'+(sum+10);
                buffer<<chr3;
            }
            else if(sum>=0){
                borrow=0;
                chr3='0'+sum;
                buffer<<chr3;
            }

        }
        result=buffer.str();
        reverse(result.begin(),result.end());

    }

            // case 3 subtraction with negative sign cause the negative num is greater//

    else if((bigint[0]!='-'&&num.bigint[0]=='-')&& (bigint.size()<num.bigint.size()-1 ) ){
            add_zeros(bigint,num.bigint);
            stringstream buffer ;
            int borrow=0;
            for(int i=bigint.size()-1;i>=0;i--){
                char chr1=bigint[i];
                char chr2=num.bigint[i+1];
                char chr3;
                int num1=(chr1-'0');;
                int num2=(chr2-'0');
                int sum=0;
                sum=num2-num1-borrow;
                if(sum<0){
                    borrow=1;
                    chr3='0'+(sum+10);
                    buffer<<chr3;
                }
                else if(sum>=0){
                    borrow=0;
                    chr3='0'+sum;
                    buffer<<chr3;
                }

            }
            buffer<<'-';
            result=buffer.str();
            reverse(result.begin(),result.end());

        }
            // case 4  num1 is negative and num2 positive and num1 is greater ---> inverse subtraction  //
            // inverse subtraction means we are going to subtract the greater-the less and but the '-' sign//
        else if((bigint[0]=='-'&&num.bigint[0]!='-')&& ((bigint.size()-1)>num.bigint.size() ) ){
            add_zeros(bigint,num.bigint);
            stringstream buffer ;
            int borrow=0;

            for(int i=num.bigint.size()-1;i>=0;i--){
                char chr1=bigint[i+1];
                char chr2=num.bigint[i];
                char chr3;
                int num1=(chr1-'0');;
                int num2=(chr2-'0');
                int sum=0;
                sum=num1-num2-borrow;
                if(sum<0){
                    borrow=1;
                    chr3='0'+(sum+10);
                    buffer<<chr3;
                }
                else if(sum>=0){
                    borrow=0;
                    chr3='0'+sum;
                    buffer<<chr3;
                }

            }
            buffer<<'-';
            result=buffer.str();
            reverse(result.begin(),result.end());

        }

        // case 5 num1 is negative and num2 positive and the positive is greater //
        // inverse subtraction with a positive sign cause the greater is positive //
        else if((bigint[0]=='-'&&num.bigint[0]!='-')&&((bigint.size()-1)<=num.bigint.size() ) ){

            add_zeros(bigint,num.bigint);
            stringstream buffer ;
            int borrow=0;
            for(int i=num.bigint.size()-1;i>=0;i--){
                char chr1=bigint[i+1];
                char chr2=num.bigint[i];
                char chr3;
                int num1=(chr1-'0');;
                int num2=(chr2-'0');
                int sum=0;
                sum=num2-num1-borrow;
                if(sum<0){
                    borrow=1;
                    chr3='0'+(sum+10);
                    buffer<<chr3;
                }
                else if(sum>=0){
                    borrow=0;
                    chr3='0'+sum;
                    buffer<<chr3;
                }

            }
            result=buffer.str();
            reverse(result.begin(),result.end());

        }
    // case 6 if both are negative we add both and add the negative sign in the end //
    else if((bigint[0]=='-'&&num.bigint[0]!='-') &&(bigint.substr(1,bigint.size()) ==num.bigint) ){
       result="0";
    }
    else if(bigint[0]=='-'&&num.bigint[0]=='-'){
        add_zeros(bigint,num.bigint);
        stringstream buffer ;
        for(int i=bigint.length()-1;i>0;i--){
            char chr1=bigint[i];                          //if both are -//
            char chr2=num.bigint[i];
            char chr3;
            int num1=(chr1-'0');;
            int num2=(chr2-'0');
            int sum=num1+num2+carry;
            carry=0;
            if(sum>=10){
                carry++;
                sum=sum-10;
                chr3=sum+'0';
                buffer<<chr3;
            }
            else{
                chr3='0'+sum;
                buffer<<chr3;
            }
        }
        if(carry==1){
            buffer<<'1';
        }
        buffer<<'-';
        result=buffer.str();
        reverse(result.begin(),result.end());

    }
    BigDecimalInt num3=(result);
    return num3;
}
BigDecimalInt BigDecimalInt::operator-(BigDecimalInt num){
    string result;
    int carry=0;
    // case 1 if both are positive and num1 is greater---> normal subtraction //
     if((bigint[0]!='-'&&num.bigint[0]!='-')&& (bigint.size()>num.bigint.size() )){
        add_zeros(bigint,num.bigint);
        stringstream buffer ;
        int borrow=0;
        for(int i=bigint.size()-1;i>=0;i--){
            char chr1=bigint[i];
            char chr2=num.bigint[i];
            char chr3;
            int num1=(chr1-'0');;
            int num2=(chr2-'0');
            int sum=0;
            sum=num1-num2-borrow;
            if(sum<0){
                borrow=1;
                chr3='0'+(sum+10);
                buffer<<chr3;
            }
            else if(sum>=0){
                borrow=0;
                chr3='0'+sum;
                buffer<<chr3;
            }

        }
        result=buffer.str();
        reverse(result.begin(),result.end());

    }
     //case 2 if both are positive and second num is greater //
    else if((bigint[0]!='-'&&num.bigint[0]!='-')&& (bigint.size()<num.bigint.size() )){
        add_zeros(bigint,num.bigint);
        stringstream buffer ;
        int borrow=0;
        for(int i=bigint.size()-1;i>=0;i--){
            char chr1=bigint[i];
            char chr2=num.bigint[i];
            char chr3;
            int num1=(chr1-'0');;
            int num2=(chr2-'0');
            int sum=0;
            sum=num2-num1-borrow;
            if(sum<0){
                borrow=1;
                chr3='0'+(sum+10);
                buffer<<chr3;
            }
            else if(sum>=0){
                borrow=0;
                chr3='0'+sum;
                buffer<<chr3;
            }

        }
        buffer<<'-';
        result=buffer.str();
        reverse(result.begin(),result.end());

    }
    //case 3 if num1 positive and num2 negative --> normal addition //
    else if(bigint[0]!='-'&&num.bigint[0]=='-'){
        add_zeros(bigint,num.bigint);
        stringstream buffer ;
        for(int i=bigint.length()-1;i>=0;i--){
            char chr1=bigint[i];
            char chr2=num.bigint[i+1];
            char chr3;
            int num1=(chr1-'0');;
            int num2=(chr2-'0');
            int sum=num1+num2+carry;
            carry=0;
            if(sum>=10){
                carry++;
                sum=sum-10;
                chr3=sum+'0';
                buffer<<chr3;
            }
            else{
                chr3='0'+sum;
                buffer<<chr3;
            }
        }
        if(carry==1){
            buffer<<'1';
        }
        result=buffer.str();
        reverse(result.begin(),result.end());

    }
    // case 4 if num1 negative and num2 positive --> normal addition with - sign added in the end//
     else if(bigint[0]=='-'&&num.bigint[0]!='-'){
         add_zeros(bigint,num.bigint);
         stringstream buffer ;
         for(int i=num.bigint.length()-1;i>=0;i--){
             char chr1=bigint[i+1];
             char chr2=num.bigint[i];
             char chr3;
             int num1=(chr1-'0');;
             int num2=(chr2-'0');
             int sum=num1+num2+carry;
             carry=0;
             if(sum>=10){
                 carry++;
                 sum=sum-10;
                 chr3=sum+'0';
                 buffer<<chr3;
             }
             else{
                 chr3='0'+sum;
                 buffer<<chr3;
             }
         }
         if(carry==1){
             buffer<<'1';
         }
         buffer<<'-';
         result=buffer.str();
         reverse(result.begin(),result.end());

     }
     else if((bigint[0]=='-'&&num.bigint[0]=='-') &&(bigint ==num.bigint) ){
         result="0";
     }
        // case 5 addition with the negative sign //

     else if((bigint[0]=='-'&&num.bigint[0]=='-')){
         add_zeros(bigint,num.bigint);
         stringstream buffer ;
         int borrow=0;
         for(int i=bigint.size()-1;i>0;i--){
             char chr1=bigint[i];
             char chr2=num.bigint[i];
             char chr3;
             int num1=(chr1-'0');;
             int num2=(chr2-'0');
             int sum=0;
             sum=num1-num2-borrow;
             if(sum<0){
                 borrow=1;
                 chr3='0'+(sum+10);
                 buffer<<chr3;
             }
             else if(sum>=0){
                 borrow=0;
                 chr3='0'+sum;
                 buffer<<chr3;
             }

         }
         buffer<<'-';
         result=buffer.str();
         reverse(result.begin(),result.end());

     }
    BigDecimalInt num3=(result);
    return num3;
}

string Remove_Zero(string str){
    int count=0;
    if((str[0]=='-'&&str[1]=='0')||(str[0]=='+'&&str[1]=='0')){

        for(int i=1;i<=str.length();i++){
            if((i==str.length()-1)&&str[i]=='0'){
                str.erase(1,count);
                return str;
            }
            else {
                if (str[i] != '0') {
                    str.erase(1, count);
                    return str;
                } else {

                    ++count;

                }
            }
        }
    }
    else if(str[0]=='0') {
        for (int i = 0; i < str.length(); i++) {

            if((i==str.length()-1)&&str[i]=='0'){
                str.erase(0,count);
                return str;
            }
            else {
                if (str[i] != '0') {
                    str.erase(0, count);
                    return str;
                } else {
                    ++count;
                }
            }
        }
    }
    else
        return str;

}

bool valid(string x){
    string rgx ="[+-]?[0-9]+";
    regex RegexRule(rgx);
   bool isValid = regex_match(x,RegexRule);
    return isValid;

}


// Empty Constructor
BigDecimalInt::BigDecimalInt(){
    bigint = "";
}


// Constructor
BigDecimalInt::BigDecimalInt(string bigint){
    if(bigint.size()>1) {
        if (valid(bigint) == 1) {
            if(bigint[0]=='+'){
                bigint.erase(0,1);
                bigint= Remove_Zero(bigint);
                cout<<bigint;
            }
            else {
                bigint = Remove_Zero(bigint);
                this->bigint = bigint;
            }
        }
        else {
            cout<<"Invalid";
            exit(1);
        }
    }
    else
    {this->bigint = bigint;}

}
// Constructor
BigDecimalInt::BigDecimalInt(int bigint){

    (*this).bigint = Remove_Zero(to_string(bigint));
}



// The > operator function
bool BigDecimalInt::operator>(BigDecimalInt num){
    if (bigint[0] == '-' && num.bigint[0] != '-'){
        return false;
    }
    else if (bigint[0] != '-' && num.bigint[0] == '-'){
        return true;
    }
    else if(bigint[0] == '-' && num.bigint[0] == '-'){
        if (bigint.length() > num.bigint.length()){
            return false;
        }
        else if (bigint.length() < num.bigint.length()){
            return true;
        }
        else {

            for (int i = 1; i < bigint.length(); i++) {
                if (bigint[i] > num.bigint[i]) {

                    return false;
                } else {

                    return true;
                }
            }
        }
    }
    else {
        if (bigint.length() < num.bigint.length()) {
            return false;
        } else if (bigint.length() > num.bigint.length()) {
            return true;
        } else {
            for (int i = 0; i <= bigint.length(); i++) {
                if (bigint[i] > num.bigint[i]) {
                    return true;
                } else if (bigint[i] < num.bigint[i]) {
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
        else if (bigint.length() < num.bigint.length()){
            return false;
        }
        else {
            for (int i = 1; i < bigint.length(); i++) {
                if (bigint[i] > num.bigint[i]) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
    else if(bigint[0] == '+' && num.bigint[0] == '+') {
        if (bigint.length() < num.bigint.length()) {
            return true;
        } else if (bigint.length() > num.bigint.length()) {
            return false;
        }
        else {
            for (int i = 1; i < bigint.length(); i++) {
                if (bigint[i] > num.bigint[i]) {
                    return false;
                }
                else {
                    return true;
                }
            }
        }
    }

    else {
        if (bigint.length() < num.bigint.length()) {
            return true;
        }
        else if (bigint.length() > num.bigint.length()) {
            return false;
        }

        else {
            for (int i = 0; i <= bigint.length(); i++) {
                if (bigint[i] > num.bigint[i]) {
                    return false;
                } else if (bigint[i] < num.bigint[i]) {
                    return true;
                }
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

