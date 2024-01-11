//
// Created by Sebastian Nae on 10.01.2024.
//

#include <fstream>
#include <ctime>
#include <sstream>
#include "Flow.h"

void Flow::addStep(FlowStep *step) {
    // Show workflow till now
    std::cout<< "Current workflow:" << std::endl;
    for (auto &step : steps) {
        std::cout << step->stepType << std::endl;
    }
    std::cout<< "Current number: "<<steps.size()<<std::endl;
    std::cout << "Adding step " << step->stepType<< std::endl;
    steps.push_back(step);

}

Flow::Flow() {
    timestamp = std::time(nullptr);
    std::string basicString;
    std::cout << "Enter the basicString of the flow: ";
    std::cin >> basicString;
    filename = basicString + ".flow";
    try {
        fd = fopen(filename.c_str(), "w");
        // the timestamp should be human readable
        // e.g. 10.01.2024 12:00:00
        std::string timestampString = std::asctime(std::localtime(&timestamp));
        fprintf(fd, "timestamp: %s\n", timestampString.c_str());
        std::cout << "Flow created successfully." << std::endl;
        this->name = basicString;
    } catch (std::exception& e) {
        std::cout << "Error opening file: " << e.what() << std::endl;
    }
}

std::string Flow::getName() const {
    return name;
}

void Flow::save() const {
    std::cout << "Saving flow to file " << filename << std::endl;
    for (auto &step : steps) {
        fprintf(fd, "%s\n", step->toString().c_str());
    }
    fclose(fd);
}

Flow::Flow(std::string filename) {
    // Open the file
    // Read the file line by line
    // Create the steps
    // Add the steps to the steps vector
    // Close the file
    std::cout << "Loading flow from file " << filename << std::endl;
    std::string true_name = filename.substr(0, filename.find(".flow"));
    this->filename = true_name;
    try {
        std::ifstream file(filename);
        std::string line;
        int idx = 0;
        // While not EOF
        while(getline(file,line)){
            if (idx == 0) {
                // First line is the timestamp from 11 to end of line
                std::string timestamp_string = line.substr(11);
                std::cout << "Timestamp: " << line.substr(11) << std::endl;
                // Convert the timestamp_string to time_t
                std::tm time_struct = {};
                std::istringstream dateStream(timestamp_string);
                dateStream >> std::get_time(&time_struct, "%a %b %d %H:%M:%S %Y");
                std::time_t time_value = mktime(&time_struct);
                std::cout << "Timestamp: " << time_value << std::endl;
                this->timestamp = time_value;
            }
            else if (idx > 1) {
                // Create the step
                // Add the step to the steps vector
                std::cout << "Step: " << line << std::endl;
                // Split the line by space
                std::istringstream iss(line);
                std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                                 std::istream_iterator<std::string>());
                std::string stepType = results[0];
                std::cout<< "Step type: " << stepType << std::endl;
            }
            idx++;
        }
    }
    catch (std::exception& e) {
        std::cout << "Error opening file: " << e.what() << std::endl;
    }
}
