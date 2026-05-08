# wolf3d

Wolfenstein-style raycasting 3D engine written in C using MiniLibX and FMOD.

---

## Features

- Raycasting engine with textured walls (XPM), floor and ceiling rendering
- Multiple wall types with different colors/textures (values 1–5 in map)
- Textured sky rendered as a wide horizontal strip
- Player movement and rotation with collision detection
- FMOD audio — background music and sound effects
- Minimap and HUD overlay (bonus)
- Custom `.map` format — grid of integers, 0 = empty, 1–5 = wall types

## Controls

| Key | Action |
|---|---|
| `W` / `S` | Move forward / backward |
| `A` / `D` | Rotate left / right |
| `ESC` | Quit |

## Map Format

Maps are plain text grids of space-separated integers:

```
1 1 1 1 1
1 0 0 0 1
1 0 4 0 1
1 0 0 0 1
1 1 1 1 1
```

- `0` — empty space
- `1–5` — wall types (different textures/colors)

## Build

```sh
make        # build
make clean  # remove objects
make fclean # remove objects + binary
make re     # fclean + build
```

## Usage

```sh
./wolf3d maps/level0.map
```

## Dependencies

- **MiniLibX** — X11 window/image library (42 School)
- **FMOD** — audio engine
