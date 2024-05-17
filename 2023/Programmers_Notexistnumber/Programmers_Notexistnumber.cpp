//https://programmers.co.kr/learn/courses/30/lessons/86051?language=cpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    //0~9까지 없는 숫자는?
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (numbers[i] == j)
            {
                answer += j;
                break;
            }
        }
    }
    return 45-answer;
}

int main()
{
    int a = solution({ 1,2,3,4,5,6,7,8,0 });
    std::cout << a;
}