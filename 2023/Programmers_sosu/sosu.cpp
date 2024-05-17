//https://programmers.co.kr/learn/courses/30/lessons/12977
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solution(vector<int> nums) 
{
    int answer = 0;
    bool check[2998] = { false, };

    for (int i = 2; i < 2998; i++)
        for (int j = i + i; j < 2998; j += i)
            check[j] = true;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
        for (int j = i + 1; j < nums.size(); j++)
            for (int k = j + 1; k < nums.size(); k++)
                if (check[nums[i] + nums[j] + nums[k]] == false)
                    answer++;

    return answer;
}