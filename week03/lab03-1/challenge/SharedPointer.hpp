#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP

class SharedPointer {
  public:
    SharedPointer();

    SharedPointer(int* pointer);
    ~SharedPointer();

    int* get();
    int const* get() const;
    int& operator*();
    int const& operator*() const;
    long use_count() const;

  private:
    int* pointer_;
};

#endif // SHARED_POINTER_HPP