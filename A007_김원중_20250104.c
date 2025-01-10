#include <stdio.h>

/*
++ 문자 배열은 null 입력하기 위한 공간 필요
++ 정수 배열은 null 이 추가 되지 않기 때문에 필요한 만큼 공간 할당 가능

문제 이해=>
다장조 cdefgabC, 총 8 개음에 1부터 8까지 번호를 붙임
1 2 3 ... 8까지 치면 ascending
8 7 6 ... 1까지 치면 descending
섞여서 치면 mixed

풀이=> 
배열 크기 8 => 숫자 입력받기 
숫자 검사 해서 결과 출력  (반복문 사용 12345678이 되는지, 87654321이 되는지)
ascending과 descending 둘 다 아니면 mixed

*/


int main(){
	int arr[8];

	for(int i = 0; i < 8; i++){
		scanf("%d", &arr[i]);
	}

  // true, false를 통한 확인
	int ascending = 1;
	int descending = 1;

	for(int i = 0; i < 8; i++){
		if(arr[i] != i + 1){
			ascending = 0; // 오름차순이 되지 않으면 거짓 처리
		}
		if(arr[i] != 8 - i){
			descending = 0;
		}
	}

	if(ascending){ 
		printf("ascending");
	}
	else if(descending){
		printf("descending");
	}
	else{ // 둘 다 아니면 mixed
		printf("mixed");
	}

	return 0;

}