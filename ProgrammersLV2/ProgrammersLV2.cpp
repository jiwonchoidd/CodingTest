#include <string>
#include <vector>
#include <stack>
using namespace std;
int main(int argc, char* argv[])
{
    return 0;
}

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    int MinNum = 1000000; 
    for(int i = 0; i < numbers.size(); ++i)
    {
        int MaxNum = -1;

        if(MinNum > numbers[i])
        {
            for(int j = i; j < numbers.size(); ++j)
            {
                if(numbers[i] < numbers[j])
                {
                    MaxNum = numbers[j];
                    break;
                }
            }
        }
        
        if(MaxNum == -1) 
        {
            MinNum = MinNum < numbers[i] ? MaxNum : numbers[i];
        }
        answer.push_back(MaxNum);
    }
    return answer;
}

vector<int> solution2(vector<int> numbers)
{
    std::vector<int> answer(numbers.size(), -1); 
    std::stack<int> st;
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        while (!st.empty() && numbers[st.top()] < numbers[i])
        {
            answer[st.top()] = numbers[i];
            st.pop();
        }
        st.push(i);
    }

    return answer;
}
