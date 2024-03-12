#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#define ull unsigned long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

bool ligel(char in)
{
    if (in <= '9' && in >= '0')
        return true;
    if (in >= 'a' && in <= 'f')
        return true;
    if (in >= 'A' && in <= 'F')
        return true;
    return false;
}

int toInt(char in)
{
    if (in <= '9' && in >= '0')
        return in - '0';
    if (in >= 'a' && in <= 'f')
        return (in - 'a') + 10;
    if (in >= 'A' && in <= 'F')
        return (in - 'A') + 10;
    return 0;
}



void praser(string x16)
{
    cout << x16 << " ";
    ull ans = 0;
    int power = 0;
    for (int i = x16.length() - 1; i >= 2 ; i--)
    {
        ull a = toInt(x16[i]);
        ans += a * pow(16, power);
        power++;
    }
    cout << ans << endl;
}


int main()
{
    while (1)
    {
        string s;
        getline(cin, s);
        if(cin.eof())break;
        int state = 0;
        string buffer = "";

        for (int i = 0; i < s.length() ; i++)
        {
            // cout << state << endl;
            if ((s[i] == 'X' || s[i] == 'x' )&& i > 0 && s[i-1] == '0')
            // if (s[i] == '0' && state == 0)
            {
                // if (i>0 && s[i+1] == 'x' || s[i+1] == 'X')
                {
                    state = 2; 
                    buffer += s[i-1];
                    buffer += s[i];
                    // i += 1;
                }
            }
            else if (state == 2)
            {
                if (ligel(s[i]))
                    buffer += s[i];
                else
                {
                    state = 0;
                    praser(buffer);
                    buffer = "";
                }
            }
        }
        if (state == 2) 
        {
            praser(buffer);
        }
    }

       return 0;
}