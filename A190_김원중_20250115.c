#include <stdio.h>



/*

문제 이해=> 
1에서 6까지 있는 주사위 3개를 던진다
  같은 눈 3개일 때, 10000 + (같은 눈 * 1000)의 상금
  같은 눈 2개일 때, 1000 + (같은 눈 * 100)의 상금
  같은 눈 1개 일 때, (가장 큰 눈) * 100의 상금

풀이=> 
첫째 줄에 3개의 눈을 입력
눈 비교
  상금 계산
출력

*/

int main(){
  int num1 = 0;
  int num2 = 0;
  int num3 = 0;
  scanf("%d %d %d", &num1, &num2, &num3); // 조건에 맞게 주어진다고 가정

  int money = 0;
  if(num1 == num2 && num1 == num3){
    money = 10000 + (num1 * 1000);
  }
  else if( num1 == num2 || num2 == num3 || num1 == num3){
    int same = (num1 == num2) ? num1 : (num2 == num3) ? num2 : num3;
    money = 1000 + (same * 100);
  }
  else{
    int top = (num1 > num2) ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2: num3);
    money = top * 100;
  }

  printf("%d", money);
  
  return 0;
}