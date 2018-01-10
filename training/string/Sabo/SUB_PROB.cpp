#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

const int P = 131;
#define ll long long
ll h[1000010], p[1000010], H;


int n, m, N;
string s, t;

inline void calc_p(){
	p[0] = 1;
	for(int i = 1; i < 1000009; i++) p[i] = p[i-1] * P;

	if(s[0] >= 'A' && s[0] <= 'Z') h[0] = (s[0] - 'A' + 1);
	else h[0] = (s[0] - 'a' + 27);

	for(int i = 1; i < m; i++){
		if(s[i] >= 'A' && s[i] <= 'Z') h[i] = h[i-1] + (s[i] - 'A' + 1) * p[i];
		else h[i] = h[i-1] + p[i] * (s[i] - 'a' + 27);		
	}
}

vector <pair <int, ll> > hash;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> N;
	m = s.size();
	calc_p();

	for(int i = 0; i < N; i++){
		cin >> t;
		H = 0;
		if(t[0] >= 'A' && t[0] <= 'Z') H = (t[0] - 'A' + 1);
		else H = (t[0] - 'a' + 27);

		for(int j = 1; j < t.size(); j++){
			if(t[i] >= 'A' && t[i] <= 'Z') H += p[i] * (t[i] - 'A' + 1);
			else H += p[i] * (t[i] - 'a' + 27);
		}
		hash.push_back(make_pair(int(t.size()), H));
	}

	for(int i = 0; i < hash.size(); i++){
		bool nf = true;
		for(int j = 0; j < s.size() - hash[i].first + 1; j++){
			if(j == 0){
				if(h[j + hash[i].first - 1] == hash[i].second * p[j]){
					nf = false;
					cout << "Y\n";
					break;
				}
			}
			else{
				if(h[j + hash[i].first - 1] - h[j-1] == hash[i].second * p[j]){
					nf = false;
					cout << "Y\n";
					break;
				}
			}
		}
		if(nf) cout << "N\n";
	}
}