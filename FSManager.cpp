//
// Created by Sebastian Nae on 10.01.2024.
//

#include "FSManager.h"
#include <filesystem>
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
