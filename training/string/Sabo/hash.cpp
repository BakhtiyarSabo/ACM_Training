#include <bits/stdc++.h>

using namespace std;

const int p = 7;

int pp[101010], h[101010];

string s;

int main(){
	cin >> s;
	int n = int(s.size());
	pp[0] = 1;
	for(int i = 1; i <= n; i++) pp[i] = pp[i-1] * p;

	for(int i = 0; i < s.size(); i++){
		h[i] = (s[i] - 'a' + 1) * pp[i];
		cout << h[i] << ' ';
		if(i > 0) h[i] += h[i-1]; 
		cout << h[i] << '\n';
	}

	cout << endl;


	int x, y, len;
	cin >> x >> y >> len;
	long long h1 = h[x + len - 1];
	if(x) h1 -= h[x-1];
	long long h2 = h[y + len - 1];
	if(y) h2 -= h[y - 1];

	if(x < y && h1 * pp[y - x] == h2 || x > y && h2 * pp[x - y] == h1) cout << "equal";
	else cout << "Diff";

}