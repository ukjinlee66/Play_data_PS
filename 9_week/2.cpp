#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <climits>
#include <vector>
#include <string>
#include <functional>
using namespace std;

int ti[3]={300, 60, 10};
int answer[3];
int T, rest;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	string s = to_string(T);
	if (T%10 != 0) 
	{
		cout <<-1;
		return (0);
	}
	else
	{
		rest = T%ti[0];
		T /= ti[0];
		answer[0] += T;
		T = rest;
		rest = T%ti[1];
		T /= ti[1];
		answer[1] += T;
		T = rest;
		rest = T %ti[2];
		T /= ti[2];
		answer[2] += T;
		T = rest;
	}
	cout << answer[0] << " " << answer[1] << " " << answer[2];
	return (0);
}
