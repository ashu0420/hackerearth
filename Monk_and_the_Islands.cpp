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
vector<vector<int>> ad(10005);
vector<int> vi(10005, 0);
vector<int> dis(10005, 0);
queue<int> q;
void bfs(int node)
{
    for (auto i : ad[node])
    {
        if (vi[i] == 0)
        {
            vi[i] = 1;
            q.push(i);
            dis[i] = dis[node] + 1;
        }
    }
    return;
}
void solve()
{
    // Your code here
    int n, m;
    cin >> n >> m;
    // vector<vector<int>> ad(n+1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    q.push(1);
    vi[1] = 1;
    dis[1] = 0;
    while (q.empty() != 1)
    {
        bfs(q.front());
        q.pop();
    }
    ct(dis[n]);
    for (int i = 0; i < n + 1; i++)
    {
        dis[i] = 0;
        vi[i] = 0;
        ad[i].clear();
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}