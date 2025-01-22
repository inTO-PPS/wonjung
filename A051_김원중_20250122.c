#include <stdio.h>
#include <string.h>

/*

문제 이해=> 
다이얼 전화 사용
숫자 1을 걸려면 2초
숫자 2를 걸려면 3초 처럼 1초씩 추가
... 

전화를 걸 때는 알파벳에 해당하는 숫자를 건다

첫째 줄에 알파벳 대문자가 주어진다. (2 < A < 15);
최소 시간을 출력하라

풀이=> 
1은 2초가 걸리고
A B C는 3초가 걸리고
D E F는 4초가 걸리는 것을 이용

  0이랑 1은 없는 것 같음



*/

int getTime(char a){
  if(a >= 'A' && a <= 'C'){
    return 3;
  }
  if(a >= 'D' && a <= 'F'){
    return 4;
  }
  if(a >= 'G' && a <= 'I'){
    return 5;
  }
  if(a >= 'J' && a <= 'L'){
    return 6;
  }
  if(a >= 'M' && a <= 'O'){
    return 7;
  }
  if(a >= 'P' && a <='S'){
    return 8;
  }
  if(a >= 'T' && a <= 'V'){
    return 9;
  }
  if(a >= 'W' && a <= 'Z'){
    return 10;
  }
}

int main(){

  char word[15];
  int time = 0;

  scanf("%s", word);

  for(int i = 0; i < strlen(word); i++){
    time += getTime(word[i]);
  }

  printf("%d", time);

  return 0;
}



