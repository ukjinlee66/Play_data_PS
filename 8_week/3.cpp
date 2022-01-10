#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <utility>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P> > PQ;
const int MAX_V = 20000;
const int INF = INT_MAX;
int maxn;
bool visit[MAX_V];
vector<P> adj[MAX_V];
int dist[MAX_V];
int solution(int n, vector<vector<int>> edge) 
{
    int answer = 0;
    fill(dist, dist+MAX_V, INF);
    dist[0] = 0;
    for(int i=0;i<edge.size();i++)
    {
        adj[edge[i][0]-1].push_back(P(edge[i][1]-1, 1));
        adj[edge[i][1]-1].push_back(P(edge[i][0]-1,1));   
    }
    PQ.push(P(0,0));
    while (!PQ.empty())
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
                dist[next] = dist[cur] + cost;
                maxn = max(maxn, dist[next]);
                PQ.push(P(dist[next],next));
            }
        }
    }
    for(int i=0;i<n;i++)
        if (dist[i] == maxn)
            answer++;
    return answer;
}
