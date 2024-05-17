//https://programmers.co.kr/learn/courses/30/lessons/77484
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> lottos, vector<int> win_nums);
int main()
{
    int lottos[6] = { 44,1,0,0,31,25 };
    int win[6] = { 31,10,45,1,6,19};
    size_t size = 6;
}
vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
        vector<int> answer;
    int indexMin, temp;
    int match = 0;
    int zero = 0;
    //선택 정렬
    for (int i = 0; i < lottos.size()-1; i++) {
        indexMin = i;
        for (int j = i + 1; j < lottos.size(); j++) {
            if (lottos[j] < lottos[indexMin]) 
            {
                indexMin = j;
            }
        }
        temp = lottos[indexMin];
        lottos[indexMin] = lottos[i];
        lottos[i] = temp;
    }
    //선택정렬
    for (int i = 0; i < win_nums.size()- 1; i++)
    {
        indexMin = i;
        for (int j = i + 1; j < win_nums.size(); j++) {
            if (win_nums[j] < win_nums[indexMin])
            {
                indexMin = j;
            }
        }
        temp = win_nums[indexMin];
        win_nums[indexMin] = win_nums[i];
        win_nums[i] = temp;
    }

    for (int zerocheck = 0; zerocheck < 6; zerocheck++)
    {
        if (lottos[zerocheck] != 0)
        {
            break;
        }
        zero++;
    }

    //비교
    for (int i = 0; i < win_nums.size(); i++)
    {
        for (int j = 0; j < lottos.size(); j++)
        {
            if (win_nums[i] == lottos[j])
            {
                match++;
                break;
            }
        }
    }
    int good = (6 - (match + zero)) + 1;
    int bad = (6 - match) + 1;
    if (zero == 6)
    {
        good = 1;
        bad = 6;
    }
    vector<int> result = { good ,bad };
    answer = result;
    return answer;
}
