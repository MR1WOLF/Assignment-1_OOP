#include <iostream>
#include <vector>

using namespace std;
// Function overloaded to print the vector
ostream &operator<<(ostream &os, const vector<string> list)
{
    for (int i = 0; i < list.size(); i++)
    {
        os << list.at(i) << " ";
    }
    os << endl;
    os << list.size();
    return os;
}

vector<string> split(string target, string delimiter);
int main()
{

    cout << split("nooooooor,jamal,f,1322", ",");
    return 0;
}
// Function to split the string
vector<string> split(string target, string delimiter)
{
    vector<string> list;
    target.append(delimiter); // Append the delimiter to the end of the string
    while (target.find(delimiter) && !target.empty())
    {
        int index = target.find(delimiter); // Find the index of the delimiter
        list.push_back(target.substr(0, index)); // Push the substring to the vector but not included the delimiter
        target.erase(0, index + 1);// Erase the substring from the string
    }
    return list;
}
