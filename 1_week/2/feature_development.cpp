#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    queue<pair<pair<int,int>,int>> Q;
    for(int i=0;i<progresses.size();i++)
        Q.push(make_pair(make_pair(progresses[i], speeds[i]),i));
    int cnt = 0,day = 1;
    while (!Q.empty())
    {
        if (Q.front().first.first + (Q.front().first.second * day) >= 100)
        {
            Q.pop();
            cnt++;
            if (Q.empty())
            {
                answer.push_back(cnt);
                break;
            }
            else if (Q.front().first.first + (Q.front().first.second * day) < 100)
            {
                answer.push_back(cnt);
                cnt = 0;
            }
        }
        else if (Q.front().second == progresses.size() - 1)
        {
            if (cnt > 0)
            {
                answer.push_back(cnt);
                cnt = 0;
            }
            else
                day++;
        }
        else
            day++;
    }
    return answer;
}
