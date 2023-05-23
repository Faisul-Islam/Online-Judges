#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
            vector<int> q;
    while (t--)
    {
        int n, m, b;

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            q.push_back(val);
        }

        cin >> m;
        long long cnt = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> b;
            cnt += b;
        }

        //cout << cnt<< "size" << endl;
        cout << q[cnt % q.size()] << endl;
        q.clear();
    }

    return 0;
}
