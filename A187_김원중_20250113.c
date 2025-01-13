#include <stdio.h>


/*

문제 이해=> 
윤년이면 1 출력, 아니면 0 출력
윤년 = 4의 배수일 때
  400의 배수면 윤년. (4의 배수임)
  100의 배수가 아니어야 윤년

풀이=> 
첫째 줄에 연도 입력
1보다 크고 4000보다 작은 자연수


*/


int main(){
  int year= 0;

  scanf("%d", &year);
  if(year < 1 || year > 4000 ){
    return 0;
  }

  if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
      printf("1");
  }
  else{
    printf("0");
  }

 
  return 0;
}