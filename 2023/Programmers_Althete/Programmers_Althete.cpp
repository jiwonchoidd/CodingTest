//https://programmers.co.kr/learn/courses/30/lessons/42862#
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    int canHelp = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (int ihelp = 0; ihelp < reserve.size(); ihelp++)
    {
        for (int ilost = 0; ilost < lost.size(); ilost++)
        {
            if (lost[ilost] == -2 || reserve[ihelp]==-2)continue;

            if (lost[ilost] == reserve[ihelp] + 1 || lost[ilost] == reserve[ihelp] - 1)
            {
                //앞뒤 사람
                canHelp++;
                reserve[ihelp] = -2;
                lost[ilost] = -2;
                continue;
            }
        }
    }
    return answer + canHelp;
}

int main()
{
    vector<int> a = { 2,4 };
    vector<int> b = { 3 };
    solution(5, a, b);
}


int solution(int n, vector<int> lost, vector<int> reserve) {

    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i = -1;
                break;
            }
        }
    }

    int answer = n - lost.size();

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j]) {
                answer++;
                reserve.erase(reserve.begin() + j);
                break;
            }
        }
    }

    return answer;
}