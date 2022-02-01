#ifndef LABORATORY_WORK_5BV_VECTORVOID_H
#define LABORATORY_WORK_5BV_VECTORVOID_H

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct vectorVoid {
    void *data;             // Указатель на нулевой элемент вектора
    size_t size;            // Размер вектора
    size_t capacity;        // Вместимость вектора
    size_t baseTypeSize;    // Размер типа хранения в байтах
}vectorVoid;

#endif //LABORATORY_WORK_5BV_VECTORVOID_H
