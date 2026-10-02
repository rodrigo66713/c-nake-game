#include <stdio.h>
#include <conio.h>

#define WALL_SIZE_LENGTH 31
#define WALL_SIZE_WIDTH 16

//Function Prototypes 
void getControls(char key_pressed);
void setPlayableArea();
void drawPlayableArea();

// Main Menu
int main() {
    char key_pressed;
    
    printf("===============================================================\n");
    printf("=================== WELCOME TO C-NAKE GAME ====================\n");
    printf("===============================================================\n");

    printf("\nPress any key to start . . .\n");
    system("pause > nul");
    system("cls");

    printf("Use WASD or ARROW KEYS to play: \n");
    setPlayableArea(); 

    while(1){
        //kbhit(): Function in <conio.h> that gets when a key is pressed on the keyboard.
        if(kbhit()){
            key_pressed = getch();

            getControls(key_pressed);
        } 
    }
}

/*
This function set the playable area where C-Nake will move, such as ground and walls.
*/
void setPlayableArea() {
    char playable_area[WALL_SIZE_LENGTH][WALL_SIZE_WIDTH];
    
    for (int width = 0; width < WALL_SIZE_WIDTH; width++) {
        for (int length = 0; length < WALL_SIZE_LENGTH; length++) {
            if ((length == 0 || length == WALL_SIZE_LENGTH - 1) || (width == 0 || width == WALL_SIZE_WIDTH - 1)) {
                playable_area[length][width] = '#';
            } else {
                playable_area[length][width] = ' ';
            }
        }
    }

    drawPlayableArea(playable_area); 
}

void drawPlayableArea(char playable_area[WALL_SIZE_LENGTH][WALL_SIZE_WIDTH]) {
    for (int width = 0; width < WALL_SIZE_WIDTH; width++) {
        for (int length = 0; length < WALL_SIZE_LENGTH; length++) {
            printf("%c", playable_area[length][width]);
        }
        printf("\n");
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