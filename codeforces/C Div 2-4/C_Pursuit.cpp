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
    vl ar(n), ar2(n), eAr, mAr;
    F0R(i, n)
    cin >> ar[i];
    F0R(i, n)
    cin >> ar2[i];

    sort(all(ar), greater<>());
    sort(all(ar2), greater<>());

    ll cStages = n - floor(n / 4), ans = 0, prevCStages = (n/4);
    ll mySum = accumulate(ar.begin(), ar.begin() + cStages, 0),
       llyaSum = accumulate(ar2.begin(), ar2.begin() + cStages, 0);


    FOR(i, cStages, n)
        eAr.push_back(ar2[i]);
    F0R(i, cStages)
        mAr.push_back(ar[i]);

    sort(all(eAr));
    sort(all(mAr), greater<>());

    if (mySum >= llyaSum)
        cout << 0 << endl;
    else
    {
        while (mySum < llyaSum)
        {
            ans++;
            if((n+ans)/4 != prevCStages){
                if(!mAr.empty()) mySum -= mAr.back(), mAr.pop_back();
            }
            if (!eAr.empty())
                llyaSum += eAr.back(), eAr.pop_back();
            mySum += 100;
            prevCStages = (n+ans)/4;
        }
        cout << ans << endl;
    }
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