//https://codeforces.com/problemset/problem/706/C

#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long int ll;
typedef long double ld;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define repA(i, a, n) for (ll i = a; i <= (n); ++i)
#define repD(i, a, n) for (ll i = a; i >= (n); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define bpc(a) __builtin_popcount(a)
#define ff first
#define ss second
#define mk0(a) memset(a, 0, sizeof(a))
#define mk_1(a) memset(a, -1, sizeof(a))
#define ar array

#define pb push_back
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(0);
#define pi pair<ll, ll>
#define map1 unordered_map

inline ll nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

inline ll read()
{
    ll ret = 0;
    bool f = 0;
    char ch = nc();
    while (ch > '9' || ch < '0')
        f ^= ch == '-', ch = nc();
    while (ch <= '9' && ch >= '0')
        ret = ret * 10 + ch - '0', ch = nc();
    return f ? -ret : ret;
}

ll power(ll base, ll ind, ll mod)
{
    ll res = 1;
    while (ind)
    {
        if (ind & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        ind >>= 1;
    }
    return res;
}

ll inv(ll den, ll mod) { return power(den, mod - 2, mod); }

const ll MAX = 1e5 + 5;
const ll MAX1 = 1e2 + 5;
const ll INF = 1e15 + 2;
const ll MOD = 998244353;

ll n;
ll cost[MAX];
string s[MAX];
ll dp[MAX][2];

void pre()
{
    mk_1(dp);
}

int main()
{
    faster;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    rep(i, n) cin >> cost[i];

    rep(i, n) cin >> s[i];
    pre();
    dp[0][0] = 0;
    dp[0][1] = cost[0];

    rep1(i, n - 1)
    {
        string prev = s[i - 1];
        string prevr = prev;
        reverse(all(prevr));
        string cur = s[i];
        string curr = s[i];
        reverse(all(curr));
        if (prev <= cur)
        {
            if (dp[i - 1][0] != -1)
                dp[i][0] = dp[i - 1][0];
        }
        if (prevr <= cur)
        {
            if (dp[i - 1][1] != -1 and dp[i][0] == -1)
                dp[i][0] = dp[i - 1][1];
            else if (dp[i - 1][1] != -1)
                dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
        if (prevr <= curr)
        {
            if (dp[i - 1][1] != -1)
                dp[i][1] = dp[i - 1][1] + cost[i];
        }
        if (prev <= curr)
        {
            if (dp[i - 1][0] != -1 and dp[i][1] == -1)
                dp[i][1] = dp[i - 1][0] + cost[i];
            else if (dp[i - 1][0] != -1)
                dp[i][1] = min(dp[i][1], dp[i - 1][0] + cost[i]);
        }
    }

    if (dp[n - 1][0] == -1 and dp[n - 1][1] == -1)
        cout << -1;
    else if (dp[n - 1][0] == -1)
        cout << dp[n - 1][1];
    else if (dp[n - 1][1] == -1)
        cout << dp[n - 1][0];
    else
        cout << min(dp[n - 1][0], dp[n - 1][1]);
}