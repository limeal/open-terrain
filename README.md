# OpenTerrain: Terrain Generation using PerlinNoise

https://github.com/limeal/open-terrain/assets/71699038/1f7b1e49-c190-44a3-a2ec-e5bb84569b12

## Motivation

- Always wanted to simulate procedural generation and perlin noise
- Learn complex shaders like multi-texture and write depth

## Goal

- Find a way to generate infinite and coherent map and highliths the potential water source found

## Features

- Water in write depth (Appear even if it's hidden by other blocks)
- Biomes (Plain, Desert, Mountain)
- Trees
- Reseeding
- Threaded Map generation

## Installing

1. Pre-Installation

[Installing OpenGL](https://www.geeksforgeeks.org/getting-started-with-opengl/)

2. Build with Cmake
```bash
chmod +x build.sh
./build.sh
```
OR
```bash
mkdir -p build
cd build
cmake ..
make
cd ..
```
