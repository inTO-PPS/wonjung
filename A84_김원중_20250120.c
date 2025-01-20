#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*

문제 이해=> 
배열 S가 주어지면
모든 접미사를 사전순으로 정렬하고 출력해라

풀이=> 
입력한 단어 길이만큼 배열을 만들고
반복문을 통해서 앞글자를 빼면서 문자를 배열에 저장
strcmp로 사전 순으로 정렬
출력


*/

int compare(const void* a, const void* b){
  return strcmp(*(const char**)a, *(const char**)b);
} // char* = S[i] 시작 주소들, char**는 문자열 포인터를 가리킴 char*


int main(){
  char S[1001]; // 1,000
  scanf("%s", S);

  int length = strlen(S);
  char** sentence = (char**) malloc(sizeof(char*) * length);

  for(int i = 0; i < length; i++){
    sentence[i] = &S[i]; // 문장의 i번째 주소(앞글자 빼는 것)
  }

  qsort(sentence,length,sizeof(char*),compare);

  for(int i = 0; i < length; i++){
    printf("%s\n", sentence[i]);
  }

  free(sentence);
  return 0;
}



