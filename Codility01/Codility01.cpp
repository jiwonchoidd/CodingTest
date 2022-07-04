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
int main()
{
    vector<int> arr = { 3,8,9,7,6 };
    solution(arr, 3);
    arr.pop_back();
}
