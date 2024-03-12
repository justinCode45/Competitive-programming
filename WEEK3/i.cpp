#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin.ignore(100,'\n');
    getline(cin,s);

    stack<char> deli;
    int ans_index = -1;

    for (int i = 0; i < s.length(); i++)
    {
        
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            deli.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (deli.empty())
            {
                ans_index = i;
                break;
            }
            char top = deli.top();
            deli.pop();        
            if (top == '(' && s[i] == ')')
            {
                continue;
            }
            if (top == '[' && s[i] == ']')
            {
                continue;
            }
            if (top == '{' && s[i] == '}')
            {
                continue;
            }

            ans_index = i;
            break;
        }
    }

    if (ans_index != -1)
    {
        cout << s[ans_index] << " " << ans_index;
    }
    else
    {
        cout << "ok so far";
    }


    return 0;
}