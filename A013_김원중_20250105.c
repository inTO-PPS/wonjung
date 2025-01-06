#include <stdio.h>
#include <stdlib.h>

/*
++ XOR연산자 사용 : 같으면 0, 다르면 1 그대로 (비트로 계산하는 것)

문제 이해=> 
정수 배열 nums가 있다.
배열의 요소는 두 번씩 나오는데, 하나의 요소가 하나만 나온다. 
한 번만 나오는 요소를 찾아라

linear runtime complexity 
constant extra space => 선형 시간 복잡도, 상수 크기의 추가 공간 
=> 한 번만 돌아야 한다. 하나의 변수로만 해결해야 한다. 

풀이=> 
정수 배열 선언 , 입력받기 
검사 
	XOR연산자 사용 (같으면 0이고 남는 것은 1로 남기 때문에 한 번만 있는 숫자를 찾을 수 있음)
결과 출력(한 번만 있는 숫자)

*/

int check(int s[], int input);

int main(){
	int input = 0;
	printf("숫자 몇 개 >");
	scanf("%d", &input);

	int *nums = (int*)malloc(input * sizeof(int));

	printf("배열에 들어갈 수 >");
	for(int i = 0; i < input; i++){
		scanf("%d", &nums[i]);
	}

	int result = check(nums,input);
	printf("%d", result);

	free(nums);
	return 0;

}

int check(int s[], int input){
	int results = 0;
	for(int i = 0; i < input; i++){
		results = results ^ s[i];
	}
	return results;
}