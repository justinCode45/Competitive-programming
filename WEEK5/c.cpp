#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> force[n + 1];
    vector<int> nonforce[n + 1];
    for (int iii = 0; iii < m; iii++)
    {
        int a, b;
        cin >> a >> b;
        if (a > 0)
        {
            nonforce[a].push_back(b);
        }
        else if (a < 0)
        {
            force[-a].push_back(b);
        }
    }

    bool visited[n + 1];
    for (auto &i : visited)
        i = 0;

    int ans = 0;
    stack<int> mainChain;
    vector<int> buggy;
    mainChain.push(1);
    visited[1] = 1;
    while (!mainChain.empty())
    {
        int now = mainChain.top();
        mainChain.pop();
        // cout << now << endl;

        for (auto i : nonforce[now])
        {
            if (!visited[i])
            {
                buggy.push_back(i);
            }
        }

        if (force[now].size() == 0)
        {
            ans++;
            break;
        }

        for (auto i : force[now])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                mainChain.push(i);
            }
        }
    }

    for (auto i : buggy)
    {
        if (visited[i])
            continue;
        visited[i] = 1;
        if (force[i].size() == 0)
        {
            ans++;
            continue;
        }
        stack<int> chain;
        chain.push(i);
        while (!chain.empty())
        {
            int now = chain.top();
            chain.pop();
            if (force[now].size() == 0)
            {
                ans++;
                break;
            }

            for (auto i : force[now])
            {
                if (!visited[i])
                {
                    visited[i] = 1;
                    chain.push(i);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}