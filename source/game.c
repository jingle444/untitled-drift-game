#include "game.h"
#include <stdio.h>
#include <math.h>

void init_game(GameState *state) {
    state->player.x = 200.0f;
    state->player.y = 120.0f;
    state->player.vx = 0.0f;
    state->player.vy = 0.0f;
    state->player.angle = 0.0f;
    state->player.speed = 0.0f;
    state->player.drift_angle = 0.0f;
    state->player.is_drifting = false;
    state->player.drift_score = 0;
    state->score = 0;
    state->timer = 0;
    state->running = true;
}

void update_player(Player *p, u32 keys) {
    // Handle steering
    if (keys & KEY_LEFT) {
        if (p->is_drifting) {
            p->drift_angle -= 5.0f;
        } else {
            p->angle -= 3.0f;
        }
    }
    if (keys & KEY_RIGHT) {
        if (p->is_drifting) {
            p->drift_angle += 5.0f;
        } else {
            p->angle += 3.0f;
        }
    }

    // Handle acceleration
    if (keys & KEY_UP) {
        p->speed += ACCELERATION;
        if (p->speed > MAX_SPEED)
            p->speed = MAX_SPEED;
    }

    // Handle braking
    if (keys & KEY_DOWN) {
        p->speed -= ACCELERATION * 1.5f;
        if (p->speed < 0.0f)
            p->speed = 0.0f;
    }

    // Handle drift (X button)
    if (keys & KEY_X) {
        handle_drift(p);
    } else {
        if (p->is_drifting) {
            p->angle = p->drift_angle;
            p->is_drifting = false;
        }
    }

    // Apply friction
    if (!(keys & KEY_UP)) {
        p->speed *= (1.0f - FRICTION);
    }

    // Update position
    float rad = p->angle * 3.14159f / 180.0f;
    p->vx = p->speed * cosf(rad);
    p->vy = p->speed * sinf(rad);

    p->x += p->vx;
    p->y += p->vy;

    // Boundary checking
    if (p->x < 10.0f)
        p->x = 10.0f;
    if (p->x > SCREEN_WIDTH - 10.0f)
        p->x = SCREEN_WIDTH - 10.0f;
    if (p->y < 10.0f)
        p->y = 10.0f;
    if (p->y > SCREEN_HEIGHT - 10.0f)
        p->y = SCREEN_HEIGHT - 10.0f;
}

void handle_drift(Player *p) {
    if (!p->is_drifting) {
        p->is_drifting = true;
        p->drift_angle = p->angle;
        p->drift_score = 0;
    }
    p->drift_score++;
}

void render_game(GameState *state) {
    // Clear top screen
    consoleSelect(&frameBuffer[GFX_TOP]);
    printf("\x1b[2J"); // Clear screen
    printf("\x1b[0;0H");
    printf("Drift Game - Score: %d", state->score + state->player.drift_score);
    printf("\x1b[2;0H");
    printf("Speed: %.1f", state->player.speed);
    printf("\x1b[3;0H");
    printf("Angle: %.1f", state->player.angle);

    if (state->player.is_drifting) {
        printf("\x1b[4;0H");
        printf("DRIFTING! Score: %d", state->player.drift_score);
    }

    draw_player(&state->player);
}

void draw_player(Player *p) {
    // Simple ASCII representation of the player
    printf("\x1b[%d;%dH", (int)p->y / 10, (int)p->x / 10);
    printf("@");
}
