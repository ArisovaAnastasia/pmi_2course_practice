#pragma once

class Vector {
private:
    size_t size_;
    size_t capacity_;
    int* data_;

    void Reallocate(size_t new_capacity) {
        if (new_capacity < capacity_) {
            return;
        }
        int* new_data = new int[new_capacity];
        for (size_t index = 0; index <= size_; ++index) {
            new_data[index] = data_[index];
        }
        delete [] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

public:
    Vector() : size_(0), capacity_(0), data_(new int[capacity_]) {
    }

    Vector(size_t size): size_(size), capacity_(size), data_(new int[capacity_]) {
        for (size_t index = 0; index < size_; ++index) {
            data_[index] = 0;
        }
    }

    Vector(std::initializer_list<int> list): size_(list.size()), capacity_(size_), data_(new int[list.size()]) {
        size_t count = 0;
        for (auto value : list) {
            data_[count++] = value;
        }
    }

    Vector(const Vector& vector) : size_(vector.size_), capacity_(vector.capacity_) {
        data_ = new int[capacity_];
        for (size_t index = 0; index < size_; ++index)
            data_[index] = vector.data_[index];
    }

    Vector& operator=(const Vector& vector) {
        size_ = vector.size_;
        capacity_ = vector.capacity_;
        delete [] data_;
        data_ = new int[capacity_];

        for (size_t index = 0; index < size_; ++index) {
            data_[index] = vector.data_[index];
        }

        return *this;
    }

    ~Vector() {
        delete [] data_; 
        size_ = capacity_ = 0;
    }

    void Swap(Vector& vector) {
        std::swap(size_, vector.size_);
        std::swap(capacity_, vector.capacity_);
        std::swap(data_, vector.data_);
    }

    const int& operator[](size_t index) const {
        return data_[index];
    }

    int& operator[](size_t index) {
        return data_[index];
    }

    size_t Size() const {
        return size_;
    }

    size_t Capacity() const {
        return capacity_;
    }

    void PushBack(int value) {
        if (capacity_ == 0)
            Reallocate(1);
        else if (size_ == capacity_)
            Reallocate(capacity_*2);

        data_[size_++] = value;
    }

    void PopBack() {
        --size_;
    }

    void Clear() {
        size_ = 0;
    }

    void Reserve(size_t new_capacity) {
        Reallocate(new_capacity);
    }
};
