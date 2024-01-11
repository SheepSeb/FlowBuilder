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
    virtual void execute() = 0;
    virtual std::string toString() = 0;
    StepType getStepType() const {
        return stepType;
    }
    // Map stepType to string
    [[nodiscard]] std::string stepTypeToString() const {
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
    static int stringTostepType(const std::string& stringStepType){
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

    static StepType stringToStep(const std::string& stringStepType){
        if(stringStepType == "TITLE"){
            return TITLE;
        }else if(stringStepType == "TEXT"){
            return TEXT;
        }else if(stringStepType == "TEXT_INPUT"){
            return  TEXT_INPUT;
        }else if(stringStepType == "NUMBER_INPUT"){
            return NUMBER_INPUT;
        }else if(stringStepType == "CALCULUS"){
            return CALCULUS;
        }else if(stringStepType == "DISPLAY"){
            return DISPLAY;
        }else if(stringStepType == "TEXT_FILE_INPUT"){
            return TEXT_FILE_INPUT;
        }else if(stringStepType == "CSV_FILE_INPUT"){
            return CSV_FILE_INPUT;
        }else if(stringStepType == "OUTPUT"){
            return OUTPUT;
        }else if(stringStepType == "END"){
            return END;
        }
        return END;
    }
};

// Derived classes for each step - Title
class Title : public FlowStep {
private:
    std::string title;
    std::string subtitle;
public:
    Title();
    explicit Title(std::vector<std::string> args);
    void execute() override;
    std::string toString() override;
};

class Text : public FlowStep {
private:
    std::string title;
    std::string copy;
public:
    Text();
    Text(std::string title, std::string copy);
    explicit Text(std::vector<std::string> args);
    void execute() override;
    std::string toString() override;
};

class TextInput : public FlowStep {
private:
    std::string description;
    std::string text_input;
public:
    TextInput();
    explicit TextInput(std::string description);
    explicit TextInput(std::vector<std::string> args);
    void execute() override;
    std::string toString() override;
};

class NumberInput : public FlowStep {
private:
    std::string description;
    float number_input;
public:
    NumberInput();
    explicit NumberInput(std::string description);
    explicit NumberInput(std::vector<std::string> args);
    void execute() override;
    float get_number_input();
    std::string toString() override;
};

class Calculus : public FlowStep {
private:
    int number_of_steps;
    std::vector<float> steps;
    std::string calculus;
    float result;
public:
    Calculus();
    Calculus(int number_of_steps, std::vector<float> steps, std::string calculus);
    explicit Calculus(std::vector<std::string> args);
    void execute() override;
    std::vector<float> get_internal_steps();
    void set_internal_steps(std::vector<float> steps);
    float get_result();
    std::string toString() override;
};

class Display : public FlowStep {
private:
    int step_number{};
public:
    Display();
    explicit Display(int step_number);
    explicit Display(std::vector<std::string> args);
    void execute() override;
    std::string toString() override;
};

class TextFileInput : public FlowStep {
private:
    std::string description;
    std::string text_file_input;
public:
    TextFileInput();
    explicit TextFileInput(std::string description);
    explicit TextFileInput(std::vector<std::string> args);
    void execute() override;
    std::string toString() override;
};

class CSVFileInput : public FlowStep {
private:
    std::string description;
    std::string csv_file_input;
public:
    CSVFileInput();
    explicit CSVFileInput(std::string description);
    explicit CSVFileInput(std::vector<std::string> args);
    void execute() override;
    std::string toString() override;
};

class Output : public FlowStep {
private:
    int step_number;
    FlowStep *output_step;
    std::string file_name;
    std::string title;
    std::string description;
public:
    Output();
    explicit Output(std::vector<std::string> args);
    void execute() override;
    int get_step_number();
    void set_output_step(FlowStep* step);
    std::string toString() override;
};

class End : public FlowStep {
public:
    End();
    void execute() override;
    std::string toString() override;
};

#endif //PRJ_FLOWSTEP_H
