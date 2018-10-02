/*
ID: ismail.8
LANG: JAVA
TASK: transform
 */
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

class transform {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("transform.in"));
        PrintWriter pw = new PrintWriter(new File("transform.out"));

        int n = sc.nextInt();

        char[][] input = new char[n][n];
        for(int i=0; i<input.length; i++) {
            String s = sc.next();
            for(int j=0; j<input[i].length; j++) {
                input[i][j] = s.charAt(j);
            }
        }

        char[][] target = new char[n][n];
        for(int i=0; i<target.length; i++) {
            String s = sc.next();
            for(int j=0; j<target[i].length; j++) {
                target[i][j] = s.charAt(j);
            }
        }

        if (Arrays.deepEquals(cw(input), target)) {
            pw.println(1);
        } else if (Arrays.deepEquals(cw(cw(input)), target)) {
            pw.println(2);
        } else if (Arrays.deepEquals(cw(cw(cw(input))), target)) {
            pw.println(3);
        } else if (Arrays.deepEquals(reflect(input), target)) {
            pw.println(4);
        } else if ((Arrays.deepEquals(cw(reflect(input)), target)) ||
                  (Arrays.deepEquals(cw(cw(reflect(input))), target)) ||
                  (Arrays.deepEquals(cw(cw(cw(reflect(input)))), target))) {
            pw.println(5);
        } else if (Arrays.deepEquals(input, target)) {
            pw.println(6);
        } else {
            pw.println(7);
        }

        pw.close();
    }

    private static void print(char[][] input) {
        for(int i=0; i<input.length; i++) {
            for(int j=0; j<input.length; j++) {
                System.out.print(input[i][j]);
            }
            System.out.println();
        }
    }

    private static char[][] cw(char[][] input) {
        char[][] ret = new char[input.length][input.length];
        for(int i=0; i<input.length; i++) {
            for(int j=0; j<input.length; j++) {
                ret[j][input.length-i-1] = input[i][j];
            }
        }
        return ret;
    }

    private static char[][] reflect(char[][] input) {
        char[][] ret = new char[input.length][input.length];
        for(int i=0; i<input.length; i++) {
            for(int j=0; j<input.length; j++) {
                ret[i][j] = input[i][input.length-j-1];
            }
        }
        return ret;
    }
}