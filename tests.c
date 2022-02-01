#include "includes/vector.h"

void test_pushBack_emptyVector1() {
    vector v = createVector(0);
    pushBack(&v, 1);

    assert(v.size == 1);
    assert(v.capacity == 1);
    assert(v.data[0] == 1);

    deleteVector();
}

void test_pushBack_fullVector1() {
    vector v = createVector(2);
    pushBack(&v, 1);
    pushBack(&v, 2);
    assert(isFull(v));
    pushBack(&v, 3);

    assert(v.size == 3);
    assert(v.capacity == 4);
    assert(v.data[0] == 1 && v.data[1] == 2 && v.data[2] == 3);

}

void test_pushBack_fullVector2() {
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);
    pushBack(&v, 5);
    pushBack(&v, 6);

    assert(isFull(v));
    pushBack(&v, 7);

    assert(v.size == 7);
    assert(v.capacity == 12);
    assert(
            v.data[0] == 1 &&
            v.data[1] == 2 &&
            v.data[2] == 3 &&
            v.data[3] == 4 &&
            v.data[4] == 5 &&
            v.data[5] == 6 &&
            v.data[6] == 7
    );

}

void test_popBack_notEmptyVector1() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_popBack_notEmptyVector2() {
    vector v = createVector(0);
    pushBack(&v, 1);
    popBack(&v);
    assert(v.size == 0);

    pushBack(&v, 2);
    popBack(&v);
    assert(v.size == 0);

    pushBack(&v, 3);
    popBack(&v);
    assert(v.size == 0);

    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(30);
    for (size_t i = 0; i < 30; ++i) {
        pushBack(&v, i);
        assert(&(v.data[i]) == atVector(v, i));
    }
}

void test_atVector_requestToLastElement() {
    vector v = createVector(10);
    for (size_t i = 0; i < 10; ++i)
        pushBack(&v, i);

    assert(&(v.data[0]) == atVector(v, 0));
    assert(&(v.data[9]) == atVector(v, 9));
}

void test_back_oneElementInVector() {
    vector v = createVector(10);
    pushBack(&v, 1);

    assert(&(v.data[0]) == back(v));
}

void test_front_oneElementInVector() {
    vector v = createVector(10);
    pushBack(&v, 1);

    assert(&(v.data[0]) == front(v));
}

void test_pushBack_emptyVector() {
    test_pushBack_emptyVector1();
}

void test_pushBack_fullVector() {
    test_pushBack_fullVector1();
    test_pushBack_fullVector2();
}

void test_popBack_notEmptyVector() {
    test_popBack_notEmptyVector1();
    test_popBack_notEmptyVector2();
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();

    return 0;
}

