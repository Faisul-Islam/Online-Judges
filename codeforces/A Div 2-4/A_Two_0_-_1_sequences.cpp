// #pragma GCC optimize("O3")
// #pragma GCC target("sse4")

// #include <bits/stdc++.h>

// using namespace std;

// #ifndef ONLINE_JUDGE
// #define deb(x) cout << #x << " " << x << endl;
// #else
// // online submission
// #endif

// typedef long long ll;
// typedef long double ld;
// typedef complex<ld> cd;

// typedef pair<int, int> pi;
// typedef pair<ll, ll> pl;
// typedef pair<ld, ld> pd;

// typedef vector<int> vi;
// typedef vector<ld> vd;
// typedef vector<ll> vl;
// typedef vector<pi> vpi;
// typedef vector<pl> vpl;
// typedef vector<cd> vcd;


// #define FOR(i, a, b) for (int i = a; i < (b); i++)
// #define F0R(i, a) for (int i = 0; i < (a); i++)
// #define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
// #define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
// #define trav(a, x) for (auto &a : x)
// #define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

// #define sz(x) (int)(x).size()
// #define mp make_pair
// #define pb push_back
// #define ff first
// #define ss second
// #define lb lower_bound
// #define ub upper_bound
// #define all(x) x.begin(), x.end()
// #define YES cout<<"YES\n"
// #define NO cout<<"NO\n"
// #define ins insert

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// const int MOD = 1000000007;
// const char nl = '\n';
// const int MX = 100001;

// void solve()
// {
//  int n, m; cin >> n >> m;

//  vi a(n), b(m);

// char tmp;
//  for(int i = 0; i < n; i++){
//      cin >> tmp;
//      a[i] = tmp - '0';
//  }

//  for(int i = 0; i < m; i++){
//      cin >> tmp;
//      b[i] = tmp - '0';
//  }

//  bool yes = true;
//  int cPos = 0;
// //  deb("yes")
//  while((n - 1 - cPos) > (m - 1)){
//     if(b[0] == 0){
//       a[cPos+1] = min(a[cPos+1], a[cPos]);
//     }else if(b[0] == 1){
//       a[cPos+1] = max(a[cPos+1], a[cPos]);
//     }
//           cPos++;
//  }
//  int bCnt = 0;
// //  deb((a[cPos]!= b[bCnt]));
// //  deb(a[cPos]);
// //  deb(b[bCnt]);
//  for(int i = cPos; i < n; i++){
//     if(a[i] != b[bCnt]){
//         cout << "NO\n";
//         return;
//     }else bCnt++;
//  }
//          cout << "YES\n";
// }

// int32_t main()
// {
//     cin.tie(0)->sync_with_stdio(0);
//     cin.exceptions(cin.failbit);

//     int T = 1;
//     cin >> T;
//     while (T--)
//     {
//         solve();
//     }
// }
#include <bits/stdc++.h>
using namespace std;
 
 
void solve(){
	int a,b;
	cin >>a >> b;
	string s1,s2;
	cin >> s1 >> s2;
 
	if(s1[a-1] != s2[b-1]){
		cout << "NO" << endl;
		return;
	}else{
		while(s1.size() > s2.size()){
 
			if(s2[0] == '0'){
				s1[1] = min(s1[0],s1[1]);
				s1.erase(0,1);
			}
 
			if(s2[0] == '1'){
 
				s1[1] = max(s1[0],s1[1]);
				s1.erase(0,1);
			}
	}
 
	if(s1 == s2)
		cout << "YES" <<endl;
	else
		cout << "NO" << endl;
	}
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    // solve();
	int t;
	cin >> t;
 
	while(t--){
		solve();
	}
 
	return 0;
}