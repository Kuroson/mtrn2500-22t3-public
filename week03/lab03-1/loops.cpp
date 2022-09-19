#include <iostream>
#include <vector>

auto loop_1() -> void {
    auto numbers = std::vector<int>{1, 2, 3, 4, 5};

    auto counter = 0ul;
    while (counter < numbers.size()) {
        std::cout << numbers[counter] << std::endl;
        ++counter;
    }
}

auto loop_2() -> void {
    auto numbers = std::vector<int>{1, 2, 3, 4, 5};
    for (auto i = 0ul; i < numbers.size(); ++i) {
        std::cout << numbers[i] << std::endl;
    }
}

auto loop_3() -> void {
    auto numbers = std::vector<int>{1, 2, 3, 4, 5};
    for (auto number : numbers) {
        std::cout << number << std::endl;
    }
}

auto loop_4() -> void {
    auto numbers = std::vector<int>{1, 2, 3, 4, 5};
    for (auto& number : numbers) {
        number = 0;
    }

    for (auto const& number : numbers) {
        std::cout << number << std::endl;
    }
    // {0, 0, 0, 0, 0}
}

auto loop_5() -> void {
    auto matrix = std::vector<std::vector<int>>{{1, 2, 3, 4, 5}, {0, 0, 0, 0, 0}};
    for (auto row : matrix) {
        //
    }
}

auto loop_6() -> void {
    auto matrix = std::vector<std::vector<int>>{{1, 2, 3, 4, 5}, {0, 0, 0, 0, 0}};
    for (auto& row : matrix) {
        // row is a std::vector<int> reference that can be changed
        (void)row;
    }

    for (auto const& row : matrix) {
        // row is a const std::vector<int> reference that cannot be changed
        (void)row;
    }
}

auto main() -> int {
    return 0;
}