# Fractol

## Overview
A fractal exploration program written in C using the MinilibX library. This project renders various fractals including Mandelbrot and Julia sets, with interactive features and animations.

## Features
- Multiple fractal types:
  - 🌀 Mandelbrot set
  - ✨ Julia set
  - 🐦‍🔥 Phoenix set
  - 🎭 Animated Julia variations
  - Interactive controls:
  - 🖱️ Zoom with mouse wheel
  - 🎨 Color palette switching
  - Smooth rendering and color transitions
  - Dynamic Julia set animation

## Usage
```bash
# Compile the program
make

# Run with specific fractal type:
./fractol [fractal_type]
```

## Controls
### General Controls
- Mouse wheel: Zoom in/out
- Arrow keys: Move around
- ESC: Exit program
- C: Change color scheme
- R: Reset view

### Additional Features
- Hold A: Runs the animation for animate_julia
- I/K: Adjust animation speed

## Technical Implementation
- MinilibX library for graphics rendering
- Complex number calculations
- Smooth coloring algorithm

## Mathematical Background
The program visualizes mathematical sets in the complex plane:
- Mandelbrot Set: z = z² + c, where c is the initial position
- Julia Set: z = z² + c, where c is a constant
- Each point's color represents its escape velocity

## Requirements
- macOS or Linux
- MinilibX library
- Make
- GCC

## Installation
```bash
# for macos
git clone https://github.com/kuruae/fract-ol.git 

# for linux
git clone -b linux https://github.com/kuruae/fract-ol

cd fractol
make
```
