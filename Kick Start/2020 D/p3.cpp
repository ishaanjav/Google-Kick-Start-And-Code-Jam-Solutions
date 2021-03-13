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
//#include <set>
//#include <map>
#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
double total = 0;

double outOf = 0;
int a, b;
vvi adj;
double amt(int d, int freq) { return d / freq; }
unordered_set<int> nodes;
void dfs(int v, int often, int times = 0) {
    if (times % often == 0) nodes.ins(v);
    for (int u : adj[v]) dfs(u, often, times + 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tr = 0; tr < t; tr++) {
        int n;
        cin >> n >> a >> b;
        outOf = n * n;
        adj.rs(0);
        adj.rs(n + 1);
        total = 0;
        for (int i = 2; i <= n; i++) {
            int v;
            cin >> v;
            // adj[v].pb(i);
            adj[i].pb(v);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                nodes.clear();
                dfs(i, a);
                dfs(j, b);
                total += nodes.size();
            }
        }
        double ans = total / outOf;
        ans = round(ans * 1000000.0) / 1000000.0;
        cout << "Case #" << tr + 1 << ": " << ans << endl;
    }
}
/*
1
4 2 1
1 1 2
 */
