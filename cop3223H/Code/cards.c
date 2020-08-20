
// Clara Poffenberger and Nathaniel Lyra
// 11/2/18
// FP4
// Note to self: do something with subtracting '0' to get the integer value from a '6' (num character) just like you do with -'a'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DECK_SIZE 52

typedef struct card {
    char value;
    char suit;
} card;

void setup (struct card *b);
void translate (struct card *b);

int main (void) {

    int n;
    char cg;
    scanf("%d", &n);

    card array[DECK_SIZE];
    
    int i, j, longestvalue=0, longestsuit=0, maxvalue=0, maxsuit=0;

    for (j = 0; j<n; j++){ 

            for (i = 0; i<52; i++) {
                
                setup(&array[i]);

                translate(&array[i]);

                if (array[i].value == 'A'){
                    if (array[i+1].value == 2){
                        array[i].value = 1;
                    }    
                }
                if (array[i].value == 'A'){
                    if (array[i-1].value == 13){
                        array[i].value = 14;
                    }
                }

                if (array[i].value == array[i+1].value-1){
                    longestvalue++;
                    if (longestvalue > maxvalue){
                        maxvalue = longestvalue;
                    }
                }
                else{
                    longestvalue = 0;
                }

                if (array[i].suit == array[i+1].suit){
                    longestsuit++;
                    if (longestsuit > maxsuit){
                        maxsuit = longestsuit;
                    }
                }
                else{
                    longestsuit = 0;
                }
                


                
            }
            
            printf("%d %d\n", maxsuit, maxvalue);

    }

       
    


    return 0;

}

void setup (struct card *b){
    
    scanf("%c%c", &(b->value), &(b->suit));
    printf("%c%c\n", b->value,b->suit);

}

void translate (struct card *b){

    if (b->value >='2' && b->value <='9'){
        b->value = b->value - '0';
    //    printf("%d\n",(b->value));
    }
    else if (b->value == 'T'){
        b->value = 10; 
      //  printf("%d\n",(b->value));
    }
    else if (b->value == 'J'){
        b->value = 11;
        //printf("%d\n",(b->value));
    }
    else if (b->value == 'Q'){
        b->value = 12;
        //printf("%d\n",(b->value));
    }
    else if (b->value == 'K'){
        b->value = 13;
        //printf("%d\n",(b->value));
    }
}