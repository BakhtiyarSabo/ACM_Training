#include <bits/stdc++.h>

using namespace std;

string s, t;

char c[10101];

int main(){	

	// scanf("%s", &c);
	// s = string(c);
	// scanf("%s", &c);
	// t = string(c);
	cin >> s >> t;
	if(s.size() == t.size() && s == t) return cout << 0, 0;
	if(s.size() < t.size()) return cout << -1, 0;
	for(int i = 0; i < s.size(); i++){
		if(s.substr(i) + s.substr(0, i) == t) return cout << s.size() - i, 0;
	}
	cout << -1;
	return 0;
}