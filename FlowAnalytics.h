//
// Created by Sebastian Nae on 12.01.2024.
//

#ifndef PRJ_FLOWANALYTICS_H
#define PRJ_FLOWANALYTICS_H
#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
class FlowAnalytics {
private:
    struct FlowStats{
        int completedCount = 0;
        int startedCount = 0;
        std::unordered_map<std::string, int> screenSkipCount;
        std::unordered_map<std::string, int> errorScreenCount;
    };
    std::unordered_map<std::string, FlowStats> flowStats;
public:
    void flowStarted(const std::string& flowName);
    void flowCompleted(const std::string& flowName);
    void screenSkipped(const std::string& flowName, std::string screenName);
    void errorScreen(const std::string& flowName, const std::string& screenName);
    void showStats(const std::string& flowName);
    void load(const std::string& filename = "analytics.csv");
    void save(const std::string& filename = "analytics.csv");
    std::unordered_map<std::string, FlowStats> getFlowStats() const {
        return flowStats;
    }
};


#endif //PRJ_FLOWANALYTICS_H
