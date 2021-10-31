//https://programmers.co.kr/learn/courses/30/lessons/81301?language=cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(string s);
int main()
{
    string a = "one4seveneight";
    solution(a);
}
int solution(string s) {
    string answer = "";
    int result = 0;
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        //숫자일때
        if (s[i] >= 48 && s[i] <= 57)
        {
            answer += s[i];
            continue;
        }
        //숫자가 아닐때
        temp += s[i];
        if (temp=="zero"|| temp == "one" || temp == "two" || temp == "three" || temp == "four" || temp == "five" || temp == "six" || temp == "seven" || temp == "eight" || temp == "nine")
        {
            (temp == "zero") ? answer += "0" : "";
            (temp == "one") ? answer += "1" : "";
            (temp == "two") ? answer += "2" : "";
            (temp == "three") ? answer += "3" : "";
            (temp == "four") ? answer += "4" : "";
            (temp == "five") ? answer += "5" : "";
            (temp == "six") ? answer += "6" : "";
            (temp == "seven") ? answer += "7" : "";
            (temp == "eight") ? answer += "8" : "";
            (temp == "nine") ? answer += "9" : "";
            temp = "";
     
        }
    }
    
    result = stoi(answer);
    return result;
}