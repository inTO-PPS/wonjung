#include <stdio.h>

/*
문제 이해=> 
두 자연수 A와 B가 있다
정수 10개를 입력받고, 42로 나눈 나머지를 구하고 
서로 다른 값이 몇 개 있는 지 출력해라

첫째 줄부터 열 번째 줄까지 숫자가 한 줄에 하나씩 ( 1000보다 작은 양의 정수)

풀이=> 
숫자 하나를 입력받음 (A % B가 아니라 A가 입력받는 거 B는 문제에서 42)
나머지를 구함
나머지가 같은게 있는 지 구함
	정렬시켜서 다음 숫자랑 비교하는 방법?
		반복문을 사용해서 i - 1과 비교해서 다르면 ++, 같으면 그냥 넘어가는 방법 
	혹은 그냥 배열이 10개니까 반복문으로 10번 확인해서 같은 값이 없으면 증가, 있으면 넘어감 **
출력함
*/

int main(){
	int A = 0;
	int remainder[10];

	for(int i = 0; i < 10; i++){
		scanf("%d", &A);
		remainder[i] = A % 42;
	}

	int count = 0;
	for(int i = 0; i < 10; i++){
		int only = 1; // true
		for( int j = 0; j < i; j++){
			if(remainder[i] == remainder[j]){
				only = 0;
				break;
			}
		}
		if(only){
			count++;
		}
	}

	printf("%d", count);


	return 0;
}