#include <stdio.h>
#include <string.h>

/*

문제 이해=> 
테스트 케이스 수 입력
원래 수 + 뒤집은 수가 좌우대칭이면 YES, 아니면 NO 출력력

풀이=> 
입력 -> 숫자 뒤집기 -> 원래 숫자 + 뒤집은 숫자가 같은지 확인

*/
int reverse(int num){ // 숫자 뒤집기 
  int reversed = 0;
  while(num > 0){
    reversed = reversed * 10 + (num % 10); // num의 끝 숫자를 구하고, reversed * 10을 통해 앞으로 
    num /= 10;
  }

  return reversed;
}

int same(int num){
  char str[10];  
  sprintf(str, "%d", num); // 문자열로 변환

  int len = strlen(str);
  for(int i = 0; i < len / 2; i++){
    if(str[i] != str[len- i - 1]){ // 
      return 0;
    }
  }
  return 1;
}


int main(){
  int test = 0;
  scanf("%d",&test);

  for(int i = 0; i < test; i++){
    int input = 0;
    scanf("%d", &input);

    int reverse_num = reverse(input);
    int sum = input + reverse_num;

    if(same(sum)){ // true일 경우
      printf("YES\n");
    }
    else{
      printf("NO\n");
    }
  }
  
  
  return 0;
}



