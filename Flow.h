//
// Created by Sebastian Nae on 10.01.2024.
//

#ifndef PRJ_FLOW_H
#define PRJ_FLOW_H
#include "FlowStep.h"

class Flow {
private:
    std::string name;
    std::vector<FlowStep*> steps;
    std::time_t timestamp;
    std::string filename;
    FILE* fd;
public:
    Flow();
    explicit Flow(std::string filename);
    void addStep(FlowStep* step);
    void execute() const;
    void skipStep() const;
    void save() const;
    std::string getName() const;
};


#endif //PRJ_FLOW_H
