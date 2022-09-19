int main() {
    int* ptr1{new int{1}};
    int* ptr2{new int{2}};
    int* ptr3{ptr2};
    int var{5};
    int* ptr4{new int{var}};
    int* ptr5{new int{var}};
    delete ptr1;
    delete ptr2;
    delete ptr3;
    delete ptr4;
    delete ptr5;
}
