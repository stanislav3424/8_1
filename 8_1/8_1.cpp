#include <iostream>
#include <string>

class bad_length : public std::exception
{
};

int function(std::string str, int forbidden_length)
{
    int length = str.length();
    if (length == forbidden_length)
    {
        throw bad_length();
    }
    return length;
}

int main()
{
    setlocale(LC_ALL, "");
    std::cout << "������� ��������� �����: ";
    int forbidden_length{};
    std::cin >> forbidden_length;

    while (true)
    {
        try
        {
            std::string input{};
            std::cout << "������� �����: ";
            std::cin >> input;
            std::cout << "����� ����� \"" << input << "\" ����� " << function(input, forbidden_length) << std::endl;
        }
        catch (bad_length)
        {
            std::cout << "�� ����� ����� ��������� �����! �� ��������" << std::endl;
            return 1;
        }
    }

    return 0;
}