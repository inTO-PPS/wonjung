#include <stdio.h>

/*
문제 이해=> 
K + A < D이거나, D = 0이면 가짜, 아니면 고수
첫째 줄에 K/D/A가 주어진다
진짜면 gosu, 가짜면 hasu 출력
0<= K, D,A <= 20

풀이=> 


*/

int main(){
  int K = 0, A = 0, D = 0;

  scanf("%d/%d/%d",&K,&D,&A);
  
  if(K + A < D || D == 0){
    printf("hasu");
  }
  else{
    printf("gosu");
  }

  return 0;
}