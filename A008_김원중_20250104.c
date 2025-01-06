#include <stdio.h>
#include <stdlib.h>

/*
문제 이해=> 
테스트 케이스의 개수 C개 (입력)
다음 줄에 학생 수 (1 <= N <= 1000), N명의 점수 입력
점수는 0<= score <= 100
평균을 넘는 학생의 비율을 반올림하여 소수점 셋째 자리까지 출력

풀이=> 
테스트 몇 개 할지 결정
테스트 개수만큼 반복 
	학생 수 입력 => 입력한 학생 수 만큼 성적 입력

평균을 넘는 학생 비율 출력(소수점 셋째 자리까지)

*/

int main(){

	int test_case = 0;
	scanf("%d", &test_case);

	double *results = (double*) malloc(test_case * sizeof(double));

	for(int i = 0; i < test_case; i++){
		int student_num = 0;
		scanf("%d", &student_num);

		int *score = (int*) malloc(student_num * sizeof(int));

		int sum = 0;
		for(int j = 0; j < student_num; j++){
			scanf("%d", &score[j]);
			sum += score[j];
		}

		double avg = (double)sum / student_num;
		int great_student = 0;
		for(int j = 0; j < student_num; j++){
			if(score[j] > avg){
				great_student++;
			}
		}

		results[i] = ((double)great_student / student_num) * 100.0;

		free(score);

	}

	for(int i = 0; i < test_case; i++){
		printf("%.3lf%%\n", results[i]);
	}

	free(results);
	return 0;

}