#include <iostream>
#define m 1000000000000000000
#include <cmath>
using namespace std;

unsigned long long f(int n)
{
    if (n == 0)
    {
        return 1;
    }
    unsigned long long ans = 1;
    while (n > 0)
    {
        ans *= n;
        n--;
    }
    return ans;
}

int main()
{
    int n;
    long double ans = 0;
    cin >> n;
    if (n > 60)
    {
        cout << "2.718281828459045";
        return 0;
    }
    for (int i = 0; i <= n; i++)
    {
        ans += 1.0 / f(i); 
    }
    cout.precision(18);
    cout.setf(ios::fixed);
    cout << ans ;
    

    return 0;
}