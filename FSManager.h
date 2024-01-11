//
// Created by Sebastian Nae on 10.01.2024.
//

#ifndef PRJ_FSMANAGER_H
#define PRJ_FSMANAGER_H
#include "Flow.h"

class FSManager {
private:
    std::vector<Flow*> flows;
public:
    FSManager();
    void showFlows() const;
//    static void deleteFlow();
};


#endif //PRJ_FSMANAGER_H
