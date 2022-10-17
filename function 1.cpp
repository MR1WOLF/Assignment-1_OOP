#include <iostream>
using namespace std;

string function1(string text){

    int counter=1;
    char charInText;

    for(char el:text){

        counter++;
    }

    for(int i=0;i<counter;i++){
        charInText=text[i];
        if(charInText=='H' &&(text[i-1]==' '||i==0)&&text[i+1]=='e' &&text[i+2]==' '){
            text.replace(i,2,"He or she");
            counter =counter+6;
        }
        if(charInText=='H' &&text[i-1]==' '&&text[i+1]=='i' &&text[i+2]=='m'&&text[i+3]==' '){
            text.replace(i,3,"Him or her");
            counter =counter+6;
        }
        if(charInText=='H' &&text[i-1]==' '&&text[i+1]=='i' &&text[i+2]=='s'&&text[i+3]==' '){
            text.replace(i,3,"His or her");
            counter =counter+6;
        }
        if(charInText=='h' &&text[i-1]==' '&&text[i+1]=='e' &&(text[i+2]==' '||text[i+2]=='.')){
            text.replace(i,2,"he or she");
            counter =counter+6;
        }
        if(charInText=='h' &&text[i-1]==' '&&text[i+1]=='i' &&text[i+2]=='m'&&text[i+3]==' '){
            text.replace(i,3,"him or her");
            counter =counter+6;
        }

        if(charInText=='h' &&text[i-1]==' '&&text[i+1]=='i' &&text[i+2]=='m'&&(text[i+3]==' '||text[i+3]=='.'|| text[i+3]==',')){
            text.replace(i,3,"him or her");
            counter =counter+6;
        }

    }

   return text;

}
int main() {



    string text="See an adviser and talk to him. He will guide you.";
    cout<<function1(text);


}
