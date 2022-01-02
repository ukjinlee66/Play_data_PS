#include <iostream>
#include <cstring>
using namespace std;
int fact[6];
int make_fact(int n)
{
	int ret = 1;
	for(int i=n;i>=1;i--)
		ret*=i;
	return (ret);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=5;i>=1;i--)
		fact[i - 1] = make_fact(i);
	while(1)
	{
		string str;
		int ret = 0;
		cin>>str;
		if (str == "0") break;
		int len = str.size();
		for(int i=0;i<str.size();i++)
		{
			ret += (str[i]-'0') * fact[--len];
		}
		cout<<ret<<'\n';
	}
	return (0);
}
