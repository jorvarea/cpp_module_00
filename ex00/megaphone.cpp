#include <iostream>

int main(int argc, char **argv) {
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else {
        for (int i = 1; i < argc; i++) {
            int j = 0;
            while (argv[i][j])
                std::cout << (unsigned char)std::toupper(argv[i][j++]);
        }
        std::cout << std::endl;
    }
    return 0;
}
