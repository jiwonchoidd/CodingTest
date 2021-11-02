//https://programmers.co.kr/learn/courses/30/lessons/64061
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int solution(vector<vector<int>> board, vector<int> moves);
int pop(vector<int>& presult, int doll)
{
    int answer=0;
    //��ġ�� ���� ����
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

//int solution(vector<vector<int>> board, vector<int> moves) {
//    int answer = 0;
//    vector<int> result;
//    vector<int> *presult=&result;
//
//    int index = 0;
//
//    for (vector<int>::iterator iter = moves.begin(); iter != moves.end(); iter++)
//    {
//        for (int i = 0; i < 5; i++)
//        {
//            int doll = board[i][*iter - 1];
//            //������ �ִٸ�?
//            if (board[i][*iter - 1] != 0)
//            {
//                //�ٷ� �迭 �߰� 
//                result.push_back(doll);
//
//                //��ġ�� ���� ����
//                answer +=pop(*presult, doll);
//                //���� �����ϰ� 0���� �ٽ� �־���
//                board[i][*iter - 1] = 0;
//                break;
//            }
//        }
//    }
//    return answer;
//}
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    //���� ���Լ���
    stack<int> st;
    for (int i = 0; i < moves.size(); i++)
    {
        int check = moves[i] - 1;
        for (int j = 0; j < board.size(); j++)
        {
            //0�̾ƴ϶�� �������̶��
            if (board[j][check] != 0)
            {
                //������� �ʰ� ���� �Ͱ� ���ٸ�
                if (!st.empty() && st.top() == board[j][check])
                {
                    st.pop();
                    answer += 2;
                }
                else
                {
                    st.push(board[j][check]);
                }
                board[j][check] = 0;
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