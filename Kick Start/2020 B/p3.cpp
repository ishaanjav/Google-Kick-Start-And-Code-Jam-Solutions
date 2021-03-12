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
#include <stack>
//#include <queue>

vi close;
pll solve(string s, int from, int to) {
    ll up = 0;
    ll right = 0;
    for (int i = from; i < to; i++) {
        if (s[i] == 'N')
            up--;
        else if (s[i] == 'S')
            up++;
        else if (s[i] == 'E')
            right++;
        else if (s[i] == 'W')
            right--;
        else {
            ll amt = s[i] - '0';
            pll res = solve(s, i + 2, close[i + 1]);
            i = close[i + 1];
            up += amt * res.fi;
            right += amt * res.se;
        }
    }
    up += 1000000000;
    right += 1000000000;
    up %= 1000000000;
    right %= 1000000000;
    return mp(up, right);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tr = 0; tr < t; tr++) {
        string s;
        cin >> s;
        int n = s.length();
        close.rs(0);
        close.rs(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')') {
                close[st.top()] = i;
                st.pop();
            }
        }
        pll ans = solve(s, 0, n);
        ans.fi += 1000000000;
        ans.se += 1000000000;
        ans.fi %= 1000000000;
        ans.se %= 1000000000;
        cout << "Case #" << tr + 1 << ": " << ans.se + 1 << " " << ans.fi + 1
             << endl;
    }
}