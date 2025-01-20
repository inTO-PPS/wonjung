#include <stdio.h>
#include <stdlib.h>

/*

문제 이해=> 


풀이=> 

*/

int* solution(int arr[], int arr_length, int* return_Size){
  int* result = (int*)malloc(sizeof(int*) * arr_length); // 일단 최대 길이 할당
  int index = 0;

  for(int i = 0; i < arr_length; i++){
    if(i == 0 || arr[i] != arr[i - 1]){ // 처음 숫자는 무조건 출력, 그다음 부터는 앞의 숫자와 다르면 출력
      result[index++] = arr[i];
    }
  }

  *return_Size = index; 
  return result; // result값을 리턴하기 때문에, result 배열의 수는 주소로 접근
}

int main(){
  int arr[] = {4,4,4,3,3};
  int length = sizeof(arr) / sizeof(arr[0]);
  int result_Size = 0;

  int* result = solution(arr, length, &result_Size);

  printf("[");
  for(int i = 0; i < result_Size; i++){
    if(i < result_Size - 1){
      printf("%d", result[i]);
      printf(",");
    }
    else{
      printf("%d", result[i]);
    }
  }
  printf("]");

  free(result);
  return 0;
}



