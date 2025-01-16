#include <stdio.h>

/*
문제 이해=> 
별찍기 문제
첫째 줄에 1개, 둘째 줄에 2개, N째 줄에 N개


풀이=> 
변수 N선언 및 입력 받기
이중반복문
  N만큼 반복

*/

int main(){
  
  int N = 0;
  scanf("%d", &N);

  for(int i = 0; i < N; i++){
    for(int j = 0; j <= i; j++){
      printf("*");
    }
    printf("\n");
  }
  
  return 0;
}