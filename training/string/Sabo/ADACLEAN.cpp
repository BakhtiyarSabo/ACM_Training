#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <string>
#include <set>

#define ull unsigned long long
#define ll long long
#define ff first
#define ss second

using namespace std;


const int power = 131;
const int maxn = int(1e5);
char c[3*maxn + 10];

ull h[3*maxn + 10], p[3*maxn + 10];

ll ans = 0;

int q, k, n;
string s;

inline void solve(){
	scanf("%d%d", &n, &k);
	scanf("%s", c);
	s = string(c);
	cout << endl;
	p[0] = 1;
	for(int i = 1; i <= n; i++) p[i] = p[i-1] * power;
	for(int i = 0; i < n; i++){
		h[i] = int(s[i] - 'a' + 1) * p[i];
		if(i) h[i] += h[i-1];
	}
	set <ull> st;
	for(int i = 0; i < n - k + 1; i++){
		ull cur = h[i+k - 1];
		if(i) cur -= h[i-1];
		cur *= p[n - i - 1];
		st.insert(cur);
	}
	printf("%d\n", int(st.size()));

}

int main(){
	int t;
	scanf("%d", &t);
	while(t--) solve();
}