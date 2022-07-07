#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <set>
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
int Landmarker(vector<vector<int>> land)
{
    int max = 0; //최댓값 저장
    //
    for (int i = 0; i < 4; i++)
    {
        //0123 하나씩 순회해서 최대 값 찾아 반환

        int col = 0; // 층수
        int step = i; // 밟은 곳, 시작은 0~3
        int hap = 0;

        while (col != land.size())
        {
            hap += land[col][step];
            if (step == 0)//0스텝일 경우 무조건 1
            {
                step = 1;
            }
            else if (step == 3)//3스텝일 경우 무조건 2
            {
                step = 2;
            }
            else // 나머지 경우에는 큰수로 밟음
            {
                //마지막 숫자는 하지 않아야함
                if (col != land.size() - 1)
                    (land[col + 1][step - 1] > land[col + 1][step + 1]) ? step-- : step++;
            }
            col++;
        }
        if (hap > max)max = hap;
    }
    return max;
}

string to_binary(int num) {
    string s = "";
    while (num > 0) {
        if (num % 2 == 1) s = "1" + s;
        else s = "0" + s;
        num >>= 1;
    }
    return s;
}

vector<int> Dev_function(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> work_que;
    size_t count = 0;
    bool publishing = false;
    for (int i = 0; i < progresses.size(); i++)
    {
        work_que.push(i);
    }
    while (!work_que.empty())
    {
        
        if (progresses[work_que.front()] >= 100)
        {
            publishing = true;
            count++;
            
            continue;
        }
        if (publishing)
        {
            answer.push_back(count);
            publishing = false;
            while(count!=0)
            {
                if (!work_que.empty())
                work_que.pop();
                --count;
            }
        }
        else if (!publishing)
        {
            for (int idx = 0; idx < progresses.size(); idx++)
            {
                progresses[idx] = progresses[idx] + speeds[idx];
            }
        }

        
    }
    return answer;
}

int Solu(vector<vector<int>> quest) {
    size_t iexp = 0; //초기 경험치
    size_t quested = 0; // 완료된 퀘스트
    map<int, bool> prog;
    //허락된 허용치의 퀘스트 찾기
    for (size_t idx = 0; idx < quest.size(); idx++)
    {
        //빠른 탐색을 위해 Map 사용
        if (prog.find(idx) != prog.end())
        {
            //이미 맵에 존재한다면 
            continue;
        }

        //가능한 퀘스트, 퀘스트를 완료시키고, 경험치를 올려준다.
        if (quest[idx][0] <= iexp)
        {
            prog.insert(make_pair(idx, true));
            quested += 1;
            iexp += quest[idx][1];
            //다시 처음부터 배열 순회
            idx = -1;
            continue;
        }
    }
    return quested;
}


//맵 위치가 허용되는 범위인지 확인하는 함수
bool SizeCheck(vector<vector<int>> field, int farmSize, int y, int x)
{
    //전체 맵 크기
    int row = field.size() - 1;
    int col = field[0].size() - 1;
    //범위안에 드는 위치임
    if (y + (farmSize - 1) >= 0 && y + (farmSize - 1) <= row)
    {
        if (x + (farmSize - 1) >= 0 && x + (farmSize - 1) <= col)
            return true;
    }
    return false;
}

//수고가 덜한 곳 고르기
// 0 - 노말, 1 - 돌, 2- 독버섯
int solu2(vector<vector<int>> field, int farmSize) {
    map<int, int> possible_Area;  // 맵 순서 와 돌 갯수 저장
    int area_index = 0;
    //밑에서부터 시작함
    for (int i = 0; i < field.size(); i++)
    {
        for (int j = 0; j < field[0].size(); j++)
        {
            //사이즈 체크
            if (!SizeCheck(field, farmSize, i, j))break;
            int x = 0;
            int stone = 0;
            int mush = 0;
            //맵탐색
            while (x != farmSize - 1)
            {
                int y = 0;
                while (y != farmSize - 1)
                {
                    if (field[x][y] == 2)
                    {
                        mush += 1;
                    }
                    else if (field[x][y] == 1)stone += 1;
                    y += 1;
                }
                x += 1;
            }
            if (mush == 0)
            {
                possible_Area.insert(make_pair(area_index, stone));
                area_index++;
            }
        }
    }

    if (possible_Area.empty())
    {
        return -1;
    }
    int min = 0;
    auto iter = possible_Area.begin();
    while (iter != possible_Area.end()) {
        if (min > iter->second)
            min = iter->second;
        ++iter;
    }

    for (auto const& area : possible_Area)
    {
        if (area.second == min)
        {
            return area.first;
        }
    }
}


int sol3(vector<int>& A)
{
    //Bubble Sort, Sort()함수 대신 구현 
    for (int i = 0; i < A.size() - 1; i++)
    {
        for (int j = 1; j < A.size() - i; j++)
        {
            if (A[j - 1] > A[j])
            {
                int temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
            }
        }
    }

    for (int i = 1; i < A.size(); i++)
    {
        if (A[i - 1] + 1 == A[i] || A[i - 1] == A[i])
        {
            continue;
        }
        else
        {
            if (A[i - 1] + 1 < 0)
                return 1;
            else
                return A[i - 1] + 1;
        }
    }

}

bool UniqueStr(string s)
{
    set<char> uniSet;

    for (int i = 0; i < s.length(); i++)
    {
        if (uniSet.count(s[i]) != 0)
        {
            return false;
        }
        uniSet.insert(s[i]);
    }

    return true;
}
int main()
{

    string a = "aBa";
    UniqueStr(a);
}
