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
int ar[101][101];
void solve()
{
 string s; cin >>s ;
 if(s.length() == 1){
    cout << 1<<endl;
    return;
 }
 bool fo = false, f1 = false;
 int ans = 0, tmp_qc = 0, oC = 0, qC = 0;
 for(int i = 0;i < s.length();i++){
    if(s[0]=='0'){
                // deb("yo");
        cout << 1 << endl;
        return;
    }
    // 1 and no ?? before
    if(s[i] == '1' && tmp_qc == 0){
        f1 = true;
        oC++;
        continue;
        }
    else if(s[i] == '1' && tmp_qc != 0){
        oC++;
         tmp_qc = 0; f1 = true; } // after ?? comes 1
    else if(s[i] == '0' && tmp_qc == 0){
        oC++;
            fo = true;
        //  10
        cout << 2 << endl;
        return;
    }else if(s[i] == '0' && tmp_qc != 0){
        fo = true;
        if(f1)
            cout << tmp_qc+2 << endl;
        else
        cout << tmp_qc+1 << endl;
        
        return;
    }
    else if(s[i] == '?'){
                // deb("yo");
                qC++;
        tmp_qc++;
    }
 }
//  deb(tmp_qc);
if(oC>0 && qC==0) cout << 1 << endl;
else if(tmp_qc == 0) cout << 1 << endl;
 else if(oC>0 && tmp_qc>0) cout << tmp_qc+1 << endl;
 else cout<<tmp_qc << endl;
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