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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tr = 0; tr < t; tr++) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        int n = s.length();
        int dp[s.length()][2];
        for (int i = 0; i < n; i++) dp[i][0] = dp[i][1] = 1e8;
        if (s[0] == '?') dp[0][0] = dp[0][1] = 0;
        dp[0][s[0] == 'J'] = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == '?') {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + x);
            } else if (s[i] == 'C')
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
            else
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + x);
        }

        cout << "Case #" << tr + 1 << ": " << min(dp[n - 1][0], dp[n - 1][1])
             << endl;
    }
}
