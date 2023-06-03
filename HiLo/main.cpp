#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

void print_greeting();
void print_rules();

int main() {
    print_greeting();
    print_rules();

    srand(time(NULL));

    int target = (rand() % 99) + 1;
    int guess;
    int num_guesses = 0;

    std::string trash;

    // Main Loop

    bool running = true;
    while (running) {
        std::cin.clear(); // Clear cin state for next loop

        std::cout << "Make a guess: ";
        std::cin >> guess;

        while (std::cin.fail()) {
            std::getline(std::cin, trash);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a valid integer: ";
            std::cin >> guess;
        }

        // Input was valid

        std::getline(std::cin, trash);

        num_guesses += 1;
        if (guess == 0) {
            std::cout << "See ya!\n";
            running = false;
        }
        else if (guess > target) {
            std::cout << "Lower\n";
            std::cout << "\n";
        }
        else if (guess < target) {
            std::cout << "Higher\n";
            std::cout << "\n";
        }
        else {
            if (num_guesses == 1) {
                std::cout << "Are you reading my mind? You got it in 1 guess!\n";
            } else {
                std::cout << "Yay! You got it in " << num_guesses << " guesses!\n";
            }
            running = false;
        }
    }
}

void print_greeting() {
    std::cout << std::endl;
    std::cout << "===================================================================" << std::endl;
    std::cout << "                         Welcome to Hi-Lo!                         " << std::endl;
    std::cout << "===================================================================" << std::endl;
    std::cout << std::endl;
}

void print_rules() {
    std::cout << "I'm thinking of a number between 1 and 100,\n"
                 "  and it's your job to guess what it is!\n"
                 "\n"
                 "Each time you guess I'll tell you if your guess was:\n"
                 "\n"
                 "  too high...\n"
                 "              too low...\n"
                 "                         or spot on!\n"
                 "\n"
                 "PS : If you enter a float I'll just round it down.\n"
                 "PPS: If you want to quit at any point, just enter 0, or hit ctrl-C.\n"
                 "\n";
}