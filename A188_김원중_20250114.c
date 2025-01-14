#include <stdio.h>


/*

문제 이해=> 
좌표가 주어지면 x와 y좌표에 따라 어느 사분면에 속하는지 출력하는 프로그램

풀이=> 
x 변수 선언 및 입력받기
y 변수 선언 및 입력받기
(−1000 ≤ x, y ≤ 1000; x, y ≠ 0)
0이면 끝내기
x가 음수 인지, 양수인지
y가 음수 인지, 양수인지

*/

int main(){
  int x = 0;
  int y = 0;
  scanf("%d", &x);
  scanf("%d", &y);
  if( x == 0 || y == 0){
    return 0;
  }

  if(x > 0){ // x가 양수 일 때
    if(y > 0){
      printf("1");
    }
    else{
      printf("4");
    }
  }
  else{
    if(y > 0){
      printf("2");
    }
    else{
      printf("3");
    }
  }
  
  return 0;
}