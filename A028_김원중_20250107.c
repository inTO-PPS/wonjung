#include <stdio.h>
#include <string.h>

/*
문제 이해=> 
두 정수 A와 B를 입력받는다 
A + B를 한다 
출력한다
0 < A,B < 10^0000

풀이=> 
10^10000 정수형 변수로 무리?
문자열로 받아서 -'0' 문자 0을 더하면 되지 않을까 

*/
#define MAX 10002

void Reverse(char str[]);

int main(){
	char A[MAX], B[MAX], result[MAX] = {0};
	scanf("%s %s", A, B);

	Reverse(A); // 뒤집는 이유 == 1의 자리부터 계산하기 위함
	Reverse(B);

	int len = strlen(A) > strlen(B) ? strlen(A) : strlen(B); // 큰 수의 자릿 수를 따라 가기 위해 큰 수의 자릴 수의 길이 구함

	int carry = 0;
	int i = 0;
	for(i = 0; i < len; i++){
		int sum = A[i] - '0' + B[i] - '0' + carry; // A와 B 한자릿 수 더함 + 올림(carry)

		if(sum > 9){ // 올림이 있는지 없는지
			carry = 1;
		}
		else{
			carry = 0;
		}

		result[i] = (sum % 10) + '0'; // 올림을 제외한 나머지

	}

	if(carry == 1){ // 더하기가 끝나고 carry가 남아있다면 맨 앞에 1이 있어야 함
		result[len] = '1';
	}
	Reverse(result);
	printf("%s", result);

	return 0;
}

void Reverse(char str[]){
	int len = 0;
	len = strlen(str);
	for( int i = 0; i < len /2; i++){
		char temp = str[i];
		str[i] = str[len - i -1];
		str[len - i - 1] = temp;
	}
}