/*  
     Problem 6 in Task 2 

     Done By " Ali Hegazy " ID : 20210248
*/
#include <iostream>
#include <fstream>
using namespace std;

void Cmp_word(ifstream &file1,ifstream &file2){                 // function for comparing char by char //
    int line_num1 = 1;
    int line_num2 = 1;
    int match = 0;
    int notmatch = 0;
    int numOfWords1 =0;
    int numOfWords2 =0;
    int counter1=0;
    string first_char;
    string second_char;
    string first_word;
    string second_word;
    while(!file1.eof()){
        file1>>first_word;
        numOfWords1++;
    }
    while(!file2.eof()){
        file2>>second_word;
        numOfWords2++;
    }

    file1.close();
    file2.close();
    file1.open("file1", ios::in);
    file2.open("file2", ios::in);

    while (!file1.eof() || !file2.eof()) {          // counting num of lines for each file //
        first_char = file1.get();
        second_char = file2.get();
        if (first_char == "\n") {   line_num1++; }
        if (second_char == "\n") {   line_num2++; }
    }

    file1.close();
    file2.close();
    file1.open("file1", ios::in);
    file2.open("file2", ios::in);

    while (!file1.eof() || !file2.eof()) {
        file1>>first_word;
        file2>>second_word;

        if(first_word==second_word){
            match++;
        }
        else{
            notmatch++;
            if(numOfWords2>numOfWords1){
                cout<<second_word<<endl;
                cout<<second_word;
                getline(file2,second_word);
                cout<<second_word;
            }
            else {
                cout<<first_word<<endl;
                cout<<first_word;
                getline(file1,first_word);
                cout<<first_word;
            }

            break;

        }
    }  if(notmatch==0){
        cout<<"Files are identical";
    }

    cout << "Match = " << match << endl;
    cout << "Not Match = " << notmatch << endl;
}


void Cmp_char(ifstream &file1,ifstream &file2) {                    // function for comparing char by char //

    int match = 0;
    int notmatch = 0;
    int line_num1 = 1;
    int line_num2 = 1;
    int counter1 = 0;
    int counter2 = 1;
    int numOfChar1=0;
    int numOfChar2=0;
    string first_char;
    string second_char;
    string line1;
    string line2;

    while(!file1.eof()){
        first_char=file1.get();
        numOfChar1++;
    }                                                           // function to count number of char in the files //
    while(!file2.eof()){
        second_char=file2.get();
        numOfChar2++;
    }

    file1.close();
    file2.close();
    file1.open("file1", ios::in);
    file2.open("file2", ios::in);

    while (!file1.eof() || !file2.eof()) {          // counting num of lines for each file //
        first_char = file1.get();
        second_char = file2.get();
        if (first_char == "\n") {   line_num1++; }
        if (second_char == "\n") {   line_num2++; }
    }

    file1.close();
    file2.close();
    file1.open("file1", ios::in);
    file2.open("file2", ios::in);

    while (!file1.eof() || !file2.eof()) {          // start of comparing //
        first_char = file1.get();
        second_char = file2.get();
        if(line_num1>line_num2){
            if (first_char == "\n" ) {   counter2++; }          // counter2 is the number where the lines differes//
        }
        else if(line_num1<line_num2){
            if (second_char == "\n" ) {   counter2++; }
        }
        else if(line_num1==line_num2){
            if(second_char== "\n")  {    counter2++; }

        }
        if (first_char == second_char) { match++; }
        else {
            notmatch++;
            break;
        }


    }
    //end of comparing .. now start of printing the different line//
    file1.close();
    file2.close();

    if (line_num1 > line_num2 ) {
        file1.open("file1", ios::in);
        while (getline(file1, line1)) {

            counter1++;                                 /* if file 1 has more content than file 2 get the different line and its number */

            if (counter1 == counter2 ) {
                cout << line1 << endl;
                cout << counter2;
            }

        }
    }
    else if (line_num2>line_num1)
    {
        file2.open("file2", ios::in);                   /* if file 2 has more content than file 1 get the different line and its number */
        while (getline(file2, line2)) {

            counter1++;
            if (counter1 == counter2) {
                cout << line2 << endl;
                cout<< counter2;
            }
        }

    }

    else if(line_num2==line_num1 &&notmatch>0 &&numOfChar2>numOfChar1 ){
        file2.open("file2", ios::in);
        while (getline(file2, line2)) {
            /* if both files has the same amount of lines check for indentical or not */
            counter1++;
            if (counter1 == counter2) {
                cout << line2 << endl;
                cout<< counter2;
            }
        }
    }
    else if(line_num2==line_num1 &&notmatch>0 &&numOfChar2<numOfChar1 ){
        file1.open("file1", ios::in);
        while (getline(file1, line1)) {

            counter1++;
            if (counter1 == counter2) {
                cout << line1 << endl;
                cout<< counter2;
            }
        }
    }

    else if(line_num2==line_num1&& notmatch==0){
        cout<<"Files are identical";
    }



}
int main(){

    ifstream file1("file1");
    ifstream file2("file2");
    Cmp_word(file1,file2);
    //Cmp_char(file1,file2);


}
