//https://programmers.co.kr/learn/courses/30/lessons/42576
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
string solution(vector<string> participant, vector<string> completion) 
{
    map<string, int> list;

    for (auto name : participant)
    {
        list[name]++;
    }
    for (auto part : completion)
    {
        list[part]--;
    }

    for (auto result : list)
    {
        if (result.second > 0)
        {
            return result.first;
        }
    }
    return "";
   
}

int main()
{
    vector<string> partcipant = { "leo", "kiki", "eden" };
    vector<string> completion = { "eden", "kiki" };

    std::cout << solution(partcipant, completion);
}