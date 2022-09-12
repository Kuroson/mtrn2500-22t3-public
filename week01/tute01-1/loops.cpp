void loop_example_1() {
    int i{0};
    while (i < 10) {
        int j{10};
        while (j > 0) {
            j -= 2;
        }
        ++i;
    }
}

void loop_example_2() {
    for (int i{0}; i < 10; ++i) {
        for (int j{10}; j > 0; j -= 2) {
        }
    }
}

int main() {
    loop_example_1();
    loop_example_2();
}