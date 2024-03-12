#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s, ans;
        cin >> s;
        int cur = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == '<')
            {
                
                cur--;
            }
            else if (s[j] == '[')
            {
                cur = 0;
            }
            else if (s[j] == ']')
            {
                cur = ans.length() - 1;
            }
            else
            {
                ans.insert(cur, 1, s[j]);
                cur++;
            }
        }
    }

    return 0;
}
