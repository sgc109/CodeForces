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

int N, K;
int A[103];
int main(){
    fastio();
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A, A + N);
    int ans = inf;
    for(int i = 0; i < N; i++){
        int id = lower_bound(A, A + N, A[i] + K + 1) - A;
        ans = min(ans, N - id + i);
    }
    cout << ans;
}