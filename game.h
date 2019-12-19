#include <allegro5/allegro5.h>

// Constants
static const int FPS = 120;
static const int SCREEN_W = 1280;
static const int SCREEN_H = 960;
static const int vehicleHeight = 173;
static const int vehicleWidth = 100;

// Colors
#define BACKGROUND al_map_rgb(0xff, 0xff, 0xff)
#define WHITE      al_map_rgb(0xff, 0xff, 0xff)
#define PINK       al_map_rgb(255, 0, 255)

struct Input {
    bool up;
    bool down;
    bool left;
    bool right;
    bool escape;
};

struct Movement {
    bool onTrack;
    float speed;
    float direction;
    float rightTurnTime;
    float leftTurnTime;
};

struct Vehicle {
    Movement moveStats;
    int fuel;
    float x;
    float y;
};

// Allegro prototypes
int initializeAllegro();
int loadBitmaps();
void checkKeystrokes(Input &key);
void drawGameScreen(Vehicle truck);

int checkTimer();
int checkDisplayClose();
int startQueue();
int checkEmpty();

// Game prototypes
void calcMovement(float &posX, float &posY, Movement prev, Input key);
float calcSpeed(float prevSpeed, bool accelKey_down, int rFrame, int lFrame);
float calcDirection(float prevDir, float prevSpeed, int rFrame, int lFrame);
void calcTurnTime(Input &key, Vehicle &truck);
void calcFuel(int &userFuel, bool up);
void printVariables(Vehicle truck, Input key);
