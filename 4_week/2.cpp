#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string N;
int B,len,res;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>B;
	len = N.size();
	for(int i=N.size()-1;i>=0;i--)
	{
		int cur = len - (i+1);
		if ('0' <= N[i] && '9'>=N[i])
			res+=(N[i]-'0') * pow(B,cur);

		else
			res += ((N[i]-'A') + 10) * pow(B, cur);

	}
	cout << res;
	return (0);
}
