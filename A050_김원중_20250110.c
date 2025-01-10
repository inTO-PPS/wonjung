#include <stdio.h>
#include <ctype.h>
#include <string.h>


/*
++ 문자를 아스키코드로 변환 시키려고 했는데
	=> 문자를 연산하면 문자 자체가 정수 값(아스키 코드)로 자동 변환된다고 함
	=> 출력할 때는 다시 문자로 출력됨

문제 이해 => 
카이사르 암호, 알파벳 문자를 3개씩 건너뛰어 적음 (+3 한 것)
26개의 대문자 알파벳
다음 3문자를 옮겨 겹치지 않게 나열하여 얻은 카이사르 암호를 원래 단어로 돌려놓는 프로그램

한 줄로 입력, 대문자 알파벳, 1000자 이하
원래 단어로 고쳐서 출력해라

풀이 => 
입력받을 문자열 선언 및 출력 , 1000자 이하
	대문자가 아니면 끝내버려
	아스키 코드로 변환시키고 - 3해서
	A B C의 경우 X Y Z가 되어야 함 
		-3을 해서 복원시키면 A B C는 대문자 범위를 벗어남
		+26(알파벳 개수)를 해서 대문자로 돌려 놓음
출력

*/

int main(){
	char input[1001];
	scanf("%s", input);
	int length = strlen(input);

	for(int i = 0; i < length; i++){
		char letter = input[i];

		if(!isupper(letter)){
			return 0;
		}

		char restore = letter - 3;

		if(restore < 'A'){
			restore = restore + 26;
		}

		printf("%c", restore);

	}

	return 0;
}