#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer = 0;
    int first=0, second=people.size()-1;
    sort(people.begin(),people.end());
    while (first <= second)
    {
        if (people[first] + people[second] <= limit)
        {
            answer++; first++; second--;
        }
        else
        {
            answer++; second--;
        }
    }
    return answer;
}
