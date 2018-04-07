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
ll c[33];
ll L;
int N;
int main(){
    fastio();
    cin >> N >> L;
    for(int i = 0; i < N; i++) cin >> c[i];
    for(int i = 1; i < N; i++){
        if(c[i] > 2 * c[i - 1]) c[i] = 2 * c[i - 1];
    }
    ll ans = infl;
    ll acc = 0;
    for(int i = N - 1; i >= 0; i--){
        ll amt = 1ll << i;
        ll cst = ((L + amt - 1) / amt) * c[i];
        ans = min(ans, acc + cst);
        acc += (L / amt) * c[i];
        L -= L / amt * amt;
    }
    cout << ans;
}
