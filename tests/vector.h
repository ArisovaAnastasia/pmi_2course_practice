//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
class Vector {
private:
    size_t capacity_;
    size_t size_;
    int* data_;

public:
    Vector() : capacity_(0), size_(0), data_(new int[capacity_]) {
    }

    Vector(size_t size)
        : capacity_(size*2)
        , size_(size)
        , data_(new int[capacity_])
    {
        for (size_t index = 0; index < size_; ++index) {
            data_[index] = 0;
        }
    }

    Vector(std::initializer_list<int> list) 
        : capacity_(list.size()*2)
        , size_(list.size()) 
        , data_(new int[capacity_])
    {
        size_t count = 0;
        for (auto value : list) {
            data_[count++] = value;
        }
    }

    Vector(const Vector& vector) 
        : capacity_(vector.capacity_)
        , size_(vector.size_)
        , data_(new int[capacity_]) 
    {
        for (size_t i = 0; i < size_; i++) {
            data_[i] = vector[i];
        }
    }

    Vector& operator=(const Vector& vector) {
        if (data_ == vector.data_) {
            return *this;
        }
        else {
            if (capacity_ < vector.size_) {
                delete[] data_;
                capacity_ = vector.capacity_;
                data_ = new int[vector.Capacity()];
            }
            size_ = vector.size_;
            for (size_t index = 0; index < size_; ++index) {
                data_[index] = vector.data_[index];
            }
            return *this;
        }
    }

    ~Vector() {
        size_ = 0;
        capacity_ = 0;
        delete[] data_;
    }

    friend void Swap(Vector& first, Vector& second) {
        std::swap(first, second);
    }

    int& operator[](size_t index) const {
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
        data_[size_++] = value;
    }

    void PopBack() {
        --size_;
    }

    void Clear() {
        while (size_) {
            PopBack();
        }
    }

    void Reserve(size_t new_capacity) {
        if (new_capacity != capacity_) {
            int* temp = new int[new_capacity];
            
            for (size_t i = 0; i < size_; i++) {
                temp[i] = data_[i];
            }
            capacity_ = new_capacity;
            delete[] data_;
            data_ = temp;
        }
    }
    
    friend bool operator==(const Vector& first, const Vector& second) {
        if (first.size_ == second.size_) {
            bool flag = 1;
            for (int i = 0; i < first.size_; i++) {
                if (first[i] != second[i]) {
                    flag = false;
                }
            }

            return ((flag) ? true : false);
        }
        else {
            return false;
        }
    }

};
