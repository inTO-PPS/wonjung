#include <stdio.h>
#include <stdlib.h>

/*
문제 이해=> 
a층의 b호에 살려면 아래층 (a-1), 1호부터 b호까지 사람들의 수를 합한 수만큼 사람이 있어야 한다
양의 정수 k와 n에 대해, k층 n호에는 몇 명이 사는가
0층부터있고, 1호부터 있다.

첫 번째 줄에 테스트 케이스의 수 T가 주어진다
각 테스트 별로, 첫 번째 줄에 정수 k, 두 번째 줄에 정수 n이 주어진다
1<= k,n <= 14

풀이=> 
t선언 및 입력받기
k선언하고 입력받기, n선언 및 입력받기

t만큼 반복해야 함
아파트 인원 저장할 변수 선언(14, 14 == 0층부터 14층) 
  0층부터 처리 ( 0층 i 호에는 i명만 살고있음)

  1층부터 k층까지 처리


*/

int main(){
  
  int T = 0;
  scanf("%d", &T);

  int *result= (int*)malloc(sizeof(int) * T);
  int count = 0;

  while(T--){ //t가 false가 될 때까지
    int k = 0, n = 0;
    scanf("%d", &k);
    scanf("%d", &n);

    int apt[15][15] = {0};

    for(int i = 1; i <= n; i++){ // 1호부터 n호까지
      apt[0][i] = i; // 아파트 0층의 i호에는 i명만 산다
    }

    for(int i = 1; i <= k; i++){
      for(int j = 1; j <= n; j++){
        apt[i][j] = apt[i - 1][j] + apt[i][j-1]; // i - 1 의 부분은 아래층의 해당 호수까지 누적, j - 1은 같은 층의 이전까지 누적된 값 => (앞집 == 아래층 앞 호수의 누적값) + 아래층 같은 호수
      }
    }

    result[count] = apt[k][n]; // 한 번에 출력하기 위해 저장
    count++;
  }

  for(int i = 0; i < count; i++){
    printf("%d\n", result[i]);
  }

  free(result);
  return 0;
}