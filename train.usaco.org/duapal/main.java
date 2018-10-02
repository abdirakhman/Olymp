/*
ID: ismail.8
LANG: JAVA
TASK: dualpal
 */
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

class dualpal {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("dualpal.in"));
        PrintWriter pw = new PrintWriter(new File("dualpal.out"));

        int n = sc.nextInt();
        int s = sc.nextInt();

        char[] rep = new char[] {'0','1','2','3','4','5','6','7','8','9',
                                 'A','B','C','D','E','F','G','H','I','J'};

        int found = 0;
        int val = s+1;
        while(found < n) {
            int cnt = 0;
            for(int j=2; j<=10; j++) {
                if (isPalindrome(toBase(val,j,rep))) {
                    cnt++;
                }
            }
            if (cnt >= 2) {
                pw.println(val);
                found++;
            }
            val++;
        }

        pw.close();
    }

    private static boolean isPalindrome(String input) {
        for(int i=0; i<input.length(); i++) {
            if (input.charAt(i) != input.charAt(input.length()-i-1)) return false;
        }
        return true;
    }

    private static String toBase(int i, int base, char[] rep) {
        StringBuilder sb = new StringBuilder();
        int val = i;
        while(val >= base) {
            sb.insert(0, rep[val%base]);
            val = val/base;
        }
        return sb.insert(0, rep[val]).toString();
    }
}