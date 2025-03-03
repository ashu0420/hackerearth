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
vector<vector<int>> ad(1000002);
vector<int> vis(1000002, 0);
vector<int> vc(1000002, 0);
int cc;

void dfs(int u)
{
    vis[u] = 1;
    vc[u] = cc;
    for (auto i : ad[u])
    {
        if (vis[i] == 0)
            dfs(i);
    }
    return;
}
void solve()
{
    // Your code here
    int n, k;
    cin >> n >> k;
    cc = 0;

    for (int i = 0; i < n + 1; i++)
    {
        ad[i].clear();
        vis[i] = 0;
        vc[i] = 0;
    }
    vector<pair<int, int>> vp;
    for (int i = 0; i < k; i++)
    {
        int u, v;
        string s;
        cin >> u >> s >> v;
        if (s == "=")
        {
            ad[u].push_back(v);
            ad[v].push_back(u);
        }
        else
        {
            vp.push_back({u, v});
        }
    }
    // ct(cc);
    // out(vc,n+1);
    for (int i = 1; i < n + 1; i++)
    {
        if (vis[i] == 0)
        {
            cc++;
            dfs(i);
        }
    }
    // out(vc,n+1);
    for (auto i : vp)
    {
        if (vc[i.first] == vc[i.second])
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}