#include <iostream>
#include <list>
#include <string>

int main() {
    // Ввод последовательности символов
    std::string input;
    std::cout << "Введите последовательность латинских букв, заканчивающуюся точкой: ";
    std::cin >> input;

    // Проверяем, оканчивается ли точкой
    if (input.back() != '.') {
        std::cerr << "Ошибка: последовательность должна оканчиваться точкой." << std::endl;
        return 1;
    }

    // Двунаправленный список для хранения результата
    std::list<char> result;

    // Обрабатываем последовательность
    for (size_t i = 0; i < input.size(); ++i) {
        if (i + 1 < input.size() && input[i] == 'C' && input[i + 1] == 'h') {
            if (!result.empty()) {
                result.pop_back();
            }
            ++i; // Пропускаем 'h'
        } else if (input[i] != '.') {  // Если это не 'Ch' и не точка, добавляем в список
            result.push_back(input[i]);
        }
    }

    // Вывод результата
    std::cout << "Преобразованная последовательность: ";
    for (char c : result) {
        std::cout << c;
    }
    std::cout << (result.empty() ? "." : ".") << std::endl; // Добавляем точку в конец

    return 0;
}
