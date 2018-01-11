#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <string>

#define ull unsigned long long
#define ll long long
#define ff first
#define ss second

using namespace std;

ull gcd (ull a, ull b) {
	return b ? gcd (b, a % b) : a;
}

ull lcm (ull a, ull b) {
	return a / gcd (a, b) * b;
}

const int power = 131;
const int maxn = int(1e6);
char c[5*maxn + 10];

ull h[5*maxn + 10], p[5*maxn + 10];

int q, n;
string s;

// The Gift Of Raksha Bandhan
// https://www.codechef.com/problems/INSQ15_A


vector<int> zf(){
	vector<int> z(n);
	int L = 0, R = 0;
	for (int i = 1; i < n; i++) {
	  	if (i > R) {
	    	L = R = i;
	    	while (R < n && s[R-L] == s[R]) R++;
	    	z[i] = R-L; R--;
	  	} else {
	    	int k = i-L;
	    	if (z[k] < R-i+1) z[i] = z[k];
	    	else {
	      		L = i;
	      		while (R < n && s[R-L] == s[R]) R++;
	      		z[i] = R-L; R--;
	    	}
	  	}
	}
	return z;
}

int main(){
	scanf("%s", c);
	s = string(c);
	n = int(s.size());
	vector <int> ans = zf();
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << endl;
	p[0] = 1;
	for(int i = 1; i <= n; i++) p[i] = p[i-1] * power;
	for(int i = 0; i < n; i++){
		h[i] = int(s[i] - 'a' + 1) * p[i];
		if(i) h[i] += h[i-1];
	}
	scanf("%d", &q);

	for(int i = 0; i < q; i++){
		int x;
		scanf("%d", &x);
		cout << min(x, ans[x]) << endl;
		// ull l = lcm(h[x-1], h[n-1] - h[x-1]);
		// printf("%lld\n", l);
	}


}