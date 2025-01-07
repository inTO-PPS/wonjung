#include <stdio.h>
#include <stdlib.h>

/*
문제 이해=> 
하나의 콘센트, N개의 멀티탭 (멀티탭은 몇 개의 콘센트로 이루어짐)
최대 몇 대의 컴퓨터를 전원에 연결할 수 있을까

첫째 줄에 멀티탭의 개수 N이 주어짐( 1 <= N <=500,000)
둘째 줄부터 N개의 줄에 멀티탭에 몇 개의 플러그를 꽂을 수 있는지 자연수가 주어짐(1,000보다 작음)

최대로 전원에 연결될 수 있ㄴ는 컴퓨터의 수를 출력한다

풀이 => 
N 변수 선언 및 입력 
N개 반복하는데 입력한 값을 저장함 (배열에 저장하기 )
	마지막 멀티탭을 제외하고는 다음 멀티탭을 꽂기 위한 콘센트 하나를 빼야함 (-1)
	마지막 멀티탭의 콘센트 수는 그대로 더하기
출력하기
*/

int main(){
	int N = 0;
	scanf("%d", &N);

	int *plug;
	plug = (int*)malloc(N * sizeof(int));

	int sum = 0;
	for(int i = 0; i < N; i++){
		scanf("%d", &plug[i]);
		if(i < N - 1){
			sum = sum + (plug[i] - 1);
		}
		else{
			sum = sum + plug[i];
		}
	}

	printf("%d", sum);

	free(plug);
	return 0;
}