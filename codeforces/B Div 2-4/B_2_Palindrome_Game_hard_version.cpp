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
int ifZeroPos = -1;
bool rev = false;
bool isPalindrome(string S)
{
    for (int i = 0; i < S.length() / 2; i++)
    {

        if (S[i] != S[S.length() - i - 1])
        {
            if (S[i] == '0')
            {
                if (rev)
                    ifZeroPos = S.length() - i - 1;
                else
                    ifZeroPos = i;
            }
            else
            {
                if (rev)
                    ifZeroPos = i;
                else
                    ifZeroPos = S.length() - i - 1;
            }

            return false;
        }
    }
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    string s;
    char tmp;
    int zc = 0;

    F0R(i, n)
    {
        cin >> tmp;
        if (tmp == '0')
            zc++, ifZeroPos = i;
        s.pb(tmp);
    }
    // deb(ifZeroPos);
    bool pale = isPalindrome(s);
    
    int alice = 0, bob = 0, steps = 0;
 
 

    if (pale)
    {
        if ((zc & 1) == 0 || zc == 1)
            cout << "BOB\n";
        else if (zc & 1)
            cout << "ALICE\n";
        else
            cout << "DRAW\n";
    }
    else
    {
    int mid = n/2;
    F0R(i,mid){
        if (s[i] != s[n - i - 1])
        {
            s[i] = '1', s[n-i - 1] = '1';
            break;
        }
    }
    // zc--;
    if(isPalindrome(s) && zc != 1){
                if ((zc & 1) || zc != 1)
            cout << "BOB\n";
        else if ((zc & 1) == 1 || zc == 1)
            cout << "ALICE\n";
        else
            cout << "DRAW\n";
    }else{
        // deb(s);
               if ((zc & 1) == 0 || zc == 1)
            cout << "ALICE\n";
        else if (zc & 1)
            cout << "BOB\n";
        else
            cout << "DRAW\n";
    }

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
