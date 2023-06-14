// 1b

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char filename[] = "example.zip";

    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    char sign[4];
    file.read(sign, 4);

    short version;
    file.read((char*)&version, 2);

    short flag;
    file.read((char*)&flag, 2);

    short comp;
    file.read((char*)&comp, 2);

    short lastTime;
    file.read((char*)&lastTime, 2);

    short lastDate;
    file.read((char*)&lastDate, 2);

    int crc;
    file.read((char*)&crc, 4);

    int sizec;
    file.read((char*)&sizec, 4);

    file.close();

    std::cout << "sign: " << sign[0] << sign[1] << sign[2] << sign[3] << endl;
    std::cout << "version: " << version << endl;
    std::cout << "flag: " << flag << endl;
    std::cout << "comp: " << comp << endl;
    std::cout << "lastTime: " << lastTime << endl;
    std::cout << "lastDate: " << lastDate << endl;
    std::cout << "crc: " << crc << endl;
    std::cout << "sizec: " << sizec << endl;

    return 0;
}

// 3B

#include <iostream>
#include <fstream>

int main()
{
    std::ifstream inFile;
    inFile.open("in.txt");

    double x0, x1, step, param;
    inFile >> x0 >> x1 >> step >> param;

    inFile.close();

    std::ofstream outFile;
    outFile.open("out.txt");

    for (double x = x0; x <= x1; x += step)
    {
        double y = 0;
        for (int i = 1; i <= param; i++)
        {
            y += 1 / (i * x);
        }
        outFile << x << ", " << y << " ";
    }

    outFile.close();

    return 0;
}

// 5

#include <iostream>
#include <fstream>

struct Student {
    char surname[50];
    float averageScore;
    int course;
};

int main() {
    const int numStudents = 5;
    Student students[numStudents];

    for (int i = 0; i < numStudents; i++) {
        std::cout << "Введите фамилию студента " << i + 1 << ": ";
        std::cin >> students[i].surname;
        std::cout << "Введите среднюю оценку студента " << i + 1 << ": ";
        std::cin >> students[i].averageScore;
        std::cout << "Введите курс студента " << i + 1 << ": ";
        std::cin >> students[i].course;
    }

    std::ofstream file("students.txt");

    for (int i = 0; i < numStudents; i++) {
        file << students[i].surname << std::endl;
        file << students[i].averageScore << std::endl;
        file << students[i].course << std::endl;
    }

    file.close();

    std::cout << "Данные о студентах были успешно записаны в файл." << std::endl;

    return 0;
}