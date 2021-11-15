//https://programmers.co.kr/learn/courses/30/lessons/12917
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    char temp;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            if (i == j)
            {
                continue;
            }
            else if (s[i] > s[j])
            {
                temp = s[j];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    return s;
}