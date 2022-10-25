#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int main()
{
   char sentence[100];

int len=0, j=0;
string str;

cout<<"Enter the sentence"<<endl;

getline(cin, str);
cout<<endl;
len = str.length();

char res[100];

strcpy(sentence, str.c_str());

for(int i = 0; i<len; i++){

if(sentence[i]==' ' && sentence[i+1]==' ')
continue;

if(sentence[i]>=65 && sentence[i]<=90){
res[j++]=sentence[i]+32;

}
else{
res[j++]=sentence[i];
}

}
res[0]=res[0]-32;

cout<<"After correction:"<<endl;
cout<<endl;
for(int i=0;i<j;i++)
cout<<res[i];




    return 0;
}
