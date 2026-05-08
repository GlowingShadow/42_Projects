# 42 Projects

A collection of projects completed at [42 School](https://42.fr), organized by category.

---

## b.basic — Foundations

| Project | Description |
|---|---|
| **libft0** | First version of the custom C standard library |
| **libft** | Extended C library: string, memory, list utilities |
| **get_next_line** | Read a file line by line using a single file descriptor |
| **fillit** | Tetromino puzzle solver — fit pieces into the smallest square |

---

## 1.Unix — System Programming

| Project | Description |
|---|---|
| **asmlibft** | Reimplementation of libft functions in x86-64 Assembly |
| **ft_ls** | Reimplementation of `ls` with flags `-l`, `-a`, `-r`, `-R`, `-t` |
| **script** | Reimplementation of the Unix `script` command (terminal recorder) |
| **sh1** | Basic shell — command parsing, pipes, redirections |
| **lemipc** | Multi-process battle game using shared memory and message queues (SysV IPC) |
| **philotmp** | Dining philosophers problem — threads and mutexes |

---

## 2.Algo — Algorithms & Data Structures

| Project | Description |
|---|---|
| **push_swap** | Sort a stack using two stacks and a limited set of operations |
| **computerV1** | Polynomial equation solver (up to degree 2) |
| **lem_in** | Ant pathfinding — find optimal flows through a graph |
| **corewar** | Virtual machine + assembler for the Corewar programming game |
| **mod1** | Java simulation — terrain deformation and water flow |
| **npuzzle** | N-puzzle (sliding tile / taquin) solver in Java — A* and IDA* with Swing GUI visualization |

---

## 3.Graphics — Computer Graphics

| Project | Description |
|---|---|
| **FdF** | Wireframe 3D terrain renderer using MiniLibX |
| **fractol** | Fractal explorer: Mandelbrot, Julia, Sierpinski — with zoom and color |
| **wolf3d** | Raycasting 3D engine (Wolfenstein-style), with FMOD audio |
| **rtv1** | Raytracer — spheres, planes, cylinders, cones, lighting, shadows |
| **scop** | OpenGL 3D object viewer in C — loads `.obj`/`.mtl` files, custom GLSL shaders, textures, skybox, camera, using GLFW/GLEW |
| **humangl** | OpenGL articulated human body animation |
| **mod1** | Terrain and water simulation in Java OpenGL |

---

## Unity

| Project | Description |
|---|---|
| **in_the_shadows_vogs** | Unity3D game project |

---

## 4.Hacking — Security & Reverse Engineering

| Project | Description |
|---|---|
| **dr_quine** | Self-replicating programs (quines) in C — programs that output their own source code |
| **Rainfall** | 10-level Linux binary exploitation — reverse engineering ELF binaries with GDB, format string attacks, ret2libc |
| **Override** | 10-level binary exploitation sequel to Rainfall — harder challenges, same CTF-style escalation through user levels |

---

## Other_Progs — Side Projects

| Project | Description |
|---|---|
| **snake** | Terminal snake game |
| **arkanoid** | Arkanoid/breakout clone using GLFW |
| **newmalloc** | Custom `malloc` / `free` / `realloc` implementation |
| **count_island.c** | Count islands in a 2D grid (BFS/DFS) |
| **mult.c** | Matrix multiplication |
| **recursive.c** | Recursive algorithms practice |

---

## Exams

Some timed C programming exams completed during the 42 cursus.

| Exam | Exercises |
|---|---|
| **exam0** | `rotone` — ROT-1 cipher · `hidenp` — subsequence check · `union` — character union of two strings |
| **exam1** | `ulstr` — swap case · `wdmatch` — word pattern match · `ft_strdup` · `inter` — string intersection · `str_maxlenoc` — longest non-repeating substring |
| **exam2** | `first_word` — print first word · `epur_str` — compress spaces · `ft_range` — allocate int range · `sort_int_tab` — sort array |
| **exam3** | `ulstr` · `wdmatch` · `rev_wstr` — reverse words · `sort_list` — sort linked list · `str_maxlenoc` · `mult` — matrix multiplication |

---

## Build

Most C projects use a `Makefile`. From any project folder:

```sh
make        # build
make clean  # remove objects
make fclean # remove objects + binary
make re     # fclean + build
