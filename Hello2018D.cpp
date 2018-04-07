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

struct event{
    int a, t, id;
    bool operator<(event& rhs) const{
        return t < rhs.t;
    }
};
int N;
ll T;
event es[200003];
vector<int> ids;
int possi(int k){
    int cnt = 0;
    ll t = 0;
    for(int i = 0; i < N; i++){
        if(cnt == k) break;
        if(k <= es[i].a) {
            ids.pb(es[i].id);
            t += es[i].t;
            cnt++;
        }
    }
    return cnt == k && t <= T;
}
int main(){
    fastio();
    cin >> N >> T;
    for(int i = 0; i < N; i++){
        int a, t;
        cin >> a >> t;
        es[i] = event{a, t, i}; 
    }
    sort(es, es + N);
    int lo = 0, hi = N + 1;
    while(lo < hi){
        int mid = lo + hi >> 1;
        if(possi(mid)) lo = mid + 1;
        else hi = mid;
        ids.clear();
    }
    int ans = lo - 1;
    possi(ans);
    cout << ans << endl;
    cout << ans << endl;
    for(int num : ids) cout << num + 1 << ' ';
}
