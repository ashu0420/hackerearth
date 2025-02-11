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
void dfs(vector<vector<int>> &ad, vector<int> &vis, int &ans, int currs, int &last, int curr)
{
    vis[curr] = 1;
    if (currs > ans)
    {
        ans = currs;
        last = curr;
    }
    for (auto i : ad[curr])
    {
        if (vis[i] == 0)
        {
            dfs(ad, vis, ans, currs + 1, last, i);
        }
    }

    return;
}

void solve()
{
    // Your code here
    int n;
    cn(n);
    vector<vector<int>> ad(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    int ans = 0;
    int currs = 0;
    int last = 1;
    vector<int> vis(n + 1, 0);
    dfs(ad, vis, ans, currs, last, 1);
    vis.assign(n + 1, 0);
    ans = 0;
    currs = 0;
    dfs(ad, vis, ans, currs, last, last);
    ct(ans);
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