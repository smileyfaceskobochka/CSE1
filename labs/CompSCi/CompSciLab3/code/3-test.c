#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Преобразование целой части из заданной системы счисления в десятичную
int convertIntToDec(const char *intPart, int base) {
  int decimalValue = 0; // Переменная для хранения десятичного значения целой части

  // Проходим по каждому символу целой части
  for (int i = 0; i < strlen(intPart); i++) {
    int digit = intPart[i] - '0';               // Преобразуем символ в число
    decimalValue = decimalValue * base + digit; // Обновляем десятичное значение
  }

  return decimalValue; // Возвращаем десятичное значение целой части
}

// Преобразование дробной части из заданной системы счисления в десятичную
double convertFracToDec(const char *frac, int base) {
  double decValue = 0.0;  // Переменная для хранения десятичного значения дробной части
  double basePower = 1.0; // Переменная для хранения текущей степени основания

  // Проходим по каждому символу дробной части
  for (int i = 0; i < strlen(frac); i++) {
    int digit = frac[i] - '0';               // Преобразуем символ в число
    decValue += digit / (basePower *= base); // Добавляем значение к десятичному
  }

  return decValue; // Десятичное значение дробной части
}

// Функция для преобразования целого числа в заданную систему счисления
int convertIntToBase(int number, int base, char *result) {
  int index = 0; // Индекс для записи символов в результат

  // Преобразование числа в заданную систему счисления
  do {
    int remainder = number % base;     // Остаток от деления на основание
    result[index++] = '0' + remainder; // Записываем символ в результат
    number /= base;                    // Делим число на основание
  } while (number > 0); // Продолжаем, пока число больше нуля

  // Завершаем строку нулевым символом
  result[index] = '\0';

  // Обратим порядок символов в строке
  for (int i = 0; i < index / 2; i++) {
    char temp = result[i];             // Временная переменная для обмена
    result[i] = result[index - i - 1]; // Меняем местами символы
    result[index - i - 1] = temp;      // Меняем местами символы
  }

  return 0; // Успешное выполнение
}

// Функция для преобразования дробной части в заданную систему счисления
int convertFracToBase(double frac, int base, char *result, int precision) {
  int index = 0; // Индекс для записи символов в результат

  // Преобразуем дробную часть с заданной точностью
  while (precision-- > 0) {
    frac *= base;                  // Умножаем дробную часть на основание
    int digit = (int)frac;         // Получаем целую часть
    result[index++] = '0' + digit; // Записываем символ в результат
    frac -= digit;                 // Убираем целую часть из дробной
  }

  result[index] = '\0'; // Завершаем строку нулевым символом
  return 0;             // Успешное выполнение
}

int main() {
  char x[50]; // Массив для хранения входной строки
  printf("Введите число x, основание его системы счисления k и основание системы счисления в которую хотите перевести: ");
  fgets(x, sizeof(x), stdin); // Читаем входные данные

  char *token = strtok(x, " "); // Разделяем строку на 3 токена
  char *numberStr = token;      // Сохраняем строку числа
  token = strtok(NULL, " ");    // Основание k
  int k = atoi(token);          // str в int k
  token = strtok(NULL, " ");    // Основание m
  int m = atoi(token);          // str в int m

  // Разделяем число на целую и дробную части
  char *intPart = strtok(numberStr, "."); // Целая часть до .
  char *fracPart = strtok(NULL, ".");     // Дробная часть после .

  // Переводим целую часть в десятичную
  int intDec = convertIntToDec(intPart, k);

  // Переводим дробную часть в десятичную
  double fracDec = fracPart ? convertFracToDec(fracPart, k) : 0.0;

  // Переводим целую часть в систему счисления M
  char intRes[50];
  convertIntToBase(intDec, m, intRes);

  // Переводим дробную часть в систему счисления M
  char fracRes[50];
  int precision = fracPart ? strlen(fracPart) : 0; // Количество знаков дробной части
  convertFracToBase(fracDec, m, fracRes, precision);

  // Выводим результат
  if (precision > 0) {
    printf("Результат: %s.%s\n", intRes, fracRes);
  }
  else {
    printf("Результат: %s\n", intRes);
  }

  return 0;
}