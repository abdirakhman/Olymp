/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>
#include <stdio.h>


#define F first
#define S second
#define pb push_back

const long long MOD = 1e9 + 7;
const long long MAXN = 1e6 + 1;
using namespace std;

typedef long long ll;

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T> 
inline void writeInt( T x, char end ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}



char s[MAXN];

struct vertex {
	bool leaf;
	char pch;
	int link, p;
	map <char, int> go;
	vertex (){
		link = p = -1;
		leaf = false;
	}
};

vector<vertex> t;
int sz = 0;
 

void Insert(char s[MAXN]) {
    int v = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int go = t[v].go[s[i]];
        if (go == 0) {
            vertex add;
            add.p = v; add.pch = s[i];
            t.push_back(add);
            go = (int) t.size() - 1;
            t[v].go[s[i]] = go;
        }
        v = go;
    }  
    t[v].leaf = true;
}


int go(int v, int c);

int get_link(int v) {
	if (t[v].link != -1)
        return t[v].link;
    if (t[v].p == 0)
        return t[v].link = 0;
    char c = t[v].pch;
    int parent = t[v].p;
    return t[v].link = go(t[parent].link, c);
}

int go(int v, int c) {
    if (t[v].go.count(c) > 0)
        return t[v].go[c];
    if (v == 0)
        return t[v].go[c] = 0;
    int suff_link = get_link(v);
    return t[v].go[c] = go(suff_link, c);
}

void buildAhoCorasick() {
    queue <int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto it : t[v].go) {
            q.push(it.second);
        }
        int link = get_link(v);
        t[v].link = link;
        if (t[link].leaf)
            t[v].leaf = true;
    }
}
                  
int main() {
	#ifndef ONLINE_JUDGE
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
	int n = readInt();
	vertex root;	
	root.link  = 0;
	t.pb(root);
	while(n--) {
		gets(s);
		Insert(s);
	}
	buildAhoCorasick();
	while(gets(s)) {
		int V = 0;
	    int len = strlen(s);
		for (int i = 0; i < len; i++) {
			V = go(V, s[i]);
			if (t[V].leaf) {
				puts(s);
				break;
			}		 
		}		
	}	    
    return 0;
}