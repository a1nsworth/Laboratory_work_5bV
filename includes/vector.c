#include "vector.h"

/// Выделение памяти под вектор
/// \param n - максимальный размер контейнера
/// \return Возвращает вектор {data, 0, n},
///         data - указатель на нулевую ячейку памяти контейнера вектора,
///         0 - кол - во помещенных элементов,
///         n - максимальный размер контейнера
vector createVector(const size_t n) {
    int *data = (int *) malloc(n * sizeof(int));
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vector) {data, 0, n};
}

/// Изменяет кол - во памяти выделенную под хранение элементов вектора
/// \param v - адрес ячейки памяти вектора
/// \param newCapacity - максимальное кол - во ячеек
void reserve(vector *v, const size_t newCapacity) {
    if (!newCapacity)
        v->data = NULL;
    else if (newCapacity < v->size)
        v->size = newCapacity;
    else {
        v->data = realloc(v->data, newCapacity * sizeof(int));
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }

        v->capacity = newCapacity;
    }
}

/// Удаляет элементы из контейнера вектора
/// \param v - адрес ячейки памяти вектора
void clear(vector *v) {
    v->size = 0;
}

/// Освобождает память выделенную под неиспользуемые эдементы
/// \param v - адрес ячейки памяти вектора
void shrinkToFit(vector *v) {
    if (v->size != 0)
        reserve(v, v->size);
}

/// Освобождение памяти выделенную под вектор
/// \param v - вектор
void deleteVector(const vector v) {
    free(v.data);
}

/// Проверка на пустоту
/// \param v - вектор
/// \return Возвращает true, если вектор пуст, иначе false
bool isEmpty(const vector v) {
    return v.size == 0;
}

/// Проверка на заполненость
/// \param v - вектор
/// \return Возвращает true, если вектор полон, иначе false
bool isFull(const vector v) {
    return v.size == v.capacity;
}

/// Получение элемента по индексу
/// \param v - вектор
/// \param indexElement - индекс запрашиваемого элемента
/// \return Возвращает элемент вектора под индексом indexElement
int getVectorValue(const vector v, const size_t indexElement) {
    assert(indexElement < v.size);

    return v.data[indexElement];
}

/// Добавляет элемент в конец массива
/// \param v - адрес ячейки памяти вектора
/// \param x - эллемент для добавления
void pushBack(vector *v, const int x) {
    if (!v->capacity)
        reserve(v, 1);
    else if (isFull(*v))
        reserve(v, v->capacity * 2);

    v->data[v->size] = x;
    (v->size)++;
}

/// Удаляет последний элемент вектора
/// \param v - адрес ячейки памяти вектора
void popBack(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "empty vector");
        exit(1);
    } else {
        (v->size)--;
        shrinkToFit(v);
    }
}

/// Получение указателя элемента под индексом index
/// \param v - вектор
/// \param index - индекс
/// \return Возвращает указатель на index-ый элемент вектора
int *atVector(const vector v, const size_t index) {
    assert(index < v.capacity);

    int *pIndex = &(v.data[index]);
    return pIndex;
}

/// Получение указателя на последний элемент вектора
/// \param v - вектор
/// \return Возвращает указатель на последний элемент вектора
int *back(const vector v) {
    assert(v.size != 0);

    int *pBack = &(v.data[v.size - 1]);
    return pBack;
}

/// Получение указателя на первый элемент вектора
/// \param v - вектор
/// \return Возвращает указатель на первый элемент вектора
int *front(const vector v) {
    assert(v.size != 0);

    int *pFront = &(v.data[0]);
    return pFront;
}