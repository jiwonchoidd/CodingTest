#include <iostream>
#include <vector>
using namespace std;
void BubbleSort(vector<int>& A)
{
    for (size_t i = 0; i < A.size() - 1; i++)
    {
        for (size_t j = 1; j < A.size() - i; j++)
        {
            if(A[j-1]>A[j])
            int temp = A[j - 1];
            A[j - 1] = A[j];
            A[j] = temp;
        }
    }
}
int main()
{
    vector<int> A = { 1,3,6,4,1,2 };

    BubbleSort(A);
    for (size_t i = 1; i < A.size(); i++)
    {
        //다음 숫자와 이어지지 않은 경우
        if (A[i - 1] != A[i] && A[i - 1] > 0 && A[i - 1] + 1 != A[i])
        {
            return A[i - 1] + 1;
        }
    }
    return  A.back() + 1;
    std::cout << "Hello World!\n";
}
