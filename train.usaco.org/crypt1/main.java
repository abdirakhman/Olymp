/*
 ID: ismail.8
 LANG: JAVA
 TASK: crypt1
 */

import java.util.*;
import java.io.*;

public class crypt1 {
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("crypt1.in"));
		PrintWriter pw = new PrintWriter(new File("crypt1.out"));
		int n = in.nextInt();
		int [] digits = new int[n];
		
		for(int i = 0; i < n; i++) {
			digits[i] = in.nextInt();
		}
		
		// System.out.println(isgoodProd(222, 22, digits));
		
		int solutioncount = 0;
		
		for(int a = 100; a <= 999; a++) {
			for(int b = 10; b <= 99; b++) {                                              
				if(isGood(a, digits) && isGood(b, digits) && isgoodProd(a, b, digits)) {
					// System.out.println(a + " " + b);
					solutioncount++;
				}
			}
		}
		
		pw.println(solutioncount);
		in.close();
		pw.close();
		
		
	}
	
	public static boolean isgoodProd(int a, int b, int [] digits) {
		// a is three digit number
		// b is three digit number
		
		int bFirst = Integer.parseInt(Integer.toString(b).substring(0, 1));
		int firstProd = a * (b % 10);
		int secondProd = a * bFirst;
		int finalProd = 10 * secondProd + firstProd;                                                             
		
		if(! isGood(firstProd, digits) || ! isGood(secondProd, digits) || ! isGood(finalProd, digits)) {
			return false;
		}
		
		if(digitCount(firstProd) != 3 || digitCount(secondProd) != 3 || digitCount(finalProd) != 4) {
			return false;
		}
		
		return true;
			
		
	}
	
	public static int digitCount(int a) {
		int count = 0;
		while(a > 0) {
			count++;
			a /= 10;
		}
		
		return count;
	}
	
	public static boolean isGood(int i, int [] digits) {
		while(i > 0) {
			int digit = i % 10;
			if(! contains(digit, digits)) return false;
			
			i /= 10;
		}
		
		return true;
	}
	
	public static boolean contains(int i, int [] digits) {
		for(int a = 0; a < digits.length; a++) {
			if(digits[a] == i) return true;
		}
		
		return false;
	}

}