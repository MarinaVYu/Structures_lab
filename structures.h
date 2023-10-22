#ifndef LAB_8_STRUCTURES_H
#define LAB_8_STRUCTURES_H
// Подраздел ФИО служащего
struct fio {
    char surname[20]; // Фамилия служащего
    char first_name[20]; // Имя служащего
    char patronymic[20]; // Отчество служащего
};
// Подраздел адрес служащего
struct adress {
    char street[20]; // Название улицы
    int build_namber; // Номер дома
    int flat_namber; // Номер квартиры
};

// Основной раздел структуры
struct servant
{
    struct fio FIO; // Подраздел ФИО
    int date_of_birth; // Подраздел "дата рождения"
    struct adress ADDRESS; // Подраздел адрес
};
#endif //LAB_8_STRUCTURES_H
