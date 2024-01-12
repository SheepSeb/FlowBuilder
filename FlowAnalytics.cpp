//
// Created by Sebastian Nae on 12.01.2024.
//

#include "FlowAnalytics.h"

void FlowAnalytics::flowStarted(const std::string &flowName) {
    flowStats[flowName].startedCount++;
}

void FlowAnalytics::flowCompleted(const std::string &flowName) {
    flowStats[flowName].completedCount++;
}

void FlowAnalytics::screenSkipped(const std::string &flowName, const std::string screenName) {
    flowStats[flowName].screenSkipCount[screenName]++;
}

void FlowAnalytics::errorScreen(const std::string &flowName, const std::string &screenName) {
    flowStats[flowName].errorScreenCount[screenName]++;
}

void FlowAnalytics::showStats(const std::string& flowName) {
    const FlowStats& stats = flowStats.at(flowName);
    std::cout << "Flow " << flowName << " stats:" << std::endl;
    std::cout << "Started: " << stats.startedCount << std::endl;
    std::cout << "Completed: " << stats.completedCount << std::endl;
    std::cout << "Skipped screens: " << std::endl;
    for (auto &screen : stats.screenSkipCount) {
        std::cout << "Screen " << screen.first << " skipped " << screen.second << " times" << std::endl;
    }
    std::cout << "Error screens: " << std::endl;
    for (auto &screen : stats.errorScreenCount) {
        std::cout << "Screen " << screen.first << " shown " << screen.second << " times" << std::endl;
    }
    // Calculate and display average errors per flow completed
    if (stats.completedCount > 0) {
        std::cout << "Average errors per flow completed: " << std::endl;
        for (auto &screen : stats.errorScreenCount) {
            std::cout << "Screen " << screen.first << " shown " << std::setprecision(2) << (float)screen.second / stats.completedCount << " times" << std::endl;
        }
    }
    else {
        std::cout << "N/A" << std::endl;
    }
}

void FlowAnalytics::save(const std::string &filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file " << filename << std::endl;
        return;
    }
    for (auto &flow : flowStats) {
        file << flow.first << "," << flow.second.startedCount << "," << flow.second.completedCount;
        for (auto &screen : flow.second.screenSkipCount) {
            file << "," << screen.first << "," << screen.second;
        }
        for (auto &screen : flow.second.errorScreenCount) {
            file << "," << screen.first << "," << screen.second;
        }
        file << std::endl;
    }
    file.close();
}

void FlowAnalytics::load(const std::string &filename){
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file " << filename << std::endl;
        return;
    }else{
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string flowName;
            std::string startedCount;
            std::string completedCount;
            std::string screenName;
            std::string screenSkipCount;
            std::string errorScreenName;
            std::string errorScreenCount;
            std::getline(ss, flowName, ',');
            std::getline(ss, startedCount, ',');
            std::getline(ss, completedCount, ',');
            flowStats[flowName].startedCount = std::stoi(startedCount);
            flowStats[flowName].completedCount = std::stoi(completedCount);
            while (std::getline(ss, screenName, ',')) {
                std::getline(ss, screenSkipCount, ',');
                flowStats[flowName].screenSkipCount[screenName] = std::stoi(screenSkipCount);
            }
            while (std::getline(ss, errorScreenName, ',')) {
                std::getline(ss, errorScreenCount, ',');
                flowStats[flowName].errorScreenCount[errorScreenName] = std::stoi(errorScreenCount);
            }
        }
        file.close();
    }
}