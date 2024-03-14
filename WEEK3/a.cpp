#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{

    int n ;
    cin >> n;
    int h[n];
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    sort(h, h+n);
    
    int dp[n];

    for (int i = 0;i < n; i++)
    {
        dp[i] = h[i] + (n-i-1);
    }

    // for (int i = 0;i < n; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    int minma = *min_element(dp,dp+n);

    if (minma < n)
        cout << minma;
    else    
        cout << n;
    return 0;
}