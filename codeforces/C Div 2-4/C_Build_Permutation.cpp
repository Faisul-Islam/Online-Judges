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
vi squares;

void calculateSquares(){
   F0R(i,1e6){
     int sq = i * i;
     if(sq > 1e6) break;
     else squares.pb(sq);
   }
}

int findClosestSquare(int n){
    int diff = INT_MAX;
      F0R(i,1e5){
     if(abs(squares[i] - n) <= diff){
        diff = abs(squares[i] - n);
     }else{
        return i;
     }
   }
   return n;
}
void solve()
{
    int n; cin >> n;
    int currentClosestSquareIdx = findClosestSquare(n);
    //  deb(squares[currentClosestSquareIdx]);
    vi ar(n), ans(n);
    int ansCntr = 0;
    F0R(i,n) ar[i] = 0;

    for(int i = n - 1; i >=0; i--){
     if(ar[abs(squares[currentClosestSquareIdx] - i)] == 0 && abs(squares[currentClosestSquareIdx] - i) <= n-1){
        ans[i] = abs(squares[currentClosestSquareIdx] - i), ar[abs(squares[currentClosestSquareIdx] - i)] = 1;
     }else{
        currentClosestSquareIdx--;
        if(currentClosestSquareIdx == -1){
            cout << -1 << endl;
            return;
        }
        while(ar[abs(squares[currentClosestSquareIdx] - i)] != 0 or (currentClosestSquareIdx > 0 and abs(squares[currentClosestSquareIdx] - i) > n-1)){
        currentClosestSquareIdx--;
            if(currentClosestSquareIdx == -1){
            cout << -1 << endl;
            return;
        }
        }
        ans[i] = abs(squares[currentClosestSquareIdx] - i), ar[abs(squares[currentClosestSquareIdx] - i)] = 1;
     }
    }
    F0R(i,n) cout << ans[i] << " ";

    cout << endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(10);
    cin.exceptions(cin.failbit);
    calculateSquares();
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
