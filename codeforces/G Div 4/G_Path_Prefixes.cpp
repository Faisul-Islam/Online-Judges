#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int v, w;
};

vector<Node> a[1000001];
int D[100001];
bool color[100001], vis[100001];
void dfs(int u) {
	if(vis[u]) return;
	vis[u]=1;
	for(Node A: a[u]) {
		D[A.v]=D[u]+A.w;
		if(D[A.v]%2==0) color[A.v]=1;
		else color[A.v]=0;
		dfs(A.v);
	}
}

int main() {
	int n;
	cin >> n;
	for(int i=1; i<n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back({v, w});
		a[v].push_back({u, w});
	}
	
	memset(vis, 0, n+1);
	memset(D, 0, n+1);
	for(int i=1; i<=n; ++i) {
		if(!vis[i]) {
			color[i]=1; 
			dfs(i);
		}
	}
	for(int i=1; i<=n; ++i) cout << color[i] << ' ';
	return 0;
}