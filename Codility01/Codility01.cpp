#include <iostream>
#include <vector>
using namespace std;
void BubbleSort(vector<int>& A)
{
    for (size_t i = 0; i < A.size() - 1; i++)
    {
        for (size_t j = 1; j < A.size() - i; j++)
        {
            if (A[j - 1] > A[j])
            {
                int iTemp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = iTemp;
            }
        }
    }
}

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
int main()
{
    NumberPlus(123);

    vector<vector<int>> arr = { {1,4}, {3,4}, {3,10} };
    Lastpoint(arr);
}
