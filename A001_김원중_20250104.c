#include <stdio.h>
#include <stdlib.h>

/*
 ++ qsort 사용(compare 함수 만들어야 함), void * 개념 공부



int findContentChildren(int* g, int gSize, int* s, int sSize) {   
} 사용

문제 이해
아이들을 만족 시켜야 함
g[i] 는 탐욕으로 아이들을 만족시켜야하는 수치
쿠키 j는 사이즈 s[j]를 가짐
s[j] >= g[i] 사이즈가 탐욕수치보다 크거나 같을 경우 만족시킬 수 있음
쿠키 j개를 아이 i명에게 주고 i명이 만족할 수 있어야 함
만족하는 아이의 수를 최대한으로 해야함
But, you should give each child at most one cookie.

g[1,2,3], s[1,1] => 사이즈가 1인 쿠키가 두 개, 최대 한 개만 줄 수 있고 만족할 수 있는 경우는 g[0]에게 하나를 주는 것
g[1,2], s[1,2,3] => 사이즈가 1 2 3인 쿠키 세 개, g[0]=1은 1을 만족, g[1] = 2로 2를 만족

1. 정렬하는 함수
2. 비교하는 함수 => 크거나 같으면 만족한 아이 증가

scanf로 g[], s[] 입력 받기 -> 함수 사용해서 만족하는 아이 찾기-> 결과 출력하기 

*/

int findContentChildren(int *g, int gSize, int *s, int sSize);
int compare(const void *a, const void *b);

int main(){
	// 아이와 쿠키 수 입력받기
	int children = 0;
	int cookie = 0; 
	printf("아이 수> ");
	scanf("%d", &children);
	printf("쿠키 수> ");
	scanf("%d", &cookie);

	// 배열로 만들고, 탐욕지수와 쿠키 사이즈 입력받기
	// int g[children];
	// int s[cookie];

  int *g = (int*)malloc(children * sizeof(int));
  int *s = (int *)malloc(cookie * sizeof(int));

	printf("아이 별 탐욕 지수> ");
	for(int i = 0; i < children; i++){
		scanf("%d", &g[i]);
	}
	printf("쿠키 별 사이즈> ");
	for(int i = 0; i < cookie; i++){
		scanf("%d", &s[i]);
	}

	// 결과 출력하기 위한 변수 선언, 함수를 통해서 계산
	int output = 0;
	output = findContentChildren(g, children, s, cookie);
	printf("%d", output);

  free(g); free(s);
	
	return 0;
}

//void qsort (void *base, size_t nel, size_t width, int (*compare)(const void *, const void *);

int findContentChildren(int *g, int children, int *s, int cookie) {
    // 탐욕수치, 과자 크기 정렬
    qsort(g, children, sizeof(int), compare);
    qsort(s, cookie, sizeof(int), compare);

    int contentChildren = 0;
    int useCookie = 0;

    // contentChildren과 useCookie가 children과 cookie의 수보다 커지면 멈춰야 함
    while(contentChildren < children && useCookie < cookie){
    	if(s[useCookie] >= g[contentChildren]){
    		contentChildren++; // g[i]보다 크면 ++
    	}
    	useCookie++;
    }
    return contentChildren; // 결과 반환
}

// int (*compare)(const void *, const void *) => qsort는 모든 데이터 타입 지원 (void 사용)
// 수업 때 배운거-> void는 타입이 명시되어 있지 않아서 타입 캐스팅 해줘야 됨 (*로 데이터를 가리킴)
int compare(const void *a, const void *b){
	return *(int *)a - *(int *)b; // 음수 면 a가 작음, 양수면 b가 작음
}