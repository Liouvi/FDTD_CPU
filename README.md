# FDTD_CPU
CPU implementation of finite difference time domain algorithm.
You can change simulation parameters in FDTD2D.cpp

# In order to compile and run:

nvcc -o FDTD FDTD2D.cpp dataacc.cpp curl.cpp geometry.cpp sim.cpp sourcetime.cpp && ./FDTD


