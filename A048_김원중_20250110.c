#include <stdio.h>
#include <string.h>

/*
문제 이해=>
그룹 단어의 개수를 출력 해라 
	그룹 단어는 문자 하나가 연달아 나와야 함
	앞에 있던 문자가 다른 문자 뒤에 나오면 그룹 문자가 아님
	kin은 그룹문자, aabb도 그룹문자, 근데 aabba는 그룹문자가 아님

풀이=> 
첫째 줄에 단어의 개수 N개가 입력된다 (100이하)
둘째 줄부터 N개의 줄에 단어가 입력된다(소문자, 길이는 100이하)
그룹인지 아닌지 판별
	알파벳 26개인거 이용
	사용되었던 단어를 표시
	만약 뒤에 사용되었던 단어가 나왔으면 그 전 단어와 비교해서 
		다르면 이어지지 않는 것, 다음 단어로 넘어가고// 비교했을 때 같으면 이어지는 것
	문제 없이 끝까지 검사하면 count++
그룹 단어의 개수 출력


*/

int main(){
	int N = 0;
	scanf("%d", &N);

	int count = 0;

	for(int i = 0; i < N; i++){
		char input[100]; // 입력
		int alphabet[26] = {0}; // 입력한 단어에서 사용된 알파벳 확인용
		scanf("%s", input);

		int length = strlen(input);
		int group = 1; // 그룹인지 아닌지 확인용

		for(int j = 0; j < length; j++){
			char letter = input[j];
			if(alphabet[letter - 'a'] == 0){	//  소문자만 있는 것을 이용
				alphabet[letter - 'a'] = 1; // 그 알파벳이 있다는 표시
			}
			else if(input[j - 1] != letter){ // 이전 글자와 다르면
				group = 0;	// 그룹 문자가 아니다
				break;
			}
		}

		if(group){
			count++;
		}
		
	}

	printf("%d", count);

	return 0;
}
