- Platform supported Windows, Linux, Mac

# ¿Qué es?
El presente proyecto permite aplicar el filtro de blanco y negro por consola a imágenes con diferentes extensiones de archivo. El programa se encuentra paralelizado y permite al usuario seleccionar el número de hilos sobre los cuales trabajará el algoritmo

# ¿Cómo instalar?
**1.** Abra su consola y clone el repositorio
```
git clone https://github.com/jahelsantiago/Parallel-image-processing
```

**2.** Cambie el directorio de trabajo actual a la carpeta donde se encuentra el repositorio
```
cd Parallel-image-processing
```

# ¿Cómo usarlo?
**1.** Compile el proyecto con GNU Compiler Collection (GCC) instalado en su sistema
- Opción 1:
```
make
```
- Opción 2:
```
gcc Image.c main.c -o gray -lm -lpthread -fopenmp
```

**2.** Ejecute el programa
```
./gray <original_image_route> <gray_image_route> <num_threads> <'omp' or 'posix'>
```

**3.** (opcional) Puede correr los tests para verificar que el programa funciona correctamente

Se recomienda hacer uso de Git Bash en Windows para correr los tests

- Opción 1.1: Pthreads - posix
```
make testpth
```

- Opción 1.2: Pthreads - posix
```
sh runpth.sh
```

- Opción 2.1: OpenMP
```
make testomp
```

- Opción 2.2: OpenMP
```
sh runomp.sh
```
