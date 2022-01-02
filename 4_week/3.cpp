#include <string>
#include <vector>
using namespace std;
string conv(int num, int n)
{
    int m = num;
    long long ret=0;
    string ret1="";
    string ret2="";
    for(long long i=1;num>0;i*=10)
    {
        long long bi = num % 2;
        ret += bi*i;
        num /= 2;
    }
    ret1 = to_string(ret);
    if (m == 0)
        ret1="";
    if (ret1.size() < n)
    {
        int len = n - ret1.size();
        ret2.append(len,'0');
    }
    ret2 += ret1;
    return ret2;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer;
    for(int i=0;i<n;i++)
    {
        string str = conv(arr1[i], n);
        string str2 = conv(arr2[i],n);
        string str3 = "";
        for(int j=0;j<str.size();j++)
        {
            if (str[j] == '0' && str2[j] == '0')
                str3+=' ';
            else
                str3+='#';
        }
        answer.push_back(str3);
    }
    return answer;
}
