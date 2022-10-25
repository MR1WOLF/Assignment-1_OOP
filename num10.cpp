#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string phishing_list[] = {"label", "invoice", "post", "document", "postal", "calculations", "copy", "fedex", "statment", "financial", "dhl", "usps", "8", "notification", "amazon", "personal", "warning", "paypal", "visa", "bank", "security", "offical", "urgent", "alert", "citibank", "atm", "confirm", "address", "telephone", "ebay"};
int phishing_points[] = {3, 3, 3, 3, 2, 2, 2, 2, 2, 1, 2, 3, 1, 2, 3, 3, 2, 1, 1, 2, 3, 3, 2, 2, 1, 1, 1, 2, 3, 1};
vector<string> result;
vector<string> showup;
vector<int> occurence;

int main()
{
    string word;
    ifstream input;
    string filename;

    //Enter the file name here
    cout << "Enter the file name: ";
    cin >> filename;
    //If the file does not have the .txt extension, add it
    if (filename.find(".txt") == string::npos)
    {
        filename += ".txt";
    }
    //Open the file
    input.open(filename);

    //add the words in the file to the vector
    while (!input.eof())
    {
        input >> word;
        result.push_back(word);
    }
    //add the phishing words to the vector
    for (int i = 0; i < 30; i++)
    {
        int count = 0;
        for (int j = 0; j < result.size(); j++)
        {
            if (phishing_list[i] == result[j])
            {
                count++;
            }
        }
        occurence.push_back(count);
    }
    //add the phishing words that appear in the file to the vector
    cout << "word"
         << "    "
         << "#"
         << "    "
         << "points" << endl;

    for (int i = 0; i < occurence.size(); i++)
    {
        if (occurence[i] != 0)
        {
            cout << phishing_list[i] << "    " << occurence[i] << "    " << occurence[i] * phishing_points[i] << endl;
        }
        else
        {
            continue;
        }
    }
    //print the total of points
    int sum = 0;
    for (int i = 0; i < occurence.size(); i++)
    {
        if (occurence[i] != 0)
        {
            sum += (occurence[i] * phishing_points[i]);
        }
        else
        {
            continue;
        }
    }
    cout << "The total points are : " << sum << endl;

    input.close();
    cout << "done!";
    return 0;
}
