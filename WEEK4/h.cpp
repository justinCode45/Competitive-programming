#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    cin >> input;

    int sample[26] = {};
    for (int i = 0; i < input.length(); i++)
    {
        sample[(int)(input[i] - 'a')] += 1;
        if (input.length() % (i + 1) != 0)
            continue;

        bool isAns = false;
        for (int j = i + 1; j < input.length(); j += (i + 1))
        {
            isAns = true;
            int ch[26] = {};
            for (int k = 0; k < (i + 1); k++)
            {
                ch[(int)(input[k+j] - 'a')] += 1;
            }
            for (int i = 0; i < 26; i++)
            {
                if (sample[i] != ch[i])
                {
                    isAns = false;
                    break;
                }
            }
            if(!isAns)
                break;
        }
        if (isAns)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << input[j];
            }
            return 0;
        }
    }
    cout << -1;
    return 0;
}