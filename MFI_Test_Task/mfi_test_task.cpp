// MFI_Test_Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "parttrue_search.h"

int main()
{
    std::cout << "Enter file name: " << std::endl;
    std::string file_name;
    std::getline(std::cin, file_name);
    std::ifstream file_stream(file_name);
    if (!file_stream.is_open())
    {
        std::cerr << "File not found, please enter correct name" << std::endl;
        return 1;
    }
    
    while (true)
    {
        std::cout << "Enter a string:" << std::endl;
        std::string sub_string;
        std::getline(std::cin, sub_string);
        std::cout << "Results: " << std::endl;
        auto clock_start = std::chrono::high_resolution_clock::now();
        parttrue_search(file_stream, sub_string);
        auto clock_end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(clock_end - clock_start).count();
        std::cout << "Execution time is: " << time << " ms"<< std::endl;
        std::cout << "=======================================================" << std::endl << std::endl;       
    }
    file_stream.close();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
