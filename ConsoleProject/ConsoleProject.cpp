/*5 21
5 6 7 8 9*/
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int main()
{

}


int BlackJack()
{
    int PlacedCardCount;
    int SumReachedCount;

    cin >> PlacedCardCount >> SumReachedCount;

    vector<int> PlacedCards;

    for (auto Index = 0; Index < PlacedCardCount; ++Index) {
        int PlacedCardNum;
        cin >> PlacedCardNum;
        PlacedCards.push_back(PlacedCardNum);
    }

    int Result = 0;
    int LessDiff = INT_MAX; // 큰 값으로 초기화
    for (int a = 0; a < PlacedCards.size() - 2; ++a) {
        for (int b = a + 1; b < PlacedCards.size() - 1; ++b) {
            for (int c = b + 1; c < PlacedCards.size(); ++c) {
                int CheckSum = PlacedCards[a] + PlacedCards[b] + PlacedCards[c];
                int difference = abs(CheckSum - SumReachedCount); // 현재 합과 목표 합과의 차이를 계산

                if (difference < LessDiff) { // 차이가 더 작은 경우에 갱신
                    LessDiff = difference;
                    Result = CheckSum;
                }
            }
        }
    }

    cout << Result;
    return 0;
}

int YAxisDropBomb(vector<vector<int>> targets)
{
    int answer = 0;

    std::sort(targets.begin(), targets.end(), [&](vector<int>& v1, vector<int>& v2) {
        return v1[1] < v2[1];
        });

    int min = -1;

    for (int i = 0; i < targets.size(); i++) {
        int s = targets[i][0];
        int e = targets[i][1];

        if (min <= s) {
            answer++;
            min = e;
        }
    }

    return answer;
}
