#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <algorithm>
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

void reciprocal1(int N) {
    float rev_num = 1.0f / N;
    float repeat_num = rev_num;

    stack<int> st; //중복 확인 스택
    string str = "0."; //문자출력
    int idx = 0; //반복 횟수 인덱스
    while (1)
    {
        idx++;
        repeat_num = repeat_num * 10.0f;
        if (st.empty() ||
            static_cast<int>(repeat_num) % 10 != st.top())
        {
            str += to_string(static_cast<int>(repeat_num) % 10);
            st.push(static_cast<int>(repeat_num) % 10);
        }
        else if (static_cast<int>(repeat_num) % 10 == st.top())
        {
            //중복되는 숫자 발견, 한번더 중복 확인
            repeat_num = repeat_num * 10.0f;
            st.push(static_cast<int>(repeat_num) % 10);
            if (static_cast<int>(repeat_num) % 10 == st.top())
            {
                //무한히 반복되는 것 맞다 판단. while문 탈출
                repeat_num = static_cast<int>(repeat_num) % 10;
                break;
            }
        }
    }

    cout << str << " " << idx;
}

void reciprocal(int N) {

    string ans;
    
    long a = 1;
    long b = N;
    long remain = a % b; //나머지 연산
    //소수점 위의 정수부 string에 저장
    ans = to_string(a / b);
    ans.push_back('.');

    //반복되는 순환 소수를 찾기위해 나눗셈을
    //분리해서 나머지가 같을 경우에 반복되는 순환을 판별
    map <int, int> m;
    while (1) 
    {
        //나머지가 맵에 없는 유일한 수일때 추가
        if (m.find(remain) == m.end()) {
            m[remain] = ans.size();
            remain *= 10;//다음 계산을 위해 10을 곱함
            ans.push_back((remain / b) + '0'); 
            remain = remain % b;
        }
        //같은 나머지의 값이면 순환되는 것
        else if(m.find(remain) != m.end())
        {
            cout << ans;
            auto result = m.find(remain);
            cout<<" "<<ans.substr(result->second, ans.length());
            break;
        }
    }
    
}
map<string, int> mp;
int GetDistance(int ax, int ay, int bx, int by)
{
    //길이르 구한다.
    //피타고라스의 정리
    return sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
}

vector<string> closestStraightCity(vector<string> c, vector<int> x, vector<int> y, vector<string> q)
{
    vector<string> answer;
    //0. 해당 도시의 인덱스를 저장, q가 순서대로 들어오지 않을 경우, 쉽게 탐색하기 위함
    for (int idx = 0; idx < c.size(); idx++)
    {
        mp.insert(make_pair(c[idx], idx));
    }

    //1. 직선상에 본인을 제외한 같이 있는 도시 찾기 없을 경우 NONE 저장
    //2. 직선상의 도시를 찾으면서 만약에 직선상에 있다면 정답 가능성 있는 도시 배열에 거리값을 넣음
    for (int icurrent = 0; icurrent < q.size(); icurrent++)
    {
        vector<pair<int, string>> city; //정답 가능성 있는 도시 배열 key는 거리, value는 도시 이름
        city.clear(); // 명시적으로 클리어

        string current_city = q[icurrent];
        auto my_index = mp.find(current_city);

        for (int i = 0; i < c.size(); i++)
        {
            if (c[i] == current_city) continue; //본인 도시 제외

            auto other_index = mp.find(c[i]); //다른 도시

            //같은 직선 상 위치에 있는 도시일때 해당 거리를 저장
            if (x[other_index->second] == x[my_index->second] || y[other_index->second] == y[my_index->second])
            {
                int distance = GetDistance(x[my_index->second], y[my_index->second], x[other_index->second], y[other_index->second]);
                city.push_back(make_pair(distance, other_index->first));//<- 정답 가능성 있는 배열 거리까지 넣음
            }
        }
        if (city.empty())//가능한 도시가 없다면 NONE
        {
            answer.push_back("NONE");
        }
        else if (city.size() == 1)//도시 하나만 직선상에 위치하면 하나만 출력
        {
            answer.push_back(city[0].second);
        }
        else if (city.size() > 1)//만약 2개 이상이라면 제일 가깝거나 동일하면 사전순으로 넣기
        {
            //정렬 거리순, 이름까지 정렬됨
            sort(city.begin(), city.end());
            //같은 거리가 있을 경우 이름 순으로 넣어야함
            for (int i = 1; i < city.size(); i++)
            {
                //거리가 다를 경우
                if (city[i - 1].first != city[i].first)
                {
                    answer.push_back(city[i - 1].second);
                    break; //탈출
                }
                else if (city[i - 1].first == city[i].first)
                {
                    //다른 경우가 나올때까지 넣어줌
                    answer.push_back(city[i - 1].second);
                }
            }
        }
    }
    return answer;
}


