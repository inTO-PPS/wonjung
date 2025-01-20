#include <stdio.h>
#include <stdlib.h>

/*

문제 이해=> 
A와 B가 주어졌을 때 최소공배수를 구해라
첫째 줄에는 테스트 케이스의 개수가 주어지고

둘째 줄부터는 A와 B가 T개 주어진다
최소공배수를 입력받은 순서대로 한 줄에 하나씩 출력한다

풀이=> 
테스트 케이스 입력받기
A와 B 입력받기
최소공배수 찾기
최소공배수를 저장할 배열 필요

// 최소공배수를 찾을 때 최대공약수(GCD)를 활용하는 방법이 가장 효율적이라고 함
A와 B에서 B를 A로 나눈 나머지 R을 계산
A에 B를 넣고, B에 R을 넣음
B가 0이 될 때까지 이 과정 반복
마지막으로 A에 남은 값이 GCD(A,B)

LCM(최소 공배수) = A * B / GCD(A,B)

// 나머지의 성질
  A와 B가 어떤 수 D를 공통으로 나눌 수 있으면
    D는 A 와 B의 나머지 R도 나눌 수 있다

*/

int GCD(int a, int b){ // 최대 공약수
  while( b != 0){
      int r = a % b;
      a = b;
      b = r;
    }
  return a;
}

int LCM(int a, int b){
  return (a*b) / GCD(a,b);
}

int main(){
  int test = 0;
  int A = 0, B = 0;

  scanf("%d", &test);

  int* result = (int*) malloc(sizeof(int) * test);

  for(int i = 0; i < test; i++){
    scanf("%d %d", &A, &B);
    

    result[i] = LCM(A,B); 
  }

  for(int i = 0; i < test; i++){
    printf("%d\n", result[i]);
  }
  
  return 0;
}



