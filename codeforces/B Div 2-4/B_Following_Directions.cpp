#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;

#define len(x) (int)(x).size()
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define ins insert

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)

void solve()
{
    ll n ;cin >> n;
    pair<ll,ll> coord = {0,0};
    string s; cin >> s;
    F0R(i,n){
        if(s[i] == 'U') coord.second += 1;
        else if(s[i] == 'D') coord.second -= 1;
        else if(s[i] == 'R') coord.first += 1;
        else if(s[i] == 'L') coord.first -= 1;
        if(coord.first == 1 and coord.second == 1){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
