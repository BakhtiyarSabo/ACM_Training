#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

const int P = 131;
#define ll unsigned long long
ll h[1000010], p[1000010], H;


int n, m, N;
string s, t;
char c[1000010];

inline void calc_p(){
	p[0] = 1;
	for(int i = 1; i <= m; i++) p[i] = p[i-1] * P;

	if(s[0] >= 'A' && s[0] <= 'Z') h[0] = (s[0] - 'A' + 1);
	else h[0] = (s[0] - 'a' + 27);

	for(int i = 1; i < m; i++){
		if(s[i] >= 'A' && s[i] <= 'Z') h[i] = h[i-1] + (s[i] - 'A' + 1) * p[i];
		else h[i] = h[i-1] + p[i] * (s[i] - 'a' + 27);		
	}
}

vector <pair <int, ll> > HASSS;


int main(){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);
	scanf("%s", c);
	scanf("%d", &N);
	s = string(c);
	m = s.size();
	calc_p();

	for(int i = 0; i < N; i++){
		scanf("%s", c);
		t = string(c);
		H = 0;
		if(t[0] >= 'A' && t[0] <= 'Z') H = (t[0] - 'A' + 1);
		else H = (t[0] - 'a' + 27);

		for(int j = 1; j < t.size(); j++){
			if(t[j] >= 'A' && t[j] <= 'Z') H += p[j] * (t[j] - 'A' + 1);
			else H += p[j] * (t[j] - 'a' + 27);
		}
		HASSS.push_back(make_pair(int(t.size()), H));
	}

	for(int i = 0; i < HASSS.size(); i++){
		bool nf = true;
		if(HASSS[i].first > m){
			puts("N");
			continue;
		}
		for(int j = 0; j < s.size() - HASSS[i].first + 1; j++){
			ll cur = h[j + HASSS[i].first - 1];
			if(j > 0){
				cur -= h[j-1];
			}

			if(cur == HASSS[i].second * p[j]){
				puts("Y");
				nf = false;
				break;
			}
		}
		if(nf) puts("N");
	}
}