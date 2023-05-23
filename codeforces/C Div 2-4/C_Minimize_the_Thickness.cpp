#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define deb(x) cout << #x << " " << x << endl;
#else
#define deb(x)
#endif
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define ins insert
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
// ALWAYS SIMULATE FULL TEST CASE
// DO CUSTOM TEST CASE CHECK, MIN & MAX CONSTRAINTS, 0,1 CONSTRAINTS
// Read statements slowly

//  this find div from GFG
void findDivisors(vl &ar, ll n)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                ar.pb(i);
            else
            {
                ar.pb(i);
                ar.pb(n / i);
            }
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    vl ar(n);

    F0R(i, n)
    {
        cin >> ar[i];
    }

    ll sm = accumulate(all(ar), 0L);

    vl divisors;
    findDivisors(divisors, sm);

    ll mxThik = n, sz = divisors.size();
 
    F0R(i, sz)
    {
        bool flag = false;

        ll mx = 0,tmpSm = 0, thickness = 0 , mxCount = 0, tmpCount = 0;

        F0R(j, n)
        {
            tmpSm += ar[j], thickness++, mxCount++;

            if (tmpSm > (sm / divisors[i]))
            {
                flag = true;
                break;
            }
            else if (tmpSm == (sm / divisors[i]))
                mx = max(mx,thickness), tmpSm = 0,thickness = 0;
    // deb(tmpSm);
    // deb(mxCount);
            
        }
    // deb(mxThik);

        if (flag == false)
            mxThik = min(mx, mxThik);
        
    }
    cout << mxThik << endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(10);
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
