#include "RPN.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " '...'" << std::endl;
        return (1);
    }

    try
    {
        int result = do_math(av[1]);
        std::cout << result << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    return (0);
}