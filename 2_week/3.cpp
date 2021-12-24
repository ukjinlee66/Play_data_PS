#include <iostream>
using namespace std;
int N,M;
int ar[20000001],br[20000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int a;
		cin>>a;
		ar[a+=10000000]++;
	}
	cin>>M;
	for(int i=0;i<M;i++)
	{
		int b;
		cin>>b;
		cout<<ar[b + 10000000]<<" ";
	}
	return (0);
}
