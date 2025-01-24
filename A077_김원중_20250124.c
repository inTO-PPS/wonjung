#include <stdio.h>

/*

문제 이해=> 
총 8문제를 푼다
문제를 풀었을 때 얻는 점수: 문제를 풀기 시작한 시간 ~ 경과한 시간과 난이도
문제를 풀지 못한 경우 0점
참가자의 총 점수: 가장 높은 점수 5개의 합

8개 줄에 각 문제에 대한 참가자의 점수가 주어짐
0 <= score <= 150

첫째 줄에 참가자의 총점
둘째 줄에는 어떤 문제가 최종 점수에 포함된 점수인지(오름차순으로)

풀이=> 

*/



int main(){
  int score[8] = {0};
  int number[8] = {0};
  int total = 0;
  int top[5];

  for(int i = 0; i < 8; i++){
    scanf("%d", &score[i]);
    number[i] = i + 1; // 1번부터 8번 문제
  }

  for(int i = 0; i < 8; i++){
    for(int j = i + 1; j < 8; j++){
      if(score[i] < score[j]){ // 점수 오름차순 정렬렬
        int temp = score[i];
        score[i] = score[j];
        score[j] = temp;

        int temp_number = number[i]; // 인덱스 
        number[i] = number[j];
        number[j] = temp_number;
        
      }
    }
  }

  for(int i = 0; i < 5; i++){ // 총 점수 합
    total += score[i];
    top[i] = number[i];
  }

  for(int i = 0; i < 5; i++){ // 인덱스 정렬
    for(int j = i + 1; j < 5; j++){
      if(top[i] > top[j]){
        int temp = top[i];
        top[i] = top[j];
        top[j] = temp;
      }
    }
  }

  printf("%d\n", total);
  for(int i = 0; i < 5; i++){
    printf("%d ", top[i]);
  }

  
  return 0;
}



