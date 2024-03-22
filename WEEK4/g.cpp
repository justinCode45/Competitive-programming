#include <iostream>
#include <string>
#include <cmath>
// #define int long long
using namespace std;

int main()
{
    while (1)
    {
        int x;
        cin >> x;
        if (x == 0)
            break;
        string s, p;
        cin >> s >> p;
        string c;
        cin >> c;
        

        int d = (int)(pow(c.length(), 1.5) + x) % c.length();
        int kl[c.length()] = {};
        int pl[c.length()] = {};
        int sl[c.length()] = {};
        pl[d] = s.find(c[d]);
        sl[d] = s.find(p[pl[d]]);
        kl[d] = sl[d];
        for (int j = 0; j < c.length(); j++)
        {
            if (j == d)
                continue;
            kl[j] = s.find(c[j]);
        }
        for (int j = d - 1 ; j != d; )
        {
            if (j < 0)
                j = c.length()-1;
            if (j == d)
                continue;
            int ja1 = (j + 1 < c.length()) ? j + 1 : 0;
            pl[j] = sl[ja1] ^ kl[j];
            sl[j] = s.find(p[pl[j]]); 
            j--;
        }
        for (auto i : pl)
        {
            cout << p[i]  ;
        }
        cout << endl;
    }

    return 0;
}