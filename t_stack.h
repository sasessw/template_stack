//
// Created by gerdon on 21.09.17.
//

#ifndef TEMPLATE_STACK_T_STACK_H
#define TEMPLATE_STACK_T_STACK_H

template <typename T> class stack
{
public:
    stack();
    stack(size_t size);
    size_t count() const;
    void push(T const &);
    T pop();
    ~stack();

private:
    T * array_;
    size_t array_size_;
    size_t count_;
};

template <typename T> stack<T>::stack() : array_size_(10),count_(0) {
    array_ = (T*)malloc(array_size_*sizeof(T));
}

template <typename T> stack<T>::stack(size_t size) : array_size_(size), count_(0) {
    array_ = (T*)malloc(array_size_*sizeof(T));
}

template <typename T> void stack<T>::push(T const & T_value) {
    if (count_ == array_size_) {
        array_size_*=2;
        array_ = (T*)realloc(array_, array_size_*sizeof(T));
    }
        array_[count_] = T_value;
        count_++;
}

template <typename T> T stack<T>::pop() {
    if(count_ != 0) {
        T tmp = array_[count_];
//        array_[count_] = NULL;
        --count_;
        return tmp;
    } else {
        throw "pop exception";
    }
}

template <typename T> stack<T>::~stack(){
    free(array_);
}

#endif //TEMPLATE_STACK_T_STACK_H
