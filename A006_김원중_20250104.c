#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
++ 0은 false, 나머지는 true 잊지 말기 
++ !check는 거짓말일 때, 즉 false (0)일 때
++ isalpha는 한글자만 검사하는 거였음

문제 이해=>
문자열 s가 주어진다 
문자열 s 에서 p의 개수와 y의 개수가 같으면 true, 다르면 false를 리턴한다
p와y모두 없으면 true로 리턴한다.
대소문자는 구별하지 않는다

문자열 s 는 최대 50글자이고, 영어로만 이루어진다

풀이=>
define MAX = 50
문자열선언, tolower로 소문자로 만들어서 p의 개수와 y의 개수를 센다 
개수가 같으면 true 리턴, 다르면 false 리턴, 둘 다 0이면 true 리턴 한다

*/
#define MAX 50

int main(){
	char s[MAX];
	
	int check = 0; 
	while(!check){ // 거짓일 때 반복(0일 때)
		scanf("%s", s);

		check = 1; // 맞다고 가정하고 밑에서 검사
		for(int i = 0; s[i] != '\0'; i++ ){
			if(!isalpha(s[i])){
				check = 0; // 알파벳이 아니면 중단
				break;
			}
		}
	}
	
	int countP = 0;
	int countY = 0;

	//변수를 만들어서 길이를 확인하거나, '\0'이 아닐 때 반복
	for(int i = 0; i < strlen(s); i++){ 
		s[i] = tolower(s[i]);
		if(s[i] == 'p') countP++;
		else if(s[i] == 'y') countY++;
	}

	if(countP == countY){
		printf("true");
	}
	else if(countP != countY){
		printf("false");
	}

	return 0;
}