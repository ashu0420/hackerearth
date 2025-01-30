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

void dfs(vector<vector<int>> &ad, vector<int> &flag, int child)
{
    flag[child] = 1;
    for (auto i : ad[child])
    {
        if (flag[i] == 0)
        {
            dfs(ad, flag, i);
        }
    }
    return;
}

void solve()
{
    // Your code here
    int n, m;
    cin >> n >> m;
    if (m > n - 1)
    {
        pn;
        return;
    }
    vector<vector<int>> ad(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    vector<int> flag(n + 1, 0);
    dfs(ad,flag,1);
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==0)
        {
            pn;
            return;
        }
    }
    py;
    return;
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