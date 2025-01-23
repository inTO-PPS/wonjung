#include <stdio.h>

/*

문제 이해=> 
충분한 500엔, 100엔, 50엔, 10엔, 5엔, 1엔
거스름돈이 가장 적게 준다

첫째 줄에 지불할 돈 입력
출력은 최소한으 ㅣ거스름돈 개수

풀이=> 
1000 - 비용 = 잔돈

잔돈 = 500엔 100엔 50엔 10엔 5엔 1엔 순환하면서 가능한 만큼 빼야함
(최소한으로 움직이기 때문에 큰 비용을 계속 빼기)

*/



int main(){
  int money = 0;  // 얼마를 냈는지 
  scanf("%d", &money);

  int change = 1000 - money;
  int coins[] = {500,100,50,10,5,1};
  int count = 0;

  for(int i = 0; i < 6; i++){// 동전만큼 반복
    count += change/coins[i];// 해당 동전으로 최대 몇 개를 낼 수 있는지 
    change = change % coins[i]; // 남은 돈 계산
  }

  printf("%d", count);
  
  return 0;
}



