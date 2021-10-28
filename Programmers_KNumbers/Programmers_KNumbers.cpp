//https://programmers.co.kr/learn/courses/30/lessons/42748
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> array, vector<vector<int>> commands);
int main()
{
    vector<int> array = { 1,5,2,6,3,7,4 };
    vector<vector<int>> commands = { {2,5,3},{4,4,1},{1,7,3} };
    vector<int> result = solution(array, commands);
}
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    int a = 0;
    int b = 0;
    int c = 0;
    int i = 0;
    for (int i = 0; i < commands.size(); i++)
    {
            temp.resize(0);
            a = commands[i][0];
            b = commands[i][1];
            c = commands[i][2];
            for (int k=a-1; k<b; k++)
            {
                temp.push_back(array[k]);
            }
            sort(temp.begin(), temp.end());
            answer.push_back(temp[c-1]);
    }
    return answer;
}
