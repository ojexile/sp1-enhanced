#ifndef _GAME_H
#define _GAME_H

#define MON_DETECT_RANGE_X 15
#define MON_DETECT_RANGE_Y 5
#define BLANK_SPACE 48
#define WALL 49
#define ENDPOINT 50
#define ICE 51
#define KEY 52
#define GATE 53

#include "Framework\timer.h"
#include <fstream>

extern CStopWatch g_swTimer;
extern bool g_bQuitGame;

// Enumeration to store the control keys that your game will have
enum EKEYS
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_ESCAPE,
    K_SPACE,
 	K_ONE,
	K_TWO,
	K_THREE,
	K_FOUR,
	K_FIVE,
	//adding keys 6-0, enter + backspace for encounterMonster.
	K_SIX,
	K_SEVEN,
	K_EIGHT,
	K_NINE,
	K_ZERO,
	K_ENTER,
	K_BACKSPACE,
	K_COUNT // unsure what this does, leaving it at the end.

};

// Enumeration for the different screen states
enum EGAMESTATES
{
	S_SPLASHSCREEN,
	S_GAME,
	S_LEVELSELECT,
	S_CHARACTERCOLOR,
	S_ENCOUNTERMONSTER,
	S_WINSCREEN,
	S_COUNT
};

enum ELEVELS
{
	L_LEVELONE,
	L_LEVELTWO,
	L_LEVELTHREE,
	L_LEVELFOUR,
	L_LEVELFIVE,
	L_COUNT
};
enum MON_IDLE
{
	MON_NOTHING,
	MON_UP,
	MON_DOWN,
	MON_LEFT,
	MON_RIGHT
};
enum MON_NO
{
	monsONE,
	monsTWO
};
enum P1_NUMBER {
	NUM_ZERO,
	NUM_ONE,
	NUM_TWO,
	NUM_THREE,
	NUM_FOUR,
	NUM_FIVE,
	NUM_SIX,
	NUM_SEVEN,
	NUM_EIGHT,
	NUM_NINE,
	NUM_NIL
};


enum MON1_MOV {
	MON1_UP,
	MON1_DOWN,
	MON1_LEFT,
	MON1_RIGHT
};


enum SLIDE_DIRECTION {
	D_NONE,
	D_UP,
	D_DOWN,
	D_LEFT,
	D_RIGHT
};

// struct for the game character
struct SGameChar
{
    COORD m_cLocation;
    bool  m_hasKey;
};


void init        ( void );      // initialize your variables, allocate memory, etc
void getInput    ( void );      // get input from player
void update      ( double dt ); // update the game and the state of the game
void render      ( void );      // renders the current state of the game to the console
void shutdown    ( void );      // do clean up, free memory

void splashScreenWait();    // waits for time to pass in splash screen
void splashScreenSelect();	// handles keypresses in main menu
void renderLevelSelectBG(); // handles level select 
void LevelScreenSelect();	// handles the key for level select
void renderCharacterColour();	// renders character colour select screen
void charactercolourselect();	//handles logic for character colour select screen
void renderLevelSelect();	// handles renderlevelselectBG
void gameplay();            // gameplay logic
void moveCharacter();       // moves the character, collision detection, physics, etc
void moveCharacterICE();	// handles (exclusive) ice movement.
void slideICE();			// handles logic-side of ice movement.
void processUserInput();    // checks if you should change states or do something else with the game, e.g. pause, exit
void clearScreen();         // clears the current screen and draw from scratch 
void renderSplashScreen();  // renders the splash screen
void renderGame();          // renders the game stuff
void renderMap();           // renders the map to the buffer first
void renderCharacter();     // renders the character into the buffer
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game
void monsterAI();			// The monster's actions
void monsterALL();			// monster number 1 position and looks
void monsterLocation();		// edits monster's location
void monsterCHASE();		// monster chasing player function
MON_IDLE monsterIDLEMOV();	// random generator for monster's movements
MON_NO monsterTABLE();		// random generator for monster on the map
void loadMap();				// loads text file into array
void winscreen();			// logic for winscreen
void winscreenRender();		// renders winscreen
void resetPos();			// resets position of all entities
bool isSolid(int x, int y);				// returns false if can move into coordinate and and true if cannot

void renderEncounterMonster();
void renderMonster();
void monsterPuzzle();
void renderMonsterPuzzle();
#endif // _GAME_H

