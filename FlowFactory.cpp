//
// Created by Sebastian Nae on 11.01.2024.
//

#include "FlowFactory.h"

FlowStep *FlowFactory::createStep(StepType stepType, std::vector<std::string> args) {
    switch (stepType) {
        case TITLE:
            return create<Title>(args);
        case TEXT:
            return create<Text>(args);
        case TEXT_INPUT:
            return create<TextInput>(args);
        case NUMBER_INPUT:
            return create<NumberInput>(args);
        case CALCULUS:
            return create<Calculus>(args);
        case DISPLAY:
            return create<Display>(args);
        case TEXT_FILE_INPUT:
            return create<TextFileInput>(args);
        case CSV_FILE_INPUT:
            return create<CSVFileInput>(args);
        case OUTPUT:
            return create<Output>(args);
        case END:
            return create<End>();
        default:
            return nullptr;
    }
}
