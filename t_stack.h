//
// Created by gerdon on 21.09.17.
//

#ifndef TEMPLATE_STACK_T_STACK_H
#define TEMPLATE_STACK_T_STACK_H

#include <iterator>

template <typename T> class stack
{
public:
    stack<T>();
    stack<T>(size_t size);
    size_t count(T&&) const;
    void push(T );
    T pop();
    ~stack();
    stack(const stack<T>&) = delete;
    stack& operator=(const stack<T>&) = delete;
private:
    T * array_;
    size_t array_size_;
    size_t count_;
};

template <typename T>
stack<T>::stack() : array_size_(10),count_(0),array_(new T[10]){}

template <typename T>
stack<T>::stack(size_t size) : array_size_(size),count_(0),array_(new T[size]){}

template <typename T> void stack<T>::push(T T_value) {
    if (count_ == array_size_) {
        T* newArray_ = new T[array_size_*2];
        std::copy(array_, array_ + array_size_, newArray_);
        delete[] array_;
        array_ = newArray_;
        array_size_*=2;
    }
    array_[count_++] = std::move(T_value);

}

template <typename T> T stack<T>::pop() {
    if(count_ != 0) {
        T tmp = std::move(array_[count_]);
//        array_[count_] = NULL;
        --count_;
        return tmp;
    } else {
        throw "pop exception";
    }
}

template <typename T> stack<T>::~stack(){
    delete[] array_;
}


#endif //TEMPLATE_STACK_T_STACK_H
