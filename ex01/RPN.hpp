#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <list>
#include <stack>
#include <stdexcept>
#include <string>
#include <climits>

class RPN {
   public:
    static int calc(const std::string &expression);

   private:
    static bool _isOperator(char c);
    static int _applyOperator(char op, int a, int b);
    static bool _willOverflow(int a, int b, char op);

    RPN();                             // = delete;
    ~RPN();                            // = delete;
    RPN(RPN const &other);             // = delete;
    RPN &operator=(RPN const &other);  // = delete;
};

#endif /* RPN_HPP */
