#include <stdio.h>
#include <stdlib.h>
/*

문제 이해=> 
로프 N개(굵기와 길이가 모두 다름) => 들 수 있는 중량이 다름
병렬로 연결하여 중량을 나눌 수 있음
k개의 로프를 사용해 중량이 w인 물체를 들어올릴 때, 로프에는 고르게 w / k 만큼 걸리게 됨
로프들에 대한 정보가 주어질 때 들 수 있는 최대 중량 구하기
모두 사용할 필요는 없음

첫째 줄에 로프 개수 N개
다음 줄부터 버틸 수 있는 최대 중량이 주어짐


풀이=> 
정렬해서 가장 무거운 무게를 들 수 있는 로프 기준
최대 용량 + 다른 로프 고려


*/

int compare(const void *a, const void *b){
  return (*(int*)b - *(int*) a);
}


int main(){
  int N = 0;
  scanf("%d", &N);

  int* rope = (int*) malloc(sizeof(int) * N);
  for(int i = 0; i < N; i++){
    scanf("%d", &rope[i]);
  }

  qsort(rope, N, sizeof(int), compare);

  int max = 0;

  for(int i = 0; i < N; i++){
    int current = rope[i] *(i + 1); // rope[i] 번째가 들 수 있는 용량, 총 i + 1개가 rope[i] 만큼 들 수 있음
    if(current > max){
      max = current;
    }
  }

  printf("%d", max);
  
  return 0;
}



