#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;

#define len(x) (int)(x).size()
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define ins insert

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)

void solve()
{
    ll n; cin >> n;
    vl ar(n);
    F0R(i, n) {
        cin >> ar[i];
    }
    F0R(i, n - 1) {
        if (ar[i] <= 0 and ar[i + 1] <= 0) {
            ar[i] = abs(ar[i]);
            ar[i + 1] = abs(ar[i + 1]);
        }
        else if (ar[i] <= 0 and ar[i + 1]) {
            if (abs(ar[i]) > ar[i + 1]) {
                ar[i] *= -1;
                ar[i + 1] *= -1;
            }
        }
        else if (ar[i] and ar[i + 1] <= 0) {
            if (ar[i] < abs(ar[i + 1])) {
                ar[i] *= -1;
                ar[i + 1] *= -1;
            }
        }
    }
        F0R(i, n - 1) {
        if (ar[i] <= 0 and ar[i + 1] <= 0) {
            ar[i] = abs(ar[i]);
            ar[i + 1] = abs(ar[i + 1]);
        }
        else if (ar[i] <= 0 and ar[i + 1]) {
            if (abs(ar[i]) > ar[i + 1]) {
                ar[i] *= -1;
                ar[i + 1] *= -1;
            }
        }
        else if (ar[i] and ar[i + 1] <= 0) {
            if (ar[i] < abs(ar[i + 1])) {
                ar[i] *= -1;
                ar[i + 1] *= -1;
            }
        }
    }
    cout << accumulate(all(ar), 0ll) << endl;
}

int main()
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
