#include <string>
#include <vector>

using namespace std;

int abs(int n)
{
    if (n < 0) return -n;
    else return n;
}

int distance(int pos, int dest)
{
    int dist = 0;

    dist += abs((pos - 1) / 3 - (dest - 1) / 3); // 행의 차이       
    dist += abs((pos - 1) % 3 - (dest - 1) % 3); // 열의 차이

    return dist;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int left = 10, right = 12;

    for (int i = 0; i < numbers.size(); i++)
    {
        int num = (numbers[i] != 0 ? numbers[i] : 11);

        if (num % 3 == 1)
        {
            left = num;
            answer.append("L");
        }
        else if (num % 3 == 0)
        {
            right = num;
            answer.append("R");
        }
        else
        {
            int left_dist = distance(left, num);
            int right_dist = distance(right, num);

            if (left_dist < right_dist)
            {
                left = num;
                answer.append("L");
            }
            else if (right_dist < left_dist)
            {
                right = num;
                answer.append("R");
            }
            else if (right_dist == left_dist)
            {
                if (hand == "left")
                {
                    left = num;
                    answer.append("L");
                }
                else if (hand == "right")
                {
                    right = num;
                    answer.append("R");
                }
            }
        }
    }

    return answer;
}