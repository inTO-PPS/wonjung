#include <stdio.h>
#include <stdlib.h>

/*
++ 동적 계획법 사용
  : 현재 계산을 위해, 이전 값을 기반으로 계산
  : 초기값은 DP알고리즘의 시작점을 제공함
    그래서 초기값은 사용자가 직접 초기화 하고, 반복문을 통해 문제 해결하는 경우가 일반적
    (DP는 작은 문제를 풀어서 큰 문제를 해결하는 방식, 이접 값이 반드시 필요함(피보나치 같은 느낌) )
++ pps213번 문제

문제 이해=> 
계단 오르기 문제 == DP 사용 문제
계단은 한 번에 한 계단 혹은 두 계단씩 오를 수 있음
마지막 도착 계단은 반드시 밟아야 함

첫째 줄에 계단의 개수가 주어짐
둘째 줄부터 점수가 주어짐


풀이=> 


*/

int big(int a, int b);

int main(){
  int N = 0;
  scanf("%d", &N);

  int *score = (int*)malloc(sizeof(int)* N);
  int *total = (int*)malloc(sizeof(int)*N);

  for(int i = 0; i < N; i++){
    scanf("%d", &score[i]);
  }

  total[0] = score[0];  // 첫 번째 계단 점수
  total[1] = score[0] + score[1]; // 1번 + 2번 계단 (첫 번째 계단은 반드시 밟아야 함)
  total[2] = big(score[0] + score[2], score[1] + score[2]); // 1번 3번 or 2번 3번 

  for(int i = 3; i < N; i++){
    total[i] = big(total[i-2] + score[i], total[i - 3] + score[i - 1] + score[i]);
  } // 직전 계단 제외 + 현재 계단 vs 직전계단 + 현재 계단(그래서 i - 3의 값이 필요) , 세 계단 연속X
  // pps213번은 big 안에 big이 또 있어서 비교했는데 이 문제는 total에 현재 계단 점수[i]를 더함
  // 이 문제 조건에 마지막 계단은 반드시 밟으라고 해서 score[i]가 필수임

  printf("%d", total[N - 1]);

  free(score);
  free(total);

  return 0;
}

int big(int a, int b){ // 더 큰 값을 제공
  return (a > b ? a : b);
}