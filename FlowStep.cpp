//
// Created by Sebastian Nae on 10.01.2024.
//

#include "FlowStep.h"
#include <iostream>
#include <fstream>
#include <sstream>

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
    return stepType_string + " Title:" + title + " Subtitle:" + subtitle;
}

Title::Title(std::vector<std::string> args) : FlowStep(TITLE) {
    this->title = args[0];
    this->subtitle = args[1];
}

std::string Title::toWrite() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + title + " " + subtitle;
}

Text::Text(std::vector<std::string> args) : FlowStep(TEXT) {
    this->title = args[0];
    this->copy = args[1];
}

std::string Text::toWrite() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + title + " " + copy;
}

TextInput::TextInput(std::vector<std::string> args) : FlowStep(TEXT_INPUT) {
    this->description = args[0];
}

std::string TextInput::toWrite() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + description;
}

NumberInput::NumberInput(std::vector<std::string> args) : FlowStep(NUMBER_INPUT) {
    this->description = args[0];
}

std::string NumberInput::toWrite() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + description;
}

Calculus::Calculus(std::vector<std::string> args) : FlowStep(CALCULUS) {
    this->number_of_steps = std::stoi(args[0]);
    for (int i = 0; i < number_of_steps; ++i) {
        float num =  std::stof(args[i+1]);
        steps.push_back(num);
    }
    this->calculus = args[number_of_steps+1];
}

std::string Calculus::toWrite() {
    std::string stepType_string = FlowStep::stepTypeToString();
    std::string final = stepType_string + " " + std::to_string(number_of_steps);
    for (int i = 0; i < number_of_steps; ++i) {
        final += " " + std::to_string(steps[i]);
    }
    final += " " + calculus;
    return final;
}

Display::Display(std::vector<std::string> args) : FlowStep(DISPLAY) {
    this->step_number = std::stoi(args[0]);
}

std::string Display::toWrite() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + std::to_string(step_number);
}

TextFileInput::TextFileInput(std::vector<std::string> args) : FlowStep(TEXT_FILE_INPUT) {
    this->description = args[0];
}

std::string TextFileInput::toWrite() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + description;
}

CSVFileInput::CSVFileInput(std::vector<std::string> args) : FlowStep(CSV_FILE_INPUT) {
    this->description = args[0];
}

std::string CSVFileInput::toWrite() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + description;
}

Output::Output(std::vector<std::string> args) : FlowStep(OUTPUT) {
    this->step_number = std::stoi(args[0]);
    this->file_name = args[1];
    this->title = args[2];
    this->description = args[3];
}

std::string Output::toWrite() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " " + std::to_string(step_number) + " " + file_name + " " + title + " " + description;
}

std::string End::toWrite() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string;
}

Text::Text() : FlowStep(TEXT) {
    std::cout << "Enter the title: ";
    std::getline(std::cin >> std::ws, this->title);
    std::cout << "Enter the copy: ";
    std::getline(std::cin >> std::ws, this->copy);
}

std::string Text::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " Title:" + title + " Copy:" + copy;
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
}

std::string TextInput::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " Description:" + description;
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
}

void NumberInput::execute() {
    std::cout << "Number Input" << std::endl;
    std::cout << "Enter the number input: ";
    std::cin >> this->number_input;
}

std::string NumberInput::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " Description:" + description;
}

NumberInput::NumberInput(std::string description) : FlowStep(NUMBER_INPUT) {
    this->description = description;
}

Calculus::Calculus() : FlowStep(CALCULUS) {
    std::cout << "Enter the number of steps: ";
    std::cin >> this->number_of_steps;
    for (int i = 0; i < number_of_steps; ++i) {
        std::cout << "Enter step id" << i << ": ";
        float num;
        std::cin >> num;
        steps.push_back(num);
    }
    std::cout << "Enter the calculus: ";
    std::cin >> this->calculus;
}

std::vector<float> Calculus::get_internal_steps() {
    return steps;
}

void Calculus::set_internal_steps(std::vector<float> steps) {
    this->steps = steps;
}

float NumberInput::get_number_input() {
    return number_input;
}

