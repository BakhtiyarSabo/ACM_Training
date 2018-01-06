#include <bits/stdc++.h>

using namespace std;

#define N 100100
#define mp make_pair
#define pb push_back

int d[N], low[N], counter, n, m;
vector <int> g[N], ans;
map < pair<int, int>, int> edge;

void dfs(int x, int parent) {
  d[x] = low[x] = counter++;
  for(auto y : g[x]) {
    if (y != parent) {
      if (d[y] == 0) {
        dfs(y, x);
        if (low[y] == d[y]) {
          // ребро (x,y) - мост
          ans.pb(edge[mp(min(x,y), max(x,y))]);
        }
        low[x] = min(low[x], low[y]);
      } else {
        low[x] = min(low[x], d[y]);
      }
    }
  }

 // if (d[x] == low[x] && (parent != -1 || kids >= 2)) {
    // вершина x - точка сочленения
  //}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
		edge[mp(min(a, b), max(a, b))] = i+1; 
	}	
	memset(d, 0, sizeof(d));
	counter = 1;
	for (int x = 0; x < N; x++) if (d[x] == 0) dfs(x, -1);
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for(auto to: ans) cout << to << ' ';
	return 0;
}
