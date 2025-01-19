#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
++ 포인터 *는 문자열을 가리킴 (문자열 시작 주소를 가리키고)
  이중 포인터 **는 문자열을 가리키는 포인터 배열을 가리킴 (배열을 가리킴)

++ 숫자를 문자열로 변환하는 가장 일반적인 방법 == sprintf
  혹은 itoa(숫자,배열,진수);

문제 이해=> 
정수 n이 주어지면, 문자열 answer을 반환해라
["1", "2", "Fiz"...] 같은 방식
3으로 나누어떨어지면 Fizz
5로 나누어떨어지면 Buzz
3과 5의 공배수면 FizzBuzz
아무것도 아니면 숫자를 문자열 형태로

풀이=> 
문자열 형태기 때문에 동적 메모리 할당을 사용해야 함


*/

char** solution(int n){
  char** number = (char**)malloc(sizeof(char*) * n);

  for(int i = 1; i <= n; i++){ // 숫자 n까지 출력해야 함
    if(i % 3 == 0 && i % 5 ==0){
      number[i - 1] = (char*)malloc(sizeof(char*) * 9);
      strcpy(number[i - 1], "\"FizzBuzz\"");
    }
    else if(i % 3 == 0  ){
      number[i - 1] = (char*)malloc(sizeof(char*) * 5);
      strcpy(number[i - 1], "\"Fizz\"");
    }
    else if(i % 5 == 0 ){
      number[i - 1] = (char*)malloc(sizeof(char*) * 5);
      strcpy(number[i - 1], "\"Buzz\"");
    }
    else{
      number[i - 1] = (char*)malloc(sizeof(char*) * 11); // 10^4만큼의 공간
      sprintf(number[i - 1], "%d", i); // 문자 형태로 변환
    }
  }
  return number;
}

int main(){
  int n = 0;
  scanf("%d", &n);

  char** result = solution(n);

  printf("[");
  for(int i = 0; i < n; i++){
    printf("%s", result[i]);
    if(i < n - 1){
      printf(",");
    }
    free(result[i]);
  }
  printf("]");
  
  free(result);
  return 0;
}
