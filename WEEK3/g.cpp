#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, P;
    cin >> N >> M >> P;
    int crank[N];
    int back[M];
    for (int i = 0; i < N; i++)
        cin >> crank[i];
    for (int i = 0; i < M; i++)
        cin >> back[i];

    double arr[N * M];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            arr[i * M + j] = crank[i] / (double)back[j];

    sort(arr, arr + (M * N));

    for (int i = 0; i < (M * N) - 1; i++)
    {
        if ((int)(((arr[i + 1] - arr[i]) / arr[i]) * 100) > P)
        {
            cout << "Time to change gears!" << endl;
            return 0;
        }
    }

    cout << "Ride on!" << endl;

    return 0;
}