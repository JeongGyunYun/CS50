

#include <stdio.h>
#include <string.h>
#include <math.h>

typedef enum{EXIT, VALID, INVALID_NUM, INVALID_STR}CODE;


typedef struct INFO{
    int sign;
    int isNum;
    int value;
}INFO;


char* grade[] = {"A+", "A", "B+", "B", "C+", "C", "D+", "D", "F"};
int score[] = {95, 90, 85, 80, 75, 70, 65, 60, 0};

int get_index(int score);
CODE chk_score(int score);
void prt_table(void);
void prt_manual(void);
INFO get_info(char * str);

int main(void){
    int score, index;
    char inStr[30];
    CODE code;

    prt_manual();
    prt_table();


    do{
        printf("성적을 입력하세요 (0 ~ 100) : ");
        scanf("%s", &inStr);

        getchar(); // stream buffer 제거

        INFO info = get_info(inStr);
        if(info.isNum){     // 숫자인지 정보 확인
            score = info.sign ? info.value : -info.value; // 부호가 1이면 양수, 0이면 음수
            code = chk_score(score);
        }else{
            code = INVALID_STR;
        }

        if(code == VALID){
            index = get_index(score);
            printf("학점은 %s 입니다\n", grade[index]);
        }
        else if(code == INVALID_NUM){
            printf("** %d 성적을 올바르게 입력하세요. 범위는 0~100 입니다.\n", score);
        }else if(code == INVALID_STR){
            printf("** %s 은 숫자가 아닙니다. 입력은 숫자만 가능합니다.\n", inStr);
        }
        else{
            printf("학점 프로그램을 종료합니다.\n");
        }
    }while(code);

    return 0;
}

INFO get_info(char * str){
    int len = strlen(str);
    // 부호 정보, 숫자 여부, 값 정보를 저장
    INFO info = {1,1, 0};

    for(int digit = len-1; digit >=0; digit--){
        char c = *str++;
        if ('0' <= c && c <= '9') { //문자가 숫자일 떄 숫자 정보입력
            info.value +=  pow(10, digit)*(c - '0');
        }else if(digit == len-1 && c == '-'){       //첫번째 문자가 부호문자 일 때 부호정보 입력
            info.sign = 0;
        }
        else {  //입력값이 문자일 때 정보 저장 후 함수 종료
            info.isNum = 0;
            return info;
        }
    }
    return info;
}


CODE chk_score(int score){
    if(score >= 0 && score <= 100 ){
        return VALID;
    }else if(score == 999){
        return EXIT;
    }else{
        return INVALID_NUM;
    }
}

int get_index(int score){
    int ten_digit, w, index;
    ten_digit = score / 10;
    w = score % 10 > 4 ? 0 : 1;

    switch (ten_digit) {
        case 10:
            index = 0;
            w = 0;
            break;
        case 9:
            index = 0;
            break;
        case 8:
            index = 2;
            break;
        case 7:
            index = 4;
            break;
        case 6:
            index = 6;
            break;
        default:
            index = 8;
            w = 0;
    }
    return index + w;
}

void prt_manual(void){
    printf("학점 프로그램\n");
    printf("종료를 원하면 \"999\"를 입력\n");
}

void prt_table(void){
    printf("[학점 테이블]\n");
    printf("점수 : ");
    for(int i = 0; i < 9; i++){
        printf("%-7d", score[i]);
    }
    puts("");
    printf("학점 : ");
    for(int i = 0; i < 9; i++){
        printf("%-7s", grade[i]);
    }
    puts("");
}
