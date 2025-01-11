#include <stdio.h>

/*
문제 이해=>
정수  x를 입력하고
x의 제곱근을 구해라(소수일 경우 내림)
연산 함수 사용하지 않고 풀어라

풀이=>
x / 2로 중간값 찾기 ((작은거 + 큰거) / 2)
제곱해서 x를 넘어가면, 큰거 - 1을 해서 다시 제곱근 찾기(x범위와 비교)
제곱해서 x보다 작으면, 작은거 + 1을 해서 제곱근 찾기
	교차하는 범위에서 가장 큰거 찾기
결과 출력 (int형 사용하면 자동으로 소수점 문제 해결)

*/

int main(){
	int x = 0;
	int result = 0;
	scanf("%d", &x);

	if(x == 0){ // 0일 경우는 0
		return 0;
	}

	int low = 1; // 0은 제외, 그리고 1부터 계산 가능
	int high = x / 2; //제곱근은 x/2보다 작거나 같음
	while(low <= high){ // 중간값을 찾기 위해 낮은 수와 높은 수를 통해 계산하고 범위를 넘어가면 끝
		int middle = low + (high - low) / 2; //(high + low) / 2는 오버플로우 문제로 high-low만큼 low에 더하는 것

		if(middle <= x / middle){ // x * x 방식은 오버플로우 문제가 있음.  
			result = middle; // middle보다 작으면 일단 정답 안에 포함됨(제곱근에 포함됨)
			low = middle + 1; // 더 큰 값과 비교
		}
		else{
			high = middle - 1;
		}
	}

	printf("%d", result);


	return 0;
}