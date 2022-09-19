#include <memory>

void foo(std::shared_ptr<int>& ptr) {
    (void)ptr;
    return;
}

int main() {
    auto ptr{std::make_shared<int>(42)};
    foo(ptr);
}
