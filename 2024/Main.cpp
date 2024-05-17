#include <iostream>
#include <vector>
using namespace std;
int main()
{
    uint8_t PlacedCardCount;
    uint32_t SumReachedCount;

    cin>>PlacedCardCount>>SumReachedCount;

    vector<uint32_t> PlacedCards;

    {
        for(auto Index = 0; Index < PlacedCardCount; ++Index)
        {
            uint32_t PlacedCardNum;
            cin>>PlacedCardNum;
            PlacedCards.push_back(PlacedCardNum);
        }

    }
   
    uint32_t Result = 0;
    int LessDiff = -1;
    for(auto a = 0; a < PlacedCards.size() - 2; ++a)
    {
        for(auto b = a + 1; b < PlacedCards.size() - 1; ++b)
            for(auto c = b + 1; c < PlacedCards.size(); ++c )
            {
                uint32_t CheckSum = PlacedCards[a] + PlacedCards[b] + PlacedCards[c];
                int difference = abs(static_cast<int>(CheckSum) - static_cast<int>(SumReachedCount)); // 현재 합과 목표 합과의 차이를 계산

                if( LessDiff == -1 || LessDiff < difference )
                {
                    LessDiff = difference;
                    Result = CheckSum;
                }
            }
    }
    cout<<Result;
    return 0;
}