#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define ll long long
#define ull unsigned long long

// inline void calc(){
// 	p[0] = 1;
// 	for(int i = 1; i < 1000001; i++) p[i] = p[i-1] * 131;
// }

string s, t;

inline void solve(){
	string s, t; 
	cin >> t >> s;

	vector <int> ans; 

	const int p = 31; 
	vector<ull> p_pow(max(s.length(), t.length())); 
	p_pow[0] = 1; 
	for (size_t i = 1; i < p_pow.size(); ++i) 
	    p_pow[i] = p_pow[i-1] * p; 

	vector<ull> h(t.length()); 
	for (size_t i = 0; i < t.length(); i++) 
	{ 
	    h[i] = (t[i] - 'a' + 1) * p_pow[i]; 
	    if (i) h[i] += h[i - 1]; 
	} 

	ull h_s = 0; 
	for (size_t i = 0; i < s.length(); i++) 
	    h_s += (s[i] - 'a' + 1) * p_pow[i]; 

	for (size_t i = 0; i + s.length() - 1 < t.length(); i++) 
	{ 
	    ull cur_h = h[i + s.length () - 1]; 
	    if (i) cur_h -= h [i - 1]; 

	    if (cur_h == h_s * p_pow[i]) 
	        ans.push_back(i + 1); 
	}
	if(ans.size() == 0) cout << "Not Found\n";
	else{
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++){

			cout << ans[i] << " ";
		}
		cout << endl;
	}
}

int T;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T--) solve();
	return 0;
}