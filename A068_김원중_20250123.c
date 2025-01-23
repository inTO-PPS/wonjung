#include <stdio.h>
#include <string.h>

/*

문제 이해=> 
여섯 가지 명령
push X는 정수 X를 추가
pop은 가장 앞에 있는 정수를 빼고 출력. 정수가 없으면 -1 출력
size는 큐에 있는 정수의 개수를 출력
empty는 큐가 비어있으면 1, 있으면 0 출력
front_i: 가장 앞에 있는 정수 출려가, 정수가 없으면 -1 출력
back_i: 가장 뒤에 있는 정수 출력, 정수가 없으면 -1 출력

풀이=> 
첫째 줄에 명령의 수가 주어짐
둘째 줄부터 명령이 주어짐
// 값의 효율성 때문에 데이터를 지우지 않고 인덱스를 조절해서 데이터를 관리한다고함

*/

int Q[2000000];
int front_i = 0;
int back_i = 0;

void push(int x){
  Q[back_i++] = x; // 현재 인덱스에 추가 후에 증가
}

int pop(){
  if(front_i == back_i){
    return -1; // 정수가 없으면 -1
  }
  else{
    return Q[front_i++]; // 앞쪽 값 리턴 후 인덱스 증가
  }
}

int size(){
  return back_i - front_i;
}

int empty(){
  if(front_i == back_i){
    return 1;
  }
  else{
    return 0;
  }
}

int front(){
  if(front_i == back_i){
    return -1;
  }
  else{
    return Q[front_i];
  }
}

int back(){
  if(front_i == back_i){
    return -1;
  }
  else{
    return Q[back_i - 1]; // 증가를 한 상태여서 -1
  }
}

int main(){
  int test = 0;
  scanf("%d", &test);

  char command[10];
  for(int i = 0; i < test; i++){
    scanf("%s", command);

    if(strcmp(command,"push") == 0){
      int x = 0;
      scanf("%d", &x);
      push(x);
    }
    else if(strcmp(command,"pop") == 0){
      printf("%d\n", pop());
    }
    else if(strcmp(command,"size") == 0){
      printf("%d\n", size());
    }
    else if(strcmp(command,"empty") == 0){
      printf("%d\n", empty());
    }
    else if(strcmp(command,"front") == 0){
      printf("%d\n", front());
    }
    else if(strcmp(command,"back") == 0){
      printf("%d\n", back());
    }
  }
  
  return 0;
}



