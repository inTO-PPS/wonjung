#include <stdio.h>

/*
문제 이해=> 
컴퓨터 고유번호 6자리를 매긴다. 
처음 다섯 자리는 00000 ~ 99999 까지고 
마지막 여섯 번째 자리는 각 자리수의 제곱을 더한 수에 나머지다. 
첫 째줄에 처음 5자리의 숫자들이 주어진다 
첫 째줄에 검증 수(여섯 번째 자리 수)를 출력해라

풀이 => 
반복문으로 각 자리 숫자 더함 
나머지 구함 
나머지 출력 
*/


int main(){
	int input[5];
	int total = 0;

	for(int i = 0; i < 5; i++){
		scanf("%d", &input[i]);
		total = total + (input[i] * input[i]);
	}

	total = total % 10;
	printf("%d", total);

	return 0;

}