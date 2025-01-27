#include <stdio.h>

/*

문제 이해=> 
탈출하려면 특이한 규칙으로 문을 순서대로 열여야 한다
1. 문을 밀거나 혹은 당겨서 열어야 한다
2. 연속 2번으로 같은 방법으로 문을 열 수 없다
3. 2의 배수 문들은 반드시 같은 방법으로 문을 열어야 한다
4. 3의 배수들은 반드시 같은 방법으로 문을 열어야 한다

첫째 줄에는 총 문의 개수가 주어진다. 
둘째 줄 부터 첫 번째 문을 연 방법이 주어진다(0은 밀어서, 1은 당겨서)

출력은 두 번째 문부터 문을 여는 방법이 주어진다

풀이=> 
2의 배수일 때, 3의 배수일 때 (공배수 일 때 불가능
첫 번째 문이 0이면 다음은 1이 되어야 하고
첫 번째 문이 1이면 다음은 0이 되어야 함
탈출이 불가능하면 Love is open door를 출력

2와 3은 달라야 함. (연속할 수 없기 때문에)
첫 번째 방법 과 세 번째는 같고
두 번째 방법과 네 번째는 같음 (즉, 첫 번째 입력과 반대로 반복되어야 함)
그런데 여기서 2의 배수, 3의 배수가 같은 방식으로 열어야 한다고 함
  공배수인데 같은 방식으로 여는 건 불가능(연속될 수 밖에 없음)

== 첫 번째 입력 방법과 계속 달라지게 출력
    하지만 5보다 크면 == 6이 되면 더이상 조건을 충족할 수 없음

*/

int main(){
  int N = 0;
  int method = 0;

  scanf("%d", &N);
  scanf("%d", &method);

  if(N > 5){
    printf("Love is open door");
  }
  else{
    for(int i = 1; i < N; i++){
      method = 1 - method;
      printf("%d\n", method);
    }
  }

  return 0;
}



