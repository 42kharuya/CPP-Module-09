#include "RPN.hpp"

#include <iostream>
#include <cassert>

void testRPN() {
    assert(RPN::calc("3 4 +") == 7);
    assert(RPN::calc("9 2 -") == 7);
    assert(RPN::calc("6 3 *") == 18);
    assert(RPN::calc("8 4 /") == 2);
    assert(RPN::calc("8 9 * 9 - 9 - 9 - 4 - 1 +") == 42);
    assert(RPN::calc("1 2 * 2 / 2 * 2 4 - +") == 0);
    assert(RPN::calc("7 7 * 7 -") == 42);
    assert(RPN::calc("5 1 2 + 4 * + 3 -") == 14);  // 5 + ((1 + 2) * 4) - 3
    assert(RPN::calc("2 3 + 5 *") == 25);          // (2 + 3) * 5
    assert(RPN::calc("8 7 1 1 + - / 3 * 2 1 1 + + -") == -1);
    // ((8 / (7 - (1 + 1))) * 3) - (2 + (1 + 1))
    assert(RPN::calc("4 2 5 * + 1 3 2 * + /") ==
           2);  // (4 + (2 * 5)) / (1 + (3 * 2))
    assert(RPN::calc("3 5 8 * 7 + *") == 141);  // 3 * (5 * 8 + 7)
    assert(RPN::calc("9 6 - 3 2 + *") == 15);   // (9 - 6) * (3 + 2)
    assert(RPN::calc("5 6 - 1 3 * 2 + 5 2 - * - 4 5 * * 8 /") == -40);
    assert(RPN::calc("0 2 - 8 8 8 8 8 8 8 8 8 8 * * * * * * * * * *") ==
           -2147483648);

    assert(RPN::calc("2 3 + 5 * 6 -") == 19);  // (2 + 3) * 5 - 6

    // Test invalid expressions
    try {
        RPN::calc("13 2 +");
        assert(false);  // Should not reach here
    } catch (std::invalid_argument &e) {
        assert(std::string(e.what()) == "invalid expression");
    }
    try {
        RPN::calc("-1 3 +");
        assert(false);  // Should not reach here
    } catch (std::invalid_argument &e) {
        assert(std::string(e.what()) == "invalid expression");
    }
    try {
        RPN::calc("3 +");
        assert(false);  // Should not reach here
    } catch (std::invalid_argument &e) {
        assert(std::string(e.what()) == "invalid expression");
    }
    try {
        RPN::calc("1 2 3 +");
        assert(false);  // Should not reach here
    } catch (std::invalid_argument &e) {
        assert(std::string(e.what()) == "invalid expression");
    }
    try {
        RPN::calc("3 * (5 * 8 + 7)");
        assert(false);  // Should not reach here
    } catch (std::invalid_argument &e) {
        assert(std::string(e.what()) == "invalid expression");
    }

    try {
        RPN::calc("4 0 /");
        assert(false);  // Should not reach here
    } catch (std::invalid_argument &e) {
        assert(std::string(e.what()) == "division by zero");
    }
    try {
        RPN::calc("2 3 &");
        assert(false);  // Should not reach here
    } catch (std::invalid_argument &e) {
        assert(std::string(e.what()) == "");
    }
    try {
        RPN::calc("(1 + 1)");
        assert(false);  // Should not reach here
    } catch (std::invalid_argument &e) {
        assert(std::string(e.what()) == "");
    }

    // Test overflow
    try {
        RPN::calc("0 2 - 8 8 8 8 8 8 8 8 8 8 * * * * * * * * * * 0 1 - /");
        assert(false);  // Should not reach here
    } catch (std::overflow_error &e) {
        assert(std::string(e.what()) == "overflow");
    }
    try {
        RPN::calc("0 2 - 8 8 8 8 8 8 8 8 8 8 * * * * * * * * * * 1 - ");
        assert(false);  // Should not reach here
    } catch (std::overflow_error &e) {
        assert(std::string(e.what()) == "overflow");
    }
    try {
        RPN::calc(
            "0 2 - 4 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 * * * * * * * * * "
            "* * * * * * * * * * * * 0 1 - /");
        assert(false);  // Should not reach here
    } catch (std::overflow_error &e) {
        assert(std::string(e.what()) == "overflow");
    }
}

int main(int argc, char **argv) {
#if defined(DEBUG)
    std::cout << "Debug mode enabled" << std::endl;
    testRPN();
    std::cout << "All tests passed!" << std::endl;
    std::cout << "----------------------------" << std::endl;
#endif

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
        return 1;
    }

    try {
        std::cout << RPN::calc(argv[1]) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error " << e.what() << std::endl;
        return 1;
    }
    // std::cout << "RPN expression: " << argv[1] << std::endl;

    return 0;
}
