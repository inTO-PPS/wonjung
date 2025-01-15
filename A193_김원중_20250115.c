#include <stdio.h>

/*

문제 이해=> 
혜아의 면접
면접관이 N바이트 크기의 정수를 출력하는 프로그램을 구현하는 법을 물ㅇ름
해야는 long 이라는 글자가 앞에 붙을 때마다 4바이트 정수를 지정할 수 있다고 알 고 있음
long long int 는 8바이트, long long long int는 12바이트 ...

첫째 줄에 N바이트를 입력하면
혜야가 생각하는 정수 자료형의 이름을 출력하라

원래 답은 (C++에 관한 문제) GMP ? 를 사용한다고 함
C의 경우 define을 통해 크기 정의
 GCC의 C++ 컴파일러를 사용해 컴파일하려고 할 경우 'long long long' is too long for GCC라는 에러 메시지와 함께 컴파일되지 않는다.

풀이=> 
첫째 줄에 N의 크기 입력
N의 크기를 4로 나눠서 몫만큼 long 출력
마지막에 int 출력력

*/

int main(){
  int N = 0;

  scanf("%d", &N);

  for(int i = 0; i < (N / 4); i++){
    printf("long ");
  }
  printf("int");
  
  return 0;
}