#include <stdio.h>

/*
문제 이해=> 
다솜이가 지 방 번호를 꾸미겠다네 
플라스틱으로? 
근데 옆집에서 플라스틱 숫자를 한 세트로 판대
0부터 9까지 한 세트를 판대. 6과 9는 서로 뒤집어서 사용 가능

첫째 줄에 방 번호 N (1,000,000 >= N)이 주어지고 (입력하고)
필요한 세트의 개수를 출력한다

풀이=> 
배열 생성 및 입력
배열 0 ~ 9까지, 각 자리에 숫자 몇 개가 있는지 확인, null문자가 나올 때까지
	근데 6과 9의 경우 같이 사용할 수 있음 => 6과 9가 몇 개인지 확인 
가장 많은 세트 수 출력 
*/


int main(){
	char room_num[1000001];
	int number[10]; // 0 1 2 3 4 5 6 7 8 9

	scanf("%s", room_num);

	for(int i = 0; room_num[i] != '\0'; i++){	// number에서 각 숫자에 ++를 통해서 몇 세트 필요한지
		number[room_num[i] - '0']++;
	}

	int six_nine = 0;
	six_nine = (number[6] + number[9] + 1) / 2; // 6과 9는 같이 사용 
	number[6] = six_nine;
	number[9] = six_nine;

	int set = 0;
	for(int i = 0; i < 10; i++){
		if(number[i] > set){
			set = number[i];
		}
	}
	
	printf("%d", set);
	return 0;
}

