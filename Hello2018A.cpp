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

ll n, m;
int main(){
    fastio();
    cin >> n >> m;
    ll tmp = 1;
    for(ll i = 0; i < n; i++) {
        if(tmp > m) return !printf("%lld", m);
        tmp *= 2;
    }
    cout << m % tmp;
}
