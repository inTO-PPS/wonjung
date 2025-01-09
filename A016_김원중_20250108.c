#include <stdio.h>
#include <stdlib.h>

/*
문제 이해 => 
구명보토를 이용하여 구출 
근데 구명보트인데 두명보트인 거임. 거기다가 무게 제한까지 있음
사람들의 몸무게를 담은 배열 people과 구명보트의 무게 제한 limit가 매개변수로 주어짐
사람들을 구출하기 위해 필요한 구명보트 개수의 최솟값을 retur 해야함. (solution 함수 만들어야 함)

갇힌 사람은 1명 이상 50,000명 이하
몸무게는 40kg 이상 240kg 이하
구명보트의 무게 제한은 40kg 이상 240kg 이하
무게 제한은 항상 주어진 몸무게 중 최댓값보다 크게 주어지므로 사람들을 구출할 수 없는 경우는 없음

풀이 => 
원래 함수만 적는 문제
배열을 만들어서 매개변수로 함수에 주는 거(입력 아닌 듯 함)

매개함수로 몸무게를 받으면 
	정렬 시킨다
	가장 가벼운 무게와 가장 무거운 무게를 찾아서 더한다
	limit과 비교한다 
		limit을 초과하면 무거운 놈은 혼자 탄다
		limit을 초과하지 않게 된다면 가벼운놈과 무거운놈 같이 탄다
		그리고 보트 수 증가
	새로운 변수(return 할 변수)에 + 1을 하고, 사용한 변수는 찾지 못하게 음수로 바꾼다다


*/

int solution(int *array, int limit, int num);
int compare(const void *a, const void *b);

int main(){
	int num = 0;
	printf("몇 명> ");
	scanf("%d", &num);
	int *people = (int*) malloc(num * sizeof(int));
	
	printf("각각 몇 kg>");
	for(int i = 0; i < num; i++){
		scanf("%d", &people[i]);
	}
	
	printf("제한 무게는> ");
	int limit = 0; 
	scanf("%d", &limit);

	int result = solution(people, limit, num);
	printf("%d", result);

	free(people);
	return 0;
}

int compare(const void *a, const void *b){
	return *(int *)a - *(int *)b; // 음수 면 a가 작음, 양수면 b가 작음
}

int solution(int *array, int limit, int num){
	qsort(array, num , sizeof(int), compare);
	int light = 0;
	int heavy = num - 1;
	int boat = 0;

	while(light <= heavy){ // light를 증가시키고, heavy를 감소시키는데 light와 heavy가 같아질 때까지
		if(array[light] + array[heavy] <= limit){
			light++; // limit보다 작거나 같을 때 다음 가벼운 사람으로 넘어가도록 
		}
		heavy--; // 무거운 사람은 light와 함께 보트를 타거나 혹은 혼자서 타야 함
		boat++; // 보트 수는 증가됨
	}
	return boat;

}