/*
ID: ismail.8
LANG: C++
TASK: namenum
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<char, int> a;
map<string, long long int> dict;

int main(){
	a['A'] = a['B'] = a['C'] = 2;
	a['D'] = a['E'] = a['F'] = 3;
	a['G'] = a['H'] = a['I'] = 4;
	a['J'] = a['K'] = a['L'] = 5;
	a['M'] = a['N'] = a['O'] = 6;
	a['P'] = a['R'] = a['S'] = 7;
	a['T'] = a['U'] = a['V'] = 8;
	a['W'] = a['X'] = a['Y'] = 9;
	
	ifstream dictin("dict.txt");
	string word;
	while(dictin>>word){
		long long int value = 0;
		for(int i=0; i<word.length(); i++)
			value = value*10 + a[word[i]];
		
		dict[word] = value;
	}
	
	ofstream fout ("namenum.out");
	ifstream fin("namenum.in");
	
	long long int N;
	fin >> N;
	
	int count = 0;
	for(map<string, long long int>::iterator it=dict.begin(); it!=dict.end(); it++){
		if(it->second == N)
			count++, fout<<it->first<<endl;
	} 
	
	if(count == 0)
		fout<<"NONE"<<endl;
	
	return 0;
}