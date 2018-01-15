#include <iostream>

using namespace std;

#define ull unsigned long long 

ull h[55555], p[55555];
ull H = 0;

const int P = 131;

int main(){
	string s;
	string t;
	cin >> s  >> t;
	p[0] = 1;
	for (int i = 1; i < 50001; i++) p[i] = p[i-1] * P;

	for (int i = 0; i < s.size(); i++) {
		h[i] = int(s[i] - 'a' + 1) * p[i];
		if (i) h[i] += h[i-1];
	}
	H = int(t[0] - 'a' + 1);
	for(int i = 1; i < t.size(); i++) {
		H += int(t[i] - 'a' + 1) * p[i];
	}

	for(int i = 0; i < s.size() - t.size() + 1; i++){
		// cout << "IN\n";
		ull cur = h[i + t.size() - 1];

		if(i) cur -= h[i-1];
		// cout << cur << ' ' << i << ' ' << H << ' ' << p[i] << ' ' << H * p[i] << "\n";
		if(cur == H * p[i]) cout << i << ' ';
	}
}