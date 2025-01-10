#include <stdio.h>
#include <string.h>

/*
문제 이해=> 
알파벳 소문자와 대문자로만 이루어진, 길이가 N인 단어 입력
한 줄에 10글자씩 끊어서 출력하는 프로그램 만들기

첫째 줄에 단어 주어짐(알파벳으로, 길이가 100을 넘지 않음)
입력으로 주어진 단어를 열 개씩 끊어서 한 줄에 하나씩 출력

풀이=> 
크기가 100인 문자열 선언 및 입력 받기
길이 재고, 길이만큼 반복
	반복문을 통해 문자 출력
	i % 10 을 했을 때 9면 개행문자 입력

*/

int main(){
	char input[100];
	scanf("%s", input);

	int length = strlen(input);

	for(int i = 0; i < length; i++){
		printf("%c", input[i]);
		if(i % 10 == 9){ // 0 ~ 9까지 출력하고, 10번째면 다음 줄
			printf("\n");
		}

	}

	return 0;
}