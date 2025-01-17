#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
++ strtok는 strtok(input, " ");의 경우 첫 번째 공백 " "을 찾고 거기에 NULL문자를 넣음
    공백자리에 NULL문자("\0")가 들어감
    input의 문장 전체가 바뀐 것 hello\0world\0Nice to meet you. 이런 식으로 전체 문장을 변경

문제 이해=> 
ㅓJadenCase : 모든 단어의 첫 문자가 대문자, 그 외의 알파벳은 소문자
첫 문자가 알파벳이 아니면 뒤에 오는 단어들은 그냥 그대로 소문자
문자열 s가 주어질 경우, s를 JadenCase로 바꾼 문자열을 리턴하는 프로그램ㄹ 작성

풀이=> 
문자열 입력받기
문자열 공백을 기준으로 끊어서
  첫 문자는 대문자로
  나머지 문자는 소문자로 바꾸기
*/

int main(){
  char input[200]; // 최대 200자
  fgets(input, sizeof(input), stdin);

  char *slice = strtok(input, " ");
  while(slice != NULL){
    if(isalpha(slice[0])){
      slice[0] = toupper(slice[0]);
    }

    for(int i = 1; slice[i] != '\0'; i++){ // 첫 번째 문자를 제외한 나머지 문자
      slice[i] = tolower(slice[i]);
    }
    printf("%s ", slice);
    slice = strtok(NULL, " "); // 다음 공백까지
  }

  return 0;
}