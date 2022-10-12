#include <iostream>
#include <vector>

using namespace std;

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

vector<string> split(string target, string delimiter)
{
    vector<string> list;
    target.append(delimiter);
    while (target.find(delimiter) && !target.empty())
    {
        int index = target.find(delimiter);
        list.push_back(target.substr(0, index));
        target.erase(0, index + 1);
    }
    return list;
}