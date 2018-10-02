/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

#define F first
#define S second
#define endl '\n'
#define pb push_back

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
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus1)
        return -result;
    else
        return result;
}


struct BigInt {

    vector <int> num;

    static const int base = 1000 * 1000 * 1000;    
    static const int baseDigits = 9;
    string leadingZerosModifier;

    /****************************************************
    * CONSTRUCTONS & SETTERS
    ****************************************************/

    void setLeadingZerosModifier() {
        leadingZerosModifier = "%0xd";
        leadingZerosModifier[2] = '0' + baseDigits;
    }

    void set(int value) {
        num.clear();
        if (value == 0) 
            num.push_back(0);
        while (value) {
            num.push_back(value % base);
            value /= base;
        }
    }

    void set(long long value) {
        num.clear();
        if (value == 0) 
            num.push_back(0);
        while (value) {
            num.push_back(value % base);
            value /= base;
        }
    }

    void set(string &value) {
        num.clear();
        for (int i = (int)value.length() - 1; i >= 0; i -= baseDigits) {
            int add = 0;
            for (int j = max(0, i - baseDigits + 1); j <= i; j++)
                add = add * 10 + value[j] - '0';
            num.push_back(add);
        }
    }

    void operator = (int value) {
        set(value);
    }

    void operator = (long long value) {
        set(value);
    }

    void operator = (string &value) {
        set(value);
    }

    BigInt() {
        setLeadingZerosModifier();
        set(0);
    }

    BigInt(int value) {
        setLeadingZerosModifier();
        set(value);
    }

    BigInt(string value) {
        setLeadingZerosModifier();
        set(value);
    }

    /*====================================================
    * SIZE METHODS
    ====================================================*/

    //returns size of vector 
    int size() {
        return (int)num.size();
    }

    //returns length of the number
    int digitNum() {
        int result = 0;
        for (int i = 0; i < (int)num.size() - 1; i++)
            result += baseDigits;
        int lastNum = num.back();
        while (lastNum) {
            result++;
            lastNum /= 10;
        }
        return result;
    }

    /*====================================================
    * I/O
    ====================================================*/

    void read() {
        string s;
        cin >> s;
        num.clear();
        for (int i = (int)s.length() - 1; i >= 0; i -= baseDigits) {
            int add = 0;
            for (int j = max(0, i - baseDigits + 1); j <= i; j++)
                add = add * 10 + s[j] - '0';
            num.push_back(add);
        }
    }

    void print() {
        printf("%d", num.back());
        for (int i = (int)num.size() - 2; i >= 0; i--)
            printf (leadingZerosModifier.c_str(), num[i]);
    }

    void println() {
        print();
        printf("\n");
    }

    string toString() {
        string result = "";
        for (int i = 0; i < (int)num.size(); i++) {
            int cur = num[i];
            for (int j = 1; j <= baseDigits; j++) {
                if (cur == 0 && i == (int) num.size() - 1)
                    break;
                result.append(1, (char) '0' + cur % 10);
                cur /= 10;
            }
        }   
        reverse(result.begin(), result.end());
        return result;
    }

    /*====================================================
    * ADDITION
    ====================================================*/

    void sumThis(BigInt number) {
        int carry = 0;
        for (int i = 0; i < max((int)num.size(), number.size()) || carry; i++) {
            if (i == num.size())
                num.push_back(0);
            if (i >= number.size())
                carry = num[i] + carry;
            else
                carry = num[i] + carry + number.num[i];
            num[i] = carry % base;
            carry /= base;
        }
    }

    void sumThis(int number) {
        int carry = number;
        for (int i = 0; i < (int)num.size() || carry; i++) {
            if (i == num.size())
                num.push_back(0);
            carry = num[i] + carry;
            num[i] = carry % base;
            carry /= base;
        }
    }

    BigInt sum(BigInt number) {
        BigInt result = *this;
        result.sumThis(number);
        return result;
    }

