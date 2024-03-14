#include <iostream>

using namespace std;

const int dm[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dn[8] = {1, -1, 0, 1, -1, 0, 1, -1};

int main()
{
    int n, m;
    cin >> m >> n;
    bool map[m + 2][n + 2] = {};
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            char input;
            cin >> input;
            if (input == '.')
                map[i][j] = 0;
            else
                map[i][j] = 1;
        }
    }
    int ans = 0;

    // for (int i = 0; i < m + 2; i++)
    // {
    //     for (int j = 0; j < n + 2; j++)
    //     {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            
            // cout << i << " " << j << " " << ans << endl;
            if (!map[i][j])
                continue;

            int poM = i;
            int poN = j;
            while (1)
            {   
                map[poM][poN] = 0;
                bool non = 1;
                for (int k = 0; k < 8; k++)
                {
                    if (map[poM + dm[k]][poN + dn[k]])
                    {
                        non = 0;
                        poM += dm[k];
                        poN += dn[k];
                        map[poM][poN] = 0;
                    }
                }
                if (non)
                    break;
            }
            // cout << i << " " << j << endl;
            ans++;
        }
    }
    cout << ans;
    return 0;
}