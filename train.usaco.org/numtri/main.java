/*
ID: ismail.8
LANG: JAVA
TASK: numtri
 */
import java.io.*;
import java.util.*;

public class numtri {

	public int solve(int n, int[][] triangle) {
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				triangle[i][j] += Math.max(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}
		return triangle[0][0];
	}


	public static void main(String[] args) throws IOException {
		String problemName = "numtri";
		BufferedReader f = new BufferedReader(new FileReader(problemName + ".in"));

		int n = Integer.parseInt(f.readLine());
		
		int[][] triangle = new int[n][n];
		for (int i = 0; i < n; i++) {
			triangle[i] = new int[n];
			StringTokenizer st = new StringTokenizer(f.readLine());
			for (int j = 0; j <= i; j++) {
				triangle[i][j] = Integer.parseInt( st.nextToken() );
			}
		}

		int res = (new numtri()).solve(n, triangle);

		// output Span
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(problemName + ".out")));
			out.println(res);
		out.close(); // close the output file
		System.exit(0); // don't omit this!
	}


}