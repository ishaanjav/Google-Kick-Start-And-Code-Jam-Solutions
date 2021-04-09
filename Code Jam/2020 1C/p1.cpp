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
#include <unordered_map>
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
    unordered_map<char, pii> u; u['S'] = mp(0, -1); u['E'] = mp(1, 0); u['N'] = mp(0, 1); u['W'] = mp(-1, 0);
    for (int tr = 0; tr < t; tr++) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        string s;
        cin >> s;
        int n = s.length();
        bool can = false;
        int i = 0;
        for(char c : s){
            x += u[c].fi, y += u[c].se;
            int dist = abs(x)+abs(y);
            i++;
            // cout << "  " << x << "," << y  << " = " << dist << endl;
            if(dist <= i){
                can = 1, ans = i; break;
            }
        }
        if (!can) {
            cout << "Case #" << tr + 1 << ": IMPOSSIBLE" << endl;
        } else
            cout << "Case #" << tr + 1 << ": " << ans << endl;
    }
}
