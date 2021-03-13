/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define Endl "\n"
#define endl "\n"
#define fi first
#define se second
#define rs resize
#define len(a) (sizeof(a)/sizeof(a[0])
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);
#define deb cout << "ASDFASDF\n"
#define read(ar) \
    for (auto& x : ar) cin >> x;
#define each(ar) for (auto i : ar)
#define eachv(ar, i) for (auto i : ar)

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
//#include <algorithm>
#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

bool prime[100001];
vi primes;
void sieve(int n = 10000) {
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
        if (prime[p])
            for (int i = p * p; i <= n; i += p) prime[i] = false;
    primes.pb(2);
    for (int p = 3; p <= 10000; p += 2)
        if (prime[p]) primes.pb(p);
    prime[0] = prime[1] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    sieve();

    for (int tr = 0; tr < t; tr++) {
        int n, m;
        cin >> m >> n;
        ll ar[n];
        read(ar);
        set<ll> list;
        for (int i = 0; i < n; i++) {
            ll val = ar[i];
            for (int p : primes) {
                if (p * 2 > val) break;
                if (val % p == 0) list.ins(p);
            }
        }
        vl v;
        for (auto p : list) v.pb(p);
        string ans = "";
        ll p1 = -1, p2 = -1;
        int x1 = -1, x2 = -1;
        int cnt = 0;
        for (auto p : v) {
            if (ar[0] % p == 0) {
                if (p1 == -1)
                    p1 = p, x1 = cnt;
                else
                    p2 = p, x2 = cnt;
            }
            cnt++;
        }
        for (int i = 1; i < n; i++) {
            ll a = -1, b = -1;
            int c = -1, d = -1;
            cnt = 0;
            for (auto p : v) {
                if (ar[i] % p == 0) {
                    if (a == -1)
                        a = p, c = cnt;
                    else
                        b = p, d = cnt;
                }
                cnt++;
            }
            if (i == 1) {
                if (p1 == a || p1 == b) {
                    // p2 is the first one
                    char c = (char)('A' + x2);
                    ans += (c);
                } else {
                    char c = (char)('A' + x1);
                    ans += (c);
                }
            }
            if (p1 == a || p1 == b) {
                // p2 is the first one
                char c = (char)('A' + x1);
                ans += (c);
            } else {
                char c = (char)('A' + x2);
                ans += (c);
            }
            if (i == n - 1) {
                if (p1 == a || p2 == a) {
                    // p2 is the first one
                    char c = (char)('A' + d);
                    ans += (c);
                } else {
                    char c = (char)('A' + c);
                    ans += (c);
                }
            }
            p1 = a, p2 = b;
            x1 = c, x2 = d;
        }
        char c = (char)('A' + 3);
        // cout << c << endl;
        cout << "Case #" << tr + 1 << ": " << ans << endl;
    }
}
