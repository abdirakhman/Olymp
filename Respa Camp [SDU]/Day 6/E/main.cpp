/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

#define F first
#define S second

const long long MOD = 1e9 + 7;
const long long MAXN = 1e6 + 1;
using namespace std;

typedef long long ll;

long long readInt() {
    bool minus1 = false;
    long long result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus1 = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' | ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus1)
        return -result;
    else
        return result;
}



struct item {
	int key, prior;
	int cnt, rev;
	int sum, pos;
	item * l, * r;
	item() { }
	item (int key, int pos1) : key(key), prior(((rand() << 16) + rand())), l(NULL), r(NULL), cnt(0), sum(0), pos(pos1), rev(0) { }
};

typedef item * pitem;

void upd_cnt (pitem t);

void push (pitem  it) {
	if (it && it->rev != 0) {                
		it->pos += it->rev;
		if (it->l)  it->l->rev += it->rev;
		if (it->r)  it->r->rev += it->rev;
		it->rev = 0;
	}
}


int getsum(pitem t) {
	return t ? (t -> sum) : 0;
}

int getcnt(pitem t) {
	return t ? (t -> cnt) : 0;
}

void upd_cnt (pitem t) {
	if (t) {
		int sum = 0;
		if (t -> pos % 5 == 3) {
			sum += t->key;
		}
		t->sum = sum + getsum(t -> l) + getsum(t -> r); 
		t->cnt = 1 + getcnt(t->l) + getcnt(t->r);
	}			
}


void split (pitem t, int key, pitem & l, pitem & r) {
	push(t);
	if (!t)
		l = r = NULL;
	else if (key < t->key)
		split (t->l, key, l, t->l),  r = t;
	else
		split (t->r, key, t->r, r),  l = t;
    upd_cnt (t);
}

void merge (pitem & t, pitem l, pitem r) {
	push(l);
	push(r);		
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}


void inorder(pitem t) {
	if (t) {
		inorder(t->l);
		cout << t->key << ' ';
		inorder(t->r);			
	}
}

void inorder1(pitem t) {
	if (t) {
		inorder1(t->l);
		cout << t->pos<< ' ';
		inorder1(t->r);			
	}
}


pitem root = NULL;


int main() {
	//#ifndef ONLINE_JUDGE
	//freopen("tree.in", "r", stdin);
    //freopen("tree.out", "w", stdout);
    //#endif
	int n = readInt();
	while(n--) {
		string s;
		cin >> s;
		if (s == "add") {
		    int x = readInt();
			pitem L, R;
			split(root, x-1, L, R);
			if (R) {
				R->rev++;		
			}
			merge(root, L, new item(x, getcnt(L)+1));
			merge(root, root, R);  
		} else if (s == "del") {
			int x = readInt();
			pitem L, R;
			pitem Ans2, Ans1;
			split(root,x-1, L, R);
			split(R, x, Ans1, Ans2);
			if (Ans2) {
				Ans2->rev--;
			}
			cout << "\n================\n";
			inorder(Ans2);
			cout << endl;
			inorder1(Ans2);
			cout << "\n================\n";

			merge(root, L, Ans2);  				                     
			cout << "\n================\n";
			inorder(root);
			cout << endl;
			inorder1(root);
			cout << "\n================\n";

		} else {
			cout << getsum(root) << "\n";			
		}   
	}
    return 0;
}
            
