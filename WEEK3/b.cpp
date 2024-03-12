#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '<')
        {
            ans.pop_back();
        }
        else
        {
            ans += s[i];
        }
    }

    cout << ans;

    return 0;
}