//https://programmers.co.kr/learn/courses/30/lessons/64061
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> board, vector<int> moves);
int pop(vector<int>& presult, int doll)
{
    int answer=0;
    //겹치는 숫자 제거
    if (presult.size() > 2)
    {
        if (presult[presult.size() - 2] == doll)
        {
            presult.pop_back();
            presult.pop_back();
            answer += 2;
            answer += pop(presult, presult.back());
        }
    }
    return answer;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> result;
    vector<int> *presult=&result;

    int index = 0;

    for (vector<int>::iterator iter = moves.begin(); iter != moves.end(); iter++)
    {
        for (int i = 0; i < 5; i++)
        {
            int doll = board[i][*iter - 1];
            //인형이 있다면?
            if (board[i][*iter - 1] != 0)
            {
                //바로 배열 추가 
                result.push_back(doll);

                //겹치는 숫자 제거
                answer +=pop(*presult, doll);
                //인형 제거하고 0으로 다시 넣어줌
                board[i][*iter - 1] = 0;
                break;
            }
        }
    }
    return answer;
}
int main()
{
    vector<vector<int>> board = { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
    vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };
    solution(board, moves);
}