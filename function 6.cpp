#include <iostream>
#include <cstring>
#include<algorithm>
#include<iomanip>
#include <cmath>
using namespace std;

bool isPowerOfTwo(int x) {

    return (ceil(log2(x) == floor(log2(x))));
}
int Power(int z,int ctr=0){

    if(z%2==0){

        ctr++;
        return Power(z/2,ctr);
    }
    return ctr;                             // ctr is a counter to count the log of 2 //
}


void stars(int i) {

    for (int g = 0; g < pow(2, Power(i + 1)); g++) {

        cout << "*";
    }

}
void spaces(int i){
    int Space=(i+1)-(pow(2, Power(i + 1)));
    if(Space%2==0){
        cout<<setw(Space/2 +1)<<setfill(' ');
    }
    else
        cout<<setw(Space)<<setfill(' ');
}

static void pattern(int n, int i) {

    if (i == 2*n-1) {

        return;
    }
    else

    {
        spaces(i);
        stars(i);
        cout<<endl;
        pattern(n, i+1);
    }

    }

int main() {

    int i,n;
    //cin>>n>>i;
    pattern(16,0);



}