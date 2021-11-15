#include "Scatch.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution1(string phone_number) {
    string::iterator iter;
    for (iter = phone_number.begin(); iter != phone_number.end() - 4; iter++)
    {
        *iter = '*';
    }

    return phone_number;
}
//https://programmers.co.kr/learn/courses/30/lessons/12935
vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int minindx = 0;
    if (arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }
    //제일 작은 인덱스 구하기
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[minindx]> arr[i])
        {
            minindx = i;
        }
    }
    arr.erase(arr.begin() + minindx, arr.begin() + (minindx + 1));
    return arr;
}

int main()
{
    vector<int> e = solution({ 1,2,3,4,5,6,7,8,9 });
}