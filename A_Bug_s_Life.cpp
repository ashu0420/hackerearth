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
#define sort(a) sort(a.begin(), a.end());
#define vin(a, n)    \
    vector<ll> a(n); \
    in(a, n);
const int MOD = 1e9 + 7;

using namespace std;
bool dfs(vector<vector<int>> &ad, vector<int> &vis, vector<int> &col, int x, int c)
{
    vis[x] = 1;
    col[x] = c;
    for (auto i : ad[x])
    {
        if (vis[i] == 0)
        {
            bool res = dfs(ad, vis, col, i, c ^ 1);
            if (res == 0)
            {
                return 0;
            }
        }
        else
        {
            if (col[i] == c)
            {
                return 0;
            }
        }
    }
    return 1;
}
void solve(int t)
{
    // Your code here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ad(n + 1);
    vector<int> vis(n + 1, 0);
    vector<int> col(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    bool flag = 1;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            // col[i] = 1;
            bool res = dfs(ad, vis, col, i, 0);
            if (res == 0)
            {
                flag = res;
            }
        }
    }
    cout << "Scenario #" << t << ":" << endl;
    if (flag)
    {
        cout << "No suspicious bugs found!" << endl;
    }
    else
    {
        cout << "Suspicious bugs found!" << endl;
    };
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout.setf(ios::fixed);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}