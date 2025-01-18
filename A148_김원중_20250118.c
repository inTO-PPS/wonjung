#include <stdio.h>
#include <string.h>

/*

문제 이해=> 
영어 대소문자와 공백으로 이루어진 문자열이 주어진다(문자열의 길이는 1,000,000을 넘지 않는다.)
단어는 공백 한 개로 구분된다. 공백이 연속되지 않는다
이 문자열에 나오는 단어가 몇 개인지 출력하라 (단어의 개수 출력)

풀이=> 
strtok사용해서 공백을 기준으로 잘라서 count++;
근데 마지막 공백을 처리하지 못함 == 직접처리해야함

*/



int main(){
  char input[1000001];
  int count = 0;

  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0';

  char *word = strtok(input," ");

  while(word != NULL){
    count++;
    word = strtok(NULL," ");
  }
  printf("%d", count);

  return 0;
}
