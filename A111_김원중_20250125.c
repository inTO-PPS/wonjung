#include <stdio.h>
#include <stdlib.h>

/*

문제 이해=> 
n명의 승객을 태움. 
버스는 버스정류장마다 문을 연다. 
각 정류장마다 타고 있는 승객의 수의 정확히 절반과 반 명의 승객이 내린다
총 k개의 정류장에서 승객이 내리고, 마지막 정류장에 승객이 없었으면 처음 타고 있던 승객은 몇 명?

첫째 줄에 테스트 케이스의 수 입력
다음 줄부터 정류장의 수 k 입력

풀이=> 
총 정류장ㅈ k
마지막 승객 수는 0
k -1 번째는 (승객 수 + 0.5) * 2 == 절반과 0.5명이 탄다고 생각


*/

int main(){
  int test = 0;
  scanf("%d", &test);

  int* result = (int*) malloc(sizeof(int) * test);
  
  for(int i = 0; i < test; i++){
    int passenger = 0;
    int k = 0;
    scanf("%d", &k);

    for(int j = 0; j < k; j++){
      passenger = (passenger + 0.5) * 2;
    }
    
    result[i] = passenger;
  }
  
  for(int i = 0; i < test; i++){
    printf("%d\n", result[i]);
  }

  free(result);
  return 0;
}



