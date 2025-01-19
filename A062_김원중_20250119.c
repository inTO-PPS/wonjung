#include <stdio.h>

/*

문제 이해=> 
2016년 1월 1일은 금요일
a월 b일은 무슨 요일인가
SUN,MON,TUE,WED,THU,FRI,SAT
윤년 2월 29일

풀이=> 
a와 b 입력받기 // 월, 일 입력받기
1월2월3월.. 별로 몇 일인지 배열로 계싼
  월 + 일을 통해 총 며칠인지 계산하고, 7로 나누기
  나머지가 0이면 일주일 지남 == 금, 1이면 토, 2면 일... 


*/

char* solution(int a, int b){
  int days[] = {31,29,31,30,31,30,31,31,30,31,30,31};
  char* week[] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};

  int total_days = 0;
  for(int i = 0; i < a - 1; i++){ // 이전 월들까지 반복
    total_days += days[i];
  }
  total_days += b; // 해당 월의 몇일인지

  int what_week = 0;
  what_week = (total_days - 1) % 7; // 2016년 1월 1일을 0으로 잡고

  return week[what_week];
}


int main(){
  int a = 0, b = 0;
  scanf("%d %d", &a, &b);

  char* result = solution(a,b);
  printf("%s", result);

  return 0;
}



