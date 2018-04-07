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
int main(){
    fastio();
    cin >> N;
    if(N < 6) cout << -1 << '\n';
    else {
        cout << "1 2\n";
        cout << "2 3\n";
        cout << "2 4\n";
        cout << "3 5\n";
        cout << "3 6\n";
        for(int i = 0; i < N - 6; i++){
            cout << 2 << ' ' << i + 7 << '\n';
        }
    }
    for(int i = 2; i <= N; i++) {
        cout << 1 << ' ' << i << '\n';
    }
}
