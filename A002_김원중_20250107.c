#include <stdio.h>

/*
문제 이해=> 
파스칼의 삼각형. 인접한 숫자의 합이 밑으로 간다 
첫 번째 줄에 몇 줄인지 입력하고 
[] 안에 각 줄의 숫자 열을 입력한다 
[[1], [1,1], [1,2,1],[1,3,3,1], [1,4,6,4,1]] [[1, 5, 10,10, 5, 1]]

풀이=> 
줄이 몇 갠지 입력 받는다 
줄이 늘어날 수록 배열이 하나씩 늘어난다. (입력받은 줄만큼 반복한다)
	첫 번째 숫자와 마지막 숫자는 어쩔 수 없이 1임
	중간에 들어가는 숫자는 앞의 숫자와 뒤의 숫자를 합하는 것 (자신의 -1행, -1열 + 자신의 -1행,같은 열 )
	행 = 열, 0행일 때, 
	1줄 = 1, 2줄 = 2, 3줄 = 3, 4줄 = 4, 5줄 = 5 ,6줄 = 6

*/

int generate(int i, int j);

int main(){
	int input = 0;
	scanf("%d", &input);

	printf("[");
	for(int i = 0; i < input; i++){ // 입력한 만큼 반복 (몇 줄 할 것인지)
		if(i < input - 1){ // 마지막 배열을 제외하고는 [1], 형태로 출력
			printf("[");
			for(int j = 0; j <= i; j++){ // n번째 줄에는 요소가 n개 있어야 함
				printf("%d", generate(i,j));
				if(j < i){
					printf(",");
				}
			}
			printf("], ");
		}
		else{
			printf("[");
			for(int j = 0; j <= i; j++){
				printf("%d", generate(i,j));
				if(j < i){
					printf(",");
				}
			}
			printf("]");
		}
	}
	printf("]");

	return 0;
}

int generate(int i, int j) {
  if(i == j || j ==0) return 1;
	else{
		return generate(i - 1, j -1) + generate(i - 1, j); // 위쪽 행(i -1), j- 1과 j는 왼쪽 오른쪽
	}
}