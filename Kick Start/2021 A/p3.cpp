/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Solutions: https://github.com/ishaanjav/Google-Kick-Start-And-Code-Jam-Solutions
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
//#include <cstring>
//#include <sstream>
//#include <stack>
#include <queue>
int grid[301][301], rows, cols;

bool inBounds(int i, int j) { return i >= 0 && i < rows && j < cols && j >= 0; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tr = 0; tr < t; tr++) {
        int n, m;
        cin >> n >> m;
        rows = n;
        cols = m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cin >> grid[i][j];
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        queue<pii> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cur = grid[i][j];
                int biggest = -1;
                for (int d = 0; d < 4; d++) {
                    int x = dx[d] + i, y = dy[d] + j;
                    if (inBounds(x, y)) {
                        max_self(biggest, grid[x][y]);
                    }
                }
                if (biggest - cur > 1) q.push(mp(i, j));
            }
        }
        ll ans = 0;
        while (!q.empty()) {
            pii top = q.front();
            q.pop();
            int biggest = -1;
            int i = top.fi, j = top.se;
            int cur = grid[i][j];
            for (int d = 0; d < 4; d++) {
                int x = dx[d] + i, y = dy[d] + j;
                if (inBounds(x, y)) {
                    max_self(biggest, grid[x][y]);
                }
            }
            if (biggest - cur > 1) {
                int change = biggest - cur - 1;
                ans += change;
                grid[top.fi][top.se] = biggest - 1;
                cur = biggest - 1;
                for (int d = 0; d < 4; d++) {
                    int x = dx[d] + i, y = dy[d] + j;
                    if (inBounds(x, y)) {
                        if (grid[x][y] + 1 < cur) q.push(mp(x, y));
                    }
                }
            }
        }
        cout << "Case #" << tr + 1 << ": " << ans << endl;
    }
}
