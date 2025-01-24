#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
++ qsort는 큰게 뒤로 간다 (계속 까먹음)
  음수면 뒤에게 크다는 거
  0이면 같은거(그대로)
  양수면 앞에게 크니까 뒤로

문제 이해=> 
길이가 다르면 짧은 것이 먼저
길이가 같으면, A의 모든 자리수 합 / B의 모든 자리수의 합 비교해서 작은 합이 앞으로 오도록
1,2번으로 비교 못하면 사전순으로

첫째 줄에 기타 개수 N,
둘째 줄부터 기타 N개의 시리얼 번호 (대문자와 숫자만으로 이루어짐)

풀이=> 

*/
int calculate(const char *str){
  int sum = 0;
  for(int i = 0; str[i] != '\0'; i++){ // 해당 시리얼 끝까지
    if(str[i] >= '0' && str[i] <= '9'){ // 해당 시리얼의 문자가 숫자인 경우
      sum += str[i] - '0'; // 숫자로 바꿔서 더하기
    }
  }

  return sum;
}

int compare(const void *a, const void *b){ // 비교하는 함수
  const char *str1 = *(const char **)a;
  const char *str2 = *(const char **)b;

  int len1 = strlen(str1); // 일단 길이 비교
  int len2 = strlen(str2);
  if(len1 != len2){
    return len1 - len2; //길이가 짧은 순서로 정렬되게
  }

  int sum1 = calculate(str1);
  int sum2 = calculate(str2);
  if(sum1 != sum2){
    return sum1 - sum2;
  }

  return strcmp(str1,str2); // 다 안되면 사전순으로 정렬

}


int main(){
  int N = 0;
  scanf("%d", &N);

  char *C[50]; // 50개의 시리얼이 모두 주소를 갖게하는 것 (동적메모리 할당을 통해 문자열이 되게 해야함)
  for(int i = 0; i < N; i++){
    C[i] = (char*) malloc(sizeof(char) * 51 ); // 동적 메모리 할당 (50 + NULL)
    scanf("%s", C[i]);
  }

  qsort(C, N, sizeof(char*), compare);

  for(int i = 0; i < N; i++){
    printf("%s\n",C[i]);
    free(C[i]); // 메모리 해제
  }
  
  return 0;
}



