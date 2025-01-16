#include <stdio.h>
#include <stdlib.h>

/*
문제 이해=> 
총 N개의 정수가 주어졌을 때 정수 v가 몇 개인지 구해라

첫째 줄에 정수 N개(1<= N <= 100)가 주어지고
둘째 줄에 정수가 공백으로 주어진다
셋째 줄에는 찾으려고 하는 정수 v가 주어진다 (-100 <= v <= 100)


풀이=> 
변수 N 선언 및 입력받기
동적할당으로 받아서 N개의 정수 입력받기
찾는 변수 입력받기

반복문을 통해서 숫자 비교하기

*/

int main(){
  
  int N = 0;
  scanf("%d", &N);

  int *array = (int*) malloc(sizeof(int) * N);
  for(int i = 0 ; i < N ; i++){
    scanf("%d", &array[i]);
  }

  int search = 0;
  scanf("%d", &search);

  int count = 0;
  for(int i = 0; i < N; i++){
    if(array[i] == search ){
      count++;
    }
  }

  printf("%d", count);
  
  return 0;
}