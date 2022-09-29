#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP

#include <iostream>
#include <ostream>
#include <unordered_map>
#include <utility>

class SharedPointer {
  public:
    SharedPointer()
    : pointer_{nullptr} {}

    SharedPointer(int* pointer)
    : pointer_{pointer} {
        std::cout << "New shared pointer created" << std::endl;
        if (pointer == nullptr) {
            return;
        }

        if (this->reference_count_.find(pointer) == this->reference_count_.end()) {
            // If the pointer is not in the map, add it
            this->reference_count_[pointer] = 1;
        }
        else {
            // Pointer in map, increment the reference count
            ++(this->reference_count_.find(pointer)->second);
        }
    }
    ~SharedPointer() {
        std::cout << "Destructor called" << std::endl;
        if (this->pointer_ == nullptr) {
            return;
        }
        auto res = this->reference_count_.find(this->pointer_);
        res->second -= 1;
        if (res->second == 0) {
            // No more references to the pointer, delete it
            delete this->pointer_;
        }
    }

    int* get();
    int const* get() const;
    int& operator*();
    int const& operator*() const;
    long use_count() const;

  private:
    int* pointer_;
    static std::unordered_map<int*, long> reference_count_;
};

#endif // SHARED_POINTER_HPP