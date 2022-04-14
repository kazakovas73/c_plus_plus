#include<iostream>

using namespace std;

template<typename T>
class my_shared_ptr {
private:
    //T* ptr = nullptr;
    //size_t* counter_ptr = nullptr;

    template<typename U>
    struct ControlBlock {
        size_t counter;
        U object;

        ControlBlock(size_t counter, U object) : counter(counter), object(object) {}
    };

    ControlBlock<T>* cptr = nullptr;

    template<typename U, typename... Args>
    friend my_shared_ptr<U> make_my_shared(Args&&... args);

    struct make_my_shared_t;

    template<typename... Args>
    my_shared_ptr(make_my_shared_t, ControlBlock<T>* storage_ptr) {
        cptr(storage_ptr);
    }

public:
    my_shared_ptr() {}

    my_shared_ptr(T* ptr) : cptr(new ControlBlock<T>(size_t(1), *ptr)) {}
        //ptr(ptr), counter_ptr(new size_t(1)) {}

    my_shared_ptr(my_shared_ptr& other) :
            cptr(other.cptr) {
            //ptr(other.ptr), counter_ptr(other.counter_ptr) {
        //++*counter_ptr;
        **cptr.counter;
    }

    my_shared_ptr(my_shared_ptr&& other) :
            cptr(other.cptr) {
            //ptr(other.ptr), counter_ptr(other.counter_ptr) {
        other.ptr = nullptr;
        other.counter_ptr = nullptr;
    }

    T& operator*() const {
        return cptr->object;
    }

    T* operator->() const {
        return &(cptr->object);
    }

    size_t use_count() {
        return cptr->counter;
    }

    ~my_shared_ptr() {
        if (cptr->counter > 1) {
            --(cptr->counter);
            return;
        }
    }
};

template<typename T, typename... Args>
my_shared_ptr<T> make_my_shared(Args&&... args) {
    auto ptr = new ControlBlock<T>{1, T{forward<Args>(args)...}};
    return my_shared_ptr<T>(my_shared_ptr<T>::make_my_shared_t(), ptr);
}

int main() {



    return 0;
}
