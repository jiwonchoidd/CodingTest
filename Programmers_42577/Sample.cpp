#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool solution(vector<string> phone_book)
{
    unordered_map<string, int> list;
    for (int i = 0; i < phone_book.size(); i++)
    {
        list[phone_book[i]] = 1;
    }

    for (int i = 0; i < phone_book.size(); i++)
    {
        string phone_number = "";
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            phone_number += phone_book[i][j];
            if (list[phone_number] &&
                phone_number != phone_book[j])
                return false;
        }
    }
    return true;
}
void main()
{
    vector<string> book = { "119", "97674223", "1195524421" };
   
    bool result = solution(book);
}