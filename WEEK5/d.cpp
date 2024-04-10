#include <iostream>
#include <cstring>
using namespace std;
#define endl '\n'

int *connection;
int *sz;

int root(int x)
{
    if (connection[x] == x)
        return x;
    return connection[x] = root(connection[x]);
}

void join(int a, int b)
{
    int roota = root(a);
    int rootb = root(b);
    if (sz[roota] < sz[rootb])
    {
        connection[roota] = rootb;
        sz[rootb] +=roota;
    }
    else
    {
        connection[rootb] = roota;
        sz[roota] +=rootb;
    }
}

int main()
{   
    cin.tie(0);
    ios_base::sync_with_stdio(0);
        
    int N, Q;
    cin >> N >> Q;
    connection = new int[N + 1];
    sz = new int[N + 1];
    for (int i = 0; i < N + 2; ++i)
    {
        connection[i] = i;
        sz[i] = 1;
    }
    while (Q--)
    {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == '?')
        {
            if (root(a) == root(b))
                cout << "yes" << endl;
                else
                cout << "no" << endl;
        }
        else if (op == '=')
        {
            join(a, b);
        }
    }

    return 0;
}