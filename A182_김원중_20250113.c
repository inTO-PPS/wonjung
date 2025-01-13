#include <stdio.h>


/*

++ long long ==> %lld, 1000000000000LL

문제 이해=> 
첫 번째 줄에 A, B, C (1 ≤ A, B, C ≤ 1012) 입력
A+B+C의 값을 출력

풀이=> 


*/


int main(){
  long long A = 0, B = 0 ,C =0;

  scanf("%lld %lld %lld", &A, &B, &C);
  if(A <= 1  || A > 1000000000000LL || B <= 1 || B > 1000000000000LL || C <= 1 || C > 1000000000000LL){
    return 0;
  }

  printf("%lld", A + B + C);
 
  return 0;
}