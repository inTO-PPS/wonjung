#include <stdio.h>


/*

문제 이해=> 
첫째 줄에 시험 점수가 주어진다. 시험 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수
시험 점수 출력

풀이=> 


*/


int main(){
  int score= 0;

  scanf("%d", &score);
  if(score < 0 || score > 100 ){
    return 0;
  }

  switch (score/10){
  case 10:
  case 9:
    printf("A");
    break;
  
  case 8:
    printf("B");
    break;

  case 7:
    printf("C");
    break;

  case 6:
    printf("D");
    break;
  
  default:
    printf("F");
    break;
  }
 
  return 0;
}