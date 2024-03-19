#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#define ull unsigned long long
using namespace std;

ull fx[100][100];

ull c, d;
ull a[20];
ull b[20];
ull abSize;

ull dp(int x, int y)
{
    if (x <= 0 || y <= 0)
        return d;
    if (fx[x][y] != 0)
        return fx[x][y];

    for (int i = 0; i < abSize; i++)
    {
        fx[x][y] += dp(x - a[i], y - b[i]);
    }
    fx[x][y] += c;
    return fx[x][y];
}

int main()
{

    int t;
    cin >> t;
    cin.ignore(100, '\n');
    while (t--)
    {
        string input;
        getline(cin, input);
        stringstream ss(input);
        abSize = 0;
        for (int i = 0;; i++)
        {
            ss >> a[i] >> b[i];
            if (ss.fail())
            break;
            abSize++;
        }
        c = a[abSize-1];
        d = b[abSize-1];
        abSize--;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        memset(fx, 0, sizeof(fx));
        while (1)
        {
            int x, y;
            ss >> x >> y;
            if (ss.fail())
                break;
            cout << dp(x, y) << endl;
        }
        cout << endl;
    }
    return 0;
}