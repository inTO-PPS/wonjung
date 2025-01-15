#include <stdio.h>
#include <stdlib.h>

/*
문제 이해=> 
A와 B를 입력받아 A+B를 출력한다
첫째 줄에 테스트 케이스의 개수가 주어진다
한 줄에 A와 B가 주어진다(0 < A,B < 10)조건에 맞게 주어진다고 가정
Case #x: A + B = C 형식으로 출력


풀이=> 


*/

int main(){
  
  int A = 0, B = 0;
  int T = 0;

  scanf("%d", &T);
  int *result = (int*) malloc(sizeof(int)*T);
  int *arrayA = (int*) malloc(sizeof(int)*T);
  int *arrayB = (int*) malloc(sizeof(int)*T);

  for(int i = 0; i < T; i++){
    scanf("%d %d", &A, &B);
    arrayA[i] = A;
    arrayB[i] = B;
    result[i] = A + B;
  }

  for(int i = 0; i < T; i++){
    printf("Case #%d: %d + %d = %d\n", i + 1, arrayA[i], arrayB[i], result[i]);
  }

  free(result);
  free(arrayA);
  free(arrayB);
  return 0;
}