#include <stdio.h>
#include <stdlib.h>

/*
++ 동적 계획법 사용
  : 현재 계산을 위해, 이전 값을 기반으로 계산
  : 초기값은 DP알고리즘의 시작점 제공

문제 이해=> 
포도잔의 개수 n이 주어진다
개수만큼 포두주 잔에 들어있는 포도주의 양이 주어진다
가장 많이 마실 수 있도록 하는 프로그램 작성
세 잔을 연속으로 마실 수 없다(최대 두 개 마시고, 건너뛰어야 함)


풀이=> 
포도주 개수 입력받기
개수만큼 양 입력받기 (배열로 저장)

*/

int big(int a, int b);

int main(){
  int N = 0;
  scanf("%d", &N);

  int *content = (int*)malloc(sizeof(int)* N);
  int *eat = (int*)malloc(sizeof(int)*N);

  for(int i = 0; i < N; i++){
    scanf("%d", &content[i]);
  }

  eat[0] = content[0];  // 첫 번째 잔을 마시는 경우 
  if(N > 1){
    eat[1] = content[0] + content[1]; // 첫 번째 잔 + 두 번째 잔잔
  }
  if(N > 2){
    eat[2] = big(eat[1], big(content[0] + content[2], content[1] + content[2])); // 세 번째 잔을 마시는 경우끼리 비교 후 세 번째 잔을 마시지 않는 경우와 비교
  } // eat[1] 1번 2번을 마시는 경우 vs (1번 3번 마시는 경우 vs 2번 3번을 마시는 경우)

  for(int i = 3; i < N; i++){
    eat[i] = big(eat[i - 1], big(eat[i - 2] + content[i], eat[i - 3] + content[i - 1] + content[i])); // i -2까지 마셨던 최대양 + 현재양 , i-3까지 마셧던 최대양 + i - 1(직전 마신) + 현재양
  }
  // 즉 eat[i] == 최대값

  printf("%d", eat[N - 1]);

  free(content);
  free(eat);

  return 0;
}

int big(int a, int b){ // 더 큰 값을 제공
  return (a > b ? a : b);
}