#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <cstring>

using namespace std;
const int P = 3;

#define ll long long

string s, t;
int T, len;

ll h[1000010], p[1000010], H;

inline void calc_p(){
	p[0] = 1;
	for(int i = 1; i < 1000009; i++) p[i] = p[i-1] * P;
}

inline void solve(){
	cin >> t >> s;
	H = 0;
	if(t.size() > s.size()){
		cout << "\n";
		return;
	}
	memset(h, 0, sizeof h);
	H += (t[0] - 'a' + 1);
	for(int i = 1; i < t.size(); i++) H += (t[i] - 'a' + 1) * p[i];

	h[0] = (s[0] - 'a' + 1);
	for(int i = 1; i < s.size(); i++) h[i] = h[i-1] + (s[i] - 'a' + 1) * p[i];

	bool f = true;
	for(int i = 0; i < s.size() - len + 1; i++){
		if(i == 0){
			if(h[i + len - 1] == H){
				cout << i << '\n';
				f = false;
			}
		}
		else{
			if(h[i + len - 1] - h[i-1] == H * p[i]){
				cout << i << '\n';
				f = false;
			}
		}
	}
	if(f) cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	calc_p();
	while(cin >> len) solve();
	return 0;
}