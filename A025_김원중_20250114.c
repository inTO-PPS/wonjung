#include <stdio.h>


/*

문제 이해=> 
정수 n이 주어질 때, 4의 제곱이면 true, 아니면 false를 출력하라

풀이=> 
정수 입력받기
4의 제곱인지 구분하기
  음수면 false
  % 4가 0 이 아니면 음수 (4의 배수여야 함)
  / 4를 끝까지 했을 때 1이 나와야 함 (4의 9제곱)
true 혹은 false 출력하기

*/


int main(){
  int input = 0;
  scanf("%d", &input);

  if(input < 0){
    printf("false");
    return 0;
  }

  while(input % 4 == 0){
    input = input / 4;
  }

  if(input == 1){
    printf("true");
  }
  else{
    printf("false");
  }


  return 0;
}