    BigInt sum(int number) {
        BigInt result = *this;
        result.sumThis(number);
        return result;
    }

    void operator += (BigInt number) {
        sumThis(number);
    }

    void operator += (int number) {
        sumThis(number);
    }

    BigInt operator + (BigInt number) {
        return sum(number);
    }

    BigInt operator + (int number) {
        return sum(number);
    }

    /*====================================================
    * SUBTRACTION
    ====================================================*/

    void subThis(BigInt number) {
        int carry = 0;
        for (int i = 0; i < (int)number.size() || carry; i++) {
            if (i < (int)number.size())
                num[i] -= carry + number.num[i];
            else
                num[i] -= carry;
            if (num[i] < 0) {
                carry = 1;
                num[i] += base;
            }
            else
                carry = 0;
        }
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();
    }

    void subThis(int number) {
        int carry = -number;
        for (int i = 0; carry > 0; i++) {
            num[i] -= carry;
            if (num[i] < 0) {
                carry = 1;
                num[i] += base;
            }
            else 
                carry = 0;
        }
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();
    }

    BigInt sub(BigInt number) {
        BigInt result = *this;
        result.subThis(number);
        return result;
    }

    BigInt sub(int number) {
        BigInt result = *this;
        result.subThis(number);
        return result;
    }

    void operator -= (BigInt number) {
        subThis(number);
    }

    void operator -= (int number) {
        subThis(number);
    }

    BigInt operator - (BigInt number) {
        return sub(number);
    }

    BigInt operator - (int number) {
        return sub(number);
    }

    /*====================================================
    * MULTIPLICATION
    ====================================================*/

    BigInt mult(BigInt number) {
        BigInt product;
        product.num.resize(num.size() + number.size());
        for (int i = 0; i < (int)num.size(); i++) {
            for (int j = 0, carry = 0; j < (int)number.size() || carry; j++) {
                long long cur = product.num[i + j] + num[i] * 1ll * (j < (int)number.size() ? number.num[j] : 0) + carry;
                product.num[i + j] = int (cur % base);
                carry = int (cur / base);
            }
        }
        while (product.size() > 1 && product.num.back() == 0)
            product.num.pop_back();
        return product;
    }

    void multThis(BigInt number) {
        *this = mult(number);
    }

    void multThis(int number) {
        int carry = 0;
        for (int i = 0; i < (int)num.size() || carry; ++i) {
            if (i == num.size())
                num.push_back (0);
            long long cur = carry + num[i] * 1ll * number;
            num[i] = int (cur % base);
            carry = int (cur / base);
        }
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();
    }

    BigInt mult(int number) {
        BigInt result = *this;
        result.multThis(number);
        return result;
    }

    void operator *= (BigInt number) {
        multThis(number);
    }    

    void operator *= (int number) {
        multThis(number);
    }    

    BigInt operator * (BigInt number) {
        return mult(number);
    }

    BigInt operator * (int number) {
        return mult(number);
    }

    void multThisByPowerOfTen(int power) {
        int baseNums = power / baseDigits;
        int curLen = (int)num.size();
        num.resize(curLen + baseNums);
        for (int i = num.size() - 1; i >= baseNums; i--) {
            num[i] = num[i - baseNums];
        }
        for (int i = baseNums - 1; i >= 0; i--)
            num[i] = 0;
        power %= baseDigits;
        int multBy = (int)pow(10.0, power); 
        multThis(multBy);
    }

    /*====================================================
    * DIVISION
    ====================================================*/

    void divThis(int number) {
        int carry = 0;
        for (int i= (int)num.size() - 1; i >= 0; i--) {
            long long cur = num[i] + carry * 1ll * base;
            num[i] = int (cur / number);
            carry = int (cur % number);
        }
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();
    }

    BigInt div(int number) {
        BigInt result = *this;
        result.divThis(number);
        return result;
    }

