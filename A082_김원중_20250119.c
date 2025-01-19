#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*

문제 이해=> 
회원가입
몇 명 입력할 건지 N
나이와 이름이 순서대로 주어지면
나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 순으로

풀이=> 
N입력받고
나이와 이름을 입력받고
qsort로 이름 오름차순 정렬하고 (입력 순서는 그대로 유지될 것 같음?)
  안되면 반복문을 통해서 번호 이름 저장할 때 순서 입력하도록
출력

*/

typedef struct{
  int age;
  char name[101];
}Member;

int compare(const void *a, const void *b){
  Member *m1 = (Member*)a;
  Member *m2 = (Member*)b;

  if(m1 -> age != m2 -> age){ // 나이가 다르면 
    return m1->age - m2->age; // 순서를 바꾸기 위해 비교
  }
}

int main(){
  int n = 0;
  scanf("%d", &n);

  Member *mem_num = (Member*)malloc(sizeof(Member) * n);
  for(int i = 0; i < n; i++){
    scanf("%d %s", &mem_num[i].age, mem_num[i].name);
  }

  qsort(mem_num, n, sizeof(Member), compare);

  for(int i = 0; i < n; i++){
    printf("%d %s\n", mem_num[i].age, mem_num[i].name);
  }

  free(mem_num);

  return 0;
}



