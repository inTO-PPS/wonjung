#include <stdio.h>

/*
문제 이해=> 
양의 정수 num이 주어진다. perfect square면 true, 아니면 false를 출력하라
perfect square 은 정사각형이 아니라 완전제곱수

완전 제곱수 == 어떤 정수가 자기 자신과 곱해져서 만들어진 정수
(어떤 정수의 제곱 결과) (정사각형 넓이와 비슷)

풀이=> 
정수여야 하니까 
1부터 num까지 i * i로 제곱해서 num이 나오면 true, 안나오면 false
======  너무 비효율적인 코드 ==== 

중간값을 찾아서 중간값 * 중간값 == num이면 true
num보다 크면 -1하고 계산
num보다 작으면 + 1하고 계산

*/

int main(){
  int num = 0;
  scanf("%d", &num);

  int first = 1, end = num;
  int result = 0;
  while(first <= end){
    long mid = first + (end - first) / 2; // 오버 플로우 방지를 위해서 long 사용 및 end - first 사용
    long perfect = mid * mid;

    if(perfect == num){
      result = 1;
      break;
    }
    else if(perfect < num){
      first = mid + 1;
    }
    else{
      end = mid - 1;
    }
  }

  if(result){
    printf("true");
  }
  else{
    printf("false");
  }

  return 0;
}