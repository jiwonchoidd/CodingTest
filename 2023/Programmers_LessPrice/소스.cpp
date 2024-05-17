#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long temp;
    long long r_money;
    long long r_price;
    long long r_count;
    r_money = static_cast<long long>(money);
    r_price = static_cast<long long>(price);
    r_count = static_cast<long long>(count);
    for (long long i = 1; i <= count; i++)
    {
        temp = static_cast<long long>(r_price * i);
        r_money -= temp;
    }
    if (money < 0)
    {
        return -r_money;
    }
    else

    return 0;
}
int main() 
{
    cout << solution(3,20,4) << endl;
}