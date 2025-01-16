#include <stdio.h>

/*
문제 이해=> 
레모네이드 한 잔 5달러
한 번에 한 명씩 순서대로 주문(입력 배열에 주어진 순서대로)
각 손님은 레모네이드 한 잔 구매 (5달러, 10달러, 20달러)
거스름돈을 제공해야함(처음에는 거스름돈이 없음)

bills[i] 는 i번째 손님이 지불한 금액
모든 손님에게 정확한 거스름돈 제공 가능하면 true, 불가능하면 false

5달러를 받을 수 있고, 10달러/20달러 지폐를 받을 수도 있음음


풀이=> 
bills 배열은 주어져있다고 가정
5달러, 10달러 변수를 각각만들어서(20달러는 거스름돈 없음)
반복문을 통해 각 돈을 받을 때 마다 ++하고, 
  거스름돈을 줘야 함 못 주면 바로 false 출력



*/

int main(){
  int bills[] = {5,5,10,20}; // 배열 조건 변경가능하게 크기 정하지 않음
  int length = sizeof(bills) / sizeof(bills[0]);

  int five = 0;
  int ten = 0;

  for(int i = 0; i < length ; i++){
    if(bills[i] == 5){
      five++;
    }
    else if(bills[i] == 10){
      ten++;
      if(five >= 1){
        five--;
      }
      else{
        printf("false");
        return 0;
      }
    }
    else if(bills[i] == 20){
      if(ten >= 1 && five >= 1){
        ten--;
        five--;
      }
      else if(five >= 3){
        five -= 3;
      }
      else{
        printf("false");
        return 0;
      }
    }
  }
  printf("true"); // 정상적으로 지불했을 경우

  return 0;
}