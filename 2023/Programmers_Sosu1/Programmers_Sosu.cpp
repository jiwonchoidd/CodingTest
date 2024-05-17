//https://programmers.co.kr/learn/courses/30/lessons/12921
#include <string>
#include <vector>

using namespace std;
bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)return false;
    }
    return true;
}
int solution(int n) {
    int answer = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))answer++;
    }
    return answer;
}
//1부터 입력받은 숫자 n 사이에 있는 소수의 개수를 반환하는 함수, solution을 만들어 보세요.
//소수는 1과 자기 자신으로만 나누어지는 수를 의미합니다.
//(1은 소수가 아닙니다.)
void main()
{
    solution(10);
}
for (int i = 2; i <= 100000; i++) {
	arr[i] = i;
}

// 지우기  
for (int i = 2; i <= 100000; i++) {
	// 이미 지워진 경우  
	if (arr[i] == 0) continue;

	// 지워지지 않은 경우 자기자신을 제외한 수부터 배수 지우기  
	for (int j = i + i; j <= 100000; j = j + i) {
		if (arr[j] == 0) continue;
		else arr[j] = 0;	// 지우기 (0으로 저장) 
	}
}

// 소수 출력하기 
for (int i = 2; i <= 100000; i++) {
	if (arr[i] != 0) {
		cout << arr[i] << ' ';
	}
}