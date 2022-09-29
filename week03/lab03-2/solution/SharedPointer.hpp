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

    // NOTE: Rule of 5?
    // Since we are managing allocated memory & we have defined the destructor
    // We really should define the other 4 (copy constructor, copy assignment, move constructor,
    // move assignment)

    // Copy constructor
    // Does it duplicate the actual allocated memory or just copy the address?
    // This is up to you
    // NOTE: I am calling SharedPointer(int*) constructor. So it automatically adds to the
    // reference_count
    SharedPointer(SharedPointer const& other)
    : SharedPointer(other.pointer_) {}

    // Move constructor
    // NOTE: I am not calling another constructor. I am just moving the pointer & reference_count
    // doesn't increase
    SharedPointer(SharedPointer&& other) noexcept
    : pointer_(std::move(other.pointer_)) {
        // Invalidate/reset members inside `other`
        other.pointer_ = nullptr;
    }

    // Copy assignment
    // Using trailing return type syntax
    auto operator=(SharedPointer const& other) -> SharedPointer&;
    auto operator=(SharedPointer&& other) noexcept -> SharedPointer&;

    friend bool operator==(SharedPointer const& lhs, SharedPointer const& rhs) {
        return lhs.pointer_ == rhs.pointer_;
    }

    // NOTE: Since we implemented the operator==, we should also implement the operator!=
    friend bool operator!=(SharedPointer const& lhs, SharedPointer const& rhs) {
        return !(lhs == rhs);
    }

    friend std::ostream& operator<<(std::ostream& os, SharedPointer const& sp) {
        os << "Value: " << *sp << std::endl;
        return os;
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