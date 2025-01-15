#include <stdio.h>
#include <math.h>


/*
++ round() 는 반올림 기능 // 0.5 이상 올림, 0.5 미만 버림
  #include <math.h> 사용


문제 이해=> 
재현이는 기분이 좋은 날, 기분이 싫은 날 밖에 없다
N일 뒤의 재현이 기분이 궁금해졌다.

첫째 줄에 정수 N(1<= N <= 100)와, 재현이의 기분(좋은 날 0, 싫은 날 1)이 주어진다
둘째 줄에 
  기분이 좋은 날 => 다음 날도 기분이 좋은 날일 확률, 다음날은 기분이 싫은 날일 확률
  기분이 싫은 날 => 다음 날은 기분이 좋은 날일 확률, 다음날도 기분이 싫은 날일 확률
  이 순서대로 주어짐(소수점 둘째자리까지 주어진다)
N일 뒤 재현이의 기분이 좋은 날일 확률과 싫은 날일 확률에 1000을 곱해 소수점 첫째 자링레서 반올림한 수를 차례대로 출력

풀이=> 
몇 일 뒤인지(N), 오늘 기분이 좋은지(0) 싫은지(0) 선언 및 입력
좋은지 싫은지에 따라 즉, 0인지 1인지에 따라 확률을 입력한다. 

N번 반복한다
1000을 곱해서 출력한다

*/

int main(){
  int N = 0;
  int mood = 0;
  scanf("%d %d", &N, &mood);

  float gg = 0;
  float gb = 0;
  float bg = 0;
  float bb = 0;
  scanf("%f %f %f %f", &gg, &gb, &bg, &bb);

  float g_percent = (mood == 0)? 1.0 : 0.0; // 좋은 날이면 g_percent를 1
  float b_percent = (mood == 1)? 1.0 : 0.0; // 싫은 날이면 b_percent를 1로
  for(int i = 0; i < N ; i++){
    float next_g = g_percent *gg + b_percent * bg;
    float next_b = g_percent *gb + b_percent * bb;
    g_percent = next_g;
    b_percent = next_b;
  }
  printf("%d\n", (int)round(g_percent * 1000));
  printf("%d", (int)round(b_percent * 1000));

  
  return 0;
}