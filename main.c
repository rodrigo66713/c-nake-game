#include <stdio.h>
#include <conio.h>

#include "playable-area.h"

//Function Prototypes 
void getControls(char key_pressed);

// Main Menu
int main() {
    char key_pressed;
    
    printf("===============================================================\n");
    printf("=================== WELCOME TO C-NAKE GAME ====================\n");
    printf("===============================================================\n");

    printf("\nPress ENTER to start . . .\n");
    getchar();

    printf("Use WASD or ARROW KEYS to play: \n");
    setPlayableArea();

    while(1){        
        //kbhit(): Function in conio.h that gets when a key is pressed on the keyboard.
        if(kbhit()){
            key_pressed = getch();

            getControls(key_pressed);
        } 
    }
}

/*
This function will get the movement keys to move C-Nake
*/
void getControls(char key_pressed) {
    switch(key_pressed){
        case 72:
        case 'w':
            printf("Move Up\n");
            break;
        
        case 80: 
        case 's': 
            printf("Move Down\n");
            break;

        case 77: 
        case 'd':
            printf("Move Right\n");
            break;

        case 75: 
        case 'a': 
            printf("Move Left\n");
            break;
        default: 
            break;
    }
}