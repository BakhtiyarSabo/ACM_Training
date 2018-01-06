#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

string s;

const int p = 7;

int pp[101010];

int main(){
	cin >> s;
	int n = int(s.size());

	pp[0] = 1;

	for(int i = 1; i <= n; i++){
		pp[i] = pp[i-1] * p;
	}

	#define ll long long
	vector <ll> h(n);
	for(int i = 0; i < n; i++){
		h[i] = (s[i] - 'a' + 1) * pp[i];
		if(i) h[i] += h[i-1];
	}

	ll res = 0;

	for(int l = 1; l <= n; l++){
		vector <ll> hs(n - l + 1);
		for(int i = 0; i < n - l + 1; i++){
			ll ch = h[i + l - 1];
			if(i) ch -= h[i-1];
			ch *= pp[n - i - 1];
			hs[i] = ch;
		}
		sort(hs.begin(), hs.end());
		hs.erase(unique(hs.begin(), hs.end()), hs.end());

		res += int(hs.size());
	}

	cout << res;
}
