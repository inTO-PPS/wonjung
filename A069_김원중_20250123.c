#include <stdio.h>
#include <stdlib.h>

/*

문제 이해=> 
1번부터 N번까지 N명의 사람이 원을 이루면 앉음
양의 정수 K가 주어짐 (K <= N)
순서대로 K 번째 사람을 제거함, N명의 사람 모두가 제거될 때까지 반복

풀이=> 
배열에 사람 넣기
  K 번째 사람 출력하기 (원형으로 계속 이어짐 %를 통해 계산)
  출력한 사람 제거

*/



int main(){
  int N =0;
  int K = 0;
  scanf("%d %d", &N, &K);

  int* arr = (int*)malloc(sizeof(int) * N);

  for(int i = 0; i < N; i++){
    arr[i] = i + 1; //1번부터 N까지 사람 있음(각 위치에 맞게 번호 넣음)
  }  

  int index = 0; // 위치
  int count = N; // 남은 사람 수

  printf("<");
  while(count > 0){
    for(int i = 0; i < K - 1; i++){ 
      index = (index + 1) % count; //원형으로 계속 이어짐
    }

    printf("%d", arr[index]);

    for(int i = index; i < count - 1; i++){
      arr[i] = arr[i+1]; // 남은 사람 앞당기기 
    }
    count--; // 전체 사람 수 감소

    if(count > 0){
      printf(", ");
      index %= count; // 인덱스가 count보다 많을 수 있는 걸 대비 크기 조정
    }
  }

  printf(">");
  free(arr);
  return 0;
}



