#pragma GCC optimize("O3")
#pragma GCC target("sse4")
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
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define ins insert
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
// ALWAYS SIMULATE FULL TEST CASE
// DO CUSTOM TEST CASE CHECK, MIN & MAX CONSTRAINTS, 0,1 CONSTRAINTS
// Read statements slowly
void solve()
{
    ll n; cin >> n;

    char mat[n][n];
    map<char, int> freq;

    F0R(i,n)
    F0R(j,n) {
        cin >> mat[i][j];
        freq[mat[i][j]]++;
    }

    char letterOfX = mat[0][0],
         letterOfO = mat[0][1];

        int cntr = 0;
        bool yes = true;

         F0R(i,n){
            if(i < n/2){
            if(mat[i][cntr] != letterOfX or mat[i][n - cntr - 1] != letterOfX) yes = false;
              cntr++;
            }else if(i == n / 2){
                if(mat[i][n/2] != letterOfX ) yes = false;
                cntr--;
            }else{
                if(mat[i][cntr] != letterOfX or mat[i][n - cntr - 1] != letterOfX) yes = false;
                cntr--;
            }
            
         }
         if(!yes or freq[letterOfX] != (n * 2 - 1) or freq[letterOfX]+freq[letterOfO] != n * n or letterOfX == letterOfO or freq.size() != 2) NO;
         else YES;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(10);
    cin.exceptions(cin.failbit);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}
