#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define ll long long

const int P = 131;
const long long mod1 = (1e16) + 7;
const ll mod2 = (1e15) + 7; 

ll h[1000010], p[1000010];

ll mx = 0;
int n;
string s;
set <ll> st;
int arr[1010101];
int pp;

bool check(int i){
	ll f = h[i] * p[n - i];
	for(int j = 1; j + i < n; j++){
		if(h[j + i - 1] * p[n - i] == f) return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	n = int(s.size());
	if(n < 3) return puts("Just a legend"), 0;
	p[0] = 1;
	for(int i = 1; i <= n; i++) p[i] = p[i-1] * P;

	h[0] = (s[0] - 'a' + 1);
	for(int i = 1; i < s.size(); i++){
		h[i] = h[i-1] + (((s[i] - 'a') + 1) * p[i]);
	}
	int r = 0;
	for(int i = 0; i < n - 1; i++){
		if(h[i] * p[n - 1 - i] == h[n - 1] - h[n-2-i]){
			r = i + 1;
			st.insert(h[i] * p[n - 1 - i]);
			arr[++pp] = i;
			// cout << endl << h[i] * p[n - 1 - i] << endl;
		}
	}

	// cout << endl;
	if(r == 0) return puts("Just a legend"), 0;

	// string ans = "";
	// int len = 0;
	// for(int i = 1; i < n - 1; i++){
	// 	for(int l = 1; l <= r; l++){
	// 		if(i + l < n){
	// 			if(h[l-1] * p[i] == h[i+l-1] - h[i-1] && h[n-1] - h[n-1-l] == h[l-1] * p[n - l]){
	// 				len = max(len, l);
	// 			}
	// 		}
	// 	}
	// }

	int l = 0; r = pp; 
	int mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(check(arr[mid])) l = mid;
		else r = mid;
	}

	if(!l) cout << s.substr(0, l);
	else
	// for(int l = r; l >= 1; l--){
	// 	for(int i = 1; i < n - l; i++){
	// 		ll ch = h[i+l-1];
	// 		if(i) ch -= h[i-1];
	// 		ll f = h[l - 1];

	// 		if(f * p[i] == ch && h[n-1] - h[n - l - 1] == h[l-1] * p[n-l]){
	// 			len = max(len, l);
	// 			return cout << s.substr(0, len), 0;
	// 		}
	// 	}
	// }
	// if(len != 0) cout << s.substr(0, len);
	cout << "Just a legend";

}