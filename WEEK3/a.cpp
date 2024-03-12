#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{

    int n ;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    int ans = 0;

    while (!h.empty())
    {
        int min_h = *h.begin();
        
        if (min_h <= h.size())
        {
            ans += 1 ;
            for (int i = 0; i < h.size(); i++)
            {
                h[i] -= 1;
                if (h[i] == 0)
                {
                    h.erase(h.begin() + i);
                    i--;
                }
            }
        }
        else
        {
            ans += h.size();
            break;
        }
    }
        

    cout << ans;

    return 0;
}