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
#include <algorithm>
//#include <set>
//#include <map>
#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
int rows, cols;
bool inBound(int i, int j) { return i >= 0 && i < rows && j >= 0 && j < cols; }
vector<unordered_set<int> > adj;
vector<bool> visited;
vector<char> order;
bool poss = true;
void dfs(int v) {
    if (visited[v]) {
        poss = false;
        return;
    }
    visited[v] = 1;
    for (int u : adj[v]) dfs(u);
    order.pb('A' + v);
}
void test() {
    adj.rs(26);
    visited.rs(26);
    // adj[0].ins(1);
    // adj[0].ins(2);
    // adj[0].ins(3);
    // adj[2].ins(4);
    // adj[3].ins(4);
    adj[0].ins(1);
    adj[0].ins(2);
    adj[0].ins(5);
    adj[1].ins(2);
    adj[1].ins(3);
    adj[1].ins(4);
    adj[2].ins(4);
    adj[2].ins(5);
    adj[3].ins(4);
    adj[5].ins(4);
    dfs(0);
    reverse(all(order));
    for (char c : order) cout << c;
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // test();
    // return 0;

    int t;
    cin >> t;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int tr = 0; tr < t; tr++) {
        cin >> rows >> cols;
        vector<vector<int> > grid(rows, vector<int>(cols));
        adj.rs(0);
        adj.rs(26);
        visited.rs(0);
        visited.rs(26);
        order.rs(0);
        poss = true;
        for (int i = 0; i < rows; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < cols; j++) {
                grid[i][j] = s[j] - 'A';
            }
        }
        int into[26];
        unordered_set<int> exist;
        for (int i = 0; i < 26; i++) {
            into[i] = 0;
            visited[i] = false;
            adj[i].clear();
        }
        for (int j = 0; j < cols; j++) {
            int top = grid[0][j];
            exist.ins(grid[0][j]);
            for (int i = 1; i < rows; i++) {
                if (grid[i][j] != top) {
                    // top depends on grid[i][j];
                    adj[grid[i][j]].ins(top);
                    exist.ins(grid[i][j]);
                    into[top]++;
                    top = grid[i][j];
                }
            }
        }
        bool foundone = false;
        // cout << into[0] << endl;
        for (int i = 0; i < 26; i++) {
            if (FOUND(exist, i) && into[i] == 0) {
                dfs(i);
                foundone = true;
            }
        }
        cout << "Case #" << tr + 1 << ": ";
        if (!foundone) poss = false;
        if (poss) {
            reverse(all(order));
            unordered_set<char> pres;
            for (char c : order) pres.ins(c);
            for (int u : exist) {
                if (!(FOUND(pres, 'A' + u))) order.pb('A' + u);
            }
            for (char c : order) cout << c;
        } else
            cout << -1;
        cout << endl;
    }
}
/*
1
3 10
AAABBCCDDE
AABBCCDDEE
AABBCCDDEE
 */
