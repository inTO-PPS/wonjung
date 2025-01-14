#include <stdio.h>


/*

문제 이해=> 
정수 num이 주어지면 
각 자릿수를 더한다(한 자리 수가 남을 때 까지)
한 자리 수가 남으면 반환한다

풀이=> 
num선언 및 입력받기 
각 자리 수 더하기
  이거는 % 10 통해서 끝자리 더하면 될 뜻
  한 자리 숫자가 나올 때까지 반복하기
출력

*/


int main(){
  int num = 0;

  scanf("%d", &num);

  while(num >= 10){ // num이 두 자리 이상일 때 동안 계속 반복 (더하기 결과를 한 자리 수로 만드는 과정)
    int result = 0;
    while(num > 0){ // 각 자리수 더하기
      result += num % 10; // 마지막 자리 수 더하기 
      num /= 10; // 한칸 당기기
    }
    num = result;
  }
  printf("%d", num);

  return 0;
}