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

ll N, K, A, B;
int main(){
    fastio();
    cin >> N >> K >> A >> B;
    if(N == 1) return !printf("0");
    if(K == 1) return !printf("%lld", (N - 1) * A);
    ll ans = 0;
    while(N > 1){
        if(N < K) {
            ans += (N - 1) * A;
            break;
        }
        if(N % K == 0){
            ans += min(B, (N - N / K) * A);
            N = N / K;
        }
        else {
            ans += (N - N / K * K) * A;
            N = N / K * K;
        }
    }
    cout << ans;
}