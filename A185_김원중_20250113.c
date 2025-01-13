#include <stdio.h>


/*

문제 이해=> 
첫째 줄에 A와 B 입력
비교 후 
A가 B보다 크면 >
A보다 B가 크면 <
A와 B가 같으면 ==

풀이=> 


*/


int main(){
  int A = 0, B = 0;

  scanf("%d %d", &A, &B);
  if(A < -10000 || A > 10000 || B < -10000 || B > 10000 ){
    return 0;
  }

  if(A > B){
    printf(">");
  }
  else if(A < B){
    printf("<");
  }
  else{
    printf("==");
  }
 
  return 0;
}