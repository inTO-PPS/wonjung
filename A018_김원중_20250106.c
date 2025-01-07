#include <stdio.h>
#include <stdlib.h>

/*
문제 이해=> 
길이가 N인 정수 배열 A와 B가 있다.
첫 번째 줄에 길이 N을 입력 
둘째 줄에 N개의 수 입력 (배열 A)
셋째 줄에 N개의 수 입력 (배열 B)
	N(길이) 는 50 이하의 자연수 
	A와 B의 각 원소는 100보다 작거나 같은 정수
최솟값 S를 출력하라

S = A[0] * B[0] + A[1] * B[1] ... A[N-1] * B[N-1]
최솟값 S는 배열 A를 재배열해서 만드는 것. B는 재배열 할 수 없음

풀이=> 
B배열을 못바꾸니까, B의 원소 중에서 큰 것에 A의 작은 것을 맞추는 방식
B의 크기를 파악 -> 거기에 맞게 A의 원소 배치 
B 중에서 큰 원소에는 A의 작은 수, B 중에서 작은 원소에는 A의 큰 수
그러면 A를 정렬해서 작은 수부터 B의 큰 수를 찾아서 곱한다. 
 ==> 힌트는 A를 1 1 0 1 6과 같이 재배열 하라고 했는데 맞는 방식인지는 모르겠으나 답은 나옴

*/

int compare(const void *a, const void *b);

int main(){
	int N = 0;

	printf("길이 N 입력하세요> ");
	while(N <= 0 || N > 50){ // 그냥 N[50] 해도 될 것 같음
		scanf("%d", &N);
	}

	int *A = (int*) malloc(N * sizeof(int));
	printf("배열 A의 원소 입력하세요(100이하의 정수)> "); // 이것도 그냥 A[100]하면 될 것 같음
	for(int i = 0; i < N; i++){
		do{
			scanf("%d", &A[i]);
		}while(A[i] > 100 || A[i] < 0);
	}

	int *B = (int*) malloc(N * sizeof(int));
	printf("배열 B의 원소 입력하세요(100이하의 정수)> ");
	for(int i = 0; i < N; i++){
		do{
			scanf("%d", &B[i]);
		}while(B[i] > 100 || B[i] < 0);
	}

	qsort(A, N, sizeof(int), compare);

	int S = 0;
	for (int i = 0; i < N; i++){
		int max = 0;
		for(int j = 1; j < N; j++){ // 배열 B 중에서 가장 큰 숫자 찾기
			if(B[j] > B[max]){
				max = j;
			}
		}
		S = S + (A[i] * B[max]);
		B[max] = -1; // 음수로 만들어서 비교하지 못하게 
	}

	printf("%d", S);

	free(A);
	free(B);

	return 0;
}


int compare(const void *a, const void *b){
	return *(int *)a - *(int *)b; // 음수 면 a가 작음, 양수면 b가 작음
}