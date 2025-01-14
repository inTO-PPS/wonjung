#include <stdio.h>
#include <string.h>
#include <ctype.h>


/*

문제 이해=> 
알파벳 대소문자를 입력(길이1000000을 넘지 않는다)
첫째 줄에 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다
가장 많ㅇ히 사용된 알파벳이 두 개 이상일 경우 ?를 출력한다

풀이=> 
문자 입력받기
대문자로 바꾸기
알파벳 별로 카운트하기
가장 많은 숫자 출력하기



*/

int main(){
  char input[1000001];
  int count[26]= {0};
  int max = 0;

  scanf("%s", input);

  char result = ' ';
  for(int i = 0; input[i] != '\0'; i++){
    char c = toupper(input[i]);
    count[c - 'A']++; // 알파벳을 아스키 코드로 변환 후 개수 ++

    if(count[c - 'A'] > max){
      max = count[c - 'A'];
      result = c;
    }
    else if(count[c - 'A'] == max){
      result = '?';
    }
  }

  printf("%c", result);

  
  return 0;
}