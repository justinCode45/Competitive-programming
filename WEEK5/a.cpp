#include <iostream>
#include <string>

using namespace std;
int *network;

int find(int x)
{
    if (network[x] == x)
        return x;
    return network[x] = find(network[x]);
}
void union_(int a, int b)
{
    int roota = find(a);
    int rootb = find(b);
    network[max(roota,rootb)] = min(roota,rootb);
}

int main()
{
    int N, M;
    cin >> N >> M;
    network = new int[N + 1];
    for (int i = 0; i < N + 1; ++i)
    {
        network[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        union_(a, b);
    }
    bool flag = 1;
    for (int i = 1; i < N + 1; i++)
    {
        if (find(i) != 1)
        {
            cout << i << endl;
            flag = 0;
        }
    }
    if (flag)
    {
        cout << "Connected";
    }
    return 0;
}