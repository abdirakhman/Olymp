
// Section 1.4.3

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/*
ID: ismail.8
LANG: JAVA
PROG: ariprog
*/


// Time Limit : 5s
// hint: generate bisquares first
public class ariprog {

	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new FileReader("ariprog.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"ariprog.out")),true);
		
		// read data
		int N = Integer.parseInt(in.readLine());
		int M = Integer.parseInt(in.readLine());
		// max: 250 * 250 * 2 = 125000
		int MM2 = M*M*2;
		
		// generate bisquares into a boolean array
		// loop times: 251 * 252 /2 = 31626
		boolean[] bisquares = new boolean[MM2+1];
		for(int p = 0; p <= M; p++)
			for(int q = p; q<= M; q++)
				bisquares[p*p + q*q] = true;
		
		// search and pruning
		List<int[]> res = new ArrayList<int[]>();
		for(int a = 0; a < MM2; a++){
			if(!bisquares[a]) continue;
			label:
			for(int b = 1; b <= (MM2-a)/ (N-1); b++){ // a+ (N-1) * b <= MM2
				for(int i = 1; i<= N-1; i++){
					if(!bisquares[a + b * i])
						continue label;
				}
				res.add(new int[]{a,b});
			}
		}

		// sort and print
		Collections.sort(res,new Comparator<int[]>(){
			public int compare(int[] o1, int[] o2) {
				if(o1[1] < o2[1]) return -1;
				if(o1[1] > o2[1]) return 1;
				if(o1[0] < o2[0]) return -1;
				if(o1[0] < o2[0]) return 1;
				return 0;
			}});
		if(res.size() == 0) out.println("NONE");
		for(int[] ab : res)
			out.println(ab[0]+ " " + ab[1]);
		
		System.exit(0);
	}
}