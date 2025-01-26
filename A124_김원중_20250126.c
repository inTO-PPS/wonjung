#include <stdio.h>

/*

문제 이해=> 
정수 N을 입력했을 때 소인수분해 해라

풀이=> 
N입력받고
반복문으로 N이 1이 될 때까지 반복
  i가 N으로 나누어지면 나누고
  안되면 i를 증가
  결과 출력

*/

void divide(int n){
  int i = 2; // 1은 의미 없으니까 2부터

  while(n > 1){
    if(n % i == 0){
      printf("%d\n", i);
      n = n / i;
    }
    else{
      i++;
    }
  }
}


int main(){
  int N = 0;
  scanf("%d", &N);

  if(N > 1){
    divide(N);
  }
  
  return 0;
}



