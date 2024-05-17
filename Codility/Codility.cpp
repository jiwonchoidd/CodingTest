
#include <iostream>
#include <vector>
/* 2022-07-28 최지원*/
int solution(std::vector<int>& A) {
    //버블 정렬
    for (size_t i = 0; i < A.size() - 1; i++)
    {
        for (size_t j = 0; j < A.size() - i; j++)
        {
            if (A[j - 1] > A[j])
            {
                int temp = A[j - i];
                A[j - i] = A[j];
                A[j] = temp;
            }
        }
    }
    for (size_t i = 1; i < A.size(); i++)
    {
        if (A[i - 1] > 0 && (A[i - 1] + 1) != A[i])
        {
            return (A[i - 1] + 1);
        }
    }
    return 1;
}

int main()
{
    std::cout << "Hello World!\n";
}

