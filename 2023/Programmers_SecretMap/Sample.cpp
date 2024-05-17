#include <string>
#include <iostream>
#include <vector>
using namespace std;
std::vector<std::string> solution(int n, std::vector<int> arr1, std::vector<int> arr2)
{
    vector<string> answer;
    for (int i = 0; i < n; i++)
    {
        string temp = "";
        arr1[i] = arr1[i] | arr2[i];

        while (temp.size() != n)
        {
            if (arr1[i] % 2 == 0)
                temp.push_back(' ');
            else
                temp.push_back('#');
            arr1[i] /= 2;
        }

        reverse(temp.begin(), temp.end());
        answer.push_back(temp);
    }
    return answer;
}
void main()
{

}