#include <iostream>
#include <cmath>
using namespace std;
int dp[3][310];
int arr[301];
int res=0;
int N=0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>arr[i];
	dp[1][0] = arr[0]; 
	dp[2][1] = arr[0]+arr[1]; dp[1][1] = arr[1];
	for(int i=2;i<N;i++)
	{
		dp[1][i] = max(dp[1][i], max(dp[2][i-2], dp[1][i-2])) + arr[i];
		dp[2][i] = max(dp[2][i], dp[1][i-1]) + arr[i];
	}
	cout << max(dp[1][N-1], dp[2][N-1]);
	return (0);
}
