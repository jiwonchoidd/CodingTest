#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int>& A, int K)
{
    unsigned int arraySize = A.size();
    //K번수 만큼 반복
    while (K != -1)
    {
        A.pop_back();
        A.insert(A.begin(), A.back());
        K--;
    }
    return A;
}

int NumberPlus(int n)
{
        int temp = n;
        int count = 0;
        int answer = 0;
        while (temp != 0)
        {
            temp = temp / 10;
            ++count;
        }
        for (int i = 0; i < count; i++)
        {
            int pos = pow(10, i);
            answer += n % pos;
        }
        return answer;
}
vector<int> Lastpoint(vector<vector<int> > v) {
    vector<int> answer;
    int x = 0;
    int y = 0;
    vector<int>& temp = v[0];
    x = temp[0] ^ temp[1] ^ temp[2];
    temp = v[1];
    y = temp[0] ^ temp[1] ^ temp[2];
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}

void BubbleSort(vector<int>& numbers)
{
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        for (int j = 1; j < numbers.size() - i; j++)
        {
            if (numbers[j - 1] > numbers[j])
            {
                int temp = numbers[j - 1];
                numbers[j - 1] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

int sol6(vector<int> numbers) {
    //정렬
    int sum = 0;
    int index = 0;
    BubbleSort(numbers);
    for (int idx = 0; idx < 10; idx++)
    {
        
        if (numbers[index] != idx)
        {
            //해당 번호가 없음
            sum += idx;
        }
        else
        {
            index++;
        }
    }
    return sum;
}
//스택을 이용해 문자 중복 이어 제거
int sol7(string s)
{
    stack<char> str;
    for (int i = 0; i < s.length(); i++)
    {

        if (str.empty() || str.top() != s[i])
        {
            str.push(s[i]);
        }
        else if (str.top() == s[i])
        {
            str.pop();
        }
    }
    //스택이 비어있다면 모두제거한것이므로 1리턴
    if (str.empty())    return true;
    return false;
}
int main()
{
    string s = "cdccd";
    sol7(s);
}
