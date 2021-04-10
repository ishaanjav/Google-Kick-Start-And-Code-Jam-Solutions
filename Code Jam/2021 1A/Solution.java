import java.util.*;
import java.io.IOException;
import java.math.BigInteger;

public class Solution {
    static int co(String a, String b) {
        if (a.length() != b.length())
            return a.length() - b.length();
        return a.compareTo(b);
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int testC = sc.nextInt();
        BigInteger one = new BigInteger("1");
        sc.nextLine();
        for (int test = 0; test < testC; test++) {
            int n = sc.nextInt();
            sc.nextLine();
            String ar[] = new String[n];
            for (int i = 0; i < n; i++)
                ar[i] = sc.next();
            long ans = 0;
            for (int i = 0; i < n - 1; i++) {
                String a = ar[i] + "", b = ar[i + 1] + "";
                if (co(ar[i + 1], ar[i]) > 0)
                    continue;
                int dif = a.length() - b.length();
                if (dif == 0) {
                    ar[i + 1] += "0";
                    ans++;
                } else {
                    // line up ar[i+1] with ar[i] on the left and compare that
                    String a1 = (a.substring(0, b.length()));
                    if (co(a1, ar[i + 1]) < 0) {
                        // just need to add 0s
                        for (int j = 0; j < dif; j++)
                            ar[i + 1] += "0";
                        ans += dif;
                    } else if (co(a1, ar[i + 1]) > 0) {
                        // we have to add 1 extra 0
                        for (int j = 0; j <= dif; j++)
                            ar[i + 1] += "0";
                        ans += dif + 1;
                    } else {
                        // 1035
                        // 1035232
                        // we can make ar[i+1] = 1 + ar[i] only if the suffix is not only 9s.
                        String suff = a.substring(b.length());
                        boolean found = false;
                        for (char c : suff.toCharArray()) {
                            if (c != '9') {
                                found = true;
                                break;
                            }
                        }
                        if (found) {
                            BigInteger big = new BigInteger(ar[i]);
                            big = big.add(one);
                            ar[i + 1] = big.toString();
                            ans += dif;
                        } else {
                            // we just have to add extra 0.
                            for (int j = 0; j <= dif; j++)
                                ar[i + 1] += "0";
                            ans += dif + 1;
                        }
                    }
                }
            }
            System.out.println("Case #" + (test + 1) + ": " + ans);
        }

    }
}