#include <stdio.h>


/*
문제 이해=> 
첫째 줄에 A, B ,C가 순서대로 주어진다
2보다 크고 10000보다 작다
첫째 줄에 (A+B)%C
둘째 줄에 ((A%C) + (B%C))%C
셋째 줄에 (A×B)%C 
넷째 줄에 ((A%C) × (B%C))%C를 출력

풀이=> 


*/


int main(){
  int A, B ,C =0;

  scanf("%d %d %d", &A, &B, &C);
  if(A < 2 || A > 10000 || B < 2 || B > 10000 || C < 2 || C > 10000){
    return 0;
  }

  printf("%d\n", (A+B)%C);
  printf("%d\n",((A%C) + (B%C))%C);
  printf("%d\n", (A*B)%C);
  printf("%d",((A%C)*(B%C))%C);
 
  return 0;
}