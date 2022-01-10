#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int ,int> P;
const int MAX_E = 2001;
const int MAX_V = 51;
const int INF = INT_MAX;
int solution(int N, vector<vector<int> > road, int K) 
{
    int answer = 1;
    vector<P> adj[MAX_V];
    int dist[MAX_V];
    bool visit[MAX_V]={false};
    fill(dist,dist+MAX_V,INF);
    dist[0]=0;
    priority_queue<P, vector<P>, greater<P>> PQ;
    for(int i=0;i<road.size();i++)
    {
        int first = road[i][0] -1;
        int second = road[i][1] -1;
        int cost = road[i][2];
        adj[first].push_back(P(second,cost));
        adj[second].push_back(P(first,cost));
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
            if (dist[next] > dist[cur]+cost)
            {
                dist[next] = dist[cur]+cost;
                PQ.push(P(dist[next],next));
            }
        }
    }
    for(int i=1;i<N;i++)
        if (dist[i] <= K) answer++;
    return answer;
}
