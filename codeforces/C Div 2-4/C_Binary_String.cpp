#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define deb(x) cout << #x << " " << x << endl;
#else
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
#define ff first
#define ss second
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

void solve()
{
    string s;
    cin >> s;
    int zc = 0, oc = 0, zc1, oc1;
    F0R(i, (int)s.length())
    if (s[i] == '0')
        zc++;

    oc = s.length() - zc;
    zc1 = zc, oc1 = oc;

    int l = 0, r = s.length() - 1, zdc = 0, odc = 0, ci = 0;
    bool fsi = true, left = true;
    while (odc != zc && zc != 0 && l < r)
    {
        if (s[l] == '0')
            zc--, l++;
        else if (s[r] == '0')
            zc--, r--;
        else{
            if(ci == 0) fsi = true;
            if(fsi){
                for(int i = l + 1; i < r; i++){
                if(s[i] == '0'){
                    // ci = i;
                    // deb(ci);
                  if(i -l > r-i){
                     left = false;
                     ci = i - l;
                  }else ci = r - i, left = true;
                }
            }
            fsi = false;
            }
            if(left)
            l++;
            else r--;

            odc++, ci--;
        }
    }
    // l = 0, r = s.length() - 1;
    // int zdc1 = 0, odc1 = 0;
    // while (odc1 != zc1 && zc1 != 0 && l <= r)
    // {
    //     if (s[l] == '0')
    //         zc1--, l++;
    //     else if (s[r] == '0')
    //         zc1--, r--;
    //     else
    //         r--, odc1++;
    // }
    // cout << min(max(zc, odc), max(zc1, odc1)) << endl;
    // deb(zc);
    // deb(odc);
    cout << min(zc, odc) << endl;
}

int32_t main()
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
