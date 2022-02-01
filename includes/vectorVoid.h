#ifndef LABORATORY_WORK_5BV_VECTORVOID_H
#define LABORATORY_WORK_5BV_VECTORVOID_H

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include <assert.h>

typedef struct vectorVoid {
    void *data;             // Указатель на нулевой элемент вектора
    size_t size;            // Размер вектора
    size_t capacity;        // Вместимость вектора
    size_t baseTypeSize;    // Размер типа хранения в байтах
} vectorVoid;

vectorVoid createVectorV(size_t n, size_t baseTypeSize);

void reserveV(vectorVoid *v, size_t newCapacity);

void shrinkToFitV(vectorVoid *v);

void clearV(vectorVoid *v);

void deleteVectorV(vectorVoid v);

bool isEmptyV(vectorVoid v);

bool isFullV(vectorVoid v);

void getVectorValueV(vectorVoid v, size_t indexElement, void *destination);

void setVectorValueV(vectorVoid *v, size_t index, void *source);

void popBackV(vectorVoid *v);

void pushBackV(vectorVoid *v, void *source);


#endif //LABORATORY_WORK_5BV_VECTORVOID_H
