# FDTD_CPU
CPU implementation of finite difference time domain algorithm.

You can change simulation parameters in FDTD2D.cpp. 

Set geometry of the optical device via geometry class. For example:
```cpp
void block(float xcenter, float ycenter, float length, float width, float eps, float mu);
```
creates a block at (xcenter,ycenter) with dimensions (length,width)

In order to compile and run:

```
nvcc -o FDTD FDTD2D.cpp dataacc.cpp curl.cpp geometry.cpp sim.cpp sourcetime.cpp && ./FDTD
```

