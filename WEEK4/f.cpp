#include <iostream>
#include <algorithm>
#include <vector>
#define ull long long
using namespace std;

ull* get_digits(ull x)
{
    ull* s = new ull[10];
       
    for (int i = 0; i < 10; i++)
    {
        s[i] = 0;
    }
    while (x != 0)
    {
        s[x % 10] += 1;
        x /= 10;
    }
    return s;
}

struct p
{
    ull x;
    ull y;  
};

bool comp(p x, p y)
{   
    if (x.x < y.x)
        return true;
    else if (x.x == y.x)
        if (x.y < y.y)
            return true;
    return false;
}

int main()
{

    ull A, B;
    cin >> A >> B;
    vector<p> ans;
    for (ull i = A; i <= B; i++)
    {
        for (ull j = i + 1; j <= B; j++)
        {
            if (i * j > B)
                break;

            auto digI = get_digits(i);
            auto digJ = get_digits(j);
            auto digij = get_digits(i * j);
            bool check = 1;
            for (int k = 0; k < 10; k++)
            {
                if (digI[k] + digJ[k] != digij[k])
                {
                    check = 0;
                    break;
                }
            }
            
            if (check)
            {
                ans.push_back(p{i, j});
            }
            delete digI;
            delete digij;
            delete digJ;
        }
    }
    sort(ans.begin(),ans.end(),comp);   
    cout << ans.size() << " digit-preserving pair(s)" << endl;
    for (auto i : ans)
    {
        cout << "x = " << i.x << ", y = " << i.y << ", xy = " << i.x * i.y << endl;
    }
    

    return 0;
}