#include <iostream>

using namespace std;

bool bear(int n){
    if (n == 42){
        return true;
    }
    else if (n < 42){
        return false;
    }
    else{
        if (n % 5 == 0){
            return bear(n - 42);
        }
        if (n % 3 == 0){
            int f_digit = n % 10;
            int s_digit = ((n % 100) / 10);
            return bear(n - (f_digit * s_digit));
        }
        if (n % 2 == 0){
            if (n % 4 == 0 && n / 2 < 42){
                int f_digit = n % 10;
                int s_digit = ((n % 100) / 10);
                return bear(n - (f_digit * s_digit));
            }
            else{
                return bear(n / 2);
            }
        }
    }
    return false;
}

int main(){
    int x = 250;
    cout << bear(x) << endl;
    return 0;
}
