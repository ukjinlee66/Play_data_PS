#include <iostream>
#include <string>
using namespace std;
string N;
int L;
long long res;
int R = 31;
int M = 1234567891;
long long POW(int r, int n)
{
	long long ret = 1;
	if (n == 0) return 1;
	else if (n == 1) return r;
	else{
		for(int i=0;i<n;i++)
		{
			ret *= r;
			ret %= M;
		}
		return ret;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>L;
	cin>>N;
	for(int i=0;i<L;i++)
	{
		res += (((N[i]-'a')+1) * POW(R,i));
		res %= M;
	}
	cout << res % M;
	return (0);
}
