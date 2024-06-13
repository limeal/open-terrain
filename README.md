# OpenTerrain: Terrain Generation using PerlinNoise

<video src="./docs/video.mp4"></video>

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