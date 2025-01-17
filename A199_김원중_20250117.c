#include <stdio.h>

/*
문제 이해=> 
별찍기 문제

규칙
  : 입력한 숫자만큼 별을 찍는다(n줄, 그리고 한 줄에 n개)
  : 홀 수 줄에는 별 먼저
  : 짝수 줄에는 공백 먼저

풀이=> 


*/

int main(){
  int input = 0;
  scanf("%d", &input);

  for(int i = 1; i <= input; i++){
    if(i % 2 == 0){
      printf(" ");
    }
    for(int j = 0; j < input; j++){
      printf("* ");
    }
    printf("\n");
  }

  return 0;
}