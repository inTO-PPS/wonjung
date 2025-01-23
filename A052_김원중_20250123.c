#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*

문제 이해=> 
OX퀴즈: O는 정답, X는 오답
점수는 연속된 O의 개수 

첫째 줄에 테스트 케이스의 개수가 주어지고
개수만큼 OX가 주어진다 (문자열 길이는 80보다 작다)

풀이=> 
테스트 케이스 입력받고
O인지 X인지
  연속되는지 안되는지
    연속되면 점수 +1
    연속되지 않으면 초기화

*/

int main(){
  int test = 0;
  scanf("%d", &test);

  int* result = (int*) malloc(sizeof(int) * test);
  for(int i = 0; i < test; i++){
    char resolve[80]; // 80보다 작음 + NULL
    scanf("%s", resolve);
    int length = strlen(resolve);

    int straight = 0;
    int count = 0;
    for(int j = 0; j < length; j++){
      if(resolve[j] == 'O'){
        straight++;
        count += straight;
      }
      else if(resolve[j] == 'X'){
        straight = 0;
      }
    }

    result[i] = count;
  }
  
  for(int i = 0; i< test; i++){
    printf("%d\n", result[i]);
  }

  return 0;
}



