#include "header.hpp"
void show_history(fix_to_fix *fixes);
void back_to_menu();
int main(int argc, char const *argv[])
{
    std::string input = "";
    std::string exp = "";
    std::string str = "";
    bool d = true;
    fix_to_fix in_post("infix to postfix");
    fix_to_fix in_pre("infix to prefix");
    fix_to_fix post_in("postfix to infix");
    fix_to_fix post_pre("postfix to prefix");
    fix_to_fix pre_in("prefix to infix");
    fix_to_fix pre_post("prefix to postfix");
    fix_to_fix fixes[6] = {in_post, in_pre,
                           post_in, post_pre, pre_in, pre_post};
    while (1 && d)
    {
        std::cout << "welcome,please chose a numebr\nor enter q to exit\n";
        std::cout << "1: infix to postfix\n";
        std::cout << "2: infix to prefix\n";
        std::cout << "3: postfix to infix\n";
        std::cout << "4: postfix to prefix\n";
        std::cout << "5: prefix to infix\n";
        std::cout << "6: prefix to postfix\n";
        std::cout << "7: show history\n";
        std::getline(std::cin, input);
        if (input == "q" || input == "exit")
        {
            break;
        }
        int a = std::stoi(input);
        std::cout << "please inter your expresion:\n";

        switch (a)
        {
        case 1:
            std::getline(std::cin, exp);
            if (is_infix(exp))
            {
                str = in_to_post(exp, true);
                std::cout << "result is: " << str;
                std::cout << "\n";
                fixes[0].update();
                back_to_menu();
            }
            else
            {
                std::cout << "\033[1;31minvalid expresion\033[0m\n";
            }
            break;

        case 2:
            std::getline(std::cin, exp);
            if (is_infix(exp))
            {
                str = in_to_pre(exp, true);
                std::cout << "result is: " << str;
                std::cout << "\n";
                fixes[1].update();
                back_to_menu();
            }
            else
            {
                std::cout << "\033[1;31minvalid expresion\033[0m\n";
            }
            break;
        case 3:
            std::getline(std::cin, exp);
            if (is_postfix(exp))
            {
                str = post_to_in(exp, true);
                std::cout << "result is: " << str;
                std::cout << "\n";
                fixes[2].update();
                back_to_menu();
            }
            else
            {
                std::cout << "\033[1;31minvalid expresion\033[0m\n";
            }
            break;
        case 4:
            std::getline(std::cin, exp);
            if (is_postfix(exp))
            {
                str = post_to_pre(exp, true);
                std::cout << "result is: " << str;
                std::cout << "\n";
                fixes[3].update();
                back_to_menu();
            }
            else
            {
                std::cout << "\033[1;31minvalid expresion\033[0m\n";
            }
            break;
        case 5:
            std::getline(std::cin, exp);
            if (is_prefix(exp))
            {
                str = pre_to_in(exp, true);
                std::cout << "result is: " << str;
                std::cout << "\n";
                fixes[4].update();
                back_to_menu();
            }
            else
            {
                std::cout << "\033[1;31minvalid expresion\033[0m\n";
            }
            break;
        case 6:
            std::getline(std::cin, exp);
            if (is_prefix(exp))
            {
                str = pre_to_post(exp, true);
                std::cout << "result is: " << str;
                std::cout << "\n";
                fixes[5].update();
                back_to_menu();
            }
            else
            {
                std::cout << "\033[1;31minvalid expresion\033[0m\n";
            }
            break;
        case 7:
            show_history(fixes);
            back_to_menu();
            break;

        default:
            std::cout << "invalid";
            std::cout << "\n";
            break;
        }
        input = "q";
    }
    return 0;
}
void show_history(fix_to_fix *fixes)
{
    fix_to_fix tmp("");
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t i = 0; i < 5; i++)
        {
            if (fixes[i].get_time() > fixes[i + 1].get_time())
            {
                tmp = fixes[i];
                fixes[i] = fixes[i + 1];
                fixes[i + 1] = tmp;
            }
        }
    }
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t i = 0; i < 5; i++)
        {
            if (fixes[i].get_count() < fixes[i + 1].get_count())
            {
                tmp = fixes[i];
                fixes[i] = fixes[i + 1];
                fixes[i + 1] = tmp;
            }
        }
    }
    for (size_t i = 0; i < 6; i++)
    {
        fixes[i].print();
    }
}
void back_to_menu()
{
    std::cout << "enter any button to back to menu\n";
    std::getchar();
    std::system("clear");
}