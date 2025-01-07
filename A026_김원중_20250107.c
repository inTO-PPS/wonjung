#include <stdio.h>

/*
문제 이해=> 
자연수 x를 입력
x가 하샤드 수인지 아닌지 검사한다
	각 자리 수를 더한 후, 그 값으로 x가 나누어질 경우 하샤드 수
결과를 true, false로 출력한다
x는 1이상, 10000 이하의 정수다 

풀이=> 
변수 선언 및 입력받기 
각 자리 수를 더하기 
x를 더한 값으로 나누기
	더한 값이 나누어 떨어지면 true, 아니면 false
*/

int main(){
	int x = 0;
	scanf("%d", &x);

	int result_x = x;
	int sum = 0;
	while(x > 0){
		sum = sum +( x % 10 );
		x = x/10;
	}

	if(result_x % sum == 0){ 
		printf("true");
	}
	else{
		printf("false");
	}

	return 0;
}