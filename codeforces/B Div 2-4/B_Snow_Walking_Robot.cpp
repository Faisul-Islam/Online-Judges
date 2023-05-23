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


#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define ins insert

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;



void solve()
{
 string s; cin >> s;
 string ans;
 map<char, int> charFreq;
  pi cl = {0,0};
  int L , R , U, D;
  L = R= U = D  = 0;
 F0R(i, s.length())
     charFreq[s[i]]++;

if(charFreq['L'] == 0 || charFreq['R'] == 0){
    charFreq['L'] = 0, charFreq['R'] = 0;
    if(charFreq['U'] == 0 || charFreq['D'] == 0){
        cout << "0\n";
        return;
    }else{       
        cout <<"2\nUD"<< endl;
    }
}else if(charFreq['U'] == 0 || charFreq['D'] == 0){
    charFreq['U'] = 0, charFreq['D'] = 0;
    if(charFreq['L'] == 0 || charFreq['R'] == 0){
        cout << "0\n";
        return;
    }else{
        cout <<"2\nLR"<< endl;
    }
}else{
        int mnLR = min(charFreq['L'], charFreq['R']),
        mnUD = min(charFreq['U'], charFreq['D']);

        cout << (2 * mnLR) + (2 * mnUD) << endl;
        F0R(i, mnLR) cout << 'R';
        F0R(i, mnUD) cout << 'U';
        F0R(i, mnLR) cout << 'L';
        F0R(i, mnUD) cout << 'D';
        cout << endl;
}
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
