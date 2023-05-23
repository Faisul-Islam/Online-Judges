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

// Read statements slowly if WA
// Check for constraints if TLE
void solve()
{
    ll n;
    cin >> n;
    vl ar(n);
    bool one = false, zeros = false;
    ll zeroCount = 0, oneCount = 0, ans = 0;
    F0R(i, n)
    {
        cin >> ar[i];
        if (ar[i])
            one = true, oneCount++;
        if (!ar[i])
            zeros = true, zeroCount++;
    }
    // i<j  and ai>aj.
    //  i < j = ai > aj
    // 0 1 1 0 1 0
    if (!zeros)
    {
        cout << oneCount - 1 << endl;
    }
    else if (!one)
    {
        cout << zeroCount - 1 << endl;
    }
    else
    {
        ll zeroToDiscard = 0, oneToDiscard = 0;
        F0R(i, n)
        {
            if (ar[i])
                break;
            zeroToDiscard++;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (!ar[i])
                break;
            oneToDiscard++;
        }
        //  deb(zeroToDiscard);
        if (zeroToDiscard > oneToDiscard and zeroToDiscard != 0)
        {
            ar[0] = 1;
            // deb("zero");
            zeroCount--;
            F0R(i, n)
            {
                if (ar[i])
                    ans += zeroCount;
                else
                    zeroCount--;
            }
        }
        else if (oneToDiscard > oneToDiscard and !oneToDiscard != 0)
        {
            // deb("one");
            ar[n - 1] = 0;
            zeroCount++;
            F0R(i, n)
            {
                if (ar[i])
                    ans += zeroCount;
                else
                    zeroCount--;
            }
        }
        else
        {
            // deb("yo");
            if (zeroCount == oneCount)
            {
                if (ar[n - 1] == 1)
                {
                    ar[n - 1] = 0;
                    zeroCount++;
                }
                else if (ar[0] == 0)
                {
                    ar[0] = 1;
                    zeroCount--;
                }
                F0R(i, n)
                {
                    if (ar[i])
                        ans += zeroCount;
                    else
                        zeroCount--;
                }
            }
            else
            {
                if (oneToDiscard > zeroToDiscard)
                {
                    // deb(oneToDiscard);
                    ar[n - 1] = 0;
                    zeroCount++;
                }
                else if (zeroToDiscard > zeroToDiscard)
                {
                    ar[0] = 1;
                    oneCount--;
                }
                F0R(i, n)
                {
                    if (ar[i])
                        ans += zeroCount;
                    else
                        zeroCount--;
                }
            }
        }
        cout << ans << endl;
    }
    // deb(zeroCount);
    // F0R(i,n){
    //     if(ar[i]) ans += zeroCount;
    // }
    // cout << ans << endl;
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
