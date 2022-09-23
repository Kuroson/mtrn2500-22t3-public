#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP

#include <iostream>
#include <ostream>
#include <unordered_map>
#include <utility>

class SharedPointer {
  public:
    SharedPointer();

    SharedPointer(int* pointer);

    ~SharedPointer();

    SharedPointer(SharedPointer const& other);

    SharedPointer(SharedPointer&& other) noexcept;

    // Copy assignment
    // Using trailing return type syntax
    auto operator=(SharedPointer const& other) -> SharedPointer&;
    auto operator=(SharedPointer&& other) noexcept -> SharedPointer&;

    friend bool operator==(SharedPointer const& lhs, SharedPointer const& rhs);

    // NOTE: Since we implemented the operator==, we should also implement the operator!=
    friend bool operator!=(SharedPointer const& lhs, SharedPointer const& rhs);

    friend std::ostream& operator<<(std::ostream& os, SharedPointer const& sp);

    int* get();
    int const* get() const;
    int& operator*();
    int const& operator*() const;
    long use_count() const;

  private:
    int* pointer_;
};

#endif // SHARED_POINTER_HPP