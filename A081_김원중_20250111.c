#include <stdio.h>
#include <stdlib.h>

/*
문제 이해=> 
배열 A가 주어졌을 때, N번째 큰 값을 출력해라
배열 A의 크기는 항상 10이다. N은 항상 3이다. 

첫 째 줄에 테스트 케이스의 개수가 주어진다 (1보다 크거나 같고, 1,000보다 작거나 같다)
배열 A의 원소 10개가 공백으로 구분되어 주어진다(원소는 1보다 크거나 같고, 1000보다 작거나 같다)

풀이=> 
테스트 케이스 수 입력받기
배열 입력받기
정렬한다. (이번에는 qsort 사용)
  내림차순으로 정렬하고, 0 1 2 (2번 째에 있는 수를 출력);

*/

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a ); // 두 숫자 차이를 반환
}

int main(){
  int test = 0;
  scanf("%d", &test);

  int *result = (int*)malloc(sizeof(int) * test);

  for(int i = 0; i < test; i++){
    int array[10];
    for(int j = 0; j < 10; j++){
      scanf("%d", &array[j]);
    }
    qsort(array, 10, sizeof(int), compare);
    result[i] = array[2];
  }

  for(int i = 0; i < test; i++){
    printf("%d\n", result[i]);
  }

  free(result);

  return 0;
}