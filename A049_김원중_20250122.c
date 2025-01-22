#include <stdio.h>
#include <string.h>

/*

문제 이해=> 
모음 a e i o u 하나를 반드시 포함해야 한다
모음 혹은 자음이 3개 연속으로 오면 안된다
같은 글자가 연속적으로 두 번 오면 안된다(ee와 oo는 허용)
(패스워드는 소문자)

end가 나오면 종료

풀이=> 
end가 나오면 종료

입력한 password 길이만큼 반복 
  모음이 존재하는 지 확인
    모음이 연속으로 3개 연속 되는지 확인
  자음이 연속으로 3개 연속 되는지 확인

  모음/ 자음이 연속되는지 확인 
    ee oo 는 예외 처리



*/

int main(){

  char pw[21]; // 패스워드는 20글자 이하

  int i = 0;
  while(1){
    int accept = 1;
    int vowel = 0; //모음
    int consonants = 0;// 자음
    int exist = 0;

    scanf("%s", pw);
    if(strcmp(pw,"end") == 0){ // end가 나오면 프로그램 종료
      break;
    }

    for(int i = 0; i < strlen(pw); i++){
      if(pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u'){
        exist = 1; // 모음이 존재한다고 표시(한 개 이상이면 됨)
        vowel++; // 모음이 연속되는지 확인
        consonants = 0; // 자음 개수는 0으로 해서 연속이 안된다는 것을 표시
      }
      else{ // 자음일 때
        consonants++;
        vowel = 0;
      }

      if(vowel == 3 || consonants == 3){
        accept = 0; // 자음이나 모음이 3개 연속이 되면 불가능
        break;
      }

      if(i < strlen(pw) - 1){ // 단어가 연속된다면
        if(pw[i] == 'e' && pw[i + 1] == 'e' || pw[i] == 'o' && pw[i + 1] == 'o' ){
          continue; // ee oo는 예외
        }
        else if(pw[i] == pw[i+1]){ // 다음 글자와 연속된다면 불가능
          accept = 0;
          break;
        }
      }
    }

    if(accept && exist){ // accept와 exist가 1이라면 == true 면
      printf("<%s> is acceptable.\n", pw);
    }
    else{
      printf("<%s> is not acceptable.\n", pw);
    }
  }

  return 0;
}



