/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

#include <iostream>
using namespace std;

#define read(ar) \
    for (auto& x : ar) cin >> x;
#define min_self(a, b) a = min(a, b);

bool pen(int a, int b, int i, int j){
    if(a < b) return i < j;
    if(a == b) return i == j;
    return i > j;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tr = 0; tr < t; tr++) {
        int n;
        cin >> n;
        int ar[n]; read(ar);
        int ans = n - 1;
        int dp[n][4];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 4; j++){
                if(i == 0) dp[i][j] = 0;
                else
                    for(int k = 0; k < 4; k++){
                        int val = dp[i - 1][k] + !pen(ar[i - 1], ar[i], k, j);
                        if(k == 0) dp[i][j] = val;
                        else min_self(dp[i][j], val);
                    }
            }
        for(int j = 0; j < 4; j++) min_self(ans, dp[n-1][j]);
        cout << "Case #" << tr + 1 << ": " << ans << endl;
    }
}
