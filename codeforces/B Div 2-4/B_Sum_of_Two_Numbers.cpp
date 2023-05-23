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

ll getSum(ll n)
{
    ll sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}
void solve()
{
    ll n; cin >> n;

    ll x = n / 2, y = n - (n / 2);
    // if(gets(n) == 1)
    if (abs(getSum(x) - getSum(y)) <= 1)
        cout << x << " " << y << endl;
    else {
        while (abs(getSum(x) - getSum(y)) > 1) {
            if (x % 2 == 0) {
                y += (x + 1) / 2;
                x /= 2;
            }
            else {
                x += (y + 1) / 2;
                y /= 2;
            }
        }

        cout << x << " " << y << endl;
    }

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
