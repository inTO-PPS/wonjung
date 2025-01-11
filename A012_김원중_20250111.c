#include <stdio.h>

/*
문제 이해=>
정수 n을 입력하고
n보다 작은 소수들의 개수를 출력해라

풀이=>
숫자 입력받기
반복문을 통해서 소수 찾기
	1은 제외니까 2부터 시작해서 n - 1까지 (i = 2로 하고, i < n)
		이중 반복문을 통해 그 숫자가 소수인지 판단
			이것도 2부터시작, %를 사용해서 0으로 떨어지면 소수 아님

*/

int main(){
	int n = 0;
	scanf("%d", &n);

	int count = 0;
	for(int i = 2; i < n; i++){
		int check = 1;
		for(int j = 2; j < i; j++){
			if(i % j == 0){
				check = 0;
				break;
			}
		}
		if(check){
			count++;
		}
	}

	printf("%d", count);

	return 0;
}