    void operator /= (int number) {
        divThis(number);
    }

    BigInt operator / (int number) {
        return div(number);
    }

    void divThisByPowerOfTen(int power) {
        int baseNums = power / baseDigits;
        int curLen = (int)num.size();
        for (int i = 0; i < (int)num.size() - baseNums; i++) {
            num[i] = num[i + baseNums];
        }
        for (int i = 1; i <= baseNums; i++)
            num.pop_back();
        power %= baseDigits;
        int divBy = (int)pow(10.0, power); 
        divThis(divBy);
    }

    /*====================================================
    * MODULO
    ====================================================*/

    void modThis(int number) {
        int carry = 0;
        for (int i= (int)num.size() - 1; i >= 0; i--) {
            long long cur = num[i] + carry * 1ll * base;
            num[i] = int (cur / number);
            carry = int (cur % number);
        }
        set(carry);
    }

    BigInt mod(int number) {
        BigInt result = *this;
        result.modThis(number);
        return result;
    }

    void operator %= (int number) {
        modThis(number);
    }

    BigInt operator % (int number) {
        return mod(number);
    }

    /*====================================================
    * COMPARISON
    ====================================================*/

    //Returns: -1 - this number is less than argument, 0 - equal, 1 - this number is greater
    int compareTo(BigInt number) {
        if ((int)num.size() < number.size())
            return -1;
        if ((int)num.size() > number.size())
            return 1;
        for (int i = (int)num.size() - 1; i >= 0; i--) {
            if (num[i] > number.num[i])
                return 1;
            if (num[i] < number.num[i])
                return -1;
        }
        return 0;
    }

    //Returns: -1 - this number is less than argument, 0 - equal, 1 - this number is greater
    int compareTo(int number) {
        if (num.size() > 1 || num[0] > number)
            return 1;
        if (num[0] < number)
            return -1;
        return 0;
    }

    bool operator < (BigInt number) {
        return compareTo(number) == -1;
    }

    bool operator < (int number) {
        return compareTo(number) == -1;
    }

    bool operator <= (BigInt number) {
        return compareTo(number) != 1;
    }

    bool operator <= (int number) {
        return compareTo(number) != 1;
    }

    bool operator == (BigInt number) {
        return compareTo(number) == 0;
    }

    bool operator == (int number) {
        return compareTo(number) == 0;
    }

    bool operator > (BigInt number) {
        return compareTo(number) == 1;
    }

    bool operator > (int number) {
        return compareTo(number) == 1;
    }

    bool operator >= (BigInt number) {
        return compareTo(number) != -1;
    }

    bool operator >= (int number) {
        return compareTo(number) != 1;
    }

    bool operator != (BigInt number) {
        return compareTo(number) != 0;
    }

    bool operator != (int number) {
        return compareTo(number) != 0;
    }

};

ll n;
int cnt;

void go(map<int, bool> m, int l, int r) {
	if (l - 1 == r) {
		for (int i = 0; i < n; i++) {
			if (m[4*i+1] + m[4*i+2] + m[4*i+3] > 1) return;
			if (m[4*i-2] + m[4*i-1] + + m[4*i] + m[4*i+1] + m[4*i+2] > 2) return;			
		}		
		cnt ++;
		return;
	}
	go(m, l+1, r);
	m[l-1] = 1;
	go(m, l+1, r);
}


ll binpow (ll a, ll n) {
	if (n == 0)
		return 1ll;
	if (n % 2 == 1)
		return ((binpow (a, n-1)%MOD) * a) % MOD;
	else {
		ll b = binpow (a, n/2) % MOD;
		return (b * b) % MOD;
	}
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt();
    cout << (binpow(7ll, (n - 1) % (MOD - 1)) * 8)%MOD << endl;
    //map <int, bool> m;
    //go(m, 1, 4*n);
    //cout << cnt;
	return 0;
}       