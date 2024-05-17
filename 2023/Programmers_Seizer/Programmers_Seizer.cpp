//https://programmers.co.kr/learn/courses/30/lessons/12926
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string solution(string s, int n) {
    string answer = "";
    string::iterator iter;
    for (iter = s.begin(); iter != s.end();)
    {
        char a = *iter;
        if (a >=65 && a <= 122)
        {
            for (int i = 0; i < n; i++)
            {
                a += 1;
                if (a == 91)
                {
                    a = 65;
                }
                if (a == 123)
                {
                    a = 97;
                }
            }
        }
        else
        {
          
        }
        answer.push_back(a);
        iter++;
    }
    return answer;
}

int main()
{
    //테스트 케이스
    string case1 = "a B z";
    solution(case1, 4);
}
