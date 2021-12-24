#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
bool check[1001];
int map[1001][1001];
int N, M,res;
void DFS(int n)
{
	for(int i=1;i<=N;i++)
	{
		if (!check[i] && map[n][i])
		{
			check[i]=true;
			res++;
			DFS(i);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		int in1, in2;
		cin>>in1>>in2;
		map[in1][in2]=1;
		map[in2][in1]=1;
	}
	check[1]=true;
	DFS(1);
	cout<<res;
	return (0);
}
