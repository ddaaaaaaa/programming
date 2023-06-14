// 2
#include <iostream>
#include <string>

int main() {
    int k = 0;
    std::string text;

    std::getline(std::cin, text);

    for (int i = 0; i < text.length() - 2; i++) {
        if (text[i - 1] == ' ' && text[i] == 'm' && text[i + 1] == 'i' && text[i + 2] == 'r' && text[i + 3] == ' ')

            k++;
    }



    std::cout << "Количество отдельных слов 'мир': " << k << std::endl;

    return 0;
}


// 15

#include <iostream>
#include <string>

int main() {
    std::string str;
    std::getline(std::cin, str);

    if (str.length() >= 10) {
        str = str.substr(0, 6);
    }
    else {
        str.append(12 - str.length(), 'o');
    }

    std::cout << str << std::endl;

    return 0;
}


// 6

#include <iostream>
#include <string>

int main() {
    std::string str;
    std::getline(std::cin, str);

    std::string rslt = "";
    for (int i = 0; i < str.length(); i++)

        if (str[i] != ' ') rslt = rslt + str[i] + ' ';

    std::cout << rslt << std::endl;

    return 0;
}

// 20

#include <iostream>
#include <string>

int main() {
    std::string str;
    std::getline(std::cin, str);

    std::string result = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            result += str[i];
        }
        if (i < str.length() - 1 && str[i] != ' ') {
            result += ' ';
        }
    }

    std::cout << result << std::endl;

    return 0;
}