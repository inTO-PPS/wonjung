#include <stdio.h>

/*

문제 이해=> 
첫째 줄에 구간의 시작과 끝을 나타내는 정수 입력
1 2 2 3 3 3 처럼 수열을 만들고
A번째 B번째 까지의 합을 구해야 함

풀이=> 


*/


int main(){
  int A =0, B = 0;

  scanf("%d %d", &A, &B);

  int result[1000]; // 수열 1000까지 만들기
  int number = 0;

  // 수열 만들기
  for(int i = 1; number < 1000; i++){
    for(int j = 0; j < i && number < 1000; j++){ // 숫자 i만큼 1 2 2 3 3 3
      result[number++] = i; // number이 1000이 될 때까지 
    }
  }

  int sum = 0;
  for(int i = A - 1; i < B; i++){
    sum += result[i];
  }

  printf("%d",sum);

  return 0;
  
}



