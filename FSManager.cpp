//
// Created by Sebastian Nae on 10.01.2024.
//

#include "FSManager.h"
#include <filesystem>
#include <vector>
FSManager::FSManager() {
    // Load all flows from the file system into the flows vector
    namespace fs = std::filesystem;
    std::string extension = ".flow";
    try{
        for (const auto & entry : fs::directory_iterator( fs::current_path() ) ) {
            if (entry.path().extension() == extension) {
                flows.push_back(new Flow(entry.path().filename()));
            }
        }
        // Initialize the flow analytics
        flowAnalytics.load();
        flowAnalytics.showStats("default");
    } catch (std::exception& e) {
        std::cout << "Error opening file: " << e.what() << std::endl;
    }
}

void FSManager::showFlows() const {
    std::cout << &"Available flows:" [ flows.size()] << std::endl;
    for (auto &flow : flows) {
        std::cout << flow->getName() << std::endl;
    }
}

void FSManager::deleteFlow() {
    // Show all flows
    // Ask the user which flow to delete
    // Delete the flow
    int idx = 0;
    for (auto &flow: flows) {
        std::cout << idx << " " << flow->getName() << std::endl;
        idx++;
    }
    std::cout << "Enter the number of the flow to delete";
    std::cout << "Or input -1 to cancel: ";
    idx = 0;
    std::cin >> idx;
    // Check if the index is valid
    if (idx < 0 || idx >= flows.size()) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    std::cout << "Deleting flow " << flows[idx]->getName() << std::endl;
    std::string filename = flows[idx]->getName();
    // Delete from the vector
    flows.erase(std::remove(flows.begin(), flows.end(), flows[idx]), flows.end());
    std::cout << "Deleting file " << filename << std::endl;
    std::remove(filename.c_str());
    std::cout << "Deleted flow " << std::endl;
}

void FSManager::executeFlow() {
    // Show all flows
    // Ask the user which flow to execute
    // Execute the flow
    int idx = 0;
    for (auto &flow: flows) {
        std::cout << idx << " " << flow->getName() << std::endl;
        idx++;
    }
    std::cout << "Enter the number of the flow to execute";
    std::cout << "Or input -1 to cancel: ";
    idx = 0;
    std::cin >> idx;
    // Check if the index is valid
    if (idx < 0 || idx >= flows.size()) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    flowAnalytics.getFlowStats()[flows[idx]->getName()];
    flowAnalytics.flowStarted(flows[idx]->getName());
    flows[idx]->execute(this->flowAnalytics);
    flowAnalytics.flowCompleted(flows[idx]->getName());
}

void FSManager::loadFlows() {
    namespace fs = std::filesystem;
    std::string extension = ".flow";
    flows.clear();
    try{
        for (const auto & entry : fs::directory_iterator( fs::current_path() ) ) {
            if (entry.path().extension() == extension) {
                flows.push_back(new Flow(entry.path().filename()));
            }
        }
    } catch (std::exception& e) {
        std::cout << "Error opening file: " << e.what() << std::endl;
    }
}

void FSManager::showAnalytics() {
    for (auto &flow : flows) {
        std::cout << "Flow " << flow->getName() << std::endl;
        // Check if the flow has stats
        if (flowAnalytics.getFlowStats().find(flow->getName()) == flowAnalytics.getFlowStats().end()) {
            std::cout << "No stats available" << std::endl;
            continue;
        }else{
            flowAnalytics.showStats(flow->getName());
        }
    }
}
