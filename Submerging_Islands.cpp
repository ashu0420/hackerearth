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
vector<int> intime(100001, 0);
vector<int> low(100001, 0);
vector<bool> isap(100001, 0);
int cnt = 0;
int timer = 0;
void dfs(int node, int p)
{
    vis[node] = 1;
    intime[node] = timer++;
    low[node] = timer++;
    int child = 0;
    for (auto i : ad[node])
    {

        if (i == p)
        {
            continue;
        }
        else if (vis[i] == 1)
        {
            low[node] = min(intime[i], low[node]);
        }
        else if (vis[i] == 0)
        {
            child++;
            dfs(i, node);

            if (p != -1 && low[i] >= intime[node])
            {
                if (isap[node] == false)
                {
                    isap[node] = true;
                    cnt++;
                }
            }
            low[node] = min(low[i], low[node]);
        }
    }
    if (p == -1 && child > 1)
    {
        if (isap[node] == false)
        {
            isap[node] = true;
            cnt++;
        }
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
    while (1)
    {

        // Your code here
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            return 0;
        }
        for (int i = 0; i < n + 1; i++)
        {
            ad[i].clear();
            intime[i] = 0;
            low[i] = 0;
            vis[i] = 0;
            timer = 0;
            cnt = 0;
            isap[i] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            ad[u].push_back(v);
            ad[v].push_back(u);
        }
        int p = -1;
        dfs(1, -1);
        ct(cnt);
    }
    return 0;
}