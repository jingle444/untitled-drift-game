#include <3ds.h>
#include <stdio.h>
#include <string.h>
#include "game.h"

int main(int argc, char *argv[]) {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    GameState game;
    init_game(&game);

    // Main game loop
    while (aptMainLoop()) {
        hidScanInput();
        u32 kDown = hidKeysDown();
        u32 kHeld = hidKeysHeld();

        if (kDown & KEY_START)
            break; // Exit on START

        // Update game state
        update_player(&game.player, kHeld);
        game.timer++;

        // Render
        render_game(&game);

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}
