/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

import java.io.*;
import java.util.*;

public class Problem {
    public static boolean has(long a){
        return (new String(a+"")).contains("4");
    }
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int testC = sc.nextInt();

        sc.nextLine();
        for (int test = 0; test < testC; test++) {
            int n = sc.nextInt();
            Random rand = new Random();
            long a = (long) rand.nextInt(n) + 1;
            long b = n - a;
            while(has(a) || has(b)){    
                a = (long) rand.nextInt(n) + 1;
                b = n - a;
            }
            System.out.println("Case #" + (test+1) + ": " + a + " " + b);
        }
    }
}
