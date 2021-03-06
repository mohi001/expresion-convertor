#include <string>
#include <iostream>
#include "Stack.cpp"
static bool is_operator(std::string str);
static void log(Stack &in, Stack &out, bool l);

std::string post_to_pre(std::string str, bool l)
{
    if (l)
    {
        std::cout << "postfix to pretfix: " << str << "\n";
    }
    Stack in(str);
    Stack out;
    std::string t;
    while (!in.isEmpty())
    {
        t = in.pop();
        if (is_operator(t))
        {
            t = t + " " + out.pop() + " " + out.pop();
            out.push(t);
        }
        else
        {
            out.push(t);
        }
        log(in, out, l);
    }
    return out.to_string();
}
static bool is_operator(std::string str)
{
    return str == "+" || str == "-" || str == "/" || str == "*" || str == "^";
}
static void log(Stack &in, Stack &out, bool l)
{
    if (l)
    {
        std::cout << "input stack:\n";
        in.print();
        std::cout << "output stack:\n";
        out.print();
    }
}