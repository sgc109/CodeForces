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

int N;
ll A[100003];
string S;
int cnt[2];
ll mxs[100003], mns[100003];
multiset<ll> st;
int main(){
    
    fastio();
    memset(mxs,0xc3,sizeof(mxs));
    memset(mns,0x3c,sizeof(mns));
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < 5; i++) st.insert(A[i]);
    for(int i = 5; i <= N; i++){
        ll mx = *(--st.end());
        ll mn = *(st.begin());
        mxs[i - 1] = mx;
        mns[i - 1] = mn;
        if(i == N) break;
        st.erase(st.find(A[i - 5]));
        st.insert(A[i]);
    }
    ll lo = -infl, hi = infl;
    cin >> S;
    for(int i = 0; i < 4; i++) cnt[S[i] - '0']++;
    for(int i = 4; i <= N; i++) {
        if(cnt[0] == 0 && S[i] == '0') hi = min(hi, mns[i] - 1);
        else if(cnt[1] == 0 && S[i] == '1') lo = max(lo, mxs[i] + 1);
        if(i == N) break;
        cnt[S[i - 4] - '0']--;
        cnt[S[i] - '0']++;
    }
    if(lo == -infl) lo = -1e9;
    if(hi == infl) hi = 1e9;
    cout << lo << ' ' << hi << endl;
}
