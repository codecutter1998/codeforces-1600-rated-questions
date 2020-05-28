//https://codeforces.com/problemset/problem/1303/C

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

int main()
{
    faster;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    rep(_, t)
    {
        string s;
        cin >> s;
        int vis[26];
        mk0(vis);
        string board;
        ll pos = 0;
        board += s[0];
        vis[s[0] - 'a'] = 1;
        int flg = 1;
        rep1(i, sz(s) - 1)
        {
            if (vis[s[i] - 'a'])
            {
                if (pos > 0 and board[pos - 1] == s[i])
                {
                    pos--;
                    continue;
                }
                if (pos < sz(board) - 1 and board[pos + 1] == s[i])
                {
                    pos++;
                    continue;
                }
                flg = 0;
                break;
            }
            else
            {
                vis[s[i] - 'a'] = 1;
                if (pos == 0)
                {
                    board = s[i] + board;
                    continue;
                }
                else if (pos == sz(board) - 1)
                {
                    board += s[i];
                    pos++;
                    continue;
                }
                flg = 0;
                break;
            }
        }
        if (flg == 0)
            cout << "NO";
        else
        {
            rep(i, 26)
            {
                if (!vis[i])
                    board += i + 'a';
            }
            cout << "YES\n"
                 << board;
        }
        cout << "\n";
    }
}