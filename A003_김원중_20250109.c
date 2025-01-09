#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
문제이해 
매우 큰 정수 배열 digit이 주어짐
digit[i]는 그 숫자의 자릿 수를 나타낸다 (각 자릿수를 배열로 나타낸 것)
숫자는 0으로 시작하지 않고
정수에 1을 더한 결과를 배열 형태로 반환해라
digit = [1, 2 3] 이면 123이고 결과는 124 에서 문자열 [1,2,4]가 됨

문자열을 정수로 바꿔서 더하기(+ 자리올림) 하는 문제 + 다시 문자열로 바꾸는

풀이(저번에 큰 숫자 문자열로 받아서 뒤집어서 더하는 거 참고)
숫자 입력받음 (1부터 101까지 확인) (각 자리 0부터 9까지 즉, 한자리 수인지 확인)
1의 자리에서 더하기 1을 하고, carry변수를 통해서 10이 넘었는지 안넘었는지에 따라 계산
	10을 넘기면 carry 1로하고 숫자는 % 10을 사용해, 그 자리수는 나머지만 남도록
	10보다 작으면 그 숫자 그대로 그 자리수에 남도록
	마지막에 carry가 1이면 앞에 1을 더해야 하는데 그냥 1 출력하면 될 뜻
출력

*/

int main(){
	char num[101] = {0};
	scanf("%s", num);

	int length = strlen(num);
	if(length < 1 || length > 100){
		return 1;
	}

	int *digit = (int*)malloc(length * sizeof(int));
	for(int i = 0; i < length; i++){ // 숫자로 바꿔서 0 부터 9까지인지 확인
		digit[i] = num[i] - '0'; 
		if(digit[i] < 0 || digit[i] > 9){ 
			free(digit);
			return 1;
		}
	}

	int carry = 1;

	for(int i = length - 1; i >= 0; i--){
		int sum = digit[i] + carry; 
		if(sum > 9){
			carry = 1;
			digit[i] = sum % 10; // 나머지를 이용해서 10보다 클 경우 대비
		}
		else{
			carry = 0;
			digit[i] = sum;
		}
	}
	
	printf("["); // 배열 형태로 출력
	if(carry == 1){
		printf("1,");
	}

	for(int i = 0; i < length; i++){
		printf("%d", digit[i]);
		if(i < length - 1){
			printf(",");
		}
	}
	printf("]");

	free(digit);
	return 0;
}
