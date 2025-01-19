#include <stdio.h>
#include <string.h>

/*

문제 이해=> 
정수를 저장하는 스택을 구현. 주어지는 명령을 처리해라

push X는 정수 X를 스택에 넣는다
pop은 가장 위에 있는 정수를 빼고, 그 수를 출력. 스택이 없으면 -1 출력
size는 스택에 들어잇는 정수의 개수 출력
empty는 비어있으면 1, 아니면 0출력
top은 가장 위에 있는 정수 출력, 정수가 없을 경우 -1 출력

풀이=> 
주어지는 명령어의 개수 n 선언 및 입력
둘째줄부터 한 줄 씩 명령어 입력 및 출력?(명령이 주어질 때마다 출력)


*/

int stack[100000];
int first = - 1; 

void push(int x){
  stack[++first] = x; // 입력받은 숫자 x 추가
}

int pop(){
  if(first == -1){
    return -1; // -1은 비어있는 경우
  }
  return stack[first--]; // 가장 최근에 들어온 정수수를 반환한 후에 제거
}

int size(){
  return first + 1; // 첫 번째 숫자는 0부터 시작
}

int empty(){
  if(first == -1){ // 비어있으면 1
    return 1;
  }
  else{
    return 0; // 비어있지 않는 경우
  }
}

int top(){
  if(first == -1){
    return -1; // 스택이 없는 경우 -1
  }
  else{
    return stack[first]; // 가장 위에 있는 정수(가장 최근에 들어온 정수)
  }
}

int main(){
  int N = 0;
  char order[10];
  int x = 0;

  scanf("%d", &N);

  for(int i = 0; i < N; i++){
    scanf("%s", order);

    if(strcmp(order,"push") == 0){
      scanf("%d", &x);
      push(x);
    }
    else if(strcmp(order,"pop") == 0){
      printf("%d\n", pop());
    }
    else if(strcmp(order,"size") == 0){
      printf("%d\n", size());
    }
    else if(strcmp(order,"empty") == 0){
      printf("%d\n", empty());
    }
    else if(strcmp(order,"top") == 0){
      printf("%d\n", top());
    }
  }

  return 0;
}



