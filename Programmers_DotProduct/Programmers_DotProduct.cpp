//https://programmers.co.kr/learn/courses/30/lessons/70128
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int solution(vector<int> a, vector<int> b) {
    int dp = 0;
    for (int i = 0; i < a.size(); i++)
    {
        dp += a[i] * b[i];
    }
    return dp;
}
int main()
{
    vector<int> a = { 1,2,3,4 };
    vector<int> b = { -3,-1,0,2 };
    solution(a, b);
}