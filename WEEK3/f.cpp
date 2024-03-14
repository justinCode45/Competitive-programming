#include <iostream>
#include <algorithm>
using namespace std;
struct Person
{
    int money;
    int time;
};

bool comparTime(Person a, Person b)
{
    return a.time < b.time;
}

int main()
{
    int N;
    int T;
    cin >> N >> T;
    Person p[T];
    for (int i = 0; i < N; i++)
    {
        cin >> p[i].money >> p[i].time;
    }
    sort(p,p+T,comparTime);

    

    return 0;
}