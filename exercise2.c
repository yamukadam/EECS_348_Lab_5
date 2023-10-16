#include <stdio.h>

int main(){
    int user_score;
    while (1){
        printf("Enter 0 or 1 to stop.\n");
        printf("Enter the NFL score: ");
        scanf("%d", &user_score);
        if (user_score <= 1){
            break;
        }
        for(int td = 0; td<= user_score/6; td++){
            for(int fg = 0; fg<= user_score/3; fg++){
                for(int safety = 0; safety<=user_score/2; safety++){
                    for(int td2 = 0; td2<=user_score/8; td2++){
                        for(int td1=0; td1<=user_score/7; td1++){
                            if((td*6)+(fg*3)+(safety*2)+(td2*8)+(td1*7) == user_score){
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3PT FG, %d Safety\n", td2, td1, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }



    

    return 0;
}