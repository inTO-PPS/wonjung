#include <stdio.h>
#include <stdlib.h>

/*

문제 이해=> 
할로윈 데이. 사탕을 공평하게 똑같이 나눠야 함
자식들에게 최대한 많은 사탕을 나누어주고, 자신에게는 몇 개가 남는지

첫째 줄에는 테스트 케이스의 수가 입력
다음 줄부터는 사탕의 개수 c와 형제의 개수 v가 차례대로 입력됨

풀이=> 

*/

int main(){
  int test= 0;
  scanf("%d", &test);
  int* provide = (int*)malloc(sizeof(int) * test);
  int* dad = (int*)malloc(sizeof(int) * test);

  for(int i = 0; i < test; i++){
    int c = 0;
    int v = 0;
    scanf("%d %d", &c, &v);

    provide[i] = c / v;
    dad[i] = c % v;
  }

  for(int i = 0; i < test; i++){
    printf("You get %d piece(s) and your dad gets %d piece(s).\n", provide[i], dad[i]);
  }

  free(provide);
  free(dad);


  return 0;
}



