#include <bits/stdc++.h>
#define pb push_back
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int N, K, M;
string words[100003];
ll cost[100003];
int grp[100003];
vector<int> grps[100003];
unordered_map<string, int> mp;
ll grpMin[100003];
int main(){
    fastio();
    cin >> N >> K >> M;
    for(int i = 0; i < N; i++) {
        cin >> words[i];
        mp[words[i]] = i;
    }
    for(int i = 0; i < N; i++) {
        cin >> cost[i];
    }
    for(int i = 0; i < K; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int id;
            cin >> id;
            grp[id - 1] = i;
            grps[i].pb(id - 1);
        }
    }
    for(int i = 0; i < K; i++){
        grpMin[i] = infl;
        for(int j = 0; j < grps[i].size(); j++){
            ll tmp = cost[grps[i][j]];
            grpMin[i] = min(grpMin[i], tmp);
        }
    }
    ll ans = 0;
    for(int i = 0; i < M; i++){
        string tmp;
        cin >> tmp;
        int id = mp[tmp];
        int grpId = grp[id];
        ans += grpMin[grpId];
    }
    cout << ans;
}
