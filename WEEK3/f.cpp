#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct Person
{
    int money;
    int time;
};

bool compar(Person a, Person b)
{
    if (a.time == b.time)
        return a.money > b.money;
    return a.time < b.time;
}

int main()
{
    int N;
    int T;
    cin >> N >> T;
    Person p[N + 1];
    for (int i = 1; i <= N; i++)
    {
        cin >> p[i].money >> p[i].time;
    }
    p[0] = {0, 0};
    sort(p + 1, p + N + 1, compar);

    int dp[N + 1][T + 1];

    memset(dp, 0, sizeof(dp));

    int maxN = 0;
    for (int t = 1; t <= T; t++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (t - 1 <= p[i].time)
            {
                dp[i][t] = max(dp[i - 1][t], dp[i - 1][t - 1] + p[i].money);
            }

            maxN = max(maxN, dp[i][t]);
        }
    }

    cout << maxN << endl;

    return 0;
}