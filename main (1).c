#include <stdio.h>

// Define the Player class
typedef struct {
    char name[100];
    void (*play)(void);
} Player;

// Method for Player class
void play_cricket(void) {
    printf("The player is playing cricket.\n");
}

// Define the Batsman class
typedef struct {
    Player base;
} Batsman;

// Override the play() method for Batsman
void play_batting(void) {
    printf("The batsman is batting.\n");
}

// Define the Bowler class
typedef struct {
    Player base;
} Bowler;

// Override the play() method for Bowler
void play_bowling(void) {
    printf("The bowler is bowling.\n");
}

int main() {
    // Create objects of Batsman and Bowler classes
    Batsman batsman;
    Bowler bowler;

    // Set the play() method for each object
    batsman.base.play = play_batting;
    bowler.base.play = play_bowling;

    // Call the play() method for each object
    printf("Batsman:\n");
    batsman.base.play();

    printf("Bowler:\n");
    bowler.base.play();

    return 0;
}
