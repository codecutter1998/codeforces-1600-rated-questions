//https://codeforces.com/problemset/problem/1036/D

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

const ll MAX = 3e5 + 5;
const ll MASK = (1 << 30) + 1;
const ll MAX1 = 1e2 + 5;
const ll INF = 1e18;
const ll MOD = 998244353;

ll n, m;
ll a[MAX], b[MAX];

int main()
{
    faster;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll s1 = 0, s2 = 0;
    cin >> n;
    rep(i, n)
    {
        cin >> a[i];
        s1 += a[i];
    }
    cin >> m;
    rep(i, m)
    {
        cin >> b[i];
        s2 += b[i];
    }
    if (s1 != s2)
    {
        cout << -1;
        return 0;
    }
    ll l1 = 0, l2 = 0;
    s1 = 0, s2 = 0;
    ll cnt = 0, flg = 0;
    while (1)
    {
       // cout<<s1<<" "<<s2<<"\n";
        if (l1 == n and l2 == m)
            break;
        if (flg == 0)
            s1 += a[l1], s2 += b[l2], l1++, l2++;
        else if (flg == 1)
            s2 += b[l2], l2++;
        else
            s1 += a[l1], l1++;

        if (s1 == s2)
            cnt++, flg = 0;
        else if (s1 > s2)
            flg = 1;
        else
            flg = 2;
    }
    //cout<<l1<<" "<<l2;

    if (s1 != s2)
        cout << -1;
    else
        cout << cnt;
}