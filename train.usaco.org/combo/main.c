/*
ID: ismail.8
LANG: C
TASK: combo
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*=====================================================================
 * Combination Lock
 * 
 * Given Farmer John's combination and the master 
 * combination, please determine the number of distinct 
 * settings for the dials that will open the lock. Order matters, 
 * so the setting (1,2,3) is distinct from (3,2,1).
 * */
 
 // Input data
 #define MaxArraySize 3
 
 int num;
 int farm[3];
 int master[3];

/*-----------------------
 * Procedure to read file
 * 
 * ex:
 * 50
 * 1 2 3
 * 5 6 7
 * */
void read_comb(FILE* fp)
{
	int i;
	
	assert(fp != NULL);
	
	fscanf(fp, "%d", &num);
	
	for(i=0; i<MaxArraySize; i++)
		fscanf(fp, "%d", &farm[i]);
	
	for(i=0; i<MaxArraySize; i++)
		fscanf(fp, "%d", &master[i]);
}

/*---------------------------------------------
 * Check if the lock can be open
 * 
 * if the current comb close enough
 * with one of our key, it will open
 * 
 * e lock has a small tolerance for error, 
 * however, so it will open even if the 
 * numbers on the dials are each within at 
 * most 2 positions of a valid combination
 * 3 can be open by 1 2 3 4 5
 * 
 * Rember  1 and N are adjacent since 
 * the dials are circular!!
 * 
 * Our Method:
 * 
 * for every digits
 * det(A) <=2 || Max - det(A) <= 2
 * 
 * intput: int current combo[3]
 * output: can open 1, otherwise 0
 * */
 int can_open_by(int combo[])
 {
	int f = 1;
	int m = 1;
	int i;
	
	for(i=0; i<MaxArraySize; i++) {
		f *= ( (abs(combo[i]-farm[i])   <= 2) || (num-(abs(combo[i]-farm[i])) <=2 ) );
		m *= ( (abs(combo[i]-master[i]) <= 2) || (num-(abs(combo[i]-master[i])) <=2 ) );
	}
	
	//printf("f=%d, m=%d\n", f, m);
	
	return (f||m);
 }
 
 /*-------------------------------------------------
  * Compute and printf how many answer we have by n
  * 
  * The lock have 3 dials, they are 1...N
  * 
  * Order matters, so the setting (1,2,3) 
  * is distinct from (3,2,1).
  * */
  void comp_open_combo(FILE* fp)
  {
	int i, j, k;
	int combo[3];
	int ans = 0;
	
	// Set numbers
	for(i=0; i<num; i++)
	for(j=0; j<num; j++)
	for(k=0; k<num; k++) {
		combo[0] = i+1;
		combo[1] = j+1;
		combo[2] = k+1;
		
		// Check the lock can be open by this combo
		if( can_open_by(combo) ) ans++;
		
	}
	
	fprintf(fp, "%d\n", ans);
  }

int main(int argc, char **argv)
{
	FILE* fin	= fopen("combo.in", "r");
	FILE* fout 	= fopen("combo.out", "w");
	
	assert( fin != NULL && fout != NULL );
	
	read_comb(fin);
	comp_open_combo(fout);

	return 0;
}