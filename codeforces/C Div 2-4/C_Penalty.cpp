#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define deb(x) cout << #x << " " << x << endl;
#else
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
    string s;
    cin >> s;
    string team2s = s;
    int team1 = 0, team2 = 0, team1q = 0, team2q = 0;
    F0R(i, s.length())
    {
        if (!(i & 1))
        {
            if (s[i] == '?')
                s[i] = '1';
            if (team2s[i] == '?')
                team2s[i] = '1';
        }
        else
        {
            if (s[i] == '?')
                s[i] = '0';
            if (team2s[i] == '?')
                team2s[i] = '0';
        }
    }

    int tmp1 = 0, tmp2 = 0, team1Chance = 5, team2Chance = 5;
    F0R(i, s.length())
    {
        if (!(i & 1))
        {
            if (s[i] == '1')
                tmp1++;
            team1Chance--;
        }
        else
        {
            if (s[i] == '1')
                tmp2++;
            team2Chance--;
        }
        if (tmp1 > tmp2 + team2Chance)
        {
            team1 = i + 1;
            break;
        }
    }
    tmp1 = tmp2 = 0;
    team1Chance = team2Chance = 5;
    F0R(i, s.length())
    {
        if (!(i & 1))
        {
            if (team2s[i] == '1')
                tmp1++;
            team1Chance--;
        }
        else
        {
            if (team2s[i] == '1')
                tmp2++;
            team2Chance--;
        }
        if (tmp2 > tmp1 + team1Chance)
        {
            team2 = i + 1;
            break;
        }
    }
    if (team1 != team2)
    {
        if (team1 < team2)
        {
            if (team1)
                cout << team1 << endl;
            else
                cout << team2 << endl;
        }
        else
        {
            if (team2)
                cout << team2 << endl;
            else
                cout << team1 << endl;
        }
    }
    else
    {
        if (team1 == 0 && team2 == 0)
            cout << 10 << endl;
        else
            cout << team1 << endl;
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
