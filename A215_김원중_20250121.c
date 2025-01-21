#include <stdio.h>
#include <stdlib.h>

/*

문제 이해=> 
N개의 정수가 주어지면
정수들의 합 S의 부호를 구해라

총 3개의 테스트
첫째 줄에는 N이 주어지고
둘째줄 부터는 정수가 주어진다

S=0이면 "0"을, S>0이면 "+"를, S<0이면 "-"를 출력

풀이=> 

*/

int main(){

  char* result = (char*)malloc(sizeof(char) * 3);
  
  for(int i = 0; i < 3; i++){
    int N = 0;
    scanf("%d", &N);
    long long sum = 0;

    for(int j = 0; j < N; j++){
      long long num = 0;
      scanf("%lld", &num);
      sum += num;
    }

    if(sum == 0){
      result[i] = '0';
    }
    else if(sum > 0){
      result[i] = '+';
    }
    else{
      result[i] = '-';
    }
  }

  for(int i = 0; i < 3; i++){
    printf("%c\n", result[i]);
  }

  return 0;
}



