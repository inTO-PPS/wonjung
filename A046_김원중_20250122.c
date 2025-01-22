#include <stdio.h>

/*

문제 이해=> 
첫 글자가 같은 선수 5명을 선발 
성의 첫 글자가 같은 선수가 5명 보다 적으면 기권

첫째 줄에 선수의 수 N이 주어짐
다음 N개 줄에 선수의 성이 주어짐

다섯 명을 선발할 수 없음 PREDAJA 출력
선발 가능할 경우 성의 첫 글자를 사전순으로 공백없이 모두 출력

풀이=> 
알파벳은 총 26개
배열 26까지 만들어서 소문자만 있으므로 이름 첫글자 - 'a'를 통해서 알파벳 배열 ++
5보다 많은 경우 출력


*/

int main(){
  int N = 0;
  scanf("%d", &N);

  int count[26] = {0};

  for(int i = 0; i < N; i++){
    char name[31]; // 최대 30글자
    scanf("%s", name);
    count[name[0] - 'a'] ++; // 이름 첫 글자 알파벳에 해당하는 count ++;
  }

  int found = 0;
  for(int i = 0; i < 26; i++){
    if(count[i] >= 5){ // 해당 글자가 5이상일 때 출력
      printf("%c", i + 'a'); // i번째에 +'a'를 통해 알파벳 소문자 출력
      found = 1;
    }
  }

  if(found != 1){
    printf("PREDAJA");
  }

  return 0;
}



