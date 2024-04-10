#include <iostream>
#include <queue>
#define pii pair<int, int>

using namespace std;

struct Point
{
    int px;
    int py;
    bool visited;
    bool water;
};

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void build(int x, int y, Point **dsu, int **map)
{
    // cout << "now H " << map[x][y] << endl;
    queue<pii> bfs;
    bfs.push({x, y});
    while (!bfs.empty())
    {
        pii now = bfs.front();
        // cout << now.first << " " << now.second << endl;
        bfs.pop();
        for (int i = 0; i < 4; i++)
        {
            int ii = dx[i];
            int jj = dy[i];
            if (map[now.first + ii][now.second + jj] == map[now.first][now.second] && !dsu[now.first + ii][now.second + jj].visited)
            {
                bfs.push({now.first + ii, now.second + jj});
                dsu[now.first + ii][now.second + jj].px = x;
                dsu[now.first + ii][now.second + jj].py = y;
                dsu[now.first + ii][now.second + jj].visited = 1;
            }
        }
    }
}

int main()
{
    int x, y;
    cin >> y >> x;
    int **map = new int *[x + 2];

    for (int i = 0; i < x + 2; i++)
    {
        map[i] = new int[y + 2];
        for (int j = 0; j < y + 2; j++)
            map[i][j] = 1000;
    }
    for (int i = 1; i < x + 1; i++)
    {
        for (int j = 1; j < y + 1; j++)
        {
            cin >> map[i][j];
        }
    }

    Point **dsu = new Point *[x + 2];
    for (int i = 1; i < x + 1; i++)
    {
        dsu[i] = new Point[y + 2];
        for (int j = 1; j < y + 1; j++)
        {
            dsu[i][j] = {i, j, 0, 1};
        }
    }

    for (int i = 1; i < x + 1; i++)
    {
        for (int j = 1; j < y + 1; j++)
        {
            if (!dsu[i][j].visited)
            {
                dsu[i][j].visited = 1;
                build(i, j, dsu, map);
            }
        }
    }

    for (int i = 1; i < x + 1; i++)
    {
        for (int j = 1; j < y + 1; j++)
        {
            bool flag = 0;
            for (int k = 0; k < 4; k++)
            {
                int ii = dx[k];
                int jj = dy[k];
                // cout << " neiH " << map[ii + i][j + jj] << " " << endl;
                if (map[i + ii][j + jj] < map[i][j])
                {
                    // cout << i << " " << j << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                dsu[dsu[i][j].px][dsu[i][j].py].water = 0;
            }
        }
    }
    int ans = 0;
    // cout << "ans" << endl;
    for (int i = 1; i < x + 1; i++)
    {
        for (int j = 1; j < y + 1; j++)
        {
            if (dsu[dsu[i][j].px][dsu[i][j].py].water)
            {
                // cout << i << " " << j << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}