typedef struct _pos {
    int x;
    int y;
}pos;


int visited[100 + 1][100 + 1];
//지나갈수없는 경우 1의 값 벽인 경우와 맵 밖일 경우, 이미 지나온 경우
bool CanVisit(int x, int y, vector<vector<int>> maze)
{
    //맵을 나갔을 경우
    if (y < 0 || y >= maze[0].size() || x < 0 || x >= maze.size())
        return false;
    //이미 지나온 경우
    if (visited[x][y] == 1)return false;
    //벽인 경우
    if (maze[x][y] == 1) return false;
    return true;
}

int minMoves(vector<vector<int>> maze, int x, int y)
{
    /*목적지는 모든 금을 모아서 혜교에게 가야함
   따라서 2를 모두 지나서 주어진 xy로 가야함
   큐를 이용한 BFS, O(v+e)*/

    //큐를 이용해 순차적으로 가까운것부터 수행
    queue<int> qy, qx, qgold, qcount;
    //초기 위치는 무조건 (0,0)에서 출발
    qy.push(0), qx.push(0); qgold.push(0);
    qcount.push(1);

    int count = -1;
    while (!qy.empty())
    {
        int cx = qx.front(); qx.pop();
        int cy = qy.front(); qy.pop();
        int cgold = qgold.front(); qgold.pop();
        int cc = qcount.front(); qcount.pop();

        //금을 다 먹은 경우 그리고 목적지에 도착한 경우 
        if (cx == x && cy == y )
        {
            /*없을경우 -1를 출력해야해서
            기본 값이 -1이고 출력할때는 +1 해야함*/
            count = cc - 1;
            break;
        }
        if (visited[cx][cy] == 1)continue; //이미 갔던 곳이면 제외
        if(x!=cx && y!=cy)//목적지는 방문노드로 취급하지 않음
        visited[cx][cy] = 1;

        /*이중 배열 기준으로 하기 때문에 X축이 Y축임*/
        //상
        if (CanVisit(cx - 1, cy, maze)) {
            qy.push(cy);
            qx.push(cx - 1);
            qcount.push(cc + 1);
            //금이 있을경우
            if (maze[cx - 1][cy] == 2)
            {
                qgold.push(cgold+1);
            }
            else
            {
                qgold.push(cgold);
            }
        }
        //하
        if (CanVisit(cx + 1, cy, maze)) {
            qy.push(cy);
            qx.push(cx + 1);
            qcount.push(cc + 1);
            if (maze[cx + 1][cy] == 2)
            {
                //방문한 노드 초기화
                qgold.push(cgold + 1);
            }
            else
            {
                qgold.push(cgold);
            }
        }
        //좌
        if (CanVisit(cx, cy - 1, maze)) {
            qy.push(cy - 1);
            qx.push(cx);
            qcount.push(cc + 1);
            if (maze[cx][cy-1] == 2)
            {
                qgold.push(cgold + 1);
            }
            else
            {
                qgold.push(cgold);
            }
        }
        //우
        if (CanVisit(cx, cy + 1, maze)) {
            qy.push(cy + 1);
            qx.push(cx);
            qcount.push(cc + 1);
            if (maze[cx][cy+1] == 2)
            {
                qgold.push(cgold + 1);
            }
            else
            {
                qgold.push(cgold);
            }
        }
    }
    return count;
}
class Node
{
public:
    //상하좌우
    vector<Node*> neighbor;
    int resource;
    Node()
    {
        resource = 0;
        neighbor.resize(4);
        for (int i = 0; i < 4; i++)
        neighbor[i] = nullptr;
    };
    Node(int res)
    {
        resource = res;
        neighbor.resize(4);
        for (int i = 0; i < 4; i++)
            neighbor[i] = nullptr;
    };
    ~Node()
    {
        for (int i = 0; i < 4; i++)
        {
            if (neighbor[i] != nullptr)
            {
                delete neighbor[i];
                neighbor[i] = nullptr;
            }
        }
    };
};


const int MAX = 54;
int report[MAX][MAX];
int Solution(int height, int width, int kit)
{
    int min = 0;
    for (int i = 0; i < height; i++)
    {
        for (int i = 0; i < width; i++)
        {
           // while()
        }
    }

    return min;
}
int main() {
    //알고리즘 문제 입출력 연산 속도 개선
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h, w, n; //높이, 너비, 건설키트

    //stdin 입력받기
    cin >> h >> w >> n;

    int temp = 0;
    for (int i = 0; i < h; i++)
    {
       cin >> temp;
       for (int j = 0; j < w; j++)
       {
           int slice = (w-1)- j;
           slice = pow(10, slice);
           report[i][j] = (temp / slice)%10;
       }
    }

    cout << Solution(h,w,n);

    return 0;
}
