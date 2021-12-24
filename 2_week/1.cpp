#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;
int check[3], idx[3];
int first[5] = {1,2,3,4,5};
int second[8] = {2,1,2,3,2,4,2,5};
int third[10] = {3,3,1,1,2,2,4,4,5,5};
int max_n = INT_MIN;
vector<int> solution(vector<int> answers) 
{
    vector<int> answer;
    for(int i=0;i<answers.size();i++)
    {
        if (idx[0] == 5) idx[0] = 0;
        if (idx[1] == 8) idx[1] = 0;
        if (idx[2] == 10) idx[2] = 0;
        if (answers[i] == first[idx[0]]) check[0]++;
        if (answers[i] == second[idx[1]]) check[1]++;
        if (answers[i] == third[idx[2]]) check[2]++;
        max_n = max(check[0], max(check[1],check[2]));
        for(int j=0;j<3;j++)
            idx[j]++;
    }
    cout << max_n << endl;
    for(int i=0;i<3;i++)
        if (check[i] == max_n)
            answer.push_back(i + 1);
    sort(answer.begin(),answer.end());
    return answer;
}
