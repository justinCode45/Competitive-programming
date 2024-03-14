#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(100, '\n');
    while (n--)
    {
        list<char> ans;
        string input;
        getline(cin, input);

        auto it = ans.begin();

        for (int i = 0; i < input.length(); i++)
        {
            char c = input[i];

            if (c == '<' )
            {
                if (it != ans.begin())
                {
                    it--;
                    it = ans.erase(it);
                }
                continue;
            }
            if (c == '[')
            {
                it = ans.begin();
                continue;
            }
            if (c == ']')
            {
                it = ans.end();
                continue;
            }
            ans.insert(it, c);
        }

        for (auto i : ans)
        {
            cout << i;
        }
        cout << endl;
    }

    return 0;
}
