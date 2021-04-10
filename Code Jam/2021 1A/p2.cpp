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
vector<ll> ar;
ll n, ans;
vb taken;
void recurse(int p = 0){
	if(p == n){
		ll sum = 0, prod = 1;
		for(int i = 0; i < n; i++){
			if(taken[i]) sum += ar[i];
			else prod *= ar[i];
		}
		if(sum == prod) max_self(ans, sum);
		return;
	}
	taken[p] = false;
	recurse(p+1);
	taken[p] = 1;
	recurse(p+1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tr = 0; tr < t; tr++) {
        cin >> n; ar.clear(); taken.clear();
		for(int i = 0; i < n; i++){
			ll a, b; cin >> a >> b;
			for(int j = 0; j < b; j++) ar.pb(a), taken.pb(0);
		}  
		n = ar.size(), ans = 0;
		if(n > 11) cout << "aa" << endl;
		recurse();
        cout << "Case #" << tr + 1 << ": " << ans << endl;
    }
}
