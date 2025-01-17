#include <stdio.h>
#include <string.h>

/*
문제 이해=> 
C성적이 주어졌을 때, 평점 몇 점인지 출력

풀이=> 

배열 입력
그 배열에 맞는 점수


*/

int main(){
  char grade[13][3] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D+", "D0", "D-","F"};
  float s[] = {4.3, 4.0, 3.7,3.3, 3.0, 2.7,2.3, 2.0, 1.7,1.3, 1.0, 0.7};

  char input[3];
  scanf("%s", input);

  for(int i = 0; i < 13; i++){
    if(strcmp(input,grade[i]) == 0){
      printf("%.1f",s[i]);
    }
  }
  return 0;
}