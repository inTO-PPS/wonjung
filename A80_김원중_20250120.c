#include <stdio.h>
#include <stdlib.h>


/*

문제 이해=> 
크기 n의 배열이 주어진다.
n의 수만큼 배열 num이 주어진다
과반수 이상을 가진 수를 출력해라?

풀이=> 
같은 숫자가 얼마나 많은지 count++
  중복되는 숫자일 때마다 ++
  다른 숫자면 --


*/

int majority(int *arr,int size){
  int count = 0;
  int temp = 0;

  for(int i = 0; i < size; i++){
    if(count == 0){ // 아무것도 없는 상태라면
      temp = arr[i]; // 임시로 설정
    }
    if(arr[i] == temp){ // 현재 임시 결과와 같으면 +1
      count++;
    }
    else{
      count -= -1; // 다른 숫자면 -1
    }
  }
  return temp;
}


int main(){
  int n = 0;
  scanf("%d",&n);

  int *num = (int*) malloc(sizeof(int) * n);
  for(int i = 0; i < n; i++){
    scanf("%d", &num[i]);
  }

  int result = majority(num, n);
  printf("%d", result);

  free(num);
  return 0;
}



