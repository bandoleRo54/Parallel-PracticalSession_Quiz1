# 🖥️ Sesión Práctica 1 & Quiz 1
Este repositorio contiene los programas que intentan aproximar el valor de Pi, unos secuenciales y otros apoyandose en la codificación multihilo, utilizando el lenguaje de programación C++.

# ¿Cómo usarlo?
En la carpeta *src*, estarán los códigos y los ejecutables compilados, exportados directamente del contenedor de Docker en el que se construyeron.
- **Para los códigos secuenciales:** Ejecutar por CLI, teniendo en cuenta el siguiente formato: \
``./compiled_filename N`` (Donde $N$ = Valor de aproximación para los métodos utilizados)
- **Para los códigos concurrentes:** Ejecutar por CLI, teniendo en cuenta el siguiente formato: \
``./compiled_filename t N`` (Donde $t$ = número de hilos, y $N$ = Valor de aproximación para los métodos utilizados)

**Nota:** Es necesario tener todos los archivos de C++ en un mismo directorio para usar el código de medición de rendimiento.
