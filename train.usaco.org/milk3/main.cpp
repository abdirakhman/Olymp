/*
ID: ismail.8
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

bool s[21][21][21] = {false};
bool ans[21] = {false};
int AVol, BVol, CVol;

void expand(int a, int b,int c)
{
    if (s[a][b][c] == true)
        return;
    else
    {
        s[a][b][c] = true;
        if (a == 0)
            ans[c] = true;
        // A->B
        if (a+b>BVol)
            expand(a+b-BVol,BVol,c);
        else
            expand(0,a+b,c);
        // A->C
        if (a+c>CVol)
            expand(a+c-CVol,b,CVol);
        else
            expand(0,b,a+c);
        // B->A
        if (a+b>AVol)
            expand(AVol,a+b-AVol,c);
        else
            expand(a+b,0,c);
        // B->C
        if (b+c>CVol)
            expand(a,b+c-CVol,CVol);
        else
            expand(a,0,b+c);
        // C->A
        if (a+c>AVol)
            expand(AVol,b,a+c-AVol);
        else
            expand(a+c,b,0);
        // C->B
        if (b+c>BVol)
            expand(a,BVol,b+c-BVol);
        else
            expand(a,b+c,0);
    }
}

int main()
{
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    fin >> AVol >> BVol >> CVol;
    //s[0][0][CVol] = true;

    expand(0,0,CVol);

    int i;
    stringstream ss;
    string s;
    for (i = 0;i < 21;i++)
        if (ans[i] == true)
            ss << i << " ";
    getline(ss, s);
    s = s.substr(0,s.length()-1);
    fout << s << endl;
    return 0;
}



