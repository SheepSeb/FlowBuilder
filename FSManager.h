//
// Created by Sebastian Nae on 10.01.2024.
//

#ifndef PRJ_FSMANAGER_H
#define PRJ_FSMANAGER_H
#include "Flow.h"
#include <vector>
#include "FlowAnalytics.h"
class FSManager {
private:
    std::vector<Flow*> flows;
    FlowAnalytics flowAnalytics;
public:
    FSManager();
    void showFlows() const;
    void deleteFlow();
    void executeFlow();
    void loadFlows();
    void showAnalytics();
};


#endif //PRJ_FSMANAGER_H
