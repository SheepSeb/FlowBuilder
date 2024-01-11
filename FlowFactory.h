//
// Created by Sebastian Nae on 11.01.2024.
//

#ifndef PRJ_FLOWFACTORY_H
#define PRJ_FLOWFACTORY_H
#include "Flow.h"
#include "FlowStep.h"

class FlowFactory {
public:
    template <typename T, typename... args>
    static T* create(args&&... arg){
        return new T(std::forward<args>(arg)...);
    }
    static FlowStep* createStep(StepType stepType, std::vector<std::string> args);
};


#endif //PRJ_FLOWFACTORY_H
