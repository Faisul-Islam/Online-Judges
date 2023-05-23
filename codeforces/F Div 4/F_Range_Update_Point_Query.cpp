#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define deb(x) cout << #x << " " << x << endl;
#else
#define deb(x)
#endif

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



ll dgs(ll n)
{
    ll sum = 0;
    while (n) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

void updateBIT(ll BITree[], int n, ll index, ll val)
{
    index = index + 1;

    while (index <= n)
    {
        BITree[index] += val;
        index += index & (-index);
    }
}

ll* constructBITree(ll arr[], ll n)
{
    ll* BITree = new ll[n + 1];
    for (ll i = 1; i <= n; i++)
        BITree[i] = 0;

    for (ll i = 0; i < n; i++)
        updateBIT(BITree, n, i, arr[i]);

    return BITree;
}


ll getSum(ll BITree[], ll index)
{
    ll sum = 0; // Initialize result

    index = index + 1;

    while (index > 0)
    {
        sum += BITree[index];

        index -= index & (-index);
    }
    return sum;
}

void update(ll BITree[], ll l, ll r, ll n, ll val)
{
    updateBIT(BITree, n, l, val);

    updateBIT(BITree, n, r + 1, -val);
}

void print(ll ar[], ll val, ll x)
{
ll ans = ar[x];
    while (ans > 9 and val) {
        ans = dgs(ans);
        val--;
    }
    cout << ans << endl;
}
void solve()
{
    ll n, q; cin >> n >> q;
    ll ar[n + 1];

    F0R(i, n) {
        cin >> ar[i];
    }

    ll dne[n + 1];
    memset(dne, 0, sizeof(dne));

    ll* BITree = constructBITree(dne, n + 1);


    while (q--) {
        ll t; cin >> t;
        if (t == 1) {
            ll l, r; cin >> l >> r;
            l--;r--;
            update(BITree, l, r, n, 1);
        }
        else {
            ll x; cin >> x;
            x--;
            ll val = getSum(BITree, x);
            print(ar, val, x);
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