#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

문제 이해=> 
야구 게임이 있다
operations라는 문자열이 주어진다. operation[i]는 당신이 기록에 적용해야 할 작업이다
정수 x는 x점을 추가
문자 +는 이전 두 점수의 합을 기록
문자 D는 이전 점수의 두 배를 기록
문자 C는 이전 점수를 무효화하고 기록에서 제거

풀이=> 

*/

int Calculation(char **operation, int length){
  int arr[1000];
  int current = 0;

  for(int i = 0; i < length; i++){
    if(strcmp(operation[i],"+") == 0){
      if(current >= 2){
        arr[current] = arr[current - 1] + arr[current - 2];
        current++;
      }
    }
    else if(strcmp(operation[i],"D") == 0){
      if(current >= 1){
        arr[current] = arr[current - 1] * 2; // 두 배
        current++;
      }
    }
    else if(strcmp(operation[i],"C") == 0){
      if(current > 0){
        current--; // 최근 점수 제거
        arr[current] = 0;
      }
    }
    else{
      arr[current] = atoi(operation[i]); // 정수로 변환
      current++;
    }
  }

  int total = 0;
  for(int i = 0; i < current; i++){
    total += arr[i];
  }

  return total;
}


int main(){
  char *operation[] = {"5","-2","4","C","D","9","+","+"}; // 문자열 추가 및 수정

  int length = sizeof(operation) / sizeof(operation[0]);
  int result = Calculation(operation, length);

  printf("%d", result);


  return 0;
}



