//
// Created by Sebastian Nae on 11.01.2024.
//

#ifndef PRJ_FILEOBSERVER_H
#define PRJ_FILEOBSERVER_H

#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <functional>
#include <algorithm>
#include "FSManager.h"

namespace fs = std::filesystem;
class Observer{
public:
    virtual void update() = 0;
};

class FileObserver : public Observer{
private:
    std::vector<std::string> files;
    std::function<void(const std::string&)> callback;
    std::string directoryPath;
    FSManager& fsManager;
public:
    FileObserver(const std::string &directoryPath, FSManager& manager, std::function<void(const std::string&)> callback);
    void update() override;
    void observeFiles();
    bool termianteThread = false;
};

class FileSystemWatcher{
private:
    std::vector<Observer*> observers;
public:
    void attach(Observer* observer);
    void notify();
};

#endif //PRJ_FILEOBSERVER_H
