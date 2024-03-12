#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 1; i <= N; i++){
        v.push_back(i);
    }
    for (auto i:v){
        cout << i << " ";
    }
    cout << "\n";
    while (next_permutation(v.begin(), v.end())){
        for (auto i:v){
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}