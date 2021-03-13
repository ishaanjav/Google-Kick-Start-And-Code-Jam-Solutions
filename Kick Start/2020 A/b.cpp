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
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>


ll ans = 0;
int n, m, k;
vvi stacks;
ll dp[51][1501];
bool done[51][1501];
ll recurse(int stack, int left, ll total = 0) {
    if (done[stack][left]) return dp[stack][left];
    if (stack == n) {
        return 0;
    }
    ll best = recurse(stack + 1, left, total), sum = 0;
    for (int j = 0; j < min(left, m); j++) {
        sum += stacks[stack][j];
        max_self(best, sum + recurse(stack + 1, left - j - 1, total + sum));
    }
    done[stack][left] = 1;
    dp[stack][left] = best;
    return best;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tr = 0; tr < t; tr++) {
        cin >> n >> m >> k;
        stacks.resize(n);
        stacks.clear();
        SET(done, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int a;
                cin >> a;
                stacks[i].pb(a);
            }
        }
        ans = recurse(0, k);

        cout << "Case #" << tr + 1 << ": " << ans << endl;
    }
}
