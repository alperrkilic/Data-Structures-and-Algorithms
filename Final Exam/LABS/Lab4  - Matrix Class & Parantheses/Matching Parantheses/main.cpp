#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

bool check_parenthesis(string str, vector<pair<int, int>> &parenthesis_pairs)
{
    vector<char> parenthesis_count;
    vector<int> parenthesis_index;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            parenthesis_count.push_back(str[i]);
            parenthesis_index.push_back(i);
        }
        else if (str[i] == ')')
        {
            if (parenthesis_count.size() == 0)
            {
                return false;
            }
            if (parenthesis_count.back() != '(')
            {
                return false;
            }
            parenthesis_pairs.push_back(pair<int, int>(parenthesis_index.back(), i));
            parenthesis_index.pop_back();
            parenthesis_count.pop_back();
        }
    }

    if (parenthesis_count.size() == 0)
    {
        return true;
    }

    return false;
}

int main(void)
{
    vector<pair<int, int>> parenthesis_pairs;
    string str;
    bool is_match;

    cout << "Please enter the operation to find whether parenthesis match : ";
    getline(cin, str);

    is_match = check_parenthesis(str, parenthesis_pairs);

    if (is_match)
    {
        cout << "\nParenthesis match." << endl;
    }
    else
    {
        cout << "\nParenthesis don't match." << endl;
    }

    for (int i = 0; i < parenthesis_pairs.size(); i++)
    {
        cout << "( " << parenthesis_pairs[i].first << " , " << parenthesis_pairs[i].second << " )" << endl;
    }

    return 0;
}