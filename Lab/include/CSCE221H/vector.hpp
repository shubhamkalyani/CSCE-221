#pragma once

#include <cstddef>
#include <iostream>

/**
 * @brief  This class loosely models a std::vector
 *
 */
namespace CSCE221H {

template <typename T> class vector {
  public:
    using value_type = T;

    /**
     * @brief Construct a new vector object
     *
     */
    vector() {
      sz = 0;
      cap = 0;
      arr = new T[cap];
    }

    /**
     * @brief Inserts new value to back of vector
     *
     * @param value value to insert
     */
    void push_back(const T &value) {
      if (sz == cap) {
        reserve(cap);
      }
      arr[sz] = value;
      sz++;
    }

    /**
     * @brief Removes the last element
     *
     */
    void pop_back() {
      sz--;
    }

    /**
     * @brief Returns a reference to last element
     *
     * @return T&
     */
    T &back() {
      return arr[sz - 1];
    }

    /**
     * @brief Returns a reference to the first element
     *
     * @return T&
     */
    T &front() {
      return arr[0];
    }

    /**
     * @brief Returns a reference to element indexed by i
     *
     * @param i
     * @return T&
     */
    T &operator[](size_t i) {
      return arr[i];
    }

    /**
     * @brief Assigns count items to container.   Replaces the contents of the
     * container.
     *
     * @param count
     * @param value
     */
    void assign(size_t count, const T &value) {
      while (count > cap) {
        cap = count;
        sz = count;
      }
      for (size_t i = 0; i < count; i++) {
        arr[i] = value;
      }
    }

    /**
     * @brief Reserves memory for future push_backs
     *
     * @param capacity
     */
    void reserve(size_t new_capacity) {
      if (new_capacity == 0) {
        new_capacity = 1;
      } else {
        new_capacity *= 2;
      }

      T* newArr = new T[new_capacity];
      for (size_t i = 0; i < sz; i++) {
        newArr[i] = std::move(arr[i]);
      }
      cap = new_capacity;
      std::swap(arr, newArr);
      delete[] newArr;
    }

    /**
     * @brief Returns the current size.
     *
     * @return size_t
     */
    size_t size() const { 
      return sz; 
    }

    /**
     * @brief Returns the current capacity.
     *
     * @return size_t
     */
    size_t capacity() const {
      return cap;
    }

    /**
     * @brief Clears the vector, but does not free capacity.
     *
     */
    void clear() {
      for (size_t i = 0; i < sz; i++) {
        arr[i] = 0;
      }
      sz = 0;
    }

    /**
     * @brief Shrinks capacity to fit current size.
     *
     */
    void shrink_to_fit() {
      cap = sz;
    }

    void swap(vector& vec) {
      size_t temp_size = sz;
      size_t temp_cap = cap;
      T* temp_arr = arr;

      sz = vec.sz;
      cap = vec.cap;
      arr = vec.arr;

      vec.sz = temp_size;
      vec.cap = temp_cap;
      vec.arr = temp_arr;
    }

    /**
     * @brief Loops over all elements in vector and applies LambdaFunction.
     *
     * @tparam LambdaFunction
     * @param l
     */
    template <typename LambdaFunction> void for_each(LambdaFunction l) {
      for (int i = 0; i < sz; i++) {
        l(arr[i]);
      }
    }
    
    private:
      size_t sz;
      size_t cap;
      T* arr;
};

} // namespace CSCE221H