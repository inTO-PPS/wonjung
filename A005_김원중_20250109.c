#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
++ 배열 길이를 구하는데 문제가 있었음
	=> 배열의 길이를 구할 때는 sizeof(배열)을 통해 구하고 원소로 나눠서 구했음 
		=> sizeof(skill_trees)는 배열의 전체 크기 (행 갯수 x 열 크기 == 4개 x 27(알파벳 수 + 널문자))
			== 총 108 바이트
		=> 이걸 sizeof(skill_trees[0])으로 나눔 (첫 번째 원소, 1차원 배열로 크기는 열 크기임)
			== 27바이트 (모든 원소의 크기는 27로 고정되어 있음)
				=> 108 / 27을 통해 배열에 총 4개가 있음을 알림

문제 이해=>
스킬트리대로 스킬을 찍어야함
	// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
	// skill_trees_len은 배열 skill_trees의 길이입니다.
배열은 이미 주어짐
skill_trees가 매개변수로 주어질 때, 가능한 스킬트리 개수를 리턴해야 함
(스킬 순서와 스킬트리는 문자열로 표기 C B D 일 경우 CBD로 표기)
	(스킬은 알파벳 대문자로 표기, 모든 문자열은 대문자로 이루어져있음)
		(스킬 길이는 1 이상 26이하, 스킬 중복 없음) => 유저가 입력하는
	(skill_trees의 길이는 1 이상 26이하) => 배열에 입력된
		(skill_trees의 원소는 길이가 2 이상 26이하임, 스킬은 중복되어 있지 않음)

풀이=> 
int solution(const char* skill, const char* skill_trees[], size_t skill_trees_len)
함수를 통해 skill 트리와 유저가 입력한 스킬이 가능한지 확인
	skill_trees에 가능한 스킬 목록? 들이 나열되어 있고 
	유저가 입력했을 때, skill_tree의 것들에 skill이 순서대로 포함되어 있으면 가능
		완벽하게 같지 않아도 됨. 일부만 포함하고 있어도 가능
			CBD를 입력한 경우 CBADF처럼 떨어져있어도 가능하고, AECB처럼 CB만 있어도 가능
	가능한 수를 count하고 
출력

*/

int solution(char skill[], char skill_trees[][27],int length);


int main(){

	char skill_trees[][27] = {"BACDE", "CBADF", "AECB", "BDA"}; // 2이상 26이하, 수정하는 부분
	char skill[26]; // 유저가 입력하는 스킬
	scanf("%s", skill);

	int length = sizeof(skill_trees) / sizeof(skill_trees[0]);
	if(length < 1 || length > 26){ // 길이 확인
		return 0;
	}

	int result = solution(skill, skill_trees, length);
	printf("%d", result);

	return 0;
}

// skill의 문자를 확인하고, 문자가 순서대로 있는지 확인해야 함(다 없어도 되는데, 순서대로 있어야 함)

int solution(char skill[], char skill_trees[][27],int length){
	int count = 0;
	int exist[26][2] = {0};
	int num = 0;

	for(int i = 0; skill[i] != '\0'; i++){ // 입력한 스킬 (문자열) 끝까지 확인
		exist[skill[i] - 'A'][0] = 1; // 입력한 스킬의 문자를 아스키 코드로 바꿔서 몇 번 아스키 코드(문자)가 있다고 표시
		exist[skill[i] - 'A'][1] = i; // 존재하는 문자가 몇 번째에 있는 지 
	}

	for(int i = 0; i < length; i++){
		num = 0; // 0번째부터 순서 확인
		for(int j = 0; skill_trees[i][j] != '\0'; j++){
			if(exist[skill_trees[i][j] - 'A'][0] == 1){ // 스킬이 존재할 때
				if(exist[skill_trees[i][j] - 'A'][1] == num){ //  num과 일치하면(올바른 순서면)
					num++;
				}
				else{
					num = -1;
					break;
				}
			}
		}
		if( num != - 1){ // -1이 아니면 순서대로 있다는 뜻으로 만족하는 스킬임
			count++;
		}
	}

	return count;

}