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
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define sz(x) (int)(x).size()
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define ins insert
#define debexec deb("exec")

// Constants
constexpr ll SZ = 2e5 + 7;
constexpr ll inf = 9e18;
constexpr ll mod = 1e9 + 7;

int modpow(int a, int b, int m = mod) {
    a = a % m; int ans = 1;
    while (b) {
        if (b & 1) { ans = (ans * a) % m; }
        b = b >> 1; a = (a * a) % m;
    }
    return ans;
}

// Inverse Mod (1 / a) % mod
int modinv(int a, int m = mod) { return modpow(a, m - 2, m); }
 
// Modular Arithematic
int modadd(int a, int b, int m = mod) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
int modsub(int a, int b, int m = mod) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
int modmul(int a, int b, int m = mod) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
int moddiv(int a, int b, int m = mod) { a = a % m; b = b % m; return (modmul(a, modinv(b, m), m) + m) % m; }

bool isKthBitSet(ll n, ll k) { return (n & (1ll << k)); }
int msbPosition(int n)
{
    int k = __builtin_clz(n);
    return 1 << (31 - k);
}
int nearest2sPower(int n){
   return pow(2, ceil(log(n)/log(2)));
}
int nearestSmallerEqual2sPower(int n){
   return pow(2, floor(log(n)/log(2)));
}

void solve(ll testCaseChecker)
{
    ll n,m; cin >> n >> m;
    string s, rev, midTmp;
    deque<string> left, middle, right;
    map<string, int> mp;
    vector<pair<string, int>> pp;
    F0R(i,n){
        cin >> s;
        rev = s;
        reverse(rev.begin(), rev.end());
        if(s == rev){
            pp.pb({s, i});
            if(mp[s] == 1){
                middle.push_front(s);
                middle.push_back(s);
                mp[s] = 0;
            }else{
                mp[s]++;
            }
        }else{
            if(mp[rev] == 1){
                left.push_front(s);
                right.pb(rev);
                mp[s] = 0;
                mp[rev] = 0;
            }else{
                mp[s]++;
            }
        }
    }
    string ans;

    for(auto &[k,v]: pp){
        if(mp[k] & 1){
            midTmp = k;
            break;
        }
    }
    for(auto &v: left) ans += v;
    for(int i = 0; i < sz(middle)/2; i++){
        ans += middle[i];
    }
    if(sz(midTmp)) ans += midTmp;
    for(int i = sz(middle)/2; i < sz(middle);i++){
        ans += middle[i];
    }
    for(auto &v: right) ans += v;
    cout << ans.size() << endl;
    cout << ans << endl;

}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(10);
    cin.exceptions(cin.failbit);

    int T = 1;
    // cin >> T;
    for(ll tcc = 1; tcc <= T; tcc++)
    {
        solve(tcc);
    }
}
