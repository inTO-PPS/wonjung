#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/*
문제이해=> 
문자열 s의 길이는 4 혹은 6이 되어야 한다. 
숫자로만 구성되어야 한다. 
=> 길이가 4 혹은 6인지 그리고 숫자로만 구성되어 있는지 확인하는 함수 solution을 만들어라 

숫자로만 되어 있으면 true 리턴, 섞여있으면 false리턴 
제한 사항: 길이 1이상 8이하? (4 혹은 6이라메)
제한 사항: 알파벳 대소문자 또는 0부터 9까지 숫자여야 한다 

풀이=> 
길이가 4 혹은 6이 아니면 답을 false로 바꾼다. 
반복문을 통해 글자 하나씩 검사해서 숫자가 아니면 false로 바꾼다
*/

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
/* bool solution(const char* s) {
    bool answer = true;
    return answer;
}
*/

bool solution(const char* s) {
	bool answer = true;
	int length = strlen(s);

	if(length != 4 && length != 6){ // 조건 1: s의 길이가 4 혹은 6
		answer = false;
	}

	for(int i = 0; i < length; i++){	// 조건 2: 숫자여야 함
		if(!isdigit(s[i])){
			answer = false;
		}
	}

  return answer;
}

int main(){
	char s[9];
	scanf("%8s", s);

	if(solution(s)){
		printf("true");
	}
	else{
		printf("false");
	}


}