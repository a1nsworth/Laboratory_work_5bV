#include "vector.h"

///
/// \param n
/// \return
vector createVector(const size_t n) {
    int *data = (int *) malloc(n * sizeof(int));
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vector) {data, 0, n};
}

///
/// \param v
/// \param newCapacity
void reserve(vector *v, const size_t newCapacity) {
    if (!newCapacity)
        v->data = NULL;
    else if (newCapacity < v->size)
        v->size = newCapacity;
    else {
        int *newData = realloc(v->data, newCapacity * sizeof(int));
        if (newData == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }
}

///
/// \param v
void clear(vector *v) {
    v->size = 0;
}

///
/// \param v
void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

///
/// \param v
void deleteVector(vector *v) {
    free(v->data);
}