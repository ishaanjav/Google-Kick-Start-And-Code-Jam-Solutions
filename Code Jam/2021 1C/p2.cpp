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
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>

bool roaring(string i, vector<string> af, int p = 0, ll prev = -1) {
    if (p == i.length()) return 1;
    if (prev == 0) return false;
    // cout << prev << ", " << p << endl;
    if (prev != -1) {
        string s = to_string(prev);
        if (i.length() - p < s.length()) return false;
        if (i.substr(p, s.length())[0] == '0') return false;
        ll a = stoll(i.substr(p, s.length()));
        bool foo = false;
        bool ans = false;
        if (a == prev + 1) {
            ans |= roaring(i, af, p + s.length(), a);
            foo = 1;
        }
        if (ans) return true;
        if (i.length() - p > s.length()) {
            a = stoll(i.substr(p, 1 + s.length()));
            if (a == prev + 1) {
                ans |= roaring(i, af, 1 + p + s.length(), a);
                foo = 1;
            }
        }
        return ans;
        // if (!foo) return false;
    }
    // ll en = stoll(i.substr(p, i.length() - p));
    // char c = i.substr(p, i.length() - p)[0];
    // cout << prev << ", " << p << endl;
    // if (c != '0' && en == 1 + prev && prev != -1) {
    //     cout << prev << " " << en << Endl;
    //     each(af) cout << i << " ";
    //     cout << endl;
    //     return true;
    // }

    int rem = i.length() - p;
    bool can = false;
    for (int len = 1; len <= rem / 2; len++) {
        string part = i.substr(p, len);
        af.pb(part);
        can |= roaring(i, af, p + len, stoll(part));
        af.erase(find(all(af), part));
    }
    return can;
}
bool roaring(string i, int p = 0, ll prev = -1) {
    if (p == i.length()) return 1;
    if (prev == 0) return false;
    // cout << prev << ", " << p << endl;
    if (prev != -1) {
        string s = to_string(prev);
        if (i.length() - p < s.length()) return false;
        if (i.substr(p, s.length())[0] == '0') return false;
        ll a = stoll(i.substr(p, s.length()));
        bool foo = false;
        bool ans = false;
        if (a == prev + 1) {
            ans |= roaring(i, p + s.length(), a);
            foo = 1;
        }
        if (ans) return true;
        if (i.length() - p > s.length()) {
            a = stoll(i.substr(p, 1 + s.length()));
            if (a == prev + 1) {
                ans |= roaring(i, 1 + p + s.length(), a);
                foo = 1;
            }
        }
        return ans;
        // if (!foo) return false;
    }
    // ll en = stoll(i.substr(p, i.length() - p));
    // char c = i.substr(p, i.length() - p)[0];
    // cout << prev << ", " << p << endl;
    // if (c != '0' && en == 1 + prev && prev != -1) {
    //     cout << prev << " " << en << Endl;
    //     each(af) cout << i << " ";
    //     cout << endl;
    //     return true;
    // }

    int rem = i.length() - p;
    bool can = false;
    for (int len = 1; len <= rem / 2; len++) {
        string part = i.substr(p, len);
        can |= roaring(i, p + len, stoll(part));
    }
    return can;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tr = 0; tr < t; tr++) {
        ll n;
        cin >> n;
        // if (n > 1e6 + 1) break;
        ll ans = -1;
        // int val[] = {2021, 2122, 78910, 123};
        for (ll i = n + 1; ans == -1; i++) {
            // string s= to_string(i);
            // for(int len = 0; len <= s.length(); len++){
            //     bool good = true;
            //     int p = 0;
            //     string pa
            // }

            // cout << i << endl;
            if (roaring(to_string(i))) {
                ans = i;
            }
        }
        cout << "Case #" << tr + 1 << ": ";
        cout << ans << endl;
    }
}