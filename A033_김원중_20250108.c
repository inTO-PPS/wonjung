#include <stdio.h>

/*
문제 이해=> 
나는 요리사다. 점수 1점부터 5점까지. 다른 사람이 음식을 점수로 평가 
참가자가 얻은 점수는 다른 사람이 평가해 준 점수의 합
각 참가자가 얻은 평가 점수가 주어졌을 때, 우승자와 그의 점수 구하기 

다섯 개 줄에 각 참가자가 얻은 네 개의 평가 점수가 공백으로 구분 되어 주어짐
첫 번째 ~ 다섯 번째 줄에 각각 그들이 받은 점수가 주어짐

첫째 줄에 우승자의 번호와 그가 얻은 점수 출력 

*/

int main(){
	int score[4] = {0};
	int max = 0;
	int max_index = 0;

	for(int i = 0; i < 5; i++){
		int sum = 0;
		
		for(int j = 0; j < 4; j++){
			scanf("%d", &score[j]);
			sum = sum + score[j];
		}

			if(max < sum){
				max = sum;
				max_index = i + 1;
			}
		}

	printf("%d %d", max_index, max);

	return 0;
}