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

    int t, n;
    cin >> t >> n;
    bool de = false;
    vector<char> ar;
    ar.pb('A');
    ar.pb('B');
    ar.pb('C');
    ar.pb('D');
    ar.pb('E');
    for (int tr = 0; tr < t; tr++) {
        string ans = "";
        vector<int> ps;
        for (int i = 0; i < 119; i++) ps.pb(i * 5 + 1);
        for (int k = 0; k < 5; k++) {
            unordered_map<string, int> freq;
            vector<string> pres;
            for (int i = 0; i < ps.size(); i++) {
                cout << ps[i] << endl;
                string res;
                cin >> res;
                pres.pb(res);
                freq[res]++;
            }
            if (pres.size() == 1) {
                for (char c : ar) {
                    if (find(all(ans), c) == ans.end() && c != pres[0][0]) {
                        ans.push_back(c);
                    }
                }
                break;
            }
            string add = "";
            int tar = 1;
            for (int i = 0; i < 4 - k; i++) tar *= (i + 1);
            for (auto p : freq) {
                if (p.se != tar) add = p.fi;
            }
            ans += add;
            vector<int> cp;
            int cnt = 0;
            for (string s : pres) {
                if (s == add) {
                    cp.pb(ps[cnt] + 1);
                }
                cnt++;
            }
            ps.clear();
            for (int i : cp) ps.pb(i);
        }

        for (char c : ar) {
            if (find(all(ans), c) == ans.end()) {
                ans.push_back(c);
            }
        }
        cout << ans << endl;
        string verdict;
        cin >> verdict;
    }
}