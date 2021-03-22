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
//#include <queue>
int grid[1001][1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tr = 0; tr < t; tr++) {
        int n, m;
        cin >> n >> m;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> grid[i][j];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;
                int up = 0, down = 0, left = 0, right = 0;
                for (int r = i; r >= 0 && grid[r][j]; r--) up++;
                for (int r = i; r < n && grid[r][j]; r++) down++;
                for (int c = j; c >= 0 && grid[i][c]; c--) left++;
                for (int c = j; c < m && grid[i][c]; c++) right++;
                if(left >=2 && down >= 2){
                    int amt = min(left/2, down) - 1;
                    ans += amt;
                    amt = min(down/2, left) - 1;
                    ans += amt;
                }
                swap(down, up);
                if (left >= 2 && down >= 2) {
                    int amt = min(left / 2, down) - 1;
                    ans += amt;
                    amt = min(down / 2, left) - 1;
                    ans += amt;
                }
                swap(right, left);
                if (left >= 2 && down >= 2) {
                    int amt = min(left / 2, down) - 1;
                    ans += amt;
                    amt = min(down / 2, left) - 1;
                    ans += amt;
                }
                swap(down, up);
                if (left >= 2 && down >= 2) {
                    int amt = min(left / 2, down) - 1;
                    ans += amt;
                    amt = min(down / 2, left) - 1;
                    ans += amt;
                }
            }
        }

        cout << "Case #" << tr + 1 << ": " << ans << endl;
    }
}
