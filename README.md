# 3DS Drift Game

A high-speed drifting racing game for Nintendo 3DS (3DSX format).

## Features

- Fast-paced drift mechanics
- Score multiplier while drifting
- Smooth controls optimized for 3DS
- Real-time speed and angle display

## Controls

- **D-Pad Left/Right**: Steer
- **D-Pad Up**: Accelerate
- **D-Pad Down**: Brake
- **X Button**: Drift (hold to maintain drift)
- **START**: Exit game

## Building

### Prerequisites

1. Install DevKit Pro: https://devkitpro.org/wiki/Getting_Started
2. Set up DevKitARM:
   ```bash
   export DEVKITARM=/opt/devkitpro/devkitARM
   export DEVKITPRO=/opt/devkitpro
   export PATH=$DEVKITPRO/tools/bin:$PATH
   ```

### Build

```bash
make clean
make
```

This will generate:
- `drift-game.elf` - Executable
- `drift-game.3dsx` - 3DS Homebrew format
- `drift-game.smdh` - Application metadata

## Installation

1. Copy `drift-game.3dsx` to your 3DS SD card
2. Place it in the `/3ds/` directory
3. Launch from Homebrew Launcher

## Development

Core files:
- `source/main.c` - Main game loop
- `source/game.c` - Game logic
- `include/game.h` - Game header

## TODO

- [ ] Add track rendering
- [ ] Implement multiple tracks
- [ ] Add sound effects
- [ ] Leaderboard system
- [ ] Particle effects for drifting
- [ ] More advanced physics
- [ ] Multiplayer support (local)

## License

MIT License
