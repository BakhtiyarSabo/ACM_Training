#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

const int P = 13;

ll h[1000010], p[1000010];


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int n = int(s.size());
	p[0] = 1;
	for(int i = 1; i < n; i++) p[i] = p[i-1] * P;

	for(int i = 0; i < s.size(); i++){
		h[i] = int(s[i] - 'a' + 1) * p[i];
		if(i) h[i] += h[i-1];
	}
	ll res = 0;

	for(int l = n; l >= 1; l--){
		vector <ll> hs(n - l + 1);
		for(int i = 0; i < n - l + 1; i++){
			ll ch = h[i + l - 1];
			if(i) ch -= h[i-1];
			ch *= p[n - i - 1];
			hs[i] = ch;
		}
		sort(hs.begin(), hs.end());
		hs.erase(unique(hs.begin(), hs.end()), hs.end());



		res += int(hs.size());
		cout << res << endl;
	}



}