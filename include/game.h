#ifndef GAME_H
#define GAME_H

#include <3ds.h>
#include <math.h>

// Game constants
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 240
#define MAX_SPEED 20.0f
#define ACCELERATION 0.5f
#define FRICTION 0.02f
#define DRIFT_FACTOR 1.5f

// Player structure
typedef struct {
    float x;
    float y;
    float vx;
    float vy;
    float angle;
    float speed;
    float drift_angle;
    bool is_drifting;
    int drift_score;
} Player;

// Game state
typedef struct {
    Player player;
    int score;
    int timer;
    bool running;
} GameState;

// Function prototypes
void init_game(GameState *state);
void update_player(Player *p, u32 keys);
void render_game(GameState *state);
void draw_player(Player *p);
void handle_drift(Player *p);

#endif
