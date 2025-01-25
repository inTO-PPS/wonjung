#include <stdio.h>

/*

문제 이해=> 
정수 X
X가 3으로 나누어 떨어지면 3으로 나누기
X가 2로 나누어 떨어지면 2로 나누기
1을 빼기
=> 적절히 사용해서 1로 만들어라

풀이=> (DP 사용) // 전의 기록 저장 후 효율적으로 계산
정수 N에서 1 

*/

int dp[1000001];

int min(int a, int b){
  return a < b ? a : b; // 작은 쪽 선택
}

int main(){
  int N = 0;
  scanf("%d", &N);

  dp[1] = 0;

  for(int i = 2; i <= N; i++){ // dp[i]는 i번째의 최소 연산 횟수
    dp[i] = dp[i - 1] + 1; // i-1번째에 1을 빼는 방식의 방법 1 추가

    if(i % 2 == 0){
      dp[i] = min(dp[i], dp[i / 2] + 1);
    }
    if(i % 3 == 0){
      dp[i] = min(dp[i], dp[i / 3] + 1);
    }
  }

  printf("%d", dp[N]);
  
  return 0;
}



