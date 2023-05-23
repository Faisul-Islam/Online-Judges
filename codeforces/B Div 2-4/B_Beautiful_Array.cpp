#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define deb(x) cout << #x << " " << x << endl;
#else
#endif

typedef long long ll;
typedef unsigned long long ull;
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
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define ins insert

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
// 1000000000000000000
// 1000000000000000000
void solve()
{
   ull n, k , b , s; cin >> n >> k >> b >> s;
   vl ar;
   ull md = s;
   ull sm = 0;
   int cntr = 0;
    ull tp = 0;

   for(int i = 0; i < n; i++){
       ull tmp = (k * b);
    //    deb((sm + tmp));
    tp = sm + tmp;
    //    deb(tp);
       if(tp <= md){
        if(cntr == n) break;
                 ar.pb(tmp);
                 sm += tmp;
                 s-= sm;
                 cntr++;
       }else{
        ll  rem = s / k;
        // deb(sm);
                if(rem > k ||( rem == 0  && s <= 0)){
            cout << -1 << endl;
            return;
        }
        for(int j = i; j < n; j++){
            ar.pb(rem);
                 sm += rem;
        }
            // deb(sm);

        if(md % k != 0){
            ar[ar.size()-1] += (md % k);
                 sm += (md % k);
        }

        break;
       }
   }
//    deb(sm);
   if( k* b > s || sm != s){
    cout << -1 << endl;
   }else{
    for(int i = 0; i < ar.size(); i++){
        cout << ar[i] << " ";
    }
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
