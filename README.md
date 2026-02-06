# Kolibri_Engine 🦅 | 3D Game Core (v0.0.1.0 Alpha)

Kolibri is a high-performance 3D game engine built from the ground up in C++. It is designed with a modular architecture to handle real-time 3D rendering, physics, and low-level system management on Linux.

> **Status:** Pre-Alpha (Architecture Phase)
> **Developer:** Belleer (GP Interactive)

---

## 🏗 Engine Architecture

The engine is split into independent sub-systems, ensuring that the Physics calculations don't bottleneck the Rendering pipeline.

### 🎥 Graphics & Display
* **API:** Modern OpenGL / GLFW.
* **Pipeline:** Designed for 3D coordinate systems ($X, Y, Z$).
* **Viewport:** Dynamic window management with aspect ratio correction.

### 📐 3D Physics & Math
* **Time-Step:** Frame-rate independent updates using high-precision $DeltaTime$.
* **Kinematics:** 3D Gravity and velocity vectors for realistic object movement.
* **Scalability:** Built to support complex collision detection in future builds.

### 💻 System Control
* **Hybrid Interface:** Real-time C++ console interaction. Control engine parameters while the 3D context is running.
* **Build System:** Professional CMake workflow for Clang/GCC compilers.

---

## 🛠 Tech Stack
* **Language:** C++17/20
* **Graphics:** OpenGL Core Profile
* **OS:** Linux (Ubuntu/Debian tested)
* **Build Tool:** CMake 3.10+

---

## 🚀 Quick Start (Linux)

To compile the engine with optimized flags:

```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
./kolibrieng
