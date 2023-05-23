#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
const ll limit = 1e5 + 100;
    vector<ll> ar;
void solve(){
    ll n, in, m;
    cin >> n >> m;
    vector<set<ll>> nums(n + 1);
    cout << "yo\n";
    for(int i = 0; i < n;i++) cin >> in, ar.push_back(in);

    for(int i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        nums[a].insert(b);
        nums[b].insert(a);
    }
    ll l = 1, ans = 0;
    for(int i = 0; i < n; i++){
        while(nums[ar[i]].lower_bound(l) != nums[ar[i]].end() && *nums[ar[i]].lower_bound(l) <= i)
            l++;
        ans += i - l + 1;
    }
    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    cin >> t;
    while(t--)
        solve();
}
