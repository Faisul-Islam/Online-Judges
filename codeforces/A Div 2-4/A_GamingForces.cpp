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
    ll n;
    cin >> n;
    vl arr(n);
    map<ll, ll> oc;
    F0R(i, n)
    {
        cin >> arr[i];
        oc[arr[i]]++;
    }

    sort(all(arr));
    ll ans = 0;
    for (auto &i : oc)
    {
        if (i.fi == 1)
        {
            ans += (i.se + 1) / 2;
        }
        else
        {
            ans += i.se;
        }
    }
    cout << ans << endl;
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
