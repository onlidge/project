#include <iostream>
#include <algorithm>

enum OS {Windows, Linux, etc};

OS getOs() {
    return
#ifdef __linux
    Linux;
#elif defined _WIN32
    Windows;
#elif defined _WIN64
    Windows;
#endif
}

void clearscreen(){
    if (getOs() == Windows) {
        std::cout << "rr";
        system("cls");
    }
    else if (getOs() == Linux){
        system("clear");
    }
}

std::string input_command(){
    std::string command;
    std::cin >> command;
    std::transform(command.begin(), command.end(), command.begin(), tolower);
    return command;
}

std::string input_text(){
    std::string command;
    std::cin >> command;
    return command;
}

void output_text(std::string out){
    std::cout << out;
    std::cout <<  "--------------------------------------------\n";
}

void continue_mechanic(){
    output_text("Write something to continue\n");
    std::string command = input_command();
}
