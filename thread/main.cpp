#include <thread>
#include <iostream>
#include <chrono>
#include <string>

void print(std::string const& str, int times)
{
    for (int i = 0; i < times; ++i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << str << std::flush;

    }
}

void user(int times)
{
    std::thread t1 { print, "Hello ",   times };
    std::thread t2 { print, "World!\n", times };

    t1.join();
    t2.join();
}

int main(void)
{
    std::cout << "How many times to repeat: ";
    
    int times = 1;
    std::cin >> times;
    user(times);

#if defined(_MSC_VER)
    system("pause");
#else
    std::cout << "\nPress [Enter] to continue ...";
    std::cin.get();
#endif
}


