# ricochet

A DVD-logo-style screensaver for the terminal, written in C and built with [Smidr](https://github.com/Max-Mend/smidr).

`SMIDR` bounces around your terminal window like the classic DVD logo, changing color every time it hits an edge.

![video](assets/ricochet-demo.mp4)

## How it works

- Reads the current terminal size on every frame (`ioctl` + `TIOCGWINSZ`), so it adapts if you resize the window mid-run.
- Tracks position and velocity as floats, advances them by `dt * speed`, and reflects the velocity off whichever edge was hit.
- Cycles through 12 colors (`RED`, `GREEN`, `YELLOW`, `BLUE`, `MAGENTA`, `CYAN`, `PINK`, `ORANGE`, `PURPLE`, `LIME`, `GOLD`, `SILVER`) via raw ANSI escape codes — one step forward each time the logo bounces.
- Delta time is computed from `clock_gettime(CLOCK_MONOTONIC, ...)` and clamped to `MAX_DT` so a slow frame (e.g. the terminal being resized) can't make the logo jump across the screen.
- Runs at roughly 20 FPS (`usleep(50000)` between frames).
- `Ctrl+C` is caught to restore the cursor before exiting, instead of leaving the terminal in a hidden-cursor state.

## Requirements

- A terminal that supports ANSI escape codes (most do).
- [Smidr](https://github.com/Max-Mend/smidr) to build it.

## Build and run

```sh
smidr build
smidr run
```

or, to skip the build step:

```sh
smidr run
```

Press `Ctrl+C` to exit.

## Project structure

```
ricochet/
├── smidr.toml
├── include/
│   ├── animation.h    position/velocity update, color cycling
│   ├── colors.h        ANSI color code definitions
│   ├── terminal.h       cursor and screen control
│   └── timer.h           monotonic clock wrapper
└── src/
    ├── main.c            main loop: timing, terminal size, rendering
    ├── animation.c
    ├── terminal.c
    └── timer.c
```

## License

Licensed under either of [Apache License, Version 2.0](LICENSE-APACHE) or [MIT license](LICENSE-MIT), at your option.
