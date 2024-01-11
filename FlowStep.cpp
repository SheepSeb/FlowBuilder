//
// Created by Sebastian Nae on 10.01.2024.
//

#include "FlowStep.h"
#include <iostream>
void Title::execute() {
    std::cout << "Title" << std::endl;
}

Title::Title() : FlowStep(TITLE) {
    std::cout << "Enter the title: ";
    std::getline(std::cin >> std::ws, this->title);
    std::cout << "Enter the subtitle: ";
    std::getline(std::cin >> std::ws, this->subtitle);
}

std::string Title::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + title + " " + subtitle;
}

Title::Title(std::vector<std::string> args) : FlowStep(TITLE) {
    this->title = args[0];
    this->subtitle = args[1];
}

Text::Text(std::vector<std::string> args) : FlowStep(TEXT) {
    this->title = args[0];
    this->copy = args[1];
}

TextInput::TextInput(std::vector<std::string> args) : FlowStep(TEXT_INPUT) {
    this->description = args[0];
}

NumberInput::NumberInput(std::vector<std::string> args) : FlowStep(NUMBER_INPUT) {
    this->description = args[0];
}

Calculus::Calculus(std::vector<std::string> args) : FlowStep(CALCULUS) {
    this->number_of_steps = std::stoi(args[0]);
    for (int i = 0; i < number_of_steps; ++i) {
        this->steps[i] = std::stoi(args[i+1]);
    }
    this->calculus = args[number_of_steps+1];
}

Display::Display(std::vector<std::string> args) : FlowStep(DISPLAY) {
    this->step_number = std::stoi(args[0]);
}

TextFileInput::TextFileInput(std::vector<std::string> args) : FlowStep(TEXT_FILE_INPUT) {
    this->description = args[0];
}

CSVFileInput::CSVFileInput(std::vector<std::string> args) : FlowStep(CSV_FILE_INPUT) {
    this->description = args[0];
}

Output::Output(std::vector<std::string> args) : FlowStep(OUTPUT) {
    this->step_number = std::stoi(args[0]);
    this->file_name = args[1];
    this->title = args[2];
    this->description = args[3];
}

Text::Text() : FlowStep(TEXT) {
    std::cout << "Enter the title: ";
    std::getline(std::cin >> std::ws, this->title);
    std::cout << "Enter the copy: ";
    std::getline(std::cin >> std::ws, this->copy);
}

std::string Text::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + title + " " + copy;
}

void Text::execute() {
    std::cout << "Text" << std::endl;
}

Text::Text(std::string title, std::string copy) : FlowStep(TEXT) {
    this->title = title;
    this->copy = copy;
}

TextInput::TextInput(): FlowStep(TEXT_INPUT) {
    std::cout << "Enter the description: ";
    // get the description as a string with spaces
    std::getline(std::cin >> std::ws, this->description);
//    std::cout << "Enter the text input: ";
//    std::cin >> this->text_input;
}

std::string TextInput::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + description;
}

void TextInput::execute() {
    std::cout << "Enter the text input: ";
    std::getline(std::cin >> std::ws, this->text_input);
}

TextInput::TextInput(std::string description) : FlowStep(TEXT_INPUT) {
    this->description = description;
    std::cout << "Enter the text input: ";
    std::getline(std::cin >> std::ws, this->text_input);
}

NumberInput::NumberInput() : FlowStep(NUMBER_INPUT) {
    std::cout << "Enter the description: ";
    std::getline(std::cin >> std::ws, this->description);
//    std::cout << "Enter the number input: ";
//    // generate exception if input is not a number (e.g. "abc") and try again
//    try {
//        std::cin >> this->number_input;
//    } catch (std::exception& e) {
//        std::cout << "Error: " << e.what() << std::endl;
//        std::cout << "Please enter a number." << std::endl;
//        std::cin >> this->number_input;
//    }
}

void NumberInput::execute() {
    std::cout << "Number Input" << std::endl;
}

std::string NumberInput::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + description + " " + std::to_string(number_input);
}

NumberInput::NumberInput(std::string description) : FlowStep(NUMBER_INPUT) {
    this->description = description;
}

Calculus::Calculus() : FlowStep(CALCULUS) {
    std::cout << "Enter the number of steps: ";
    std::cin >> this->number_of_steps;
    for (int i = 0; i < number_of_steps; ++i) {
        std::cout << "Enter step id" << i << ": ";
        std::cin >> this->steps[i];
    }
    std::cout << "Enter the calculus: ";
    std::cin >> this->calculus;
}

void Calculus::execute() {
    std::cout << "Calculus" << std::endl;
}

std::string Calculus::toString() {
    std::string final = FlowStep::stepTypeToString();;
    final += " " + std::to_string(number_of_steps);
    for (int i = 0; i < number_of_steps; ++i) {
        final += " " + std::to_string(steps[i]);
    }
    final += " " + calculus;
    return final;
}

Calculus::Calculus(int number_of_steps, std::vector<int> steps, std::string calculus) : FlowStep(CALCULUS) {
    this->number_of_steps = number_of_steps;
    this->steps = steps;
    this->calculus = calculus;
}

Display::Display() : FlowStep(DISPLAY) {
    // Show all the steps that are TEXT INPUT or CSV INPUT
    std::cout << "Enter the step number: ";
    std::cin >> this->step_number;
}

void Display::execute() {
    std::cout << "Display" << std::endl;
}

std::string Display::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + std::to_string(step_number);
}

Display::Display(int step_number) : FlowStep(DISPLAY) {
    this->step_number = step_number;
}

TextFileInput::TextFileInput() : FlowStep(TEXT_FILE_INPUT) {
    std::cout << "Enter the description: ";
    std::cin >> this->description;
    std::cout << "Enter the filename: ";
    std::cin >> this->text_file_input;
}

void TextFileInput::execute() {
    std::cout << "Text File Input" << std::endl;
}

std::string TextFileInput::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + description + " " + text_file_input;
}

TextFileInput::TextFileInput(std::string description) : FlowStep(TEXT_FILE_INPUT) {
    this->description = description;
    std::cout << "Enter the filename: ";
    std::cin >> this->text_file_input;
}

CSVFileInput::CSVFileInput() : FlowStep(CSV_FILE_INPUT) {
    std::cout << "Enter the description: ";
    std::cin >> this->description;
    std::cout << "Enter the filename: ";
    std::cin >> this->csv_file_input;
}

void CSVFileInput::execute() {
    std::cout << "CSV File Input" << std::endl;
}

std::string CSVFileInput::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + description + " " + csv_file_input;
}

CSVFileInput::CSVFileInput(std::string description) : FlowStep(CSV_FILE_INPUT) {
    this->description = description;
    std::cout << "Enter the filename: ";
    std::cin >> this->csv_file_input;
}

Output::Output() : FlowStep(OUTPUT) {
    std::cout << "Enter step number: ";
    std::cin >> this->step_number;
    std::cout << "Enter the filename: ";
    std::cin >> this->file_name;
    std::cout<< "Enter the title: ";
    std::cin >> this->title;
    std::cout << "Enter the description: ";
    std::cin >> this->description;
}

void Output::execute() {
    std::cout << "Output" << std::endl;
}

std::string Output::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + std::to_string(step_number) + " " + file_name + " " + title + " " + description;
}

End::End() : FlowStep(END) {}

void End::execute() {
    std::cout << "End" << std::endl;
}

std::string End::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string;
}

