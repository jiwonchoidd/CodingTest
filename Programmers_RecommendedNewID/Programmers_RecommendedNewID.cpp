//https://programmers.co.kr/learn/courses/30/lessons/72410
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string solution(string new_id);
int main()
{
	cout << solution("abcdefghijklmn.p") << endl;
}
string solution(string new_id) {
    string answer;
    //1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    for (string::iterator iter = new_id.begin(); iter != new_id.end(); ++iter)
    {
        if (*iter <= 90 && *iter >= 65)
        {
            *iter = *iter + 32;
        }
    }
    //2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    for (string::iterator iter = new_id.begin(); iter != new_id.end(); ++iter)
    {
        //소문자
        if (*iter >=97 || *iter >= 48 && *iter <= 57 || *iter == '-' || *iter == '_' || *iter == '.')
        {
            continue;
        }
        new_id.erase(iter);
        if (iter != new_id.begin())
        iter--;
    }
    //3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    int con = 0;
    for (string::iterator iter = new_id.begin(); iter != new_id.end(); ++iter)
    {
        if (*iter == '.')
        {
            con++;
            if (con > 1)
            {
                new_id.erase(iter);
                iter--;
            }
        }
        else
        {
            con = 0;
        }
    }
    //4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    if (new_id.length() > 0)
    {
        if (new_id.front() == '.')
        {
            new_id.erase(0, 1);
        }
    }
    if (new_id.length() > 0)
    {
        if (new_id.back() == '.')
        {
            new_id.pop_back();
        }
    }
    //5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if (new_id.length() == 0)
    {
        new_id.push_back('a');
    }
    //6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
    if (new_id.length() >= 16)
    {
        while (new_id.length() > 15)
        {
            new_id.pop_back();
        }
    }
    //만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    if (new_id.back() == '.')
    {
        new_id.pop_back();
    }
    //7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    if (new_id.length() <= 2)
    {
        char temp = new_id.back();
        while (new_id.length() < 3)
        {
            new_id.push_back(temp);
        }
    }
    return new_id;
}

#pragma region 효율성 개선
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string new_id) {
//    //1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
//    for (string::iterator iter = new_id.begin(); iter != new_id.end(); ++iter)
//    {
//        if (*iter <= 90 && *iter >= 65)
//        {
//            *iter = *iter + 32;
//        }
//    }
//    //2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
//    for (int i = 0; i < new_id.length(); ) {
//        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')
//            || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
//        {
//            i++;
//            continue;
//        }
//
//        new_id.erase(new_id.begin() + i);
//    }
//    //3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
//    for (int i = 1; i < new_id.length(); ) {
//        if (new_id[i] == '.' && new_id[i - 1] == '.') {
//            new_id.erase(new_id.begin() + i);
//            continue;
//        }
//        else i++;
//    }
//    //4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
//    if (new_id.front() == '.') new_id.erase(new_id.begin());
//    if (new_id.back() == '.') new_id.erase(new_id.end() - 1);
//    //5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
//    if (new_id.length() == 0)
//    {
//        new_id.push_back('a');
//    }
//    //6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
//    if (new_id.length() >= 16)
//    {
//        while (new_id.length() > 15)
//        {
//            new_id.pop_back();
//        }
//    }
//    //만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
//    if (new_id.back() == '.')
//    {
//        new_id.pop_back();
//    }
//    //7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
//    if (new_id.length() <= 2)
//    {
//        char temp = new_id.back();
//        while (new_id.length() < 3)
//        {
//            new_id.push_back(temp);
//        }
//    }
//    return new_id;
//}
#pragma endregion
