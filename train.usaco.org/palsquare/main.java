/*
ID: ismail.8
LANG: JAVA
TASK: palsquare
 */
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

class palsquare {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("palsquare.in"));
        PrintWriter pw = new PrintWriter(new File("palsquare.out"));

        int base = sc.nextInt();

        char[] rep = new char[] {'0','1','2','3','4','5','6','7','8','9',
                                 'A','B','C','D','E','F','G','H','I','J'};
        for(int i=1; i<=300; i++) {
            String square = toBase(i*i,base,rep);
            System.out.println(i + " " + toBase(i,base,rep));
            if (isPalindrome(square)) {
                pw.println(toBase(i,base,rep) + " " + square);
            }
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