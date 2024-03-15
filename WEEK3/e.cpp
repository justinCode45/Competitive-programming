#include <queue>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<long long, vector<long long>, greater<long long>> q;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            q.push(temp);
        }

        int ans = 0;
        // if (n == 1)
        // {
        //     cout << q.top() << endl;
        //     continue;
        // }
        while (q.size() != 1)
        {
            long long a = q.top();
            q.pop();
            long long b = q.top();
            q.pop();
            ans += a;   
            ans += b;
            // if (q.size() != 0)
            q.push(a + b);
        }
        cout << ans <<endl;
    }

    return 0;
}