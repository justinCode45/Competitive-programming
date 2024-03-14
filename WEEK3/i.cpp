#include <iostream>
#include <list>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore(100, '\n');
    for (int i = 0; i < t; i++)
    {
        string ans = "";
        string buffer = "";
        string line;
        getline(cin, line);
        stringstream ss(line);
        char input;
        int after = 1;
        while (1)
        {
            ss >> input ;
            if (ss.fail())
                break;
            if (input == '[')
            {
                if (after)
                    ans = ans + buffer;
                else 
                    ans = buffer + ans;
                after = 0;
                buffer = "";
            }
            else if (input == ']')
            {
                if (after)
                    ans = ans + buffer;
                else 
                    ans = buffer + ans;
                after = 1;
                buffer = "";
            }
            else if (input == '<')
            {
                buffer.erase(buffer.length() - 1);
            }
            else
            {
                buffer += input;
            }
        }
        if (after)
            ans = ans + buffer;
        else 
            ans = buffer + ans;
        cout << ans << endl;

    }

    return 0;
}