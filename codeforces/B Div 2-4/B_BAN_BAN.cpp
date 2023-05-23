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
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define ins insert
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 1e5;
// ALWAYS SIMULATE FULL TEST CASE
// DO CUSTOM TEST CASE CHECK, MIN & MAX CONSTRAINTS, 0,1 CONSTRAINTS

// Read statements slowly if WA
// Check for constraints if TLE
bool flgs[MX+1];
void pre(){
    for(int i = 2; i <= MX; i+=3){
        flgs[i] = 1;
    }
}
void solve()
{
    ll n; cin >>n;
    // B1NB2NBANBANBAN2A1

    // banbanbanbanban
    // b1nb2nb3nba32a1
    // banbanbanban
    // b1nb2nb332a1
    

    // B
    // BNNBBNAAA
    // BNNBAA
        // string s;
        // F0R(i, n){
        //    s.pb('B'),s.pb('A'), s.pb('N');
        // }
    
    if(n & 1){
       if(n == 1){
        cout << 1 << endl;
        cout << "1 2" << endl;
       }else{
        cout << (n+1 / 2)  << endl;
       ll cntr = 0, l = 2, r = n*3;
        while(cntr != (n/2)+1){
            cout << l << " " << r << endl;
            l += 3;
            if(flgs[r-1]) r-=2;
            else r--;
            cntr++;
        }
       }
    }else{
        if(n == 2){
        cout << 1 << endl;
        cout << "2 6" << endl;
       }else{
        cout << (n/2)+1 << endl;
        ll cntr = 0, l = 2, r = n*3;

        while(cntr != (n/2)){
            cout << l << " " << r << endl;
            l += 3;
            if(flgs[r-1]) r-=2;
            else r--;
            cntr++;
        }
       }
    }
    //  cout << s << endl;

}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(10);
    cin.exceptions(cin.failbit);
    pre();
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
