//
// Created by Sebastian Nae on 10.01.2024.
//

#ifndef PRJ_FLOWSTEP_H
#define PRJ_FLOWSTEP_H
#include <string>
#include <iostream>
// Defined steps
enum StepType {
    TITLE,
    TEXT,
    TEXT_INPUT,
    NUMBER_INPUT,
    CALCULUS,
    DISPLAY,
    TEXT_FILE_INPUT,
    CSV_FILE_INPUT,
    OUTPUT,
    END
};

// Base class for all steps
class FlowStep {
public:
    StepType stepType;
    explicit FlowStep(StepType type) : stepType(type) {}
    virtual void execute() const = 0;
    virtual std::string toString() = 0;
    // Map stepType to string
    std::string stepTypeToString() const {
        switch (stepType) {
            case TITLE:
                return "TITLE";
            case TEXT:
                return "TEXT";
            case TEXT_INPUT:
                return "TEXT_INPUT";
            case NUMBER_INPUT:
                return "NUMBER_INPUT";
            case CALCULUS:
                return "CALCULUS";
            case DISPLAY:
                return "DISPLAY";
            case TEXT_FILE_INPUT:
                return "TEXT_FILE_INPUT";
            case CSV_FILE_INPUT:
                return "CSV_FILE_INPUT";
            case OUTPUT:
                return "OUTPUT";
            case END:
                return "END";
        }
    }
    int stringTostepType(const std::string& stringStepType){
        if(stringStepType == "TITLE"){
            return 1;
        }else if(stringStepType == "TEXT"){
            return 2;
        }else if(stringStepType == "TEXT_INPUT"){
            return 3;
        }else if(stringStepType == "NUMBER_INPUT"){
            return 4;
        }else if(stringStepType == "CALCULUS"){
            return 5;
        }else if(stringStepType == "DISPLAY"){
            return 6;
        }else if(stringStepType == "TEXT_FILE_INPUT"){
            return 7;
        }else if(stringStepType == "CSV_FILE_INPUT"){
            return 8;
        }else if(stringStepType == "OUTPUT"){
            return 9;
        }else if(stringStepType == "END"){
            return 10;
        }else{
            return 0;
        }
    }
};

// Derived classes for each step - Title
class Title : public FlowStep {
private:
    std::string title;
    std::string subtitle;
public:
    Title();
    Title(std::string title, std::string subtitle);
    void execute() const override;
    std::string toString() override;
};

class Text : public FlowStep {
private:
    std::string title;
    std::string copy;
public:
    Text();
    Text(std::string title, std::string copy);
    void execute() const override;
    std::string toString() override;
};

class TextInput : public FlowStep {
private:
    std::string description;
    std::string text_input;
public:
    TextInput();
    TextInput(std::string description);
    void execute() const override;
    std::string toString() override;
};

class NumberInput : public FlowStep {
private:
    std::string description;
    float number_input{};
public:
    NumberInput();
    NumberInput(std::string description);
    void execute() const override;
    std::string toString() override;
};

class Calculus : public FlowStep {
private:
    int number_of_steps;
    std::vector<int> steps;
    std::string calculus;
public:
    Calculus();
    Calculus(int number_of_steps, std::vector<int> steps, std::string calculus);
    void execute() const override;
    std::string toString() override;
};

class Display : public FlowStep {
private:
    int step_number{};
public:
    Display();
    explicit Display(int step_number);
    void execute() const override;
    std::string toString() override;
};

class TextFileInput : public FlowStep {
private:
    std::string description;
    std::string text_file_input;
public:
    TextFileInput();
    TextFileInput(std::string description);
    void execute() const override;
    std::string toString() override;
};

class CSVFileInput : public FlowStep {
private:
    std::string description;
    std::string csv_file_input;
public:
    CSVFileInput();
    CSVFileInput(std::string description);
    void execute() const override;
    std::string toString() override;
};

class Output : public FlowStep {
private:
    int step_number;
    std::string file_name;
    std::string title;
    std::string description;
public:
    Output();
    void execute() const override;
    std::string toString() override;
};

class End : public FlowStep {
public:
    End();
    void execute() const override;
    std::string toString() override;
};

#endif //PRJ_FLOWSTEP_H
