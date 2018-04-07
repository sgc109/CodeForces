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
string S;
int main(){
    fastio();
    cin >> N >> K >> S;
    string chs = "";
    for(int i = 0; i < N; i++) chs += S[i];
    sort(all(chs));
    if(N < K) {
        cout << S;
        for(int i = 0; i < K - N; i++) cout << chs[0];
        return 0;
    }
    if(S[K - 1] == chs.back()){
        int pos = K - 1;
        while(pos >= 0 && S[pos] == chs.back()) pos--;
        assert(pos >= 0);
        for(int i = 0; i < pos; i++) cout << S[i];
        cout << chs[upper_bound(all(chs), S[pos]) - chs.begin()];
        for(int i = pos + 1; i < K; i++) cout << chs[0];
        return 0;
    }
    for(int i = 0; i < K - 1; i++) cout << S[i];
    cout << chs[upper_bound(all(chs), S[K - 1]) - chs.begin()];
}
