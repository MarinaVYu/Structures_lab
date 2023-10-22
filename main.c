#include <stdio.h>
#include <string.h>
#include "structures.h" // Отдельный заголовочный файл для определения структуры


#define CONSOLE_INPUT_WAY // Выбор пути ввода: при определении данного макроса выбирается ввод данных с консоли

#ifdef CONSOLE_INPUT_WAY
struct servant servants[20]; // Массив из структур servant
int size_of_mass; // Переменная, отображающая размер массива servants

#else // Выбран способ ввода данных  из заранее заполненного массива
int size_of_mass = 3; //Указывается размер заполненного массива

//Заранее заполненный массив
struct servant servants[] = {
        {"Pavlov", "Arcadiy", "Arcadievich", 1994,"Vinogradova1", 5, 5 },
        {"Petrov", "Anatoliy", "Andreevich", 2000,"Vinogradova", 6, 44 },
        {"Vasil'chuk", "Afanasiy", "Antonovich", 1998,"Vinogradova", 9, 31 },
};
#endif


int main() {
#ifdef CONSOLE_INPUT_WAY
    struct servant men; // Создание структуры для записи вводимых данных
    printf("Skol'ko sotrudnikov?\nVvedite chislo:"); // Запрос о количестве служащих предполагаемого списка
    scanf("%d", &size_of_mass); // Считывание и запись введенного числа
    // Запрашиваем и записываем в структуру men данные служащего
    for (int i = 0; i < size_of_mass; i++) {
        printf("\nVvedite familiyu: ");
        scanf("%s", men.FIO.surname);
        printf("Vvedite imya:");
        scanf("%s", men.FIO.first_name);
        printf("Vvedite otchestvo:");
        scanf("%s", men.FIO.patronymic);
        printf("Vvedite god rozhdeniya:");
        scanf("%d", &men.date_of_birth);
        printf("Vvedite adres - ulitsu:");
        scanf("%s", men.ADDRESS.street);
        printf("Vvedite adres - nomer doma:");
        scanf("%d", &men.ADDRESS.build_namber);
        printf("Vvedite adres - nomer kvartiry:");
        scanf("%d", &men.ADDRESS.flat_namber);
        servants[i] = men; // Сохраняем считанные данные в массив servants
    }
#endif
//Вывод структуры
    for (int i = 0; i < size_of_mass; i++) {
        printf("%s %s %s %d god, %s d.%d kv.%d\n", servants[i].FIO.surname, servants[i].FIO.first_name, servants[i].FIO.patronymic, servants[i].date_of_birth, servants[i].ADDRESS.street, servants[i].ADDRESS.build_namber, servants[i].ADDRESS.flat_namber );

    }
    // Запрос и запись названия улицы, на которой надо выделить самого старого служащего
    char street_for_search[20];
    printf("Ukazhite ulitsu dlya poiska:");
    scanf("%s", street_for_search);

    int year = 2050; // Переменная для записи года рождения самого старого служащего. Взят нереальный год рождения для корректного сравнения с годом рождения  первого служащего
    int num_of_servant = -1; // Переменная для записи номера служащего, оказавшегося самым старым. -1 используется как флаг того, что служащие, живущие на такой улице не найдены
// Выделение служащего, живущего на интересующей улице, и сравнение его года рождения с годом рождения ранее вявленного старейшего служащего
    for (int i = 0; i < size_of_mass; i++) {
        if ((strcmp (street_for_search, servants[i].ADDRESS.street)) == 0 ) {
            if (year > servants[i].date_of_birth) {
                year = servants[i].date_of_birth;
                num_of_servant = i;
            }
        }
    }
    // Проверка флага, показывающего, что не найдено служащих, живущих на интересующей улице
    if (num_of_servant == -1) {
        printf("Net sluzhashchih, zhivushchih na takoj ulitse.");
    }
    else {
        // Вывод служащего, оказавшегося старейшим среди живущих на заданной улице
        printf("Samyj staryj sluzhashchij: %s %s %s\n", servants[num_of_servant].FIO.surname, servants[num_of_servant].FIO.first_name, servants[num_of_servant].FIO.patronymic);
    }

    return 0;
}
