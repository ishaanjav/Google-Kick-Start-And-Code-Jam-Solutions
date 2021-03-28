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
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
bool done = false;
int fa[] = {1, 2, 3, 4, 5, 6, 7}, cost;
void recurse(int n, int p = 0){
    if(done) return;
    if(p == n){
        int ans = 0;
        int ar[n]; for(int i =0; i < n; i++) ar[i] = fa[i];
        for (int i = 0; i < n - 1; i++) {
            int p = i;
            for (int j = i + 1; j < n; j++)
                if (ar[j] < ar[p]) p = j;

            ans += p - i + 1;
            reverse(ar + i, ar + p + 1);
        }
        if(ans == cost){
            for(int i = 0; i < n; i++) cout << fa[i] << " ";
            cout << endl;
            done = 1;
        }
        return;
    }
    for(int i = p; i < n; i++){
        swap(fa[i], fa[p]);
        recurse(n, p + 1);
        swap(fa[i], fa[p]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tr = 0; tr < t; tr++) {
        int n, ans = 0;
        cin >> n >> cost;
        if (cost < n - 1 || cost >= n * (n + 1) / 2) {
            cout << "Case #" << tr + 1 << ": IMPOSSIBLE" << endl;
            continue;
        }
        done = false;
        cout << "Case #" << tr + 1 << ": " ;
        recurse(n);
    }
}
