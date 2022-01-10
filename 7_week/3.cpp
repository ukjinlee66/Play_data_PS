#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int n, num, res = 123456789;
int temp;
int siz;
string str3;
void sol(int cnt, int sum)
{
    if (cnt > 8 || sum < 0) return;
    if (sum == num) // 기저
    {
        res = min(res, cnt);
        return;
    }
    sol(cnt+2,sum + 1); // (5/5)
    sol(cnt+2,sum - 1); // (5/5)
    for(int i=1;i<=str3.size();i++)
    {
        int nu = stoi(str3.substr(0,i));
        sol(cnt+i,sum + nu);
        sol(cnt+i,sum * nu);
        sol(cnt+i,sum - nu);
        sol(cnt+i,sum / nu);
    }
    for(int i=1;i<=str3.size();i++)
    {
        int nu = stoi(str3.substr(0,i));
        for(int j=1;j<=str3.size();j++)
        {
            int nu2 = stoi(str3.substr(0,j));
            if (i!=j)
            {
                sol(cnt+i+j,sum + nu/nu2);
                sol(cnt+i+j,sum - nu/nu2);
                sol(cnt+i+j,sum * nu/nu2);
            }
        }
    }
}

int solution(int N, int number) 
{
    n = N; num = number;
    string str = to_string(number); int len = str.size();
    str3.append(str.size(),N+'0');
    for(int i=1;i<=len;i++)
    {
        string str2;
        str2.append(i, N+'0');
        temp = stoi(str2);
        siz = str2.size();
        sol(i,stoi(str2));
    }
    if (res == 123456789) res = -1;
    return res;
}
