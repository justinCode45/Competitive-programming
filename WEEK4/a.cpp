#include <iostream>

using namespace std;


int main()
{
    int n;
    cin >> n;
    int arr[n][n];
    int ans[n] = {};
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            ans[i] |= temp;
        }
    }

    for (auto i : ans)
        cout << i << " ";
    return 0;
}