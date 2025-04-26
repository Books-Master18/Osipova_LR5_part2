#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"
//подключение модуля с тестируемыми методами 
#include "Osipova_MyTask.h" 

using namespace cute;

void testAsciiSum() {
    char chr1 = '3';
    char chr2 = '5';

    int expected = 51 + 53;

    // получение значения с помощью тестируемого метода
    int actual = printAsciiSum(chr1, chr2); // Получаем фактическую сумму ASCII кодов

    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

void testUserInput_Empty() {
    // исходные данные
    string str = "";
    // ожидаемое значение результата работы функции UserInput
    bool expected = false;
    // получение значения с помощью тестируемого метода
    bool actual = UserInput(str);
    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

void testUserChar_SingleCharacter_Letter() {
    // исходные данные
    string str = "a";
    // ожидаемое значение
    bool expected = true;
    // получение значения
    bool actual = UserChar(str);
    // сравнение
    ASSERT_EQUAL(expected, actual);
}

void testUserChar_SingleCharacter_Digit() {
    // исходные данные
    string str = "1";
    // ожидаемое значение
    bool expected = true;
    // получение значения
    bool actual = UserChar(str);
    // сравнение
    ASSERT_EQUAL(expected, actual);
}

void testUserInput_NegativeValue() {
    // исходные данные
    string str = "-5";
    // ожидаемое значение результата работы функции UserInput
    bool expected = false;
    // получение значения с помощью тестируемого метода
    bool actual = UserInput(str);
    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}




int main() {
    suite s;

    // Добавляем тестовую функцию в набор
    s.push_back(CUTE(testAsciiSum));
    s.push_back(CUTE(testUserInput_Empty));
    // s.push_back(CUTE(testUserInput_DigitLetterValue));
    s.push_back(CUTE(testUserInput_NegativeValue));
    s.push_back(CUTE(testUserChar_SingleCharacter_Letter));
    s.push_back(CUTE(testUserChar_SingleCharacter_Digit));


    // Создаем listener и runner
    ide_listener<> listener;
    makeRunner(listener)(s, "All MyTask Tests");
    return 0;
}