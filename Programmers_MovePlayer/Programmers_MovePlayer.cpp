#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solution(string dirs);
int main()
{
	cout << solution("LULLLLLLU") << endl;
}
int solution(string dirs)
{
	int x = 0;
	int y = 0;
	int count = 0;
	vector<pair<int, int>> mem;
	for (string::iterator iter = dirs.begin(); iter != dirs.end(); iter++)
	{
		if (*iter == 'U')
		{
			y++;
			mem.push_back(make_pair(x, y));
		}
		else if (*iter == 'D')
		{
			y--;
			mem.push_back(make_pair(x, y));
		}
		else if (*iter == 'R')
		{
			x++;
			mem.push_back(make_pair(x, y));
		}
		else if (*iter == 'L')
		{
			x--;
			mem.push_back(make_pair(x, y));
		}
		if (x > -5) x=-5;
		if (x < 5) x=5;
		if (y > -5)y=-5;
		if (y < 5)y=5;
	}
	sort(mem.begin(), mem.end());
	//중복 검사
	for (vector<pair<int, int>>::iterator iter = mem.begin()+1; iter != mem.end(); iter++)
	{
		if (*iter == *(iter -1))
		{
			continue;
		}
		else
		{
			count++;
		}
	}
	return count;
}

