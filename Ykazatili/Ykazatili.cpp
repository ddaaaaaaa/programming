// 1 double

#include <iostream>

int main() {
    double a = 5, b = 9;
    double* a1, * b1;

    a1 = &a;
    b1 = &b;

    std::cout << "����� ���������� a: " << a1 << std::endl;
    std::cout << "����� ���������� b: " << b1 << std::endl;

    double sum = *a1 + *b1;
    double sub = *a1 - *b1;

    std::cout << "�����: " << sum << std::endl;
    std::cout << "��������: " << sub << std::endl;

    return 0;
}

// 2 double

#include <iostream>

void swap(double* x, double* y) {
    double temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    double a = 10;
    double b = 15;

    std::cout << "A����� a: " << &a << ", �������� a: " << a << std::endl;
    std::cout << "A����� b: " << &b << ", �������� b: " << b << std::endl;
    std::cout << "A����� ��������� a: " << &*(&a) << ", �������� ��������� a: " << *&a << std::endl;
    std::cout << "A����� ��������� b: " << &*(&b) << ", �������� ��������� b: " << *&b << std::endl;

    std::cout << "�� ������: a = " << a << ", b = " << b << std::endl;

    swap(&a, &b);

    std::cout << "����� ������: a = " << a << ", b = " << b << std::endl;

    return 0;
}

// 3 double

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(NULL));

    int size;
    std::cout << "������� ������ �������: ";
    std::cin >> size;

    double* arr = new double[size]; 

    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }

    for (int i = 0; i < size; i++) {
        std::cout << "����� �������� " << i << ": " << &arr[i] << ", ��������: " << arr[i] << std::endl;
    }

    delete[] arr;

    return 0;
}

// 4b

#include <iostream>
#include <ctime>
#include <string>

struct Plane {
    int id;
    std::string model;
    int maxSpeed;
    int maxAltitude;
};

void changePlain(Plane* planes, int index) { // ��������� �������� � �������
    std::cout << "������� ����� ������: ";
    std::cin >> planes[index].model;
    std::cout << "������� ����� ����.��������: ";
    std::cin >> planes[index].maxSpeed;
    std::cout << "������� ����� ����.������: ";
    std::cin >> planes[index].maxAltitude;
    std::cout << std::endl;

}

void listOutput(Plane* planes, int planesCount) { // ������� ������ �������
    for (int i = 0; i < planesCount; i++) {
        std::cout << "Plane #" << planes[i].id << ":\n";
        std::cout << "Model: " << planes[i].model << "\n";
        std::cout << "Max speed: " << planes[i].maxSpeed << "\n";
        std::cout << "Max altitude: " << planes[i].maxAltitude << "\n\n";
    }
}

int main() {
    int planesCount;
    std::cout << "������� ���-�� ��������: ";
    std::cin >> planesCount;
    Plane* planes = new Plane[planesCount];

    srand(time(NULL));

    for (int i = 0; i < planesCount; i++) {
        planes[i].id = i + 1;
        planes[i].model = "Boeing " + std::to_string(rand() % 1000);
        planes[i].maxSpeed = rand() % 1000 + 500;
        planes[i].maxAltitude = rand() % 10000 + 5000;
    }

    listOutput(planes, planesCount);

    int index;
    std::cout << "������� ����� �������� ��� ������ ������: ";
    std::cin >> index;
    index--;
    changePlain(planes, index);

    std::cout << "����� �������: ";
    std::cout << "Plane #" << planes[index].id << ":\n";
    std::cout << "Model: " << planes[index].model << "\n";
    std::cout << "Max speed: " << planes[index].maxSpeed << "\n";
    std::cout << "Max altitude: " << planes[index].maxAltitude << "\n\n";

    int swap;
    std::cout << "�������� �������:\n"
        << "1. �������� ���� ������ � �����\n"
        << "2. �����";
    std::cin >> swap;
    if (swap == 1) {
        listOutput(planes, planesCount);
        delete[] planes;
    }
    else {
        delete[] planes;
    }

    return 0;
};

