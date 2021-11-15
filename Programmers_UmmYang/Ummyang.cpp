//https://programmers.co.kr/learn/courses/30/lessons/76501
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int temp = 0;
    for (int index = 0; index < absolutes.size(); index++)
    {
        temp=absolutes[index];
        if (!signs[index])
        {
            temp=-temp;
        }
        answer += temp;
    }
    
    return answer;
}

int main()
{
}