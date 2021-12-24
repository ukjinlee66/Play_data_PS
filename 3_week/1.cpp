#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
bool check[1001];
int map[1001][1001];
int N, M, start;
void BFS(int n)
{
	check[n]=true;
	queue<int> Q;
	Q.push(n);
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		cout<<cur<<" ";
		for(int i=1;i<=N;i++)
		{
			if (!check[i] && map[cur][i] == 1)
			{
				check[i]=true;
				Q.push(i);
			}
		}
	}
}
void DFS(int n)
{
	cout <<n<<" ";
	for(int i=1;i<=N;i++)
	{
		if (!check[i] && map[n][i] == 1)
		{
			check[i]=true;
			DFS(i);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N >> M >> start; 
	for(int i=0;i<M;i++)
	{
		int in1,in2;
		cin>> in1>>in2;
		map[in1][in2]=1;
		map[in2][in1]=1;
	}
	check[start]=true;
	DFS(start);
	cout<<endl;
	memset(check, false, sizeof(check));
	BFS(start);
	return (0);
}
