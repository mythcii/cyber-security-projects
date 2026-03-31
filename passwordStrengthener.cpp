#include <string>
#include <iostream>

int main(int argc, char* argv[]) {

    std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string numbers = "1234567890";
    std::string alphanumeric = lowercase + uppercase + numbers;
    bool strong, length, upper, lower, num, special = false;

    std::string pwInput;
    while (!strong) {

        std::cout << "Please enter your password:\n";
        std::cin >> pwInput;

        if (pwInput.length() > 11) length = 1;      
        else {
            length = 0;
            std::cout << "Must be >11 characters\n";
        }

        if (pwInput.find_first_of(uppercase) != std::string::npos) upper = 1;
        else {
            upper = 0;
            std::cout << "Missing uppercase letter\n";
        }

        if (pwInput.find_first_of(lowercase) != std::string::npos) lower = 1;
        else {
            lower = 0;
            std::cout << "Missing lowercase letter\n";
        }

        if (pwInput.find_first_of(numbers) != std::string::npos) num = 1;
        else {
            num = 0;
            std::cout << "Missing a number\n";
        }

        if (pwInput.find_last_not_of(alphanumeric) != std::string::npos) special = 1;
        else {
            special = 0;
            std::cout << "Missing a special character\n";
        }

        std::cout << std::endl;
        if (special && length && num && upper && lower) strong = 1;
    }

    std::cout << "Password accepted\n";


    return 0;
}