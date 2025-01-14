#include <stdio.h>


/*

문제 이해=> 
숫자가 오름차순으로 정렬된 채로 배열(nums)이 주어짐 (중복된 숫자가 없음)
[a,b]까지 숫자 중에 배열 nums에 있는 숫자를 포함시켜서 묶어야 함
  nums = [0, 1, 2, 4, 5, 7]일 경우, 0부터 7까지 숫자 중에서
    012가 이어지고, 45가 이어짐
      ["0->2","4->5","7"] 을 출력해야 함

풀이=> 
nums를 입력받는다 (nums 는 0 이상 20이하) // 입력 숫자를 알아야지 반복문 횟수를 정할 수 있어서 추가함
앞의 숫자와 뒤의 숫자를 비교한다 (nums[i]의 값의 범위는 int 자료형)
  a != b일 경우 +1씩 증가했다면 이어서 (범위 시작과 끝이 다름)
  a 와 b가 +1의 관계가 아니면 a == a (범위 시작과 끝이 같음)
묶어서 출력


*/


int main(){
  int nums[20];
  int input = 0;

  printf("몇 개 입력 > ");
  scanf("%d", &input);
  if(input < 0 || input > 20){
    return 0;
  }

  for(int i = 0 ; i < input; i++){
    scanf("%d", &nums[i]);
  }

  printf("[");
  int a = nums[0]; // 첫 번째 값부터 시작
  for(int i = 1; i <= input; i++){
    if(i == input || nums[i] != nums[i-1]+1){ // 마지막 숫자일 때, 범위가 끊어 졌을 때
      if(a == nums[i - 1]){ // 시작값과 끝 값이 같을 때 즉, a == b일 때
        printf("\"%d\"", a);
      }
      else{ // 범위 시작값과 끝값이 다를 때
        printf("\"%d->%d\"", a, nums[i - 1]);
      }
      if(i < input){
        printf(",");
        a = nums[i]; // 새로운 시작 범위 설정
      }
    }
  }
  printf("]");

  return 0;
}