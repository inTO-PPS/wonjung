#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
++ strtok는 첫 번째 호출 이후, 남은 문자열에 접근하려면 (strtok(NULL, " "))처럼 NULL로 접근해야 한다
++ NULL로 하는 이유는 문자열 전체를 다시 입력받지 않고, 이전 상태에서 처리하기 위함
++ strtok의 동작 원리 = strtok(input, " ");을 했을 경우 input 문자열에서 공백까지 변수에 저장, 다음 호출 시 NULL을 통해 이전 상태에서 이어서 진행

++ '\0' 이랑 NULL은 비슷한데
++ '\0'은 단일 문자로, 문자열을 끝낼 때 사용하고
++ 'NULL'은 문자열 주소를 끝낼 때 사용해야 한다.(포인터, 이번 문제의 경우 char *first를 사용해서 NULL사용)
	=> 즉, 반환값이 포인터인지, 문자열인지 알고 그에 맞게 사용해야 한다.

문제 이해=> 
화성 간대
@는 *3
%는 +5
#은 -7
화성의 수학 식= 숫자 연산자

입력-
첫째 줄에 테스트 케이스의 개수 T가 주어지고
다음 줄부터 수학식이 한 줄에 하나씩(수는 정수 or 소수 첫 재자리, 0 이상 100이하)
연산자는 최대 3 개 주어짐

출력-
소수점 둘 째자리까지 출력


풀이=>
테스트 케이스 숫자 입력
입력된 숫자만큼 수학식 입력
	계산하고 배열에 넣기
		숫자 + 문자열 문자열 문자열이어서 문자열로 받아야 함
			atof사용
			문자열 공백 문자열 공백 문자열이어서 strtok로 ' ' 기준으로 끊어서 계산하도록
입력된 숫자만큼 소수점 둘 째자리까지 출력

*/

int main(){
	int test = 0;

	scanf("%d", &test);
	getchar();
	char input[15];
	
	double *result = (double*) malloc(test * sizeof(double));
	for(int i = 0; i < test; i++){
		fgets(input, sizeof(input), stdin);
		char *first = strtok(input, " "); // strtok로 공백을 기준으로 나누고

		double num = atof(first); // 첫 번째 입력은 숫자로 바꿈

		while((first = strtok(NULL, " ")) != NULL){ // 문자열 끝까지 기호 찾기
			if(first[0] == '@'){
				num *= 3;
			}
			else if(first[0] == '%'){
				num += 5;
			}
			else if(first[0] == '#'){
				num -= 7;
			}
		}
		result[i] = num;

	}

	for(int i = 0; i < test; i++){
		printf("%.2f\n",result[i] );
	}

	free(result);	
	return 0;
}