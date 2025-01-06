#include <stdio.h>
#include <stdlib.h>

/*
<<나누어 떨어지는 숫자 배열>>
- 문제 이해
 배열 array에 자연수가 담긴다
 divisor 가 주어지고 나누어 떨어지는 값을 오름차순으로 정렬해서 반환한다 ([5, 10]과 같은 방식으로)
 나누어 떨어지지 않는다면 -1을 반환한다

=> 
배열 선언 => 배열 array에 들어갈 숫자를 입력받음
divisor 선언 => divisor 입력받기 

배열을 하나씩 나누고 나누어 떨어지는 것들을 오름차순으로 정렬한다
출력한다

*/
int compare(const void *a, const void *b);

int main(){
	int size = 0;
	printf("배열에 들어갈 자연수의 수> ");
	scanf("%d", &size);

	printf("숫자 입력> ");
	int *array = (int*) malloc(size * sizeof(int));
	for(int i = 0; i < size; i++){
		scanf("%d", &array[i]);
	}

	int divisor = 0;
	printf("divisor> ");
	scanf("%d", &divisor);

	int *temp = (int*) malloc(size * sizeof(int));
	int count = 0;

	for(int i = 0; i < size; i++){
		if(array[i] % divisor == 0){
			temp[count++] = array[i];
		}
	}

	if(count == 0){
		printf("[-1]");
	}
	else{
		qsort(temp, count, sizeof(int), compare);

		printf("[");
		for(int i = 0; i < count; i++){
			printf("%d", temp[i]);
			if(i < count - 1){	// 마지막 수 , 빼기
				printf(", ");
			}
		}
		printf("]");
	}


	free(temp);
	free(array);
	return 0;
}

int compare(const void *a, const void *b){
	return *(int *)a - *(int *)b; // 음수 면 a가 작음, 양수면 b가 작음
}