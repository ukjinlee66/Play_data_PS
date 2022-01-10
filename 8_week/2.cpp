#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <climits>
#include <vector>
#include <functional>
using namespace std;
typedef pair<int, int> P;
int N,M,K,X;
const int MAX_V = 300000;
const int INF = INT_MAX;
bool visit[MAX_V];
priority_queue<P, vector<P>, greater<P> > PQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K>>X;
	vector<P> adj[MAX_V];
	int dist[MAX_V];
	fill(dist,dist+MAX_V,INF);
	dist[X-1]=0;
	for(int i=0;i<M;i++)
	{
		int first,second;
		cin>>first>>second;
		adj[first-1].push_back(P(second-1,1));
	}
	PQ.push(P(0,X-1));
	while(!PQ.empty())
	{
		int cur;
		do
		{
			cur = PQ.top().second;
			PQ.pop();
		}while(!PQ.empty() && visit[cur]);
		if (visit[cur]) break;
		visit[cur] = true;
		
		for(auto &p : adj[cur])
		{
			int next = p.first; int cost = p.second;
			if (dist[next] > dist[cur] + cost)
			{
				dist[next] = dist[cur]+cost;
				PQ.push(P(dist[next],next));
			}
		}
	}
	bool flag=false;
	for(int i=0;i<N;i++)
	{
		if (dist[i] == K)
		{
			if (i != N-1)
				cout<<i+1<<'\n';
			else
				cout<<i+1;
			if (!flag) flag = true;
		}
	}
	if (!flag) cout<<-1;
	return (0);
}
