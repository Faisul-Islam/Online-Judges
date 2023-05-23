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
bool ispal(string str)
{
    string temp = str;
    reverse(all(str));
    if (str == temp)
        return true;
    else
        return false;
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    string s;
    cin >> s;

    ll len = s.length();
    int zeroCount = 0, oneCount = 0, questionCount = 0;

    F0R(i, len)
    {
        if (s[i] == '0')
            zeroCount++;
        else if (s[i] == '1')
            oneCount++;
        else if (s[i] == '?')
            questionCount++;
    }

    F0R(i, (len / 2))
    {
        if (((s[i] == '1' && s[len - i - 1] == '?') || (s[i] == '?' && s[len - i - 1] == '1')) && oneCount < b)
            s[i] = s[len - i - 1] = '1', oneCount++, questionCount--;
        else if (((s[i] == '0' && s[len - i - 1] == '?') || (s[i] == '?' && s[len - i - 1] == '0')) && zeroCount < a)
            s[i] = s[len - i - 1] = '0', zeroCount++, questionCount--;
        else if ((s[i] == '?' && s[len - i - 1] == '?') && (oneCount < b || zeroCount < a))
        {
            if (a - zeroCount >= 2)
                s[i] = s[len - i - 1] = '0', zeroCount += 2, questionCount -= 2;
            else if (b - oneCount >= 2)
                s[i] = s[len - i - 1] = '1', oneCount += 2, questionCount -= 2;
            else
            {
                cout << -1 << endl;
                return;
            }
        }
        else if (s[i] != s[len - i - 1] && (s[i] != '?' && s[len - i - 1] != '?'))
        {
            cout << -1 << endl;
            return;
        }
    }

    if (len & 1)
    {
        if (s[len / 2] == '?')
        {
            if (oneCount < b)
                s[len / 2] = '1', oneCount++, questionCount--;
            else if (zeroCount < a)
                s[len / 2] = '0', zeroCount++, questionCount--;
            else
            {
                cout << -1 << endl;
                return;
            }
        }
    }

    if (zeroCount == a && oneCount == b && questionCount == 0 && ispal(s))
        cout << s << endl;
    else
        cout << -1 << endl;
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
