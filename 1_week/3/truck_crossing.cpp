#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0, bridge_weight=0;
    queue<pair<int,int>> bridge;
    queue<int> truck;
    for(int i=0;i<truck_weights.size();i++)
        truck.push(truck_weights[i]);
    while (!bridge.empty() || !truck.empty())
    {
        while (!bridge.empty() && bridge.front().second == bridge_length)
        {
            bridge_weight -= bridge.front().first;
            bridge.pop();
        }
        if (!truck.empty() &&  bridge_weight + truck.front() <= weight)
        {
            bridge.push(make_pair(truck.front(),0));
            bridge_weight += truck.front();
            truck.pop();
        }
        if(!bridge.empty())
        {
            int len = bridge.size();
            while (len--)
            {
                bridge.push(make_pair(bridge.front().first, bridge.front().second+1));
                bridge.pop();
            }
        }
        answer++;
    }
    return answer;
}
