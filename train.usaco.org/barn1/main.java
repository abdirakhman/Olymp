/*
ID: ismail.8
LANG: JAVA
PROB: barn1
*/

import java.io.*;
import java.util.*;

class barn1{
	
	public void execute() throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("barn1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("barn1.out")));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int maxNum = Integer.parseInt(st.nextToken());
		int stallAmount = Integer.parseInt(st.nextToken());
		int occupiedAmount = Integer.parseInt(st.nextToken());
		
		int[] occupied = new int[occupiedAmount];
		for (int i=0;i<occupiedAmount;i++){
			occupied[i] = Integer.parseInt(br.readLine());
		}

		Arrays.sort(occupied);
		
		
		Gap[] gap = new Gap[occupiedAmount-1];
		for (int i=0;i<occupiedAmount-1;i++){
			int tempStartPoint = occupied[i];
			int tempDifference = occupied[i+1] - occupied[i];
			boolean chosen = false;
			Gap tempGap = new Gap(tempStartPoint, tempDifference, chosen);
			gap[i] = tempGap;
		}
		
		
		
		for (int i=0;i<maxNum-1;i++){
			Gap tempGap = this.getGapWithMaxDifference(gap);
			tempGap.setDifference(0);
			tempGap.setChosen(true);
		}
		
		
		
	
		int result = 0;
		int gapStart = occupied[0];
		int gapEnd;
		for (int i=0;i<occupiedAmount-1;i++){
			if (gap[i].getChosen()) {
				gapEnd = gap[i].getStartPoint();
				result += gapEnd - gapStart + 1;
				gapStart = occupied[i+1];
			}
		}
		gapEnd = occupied[occupiedAmount-1];
		result += gapEnd - gapStart + 1;
		
		out.println(result);
		br.close();
		out.close();
	}
	
	public Gap getGapWithMaxDifference(Gap[] gap){
		
		int maxDifference = 0;
		Gap maxGap = new Gap();
		for (int i=0;i<gap.length;i++){
			if (gap[i].getDifference() > maxDifference){
				maxDifference = gap[i].getDifference();
				maxGap = gap[i];
			}
		}
		
		return maxGap;
	}
	
	private class Gap{
		private int startPoint;
		private int difference;
		private boolean chosen;
		
		public Gap(){
			this.startPoint = 0;
			this.difference = 0;
			this.chosen = false;
		}
		
		public Gap(int startPoint, int difference, boolean chosen){
			this.startPoint = startPoint;
			this.difference = difference;
			this.chosen = chosen;
		}
		
		public int getStartPoint(){
			return this.startPoint;
		}
		
		public int getDifference(){
			return this.difference;
		}
		
		public void setDifference(int difference){
			this.difference = difference;
		}
		
		public boolean getChosen(){
			return this.chosen;
		}
		
		public void setChosen(boolean b){
			this.chosen = b;
		}
	}
	
	
	public static void main(String[] args) throws IOException{
		
		barn1 executor = new barn1();
		executor.execute();
	}
}