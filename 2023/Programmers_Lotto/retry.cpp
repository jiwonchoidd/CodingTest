//https://programmers.co.kr/learn/courses/30/lessons/77484
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> lottos, vector<int> win_nums);
int main()
{
    vector<int> lottos = { 44,1,0,0,31,25 };
    vector<int> win = { 31,10,45,1,6,19 };
    solution(lottos, win);
}
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int match = 0;
    int zero = 0;
    int good = 0;
    int bad = 0;
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());

    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            zero++;
            continue;
        }
        for (int j = 0; j < win_nums.size(); j++)
        {
            if (lottos[i] == win_nums[j])
            {
                match++;
            }
        }
    }
    good = 7 - (match + zero);
    bad = 7 - match;
    if (good > 6)
    {
        good = 6;
    }
    if (bad > 6)
    {
        bad = 6;
    }
    answer.push_back(good);
    answer.push_back(bad);
    return answer;
}