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
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define ins insert

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;

void solve()
{
    int n, m, tmp;
    cin >> n >> m;
    vl ar[n];
    int lastVal = -1, maxUnsortedRow = 0, tmpUnsortedRow = 0;
    bool isSorted = true;
    pi unsortedPairRows1 = {-1,-1};
    pi unsortedPairRows = {-1,-1};

    F0R(i, n)
    {
        lastVal = -1;
        tmpUnsortedRow = 0;
        F0R(j, m)
        {
            cin >> tmp;
            ar[i].pb(tmp);
            if (tmp < lastVal && lastVal != -1){
                isSorted = false, tmpUnsortedRow++;
               if(unsortedPairRows1.ff == -1 && unsortedPairRows1.ss == -1){ 
                unsortedPairRows1.ff = j;
                }
               else{ unsortedPairRows1.ss = j;}
            }
            lastVal = tmp;
        }
        if(tmpUnsortedRow>0) maxUnsortedRow++;
    }
if(isSorted == true){
    cout << "1 1\n";
    return;
}else if(maxUnsortedRow > 2){
    cout <<"-1\n";
    return;
}

F0R(i,n){
        swap(ar[i][unsortedPairRows1.ff],ar[i][unsortedPairRows.ss]);
}
F0R(i,n){
    if(!is_sorted(all(ar[i]))){
        cout << "-1\n";
    }
}
cout << unsortedPairRows1.ff << " "<< unsortedPairRows1.ss << endl;


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
