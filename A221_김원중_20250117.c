#include <stdio.h>
#include <stdlib.h>

/*
문제 이해=> 
N개의 정수가 주어지면 홀수인지 짝수인지 출력

첫 번째 줄에 숫자의 개수 N(1 <= N <= 100)이 
두 번째 줄부터 N+1번째 줄에 걸쳐 홀수인지 짝수인지 확인할 정수 K (1 <= K <= 10^60)

K가 홀수라면 'odd'를, 짝수라면 'even'을 출력

풀이=> 
정수 N 입력받기
N개만큼 K 입력받기
  짝수, 홀수 판단하기
출력하기


*/

int main(){
  int N = 0;
  scanf("%d", &N);

  int *result = (int*) malloc(sizeof(int) * N);
  for(int i = 0; i < N; i++){
    int K = 0;
    scanf("%d", &K);
    if(K % 2 == 0){
      result[i] = 1;
    }
    else if( K % 2 != 0){
      result[i] = 0;
    }
  }

  for(int i = 0; i < N; i++){
    if(result[i] == 1){
      printf("even\n");
    }
    else{
      printf("odd");
    }
  }
  
  return 0;
}