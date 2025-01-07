#include <stdio.h>

/*
문제 이해=>
첫째 줄에 A, 둘째 줄에 B, 셋째 줄에 C를 입력한다 
A, B, C는 100보다 크거나 같고, 1,000보다 작은 자연수다
A x B x C를 했을 때의 결과를 1은 몇 개가 나왔는지, 2는 몇 개가 나왔는지 10까지 출력한다
즉, 첫째 줄에는 0이 몇 개인지, 둘째 줄에는 1이 몇 개인지 ... 아홉번째 줄에는 9가 몇개 인지 출력한다 

풀이=> 
A,B,C선언 및 입력 
A*B*C 결과를 나머지로 나누고, 그 숫자를 문자열에 ++, 계산한 자릿수는 빼기
결과 0부터 9까지 출력하기

*/

int main(){
	int A = 0, B = 0, C = 0;
	printf("A입력> ");
	while(A < 100 || A > 1000){
		scanf("%d", &A);
	}
	printf("B입력> ");
	while(B < 100 || B > 1000){
		scanf("%d", &B);
	}
  printf("C입력> ");
	while(C < 100 || C > 1000){
		scanf("%d", &C);
	}

	int mul = 0;
	mul = A * B * C;

	int result[10] = {0};
	while(mul > 0){
		int num = mul % 10;
		result[num]++;
		mul /= 10;
	}

	for(int i = 0; i <= 9; i++){
		printf("%d\n", result[i]);
	}

	return 0;
}