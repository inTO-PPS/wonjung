#include <stdio.h>

/*

문제 이해=> 
N장의 카드가 있음
1번 카드가 제일 위에, N번 카드가 제일 아래에
제일 위 카드를 버린다 -> 제일 위 카드를 제일 아래 카드 밑으로 옮긴다 (반복)
마지막에 남는 카드를 구해라

풀이=> 
배열에 맞는 번호 부여
반복문 1장 남을 때까지
  맨 앞 카드 지우고, 다음 카드를 맨 뒤에 넣기

*/



int main(){
  int N = 0;
  scanf("%d",&N);

  int arr[500000];
  int front = 0;
  int back = 0;

  for(int i = 1; i <= N; i++){ //1부터 N까지 번호 추가 
    arr[back++] = i;
  }

  while(back - front > 1){//한장 남을 때 까지
    front++; // 배열을 뒤로 옮기면서 맨 위 카드 제거
    arr[back++] = arr[front++]; // 맨 위 카드를 맨 뒤로 옮김
  }

  printf("%d", arr[front]); // 남은 카드 출력

  
  return 0;
}



