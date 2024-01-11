//
// Created by Sebastian Nae on 11.01.2024.
//

#include "FileObserver.h"

FileObserver::FileObserver(const std::string &directoryPath, FSManager& manager, std::function<void(const std::string &)> callback) : fsManager(manager) {
    this->directoryPath = directoryPath;
    this->callback = callback;
    for (const auto &entry : fs::directory_iterator(directoryPath)) {
        files.push_back(entry.path());
    }
    fsManager = manager;
}

void FileObserver::update() {
    std::vector<std::string> newFiles;
    for (const auto &entry : fs::directory_iterator(directoryPath)) {
        const std::string &path = entry.path().string();
        if(entry.is_regular_file() && entry.path().extension() == ".flow"){
            newFiles.push_back(entry.path());
        }
    }
    std::sort(newFiles.begin(), newFiles.end());
    std::sort(files.begin(), files.end());
    std::vector<std::string> diff;
    std::set_difference(newFiles.begin(), newFiles.end(), files.begin(), files.end(),
                        std::inserter(diff, diff.begin()));
    for (const auto &file : diff) {
        callback(file);
    }
    files = newFiles;
    fsManager.loadFlows();
}

void FileSystemWatcher::attach(Observer *observer) {
    observers.push_back(observer);
}

void FileSystemWatcher::notify() {
    for (auto &observer : observers) {
        observer->update();
    }
}

void FileObserver::observeFiles() {
    while (true) {
        update();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}