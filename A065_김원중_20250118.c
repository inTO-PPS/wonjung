#include <stdio.h>
#include <stdlib.h>

/*
++ const void *는 모든 데이터 타입의 포인터를 가리킬 수 있는 제네릭 포인터
  void *: 타입이 없는 포인터, const는 데이터 변경이 불가능(상수)

++ 평소 (int*) 라는 형태를 잘 몰랐는데 typedef을 통해 알게 됨
  이번 문제에서 Point를 정의했는데
  (Point *)a는 Point 구조체 포인터로 형 변환 한 것
  *은 역참조하는 것
    *(Point *)a 는 a를 Point 타입으로 형 변환 후 역참조해서 메모리를 가져오는 것

++ compare 함수는 qsort 함수와 함께 사용
  return 값이 양수인 경우 : a와 b의 순서를 바꿈 (a가 b보다 크다)
  return 값이 음수인 경우 : a와 b의 순서 유지(b가 a보다 크다)
  return 값이 0 : a와 b가 같다
    qsort가 배열의 두 요소를 compare함수에 전달
    compare함수가 값을 반환
    보통 return A - B를 통해 양수면 A가 크고, 음수면 B가 큰 것을 이용

문제 이해=> 
2차원 점 n개가 주어진다.
x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순으로 정렬하라

풀이=> 

*/

typedef struct{
  int x;
  int y;
}Point; // 구조체 선언

int compare(const void *a, const void *b){
  Point A = *(Point *)a; // const void *a 타입을 Point *A로 형 변환(qsort 정렬을 위해)
  Point B = *(Point *)b;

  if(A.x > B.x){ // 양수면 순서를 바꿈, 음수면 순서를 유지
    return 1;
  }
  else if(A.x == B.x){
    if(A.y > B.y){
      return 1;
    }
    else{
      return -1;
    }
  }
  return -1; //B.x가 클 경우
}

int main(){
  int n = 0;
  scanf("%d", &n);

  Point *arr = (Point*) malloc(sizeof(Point) * n);

  for(int i = 0; i < n ; i++){
    scanf("%d %d", &arr[i].x, &arr[i].y);
  }
  qsort(arr, n , sizeof(Point), compare);

  for(int i = 0; i < n; i++){
    printf("%d %d\n", arr[i].x, arr[i].y);
  }

  free(arr);
  return 0;
}
