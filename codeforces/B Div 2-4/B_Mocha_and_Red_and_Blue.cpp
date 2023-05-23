#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define deb(x) cout << #x << " " << x << endl;
#else
// online submission
#endif

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template <class T>
bool ckmin(T &a, const T &b)
{
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b)
{
    return a < b ? a = b, 1 : 0;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
ll ar[51][51], arv[51][51];
bool flag;
ll t;
bool zero=true,one=false;
void solve()
{
 int n; cin >> n;
 vector<int> chk(n, 0);
 string s; cin >> s;

 int cnt = 0;
 char f_l;
 for(int i = 0; i < n; i++){
    if(s[i] == 'R' || s[i] == 'B') {f_l = s[i];break;}
    cnt++;
 }
 char odd, even;
 if(cnt & 1){
    if(f_l == 'R') odd = 'R', even = 'B';
    else odd = 'B', even = 'R';
 }else{
    if(f_l == 'R') odd = 'B', even = 'R';
    else odd = 'R', even = 'B';
 }

 for(int i = 0; i < cnt; i++){
    if(i & 1) s[i] = odd;
    else s[i] = even;
 }

 for(int i = 0; i < n; i++){
    if(s[i] != '?') {
        if(i> 1 && chk[i-1] == 1){
            if(s[i] == 'R') s[i-1] = 'B';
            else if(s[i] == 'B') s[i-1] = 'R';
        }
        continue;
    }
    else{
        if(i>0){
            if(s[i-1] == 'R') s[i] = 'B';
            else if(s[i-1] == 'B') s[i] = 'R';
        }
        chk[i] = 1;
    }
 }
//  if(s[0] == '?'){
//     if(s[1] )
//  }
     cout << s << endl;

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
