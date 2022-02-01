#include "includes/vectorVoid.h"
#include "includes/vector.h"

void test_pushBackV_emptyVector1() {
    vectorVoid v = createVectorV(0, sizeof(int));
    int x = 1;
    pushBackV(&v, &x);

    int t;
    getVectorValueV(v, 0, &t);

    assert(v.size == 1);
    assert(v.capacity == 1);
    assert(t == x);

    deleteVectorV(v);
}

void test_pushBackV_fullVector1() {
    vectorVoid v = createVectorV(2, sizeof(int));
    int x = 1;
    pushBackV(&v, &x);
    x = 2;
    pushBackV(&v, &x);
    assert(isFullV(v));
    x = 3;
    pushBackV(&v, &x);

    int elem0;
    getVectorValueV(v, 0, &elem0);
    int elem1;
    getVectorValueV(v, 1, &elem1);
    int elem2;
    getVectorValueV(v, 2, &elem2);
    assert(v.size == 3);
    assert(v.capacity == 4);
    assert(elem0 == 1 && elem1 == 2 && elem2 == 3);

    deleteVectorV(v);
}

void test_popBackV_notEmptyVector1() {
    vectorVoid v = createVectorV(0, sizeof(int));
    int x = 10;
    pushBackV(&v, &x);

    assert(v.size == 1);
    popBackV(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVectorV(v);
}

void test_popBackV_notEmptyVector2() {
    vectorVoid v = createVectorV(0, sizeof(int));
    int x = 1;
    pushBackV(&v, &x);
    popBackV(&v);
    assert(v.size == 0);

    x = 2;
    pushBackV(&v, &x);
    popBackV(&v);
    assert(v.size == 0);

    x = 3;
    pushBackV(&v, &x);
    popBackV(&v);
    assert(v.size == 0);

    assert(v.capacity == 1);

    deleteVectorV(v);
}

void test_pushBackV_emptyVector() {
    test_pushBackV_emptyVector1();
}

void test_pushBackV_fullVector() {
    test_pushBackV_fullVector1();
}

void test_popBackV_notEmptyVector() {
    test_popBackV_notEmptyVector1();
    test_popBackV_notEmptyVector2();
}

void test() {
    test_pushBackV_emptyVector();
    test_pushBackV_fullVector();
    test_popBackV_notEmptyVector();
}

int main() {
    test();

    return 0;
}

