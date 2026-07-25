#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <citro3d.h>

// Graphics initialization
void graphics_init();
void graphics_clear_screen(float r, float g, float b);
void graphics_draw_rect(float x, float y, float width, float height, float r, float g, float b);
void graphics_draw_player(float x, float y, float angle, float r, float g, float b);
void graphics_draw_track();
void graphics_draw_drift_particles(float x, float y, float angle);
void graphics_update();
void graphics_exit();

#endif
