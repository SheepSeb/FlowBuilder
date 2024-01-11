#include <iostream>
#include "Flow.h"
#include "FSManager.h"

void showAvailableSteps() {
    std::cout << "Available Steps:" << std::endl;
    std::cout << "1. TITLE" << std::endl;
    std::cout << "2. TEXT" << std::endl;
    std::cout << "3. TEXT_INPUT" << std::endl;
    std::cout << "4. NUMBER_INPUT" << std::endl;
    std::cout << "5. CALCULUS" << std::endl;
    std::cout << "6. DISPLAY" << std::endl;
    std::cout << "7. TEXT_FILE_INPUT" << std::endl;
    std::cout << "8. CSV_FILE_INPUT" << std::endl;
    std::cout << "9. OUTPUT" << std::endl;
    std::cout << "10. END" << std::endl;
}

void createWorkflow() {
    std::cout << "Creating new workflow." << std::endl;
    Flow *flow = new Flow();
    while (true) {
        std::cout << "Available Steps:" << std::endl;
        std::cout << "1. TITLE" << std::endl;
        std::cout << "2. TEXT" << std::endl;
        std::cout << "3. TEXT_INPUT" << std::endl;
        std::cout << "4. NUMBER_INPUT" << std::endl;
        std::cout << "5. CALCULUS" << std::endl;
        std::cout << "6. DISPLAY" << std::endl;
        std::cout << "7. TEXT_FILE_INPUT" << std::endl;
        std::cout << "8. CSV_FILE_INPUT" << std::endl;
        std::cout << "9. OUTPUT" << std::endl;
        std::cout << "10. END" << std::endl;
        std::cout << "11. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid choice. Please try again !NON NUMERIC." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                flow->addStep(new Title());
                break;
                case 2:
                flow->addStep(new Text());
                break;
            case 3:
                flow->addStep(new TextInput());
                break;
            case 4:
                flow->addStep(new NumberInput());
                break;
            case 5:
                flow->addStep(new Calculus());
                break;
            case 6:
                flow->addStep(new Display());
                break;
            case 7:
                flow->addStep(new TextFileInput());
                break;
            case 8:
                flow->addStep(new CSVFileInput());
                break;
            case 9:
                flow->addStep(new Output());
                break;
            case 10:
                flow->addStep(new End());
                flow->save();
                std::cout << "Workflow saved successfully." << std::endl;
                std::cout << "End step reached. Exiting the workflow." << std::endl;
                return;
            case 11:
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

void showWorkflows(FSManager *fsManager) {
    std::cout << "Showing workflows." << std::endl;
    fsManager->showFlows();
}

int main() {
    auto *fsManager = new FSManager();

    while (true) {
        std::cout << "\nMain Menu:" << std::endl;
        std::cout << "1. Show Available Steps" << std::endl;
        std::cout << "2. Create New Workflow" << std::endl;
        std::cout << "3. Show Workflows" << std::endl;
        std::cout << "4. Show Analytics" << std::endl;
        std::cout << "5. Delete Workflows" << std::endl;
        std::cout << "6. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        // Check if the input is numeric
        if (std::cin.fail()) {
            std::cout << "Invalid choice. Please try again !NON NUMERIC." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        switch (choice) {
            case 1:
                showAvailableSteps();
                break;
            case 2:
                createWorkflow();
                break;
            case 3:
                showWorkflows(fsManager);
                break;
            case 4:
//                showAnalytics(workflows);
                break;
            case 5:
                break;
            case 6:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                // Clear the input buffer
                std::cin.clear();
        }
    }
    return 0;
}