void Calculus::execute() {
    std::cout << "Calculus" << std::endl;
    // Check what type of calculus it is
    if (calculus == "+") {
        // Sum all the steps
        this->result = 0;
        for (int i = 0; i < number_of_steps; ++i) {
            this->result += steps[i];
        }
        std::cout << "The result is: " << result << std::endl;
    } else if (calculus == "-") {
        // Subtract all the steps
        this->result = steps[0];
        for (int i = 1; i < number_of_steps; ++i) {
            this->result -= steps[i];
        }
        std::cout << "The result is: " << result << std::endl;
    } else if (calculus == "*") {
        // Product all the steps
        this->result = 1;
        for (int i = 0; i < number_of_steps; ++i) {
            this->result *= steps[i];
        }
        std::cout << "The result is: " << result << std::endl;
    } else if (calculus == "/") {
        // Divide all the steps
        this->result = steps[0];
        for (int i = 1; i < number_of_steps; ++i) {
            this->result /= steps[i];
        }
        std::cout << "The result is: " << result << std::endl;
    }
    else if (calculus == "min") {
        this->result = steps[0];
        for (int i = 1; i < number_of_steps; ++i) {
            if (steps[i] < result) {
                this->result = steps[i];
            }
        }
        std::cout << "The result is: " << result << std::endl;
    }
    else if (calculus == "max") {
        this->result= steps[0];
        for (int i = 1; i < number_of_steps; ++i) {
            if (steps[i] > result) {
                this->result = steps[i];
            }
        }
        std::cout << "The result is: " << result << std::endl;
    } else {
        std::cout << "Invalid calculus" << std::endl;
        this->result = 0;
    }
    this->result = result;
}

float Calculus::get_result() {
    return result;
}

std::string TextFileInput::get_text_file_input() {
    return text_file_input;
}

std::string CSVFileInput::get_csv_file_input() {
    return csv_file_input;
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

Calculus::Calculus(int number_of_steps, std::vector<float> steps, std::string calculus) : FlowStep(CALCULUS) {
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
    std::string file_name;
    // Check if the step is TEXT INPUT or CSV INPUT
    if (display_step->getStepType() == TEXT_FILE_INPUT) {
        TextFileInput *textInput = (TextFileInput *) display_step;
        file_name = textInput->get_text_file_input();
        // Read the file and print the content
        std::ifstream file;
        file.open(file_name);
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else if (display_step->getStepType() == CSV_FILE_INPUT) {
        CSVFileInput *csvFileInput = (CSVFileInput *) display_step;
        file_name = csvFileInput->get_csv_file_input();
        // Read the file and print the content
        std::ifstream file;
        file.open(file_name);
        std::vector<std::string> row;
        std::string line, word, temp;
        while (std::getline(file, line)) {
            row.clear();
            std::stringstream s(line);
            while (std::getline(s, word, ',')) {
                row.push_back(word);
            }
            for (int i = 0; i < row.size(); ++i) {
                std::cout << row[i] << " ";
            }
            std::cout << std::endl;
        }
        file.close();
    } else {
        std::cout << "Invalid step" << std::endl;
    }
}

std::string Display::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " step:" + std::to_string(step_number);
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
    std::cout << "Enter the filename: ";
    std::cin >> this->text_file_input;
    std::ifstream file;
    file.open(this->text_file_input);
    std::string line;
    while (std::getline(file, line)) {
        this->data += line;
    }
    file.close();
}

std::string TextFileInput::get_data() {
    return data;
}

std::string TextFileInput::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " Description" + description;
}

TextFileInput::TextFileInput(std::string description) : FlowStep(TEXT_FILE_INPUT) {
    this->description = description;
    std::cout << "Enter the filename: ";
    std::cin >> this->text_file_input;
    this->text_file_input += ".txt";
}

CSVFileInput::CSVFileInput() : FlowStep(CSV_FILE_INPUT) {
    std::cout << "Enter the description: ";
    std::cin >> this->description;
    std::cout << "Enter the filename: ";
    std::cin >> this->csv_file_input;
    this->csv_file_input += ".csv";
}

void CSVFileInput::execute() {
    std::cout << "CSV File Input" << std::endl;
    std::cout << "Enter the filename: ";
    std::cin >> this->csv_file_input;
    std::ifstream file;
    file.open(this->csv_file_input);
    std::vector<std::string> row;
    std::string line, word, temp;
    while (std::getline(file, line)) {
        row.clear();
        std::stringstream s(line);
        while (std::getline(s, word, ',')) {
            row.push_back(word);
        }
        for (int i = 0; i < row.size(); ++i) {
            this->data += row[i] + " ";
        }
        this->data += "\n";
    }
    file.close();
}

std::string CSVFileInput::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " Description:" + description;
}

std::string CSVFileInput::get_data() {
    return data;
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
    // Create a file with the name file_name
    std::ofstream file;
    // Mode append if the file already exists
    // And if you want to add multiple lines to it
    file.open(file_name, std::ios_base::app);
    file << this->title << std::endl;
    file << this->description << std::endl;
    file << output_step->toString() << std::endl;
    // Flush the buffer
    file.flush();
    file.close();
}

void Display::set_display_step(FlowStep *step) {
    this->display_step = step;
}

int Display::get_step_number() {
    return step_number;
}

int Output::get_step_number() {
    return step_number;
}

void Output::set_output_step(FlowStep *step) {
    this->output_step = step;
}

std::string Output::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string + " Step:" + std::to_string(step_number) + " File Name:" + file_name + " Title:" + title + " Description:" + description;
}

End::End() : FlowStep(END) {}

void End::execute() {
    std::cout << "End" << std::endl;
}

std::string End::toString() {
    std::string stepType_string = FlowStep::stepTypeToString();
    return stepType_string;
}

