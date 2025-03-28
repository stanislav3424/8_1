#include <iostream>
#include <string>

class bad_length : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "�� ����� ����� ��������� �����! �� ��������";
    }
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
            int len = function(input, forbidden_length);
            std::cout << "����� ����� \"" << input << "\" ����� " << len << std::endl;
        }
        catch (const bad_length& error)
        {
            std::cout << error.what() << std::endl;
            return 1;
        }
    }

    return 0;
}