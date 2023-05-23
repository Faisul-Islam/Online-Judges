#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define deb(x) cout << #x << " " << x << endl;
#else
// online submission
#endif

typedef long long ll;

template <class T>
bool ckmin(T &a, const T &b)
{
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b)
{
    return a < b ? a = b, 1 : 0;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
ll m, n;
const int N = 1e6 + 10;
vector<int> pos(N);

void solve()
{
    cin >> n;
    vector<int> ar(n + 1);
    ar[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
        ar[i] = ar[i] + ar[i - 1];
        for (int j = ar[i - 1] + 1; j <= ar[i]; j++)
        {
            pos[j] = i;
        }
    }

    ll m;
    cin >> m;
    vector<int> ar2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> ar2[i];
    }

    for (int i = 0; i < m; i++)
    {
        cout << pos[ar2[i]] << endl;
    }
}

int main()
{

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}
