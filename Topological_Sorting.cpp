#include <bits/stdc++.h>
#define ll long long
#define li long
#define cn(n) cin >> n
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define ct(c) cout << c << endl
#define fr(dt, a, b) for (dt i = a; i < b; i++)
#define in(a, n) \
    fr(ll, 0, n) { cn(a[i]); }
#define out(a, n)                         \
    fr(ll, 0, n) { cout << a[i] << " "; } \
    cout << endl;
#define X ct('X')
#define sort(a) sort(a.begin(), a.end());
#define vin(a, n)    \
    vector<ll> a(n); \
    in(a, n);
const int MOD = 1e9 + 7;
using namespace std;
vector<vector<int>> ad(100001);
vector<int> vis(100001, 0);
vector<int> f(100001, 0);

void solve()
{
    // Your code here
    int n, m;
    cin >> n >> m;
    vector<int> res;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ad[u].push_back(v);
        f[v]++;
    }
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 0)
        {
            s.insert(i);
        }
    }
    while (!s.empty())
    {
        int curr = *s.begin();
        s.erase(s.begin());
        res.push_back(curr);
        for (auto i : ad[curr])
        {
            f[i]--;
            if (f[i] == 0)
            {
                s.insert(i);
            }
        }
    }

    if (res.size() == n)
    {
        out(res, res.size());
    }
    else
    {
        ct("Sandro fails.");
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout.setf(ios::fixed);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}