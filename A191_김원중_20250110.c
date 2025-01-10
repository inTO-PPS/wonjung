#include <stdio.h>
#include <stdlib.h>

/*
문제 이해=> 
두 정수 A와 B를 입력받고, A+ B의 결과를 출력함
첫째 줄에 테스트 케이스의 개수 T를 입력
각 줄에 A와 B가 주어짐 ( 0<A, B<10)

각 테스트 케이스마다 A+B를 출력한다
*/

int main(){
	int A, B =0;
	int test = 0;
	scanf("%d", &test);

	int *result = (int*) malloc(sizeof(int) * test);

	for(int i = 0; i < test; i++){
		scanf("%d %d", &A, &B);
		if(A < 0 && A > 10 && B < 0 && B > 10){
			return 0;
		}
		result[i] = A+B;
	}

	for(int i = 0; i < test; i++){
		printf("%d\n", result[i]);
	}

	return 0;
}