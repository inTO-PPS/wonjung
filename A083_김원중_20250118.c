#include <stdio.h>
#include <stdlib.h>

/*

문제 이해=> 
N개의 정수가 주어진다. 오름차순 정렬해라
첫째 줄에는 N의 개수가 주어지고
둘째 줄에는 숫자가 주어진다

중복을 제외하고 정렬하여 출력


풀이=> 
N입력받기
숫자 입력받기
정렬하기
출력하기
  첫 번째 출력하고
    이전 숫자와 같으면 넘어가고, 다르면 출력하게 해서 중복처리

*/

int compare(const void* a, const void* b);

int main(){
  int N = 0;
  scanf("%d", &N);

  int *arr = (int*) malloc(sizeof(int) * N);

  for(int i = 0; i < N; i++){
    scanf("%d", &arr[i]);
  }

  qsort(arr, N, sizeof(int), compare);

  printf("%d", arr[0]); // 첫 번째 수는 무조건 출력하고
  for(int i = 1; i < N; i++){
    if(arr[i] != arr[i - 1]){ // 다음 숫자가 이전 숫자와 다를 때만 출력
      printf(" %d", arr[i]);
    }
  }
}

int compare(const void* a, const void* b){
  return (*(int*)a - *(int*)b);
}

