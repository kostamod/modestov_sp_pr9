// modestov_pr9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

const int SIZE = 5;

void operation1(double* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = data[i] + 10;
    }
}

void operation2(double* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = data[i] - 10;
    }
}

void operation3(double* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = 100;
    }
}

void operation4(double* data, int size) {
    for (int i = 0; i < size; i++) {
        if (data[i] < 0) {
            data[i] = 0;
        }
        if (data[i] > 100) {
            data[i] = 100;
        }
    }
}

void applyProcessing(double* data, int size, void (*processor)(double*, int)) {
    if (processor != nullptr) {
        processor(data, size);
    }
}

void inputData(double* data, double* original, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Заряд устройства " << i + 1 << " (0-100): ";
        cin >> data[i];
        while (data[i] < 0 || data[i] > 100) {
            cout << "Нужно число от 0 до 100: ";
            cin >> data[i];
        }
        original[i] = data[i];
    }
}

void showData(double* data, int size) {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void restoreData(double* data, double* original, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = original[i];
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    double data[SIZE] = { 0 };
    double original[SIZE] = { 0 };

    void (*processors[])(double*, int) = {
        operation1,
        operation2,
        operation3,
        operation4
    };

    int choice = 0;

    while (choice != 5) {
        cout << endl;
        cout << "1. Ввести данные" << endl;
        cout << "2. Показать данные" << endl;
        cout << "3. Выбрать и выполнить обработку" << endl;
        cout << "4. Восстановить исходные данные" << endl;
        cout << "5. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            inputData(data, original, SIZE);
            break;
        case 2:
            showData(data, SIZE);
            break;
        case 3: {
            int op;
            void (*processor)(double*, int) = nullptr;
            cout << "1. Увеличить заряд на 10" << endl;
            cout << "2. Уменьшить заряд на 10" << endl;
            cout << "3. Установить заряд всех устройств равным 100" << endl;
            cout << "4. Ограничить значения диапазоном от 0 до 100" << endl;
            cout << "Номер обработки: ";
            cin >> op;
            if (op >= 1 && op <= 4) {
                processor = processors[op - 1];
            }
            else {
                cout << "Нет такой обработки" << endl;
            }
            cout << "До: ";
            showData(data, SIZE);
            applyProcessing(data, SIZE, processor);
            cout << "После: ";
            showData(data, SIZE);
            break;
        }
        case 4:
            restoreData(data, original, SIZE);
            cout << "Данные восстановлены" << endl;
            break;
        case 5:
            break;
        default:
            cout << "Нет такого пункта" << endl;
        }
    }

    return 0;
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
