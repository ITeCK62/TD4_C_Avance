#include <stdio.h>
#include <assert.h>

// 000 000 000 0
// 100 000 000 0
// X |  | 
//   |  |
//   |  |

// 100 001 000 1
// X |  |
//   |  | O
//   |  |

// 101 001 000 0
// X |  | X
//   |  | O
//   |  |

typedef struct {
    unsigned char in;
    unsigned termine : 1;
    unsigned ligne : 2;
    unsigned colonne : 2;
    unsigned player : 1;
    unsigned c_1_1 : 2;
    unsigned c_1_2 : 2;
    unsigned c_1_3 : 2;
    unsigned c_2_1 : 2;
    unsigned c_2_2 : 2;
    unsigned c_2_3 : 2;
    unsigned c_3_1 : 2;
    unsigned c_3_2 : 2;
    unsigned c_3_3 : 2;
} data;

int switch(){
    if(player == 0){
        player = 1;
    }
    else{
        player = 0;
    }
}

int jeu(){
    while (!termine){
        printf("Quel ligne ?");
        scanf("%hhu", &jeu_data.in);
        assert(jeu_data.in > 2 && jeu_data.in < 0);
        jeu_data.ligne = jeu_data.in;
        printf("Quel colonne ?");
        scanf("%hhu", &jeu_data.in);
        assert(jeu_data.in > 2 && jeu_data.in < 0);
        jeu_data.colonne = jeu_data.in;
        if(player == 0){
            printf("c_ X", &ligne, &colonne);
            switch();
        }
        else{
            printf("c_%d_%d O", &ligne, &colonne);
            switch();
        }
    }
}

int main(){
    data jeu_data;
    jeu();
}