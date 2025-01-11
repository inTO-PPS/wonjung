#include <stdio.h>
#include <string.h>

/*
문제 이해=>
배열 정렬하기 
수가 주어지면 
그 수의 각 자리수를 내림차순으로 정렬하라

풀이=>
첫째 줄에 정렬하려고 하는 수 N이 주어진다 
N은 1,000,000,000보다 작거나 같다 (숫자가 크니까 문자열로 받아서 )
	qsort 사용해서 정렬시키거나
	직접 정렬시켜야함
		문자 길이 
		문자 길이만큼 반복
			숫자가 가장 작은거를 찾아서 앞에 놓기

*/

int main(){
	char N[11]; // 1 000 000 000
	scanf("%s", N);

	int length = strlen(N);

	int bigger =0;
	char temp;
	for(int i = 0; i < length; i++){ // 0번째부터 시작해서 숫자가 큰 수들을 정렬시키는 것
		bigger = i; // 현재 위치를 가장 크다고 가정
		for(int j = i + 1; j < length; j++){
			if(N[j] > N[bigger]){
				bigger = j; // 가장 큰 수의 인덱스 찾기
			}
		}

		// 위치 바꾸기
		temp = N[i];
		N[i] = N[bigger];
		N[bigger] = temp;
	}

	printf("%s", N);

	return 0;
}