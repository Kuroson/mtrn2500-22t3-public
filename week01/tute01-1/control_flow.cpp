int main() {
    bool x{true};
    bool y{false};
    bool z{true};
    if ((x && y) || z) {
        // Do something.
    }
    else if (x || (y && z)) {
        // Do something.
    }
    else {
        // Do something if none of the above conditions are true.
    }

    char letter{'a'};
    switch (letter) {
    case 'a':
        // Do something.
        break;
    case 'b':
        // Do something.
        // break;  // If we do not break, then we execute case 'c'.
    case 'c':
        // Do something.
        break;
    default:
        // Do something.
        break;
    }
}