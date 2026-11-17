// Copyright (c) 2025 All rights reserved.
//
// Created by: Adrian student.
// Created on: 13th NOV 2026
// This program uses a random number generator to choose a
// random number and then asks the user to try guessing it
#include <iostream>
#include <random>
#include <string>

int main() {
    // declare integer to hold random number
    int randomNumber;
    std::string guessNumberStr;
    int guessNumberInt;

    // set up the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 9);
    randomNumber = dist(gen);

    do {
        // get the user guess number
        std::cout << "\n";
        std::cout << "Enter your guess number between  0 and 9 : ";
        std::cin >> guessNumberStr;

        // prevent crashing
        try {
            guessNumberInt = std::stoi(guessNumberStr);
            if (guessNumberInt >= 0 && guessNumberInt <= 9) {
                if (guessNumberInt != randomNumber) {
                    std::cout << "That is not the correct number . Try again";
                }
            } else {
                std::cout << guessNumberInt << " is off range.Please try again";
                std::cout << "\n";
            }
        } catch (std::invalid_argument) {
            std::cout << guessNumberStr <<" is not an integer.Please try again";
            std::cout << "\n";
        }
    } while (guessNumberInt != randomNumber);
    std::cout << "\n";
    std::cout << "you guessed correctly !!";
    std::cout << "\n";
    std::cout << "Thanks for playing !!";
    std::cout << "\n";
}
