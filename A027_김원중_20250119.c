#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*

++ 스택 방식이라고 함
  가장 큰 숫자를 만들기 위해 작은 숫자를 제거하고 큰 숫자를 남기는 과정
  Stack . 데이터를 쌓고 빼는 구조

문제 이해=> 
어떤 숫자에서 k개 수를 제거할 때 가장 큰 수를 구하라
문자열 형식의 숫자 number 와 k가 주어진다. 
문자열 형태로 가장 큰 숫자를 return 하라


풀이=> 
문자열 숫자 number 입력받기
지우는 개수 k입력받기
k만큼 반복하기
  왼쪽부터 시작해서 만약 앞의 숫자가 현재 숫자보다 작으면 제거
문자열로 출력 

*/



int main(){
  char number[1000001];
  int k = 0;

  scanf("%s", number);
  scanf("%d", &k);

  int length = strlen(number);
  int result = length - k; // 결과 문자열 길이
  char *arr = (char*)malloc(sizeof(char)*(result + 1)); // 결과를 저장할 배열 + NULL문자
  int first = -1; // -1부터시작해서 문자 하나를 확인하고 넣을 때마다 ++, 현재는 빈 상태

  for(int i = 0; i < length; i++){
    while(first >= 0 && arr[first] < number[i] && k > 0){ // 맨 앞의 뒤에 숫자가 더 큰 경우
      first--; // 숫자 제거
      k--; // 제거 횟수 감소시키고 다시 제거
    }
    arr[++first] = number[i]; // 현재 숫자를 배열에 추가
  }

  arr[result] = '\0'; // NULL문자 추가가

  printf("%s", arr);

  free(arr);
  return 0;
}



