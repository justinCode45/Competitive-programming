#include <iostream>
#include <unordered_map>
#include <vector>
#define ull unsigned long long
using namespace std;

unordered_map<int, int> get_digits(ull x)
{
    unordered_map<int, int> s;
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

int main()
{

    ull A, B;
    cin >> A >> B;
    ull count = 0;
    vector<p> ans;
    for (ull i = A; i <= B; i++)
    {
        for (ull j = i + 1; j <= B; j++)
        {
            if (i * j >= B)
                break;

            auto digI = get_digits(i);
            auto digJ = get_digits(j);
            auto digij = get_digits(i * j);
            bool check = 1;
            for (int k = 0; k < 10; k++)
            {
                if (digI[k] + digJ[k] == digij[k])
                {
                    continue;
                }
                else
                {
                    check = 0;
                    break;
                }
            }
            if (check)
            {
                ans.push_back(p{i, j});
            }
        }
    }

    cout << ans.size() << " digit-preserving pair(s)" << endl;
    for (auto i : ans)
    {
        cout << "x = " << i.x << ", y = " << i.y << ", xy = " << i.x * i.y << endl;
    }
    

    return 0;
}