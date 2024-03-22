#include<bits/stdc++.h>
using namespace std;
// using vi = vector<int>;

#define int long long
//#define ll long long
#define pb push_back
#define vi vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define f first
#define s second

void solve(){
    int a,b;
    cin >> a >> b;
    
    vector<pair<int,int>> ans;
    
    rep(i,a,b + 1){
        rep(j,i+1,b + 1){
            int A[10] = {}, B[10] = {};
            
            if(i*j > b)break;
            
            int ti = i, tj = j, tij = i*j;
            
            while(ti/10 != 0){
                A[ti%10]++;
                ti/=10;
            }
            A[ti]++;
            
            while(tj/10 != 0){
                A[tj%10]++;
                tj/=10;
            }
            A[tj]++;
            
            while(tij/10 != 0){
                B[tij%10]++;
                tij/=10;
            }
            B[tij]++;
            
            int flag = 1;
            
            rep(k,0,10){
                if(A[k] != B[k]){
                    flag = 0;
                    break;
                }
            }
            
            if(flag){
                ans.pb({i,j});
            }
        }
    }
    
    cout << ans.size() << " digit-preserving pair(s)" << endl;
    
    sort(ans.begin(),ans.end());
    
    rep(i,0,ans.size()){
        cout << "x = " << ans[i].f << ", y = " << ans[i].s << ", xy = " << ans[i].f*ans[i].s << endl;
    }
    
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}