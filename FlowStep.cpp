//
// Created by Sebastian Nae on 10.01.2024.
//

#include "FlowStep.h"

void Title::execute() const {
    std::cout << "Title" << std::endl;
}

Title::Title() : FlowStep(TITLE) {
    std::cout << "Enter the title: ";
    std::cin >> this->title;
    std::cout << "Enter the subtitle: ";
    std::cin >> this->subtitle;
}

std::string Title::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + title + " " + subtitle;
}

Title::Title(std::string title, std::string subtitle) : FlowStep(TITLE) {
    this->title = title;
    this->subtitle = subtitle;
}

Text::Text() : FlowStep(TEXT) {
    std::cout << "Enter the title: ";
    std::cin >> this->title;
    std::cout << "Enter the copy: ";
    std::cin >> this->copy;

}

std::string Text::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + title + " " + copy;
}

void Text::execute() const {
    std::cout << "Text" << std::endl;
}

Text::Text(std::string title, std::string copy) : FlowStep(TEXT) {
    this->title = title;
    this->copy = copy;
}

TextInput::TextInput(): FlowStep(TEXT_INPUT) {
    std::cout << "Enter the description: ";
    std::cin >> this->description;
//    std::cout << "Enter the text input: ";
//    std::cin >> this->text_input;
}

std::string TextInput::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + description + " " + text_input;
}

void TextInput::execute() const {
    std::cout << "Text Input" << std::endl;
}

TextInput::TextInput(std::string description) : FlowStep(TEXT_INPUT) {
    this->description = description;
    std::cout << "Enter the text input: ";
    std::cin >> this->text_input;
    this->text_input = text_input;
}

NumberInput::NumberInput() : FlowStep(NUMBER_INPUT) {
    std::cout << "Enter the description: ";
    std::cin >> this->description;
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

void NumberInput::execute() const {
    std::cout << "Number Input" << std::endl;
}

std::string NumberInput::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + description + " " + std::to_string(number_input);
}

NumberInput::NumberInput(std::string description) : FlowStep(NUMBER_INPUT)) {
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

void Calculus::execute() const {
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
    std::cout << "Enter the step number: ";
    std::cin >> this->step_number;
}

void Display::execute() const {
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

void TextFileInput::execute() const {
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

void CSVFileInput::execute() const {
    std::cout << "CSV File Input" << std::endl;
}

std::string CSVFileInput::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + description + " " + csv_file_input;
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

void Output::execute() const {
    std::cout << "Output" << std::endl;
}

std::string Output::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + std::to_string(step_number) + " " + file_name + " " + title + " " + description;
}

End::End() : FlowStep(END) {}

void End::execute() const {
    std::cout << "End" << std::endl;
}

std::string End::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string;
}

