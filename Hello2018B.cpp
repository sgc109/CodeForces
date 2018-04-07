#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int N;
vector<int> G[1003];
int ans;
int deg[1003];
void dfs(int cur){
    int cnt = 0;
    for(int nxt : G[cur]){
        if(deg[nxt] == 0) cnt++;
        dfs(nxt);
    }
    if(deg[cur] && cnt < 3) ans = 0;
}
int main(){
    fastio();
    cin >> N;
    for(int i = 1; i <= N - 1; i++){
        int ch = i + 1;
        int p;
        cin >> p;
        deg[p]++;
        G[p].pb(ch);
    }
    ans = 1;
    dfs(1);
    if(!ans) cout << "No";
    else cout << "Yes";
}
