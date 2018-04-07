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

ll N;
bool isSqr(ll x){
    ll lo = 0, hi = 50;
    while(lo < hi){
        ll mid = lo + hi >> 1;
        if((1ll << mid) < x) lo = mid + 1;
        else if(x < (1ll << mid)) hi = mid;
        else return true;
    }
    return lo * lo == x;
}
ll go(ll x){
    if(!x) return 0;
    if(x == 2) return 1;
    int cnt = 0;
    ll tmp = x;
    while(x){
        cnt++;
        x >>= 1;
    }
    cnt--;
    x = tmp;
    if(isSqr(x)) return cnt * x / 2;
    return go(x - (1ll << cnt)) + go(1ll << cnt) + (1ll << cnt);
}
int main(){
    fastio();
    cin >> N;
    cout << go(N);
}
