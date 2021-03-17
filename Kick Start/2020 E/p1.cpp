/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Solutions: https://github.com/ishaanjav/Google-Kick-Start-And-Code-Jam-Solutions
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    int orig = t;
    while (t--) {
        int n;
        cin >> n;
        int ar[n];
        for (int i = 0; i < n; i++) cin >> ar[i];

        int answer = 2;
        int dif = ar[0] - ar[1];
        int soFar = 2;
        for (int i = 1; i < n - 1; i++) {
            if (ar[i] - ar[i + 1] == dif) {
                soFar++;
                answer = max(answer, soFar);
            } else {
                dif = ar[i] - ar[i + 1];
                soFar = 2;
            }
        }
        cout << "Case #" << orig - t << ": " << answer << "\n";
    }
}
