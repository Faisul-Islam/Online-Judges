#include <bits/stdc++.h>
using namespace std;
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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll alice = 0, bob = 0;
    ll ans = 0;
    bool flag = true;

    if((a == 0 and b == 0 and c == 0 and d) || (a == 0 and d == 0 and c == 0 and b) || (a == 0 and d == 0 and b == 0 and c)){
        cout << 1 << endl;
        return;
    }
    while (1)
    {
        if (a)
        {
            alice += a, bob += a;
            ans += a;
            a = 0;
        }
        else{
            if(a and b){
                ans += min(c,b);
                b -= min(c,b);
                c -= min(c,b);
                

            }
        }
    }
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
