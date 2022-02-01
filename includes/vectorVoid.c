#include "vectorVoid.h"

/// Выделение памяти под вектор
/// \param n - максимальный размер контейнера
/// \param baseTypeSize - размер типа в байтах
/// \return Возвращает вектор {data, 0, n},
///         data - указатель на нулевую ячейку памяти контейнера вектора,
///         0 - кол - во помещенных элементов,
///         n - максимальный размер контейнера
vectorVoid createVectorV(const size_t n, const size_t baseTypeSize) {
    void *data = (void *) malloc(n * baseTypeSize);
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vectorVoid) {data, 0, n, baseTypeSize};
}

/// Изменяет кол - во памяти выделенную под хранение элементов вектора
/// \param v - адрес ячейки памяти вектора
/// \param newCapacity - максимальное кол - во ячеек
void reserveV(vectorVoid *v, const size_t newCapacity) {
    if (!newCapacity)
        v->data = NULL;
    else if (newCapacity < v->size)
        v->size = newCapacity;
    else {
        v->data = realloc(v->data, newCapacity * v->baseTypeSize);
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }

        v->capacity = newCapacity;
    }
}

/// Освобождает память выделенную под неиспользуемые эдементы
/// \param v - адрес ячейки памяти вектора
void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

/// Удаление элементов вектора
/// \param v - адрес ячейки памяти вектора
void clearV(vectorVoid *v) {
    v->size = 0;
}

/// Освобождение памяти под вектор
/// \param v - вектор
void deleteVectorV(vectorVoid v) {
    free(v.data);
}

/// Проврка на пустоту вектора
/// \param v - вектор
/// \return Возвращает true, если вектор пустой, иначе false
bool isEmptyV(const vectorVoid v) {
    return v.size == 0;
}

/// Проверка на заполненость вектора
/// \param v - вектор
/// \return Возвращает true, если вектор полон, иначе false
bool isFullV(const vectorVoid v) {
    return v.size == v.capacity;
}

/// Получение значения элемента ветора по индексу и запись его в destination
/// \param v - вектор
/// \param indexElement - индекс получаемого элемента
/// \param destination - нетипизированный указатель на ячейку памяти, для записи
void getVectorValueV(const vectorVoid v, const size_t indexElement, void *destination) {
    assert(indexElement < v.size);

    char *sourse = (char *) v.data + indexElement * v.baseTypeSize;
    memcpy(destination, sourse, v.baseTypeSize);
}

/// Перезапись элемента вектора
/// \param v - адрес ячейки памяти вектора
/// \param index - индекс элемента для перезаписи
/// \param source - нетипизированный указатель на ячейку памяти
void setVectorValueV(vectorVoid *v, const size_t index, void *source) {
    assert(index < v->capacity);

    memcpy((char *) v->data + index * v->baseTypeSize, source, v->baseTypeSize);
}

/// Удаление последнего элемента вектора
/// \param v - адрес ячейки памяти вектора
void popBackV(vectorVoid *v) {
    if (v->size == 0) {
        fprintf(stderr, "empty vector");
        exit(1);
    } else {
        (v->size)--;
        shrinkToFitV(v);
    }
}

/// Добавление элемента в конец массива
/// \param v - адрес ячейки памяти вектора
/// \param source - нетипизированный указатель на ячейку памяти
void pushBackV(vectorVoid *v, void *source) {
    if (!v->capacity)
        reserveV(v, 1);
    else if (isFullV(*v))
        reserveV(v, v->capacity * 2);

    setVectorValueV(v, v->size, source);
    v->size++;
}