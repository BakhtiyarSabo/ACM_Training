#include <bits/stdc++.h>

using namespace std;

#if defined(__GNUC__)
#  define UNUSED __attribute__ ((unused))
#elif defined(_MSC_VER)
#  define UNUSED __pragma(warning(suppress:4100))
#else
#  define UNUSED
#endif

vector <string> b;
string s, t;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> t;

	for(int i = 0; i < t.size(); i++){
		b.push_back(t.substr(i) + t.substr(0, i));
	}

	int ans = 0;

	for(int i = 0; i <= s.size() - t.size(); i++){
		int f = 0;
		string y = s.substr(i, t.size());
		for(const string &x : b){
			if(x == y){
				f = 1;
				break;
			}
		}
		ans += f;
	}

	cout << ans;
	return 0;
}