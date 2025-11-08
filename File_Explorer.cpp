#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;
namespace fs = std::filesystem;

void logAction(string action) {
    ofstream log("activity_log.txt", ios::app);
    if (log.is_open()) {
        time_t now = time(0);
        char *dt = ctime(&now);
        string timeStr(dt);
        timeStr.pop_back();
        log << "[" << timeStr << "] " << action << endl;
    }
    log.close();
}

void listFiles() {
    cout << "\nFiles and Directories:\n";
    for (auto &entry : fs::directory_iterator(fs::current_path())) {
        if (entry.is_directory())
            cout << "[DIR] " << entry.path().filename().string() << endl;
        else
            cout << "      " << entry.path().filename().string() << endl;
    }
    logAction("Listed files in " + fs::current_path().string());
}

void changeDir(string folder) {
    try {
        fs::current_path(folder);
        cout << "Now in: " << fs::current_path() << endl;
        logAction("Changed directory to: " + fs::current_path().string());
    } catch (...) {
        cout << "Directory not found.\n";
        logAction("Failed to change directory: " + folder);
    }
}

void createFile(string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        cout << "File created: " << filename << endl;
        logAction("Created file: " + filename);
    } else {
        cout << "Error creating file.\n";
        logAction("Failed to create file: " + filename);
    }
    file.close();
}

void deleteFile(string filename) {
    if (fs::remove(filename)) {
        cout << "File deleted: " << filename << endl;
        logAction("Deleted file: " + filename);
    } else {
        cout << "File not found.\n";
        logAction("Failed to delete file: " + filename);
    }
}

void copyFile(string src, string dest) {
    try {
        fs::copy_file(src, dest, fs::copy_options::overwrite_existing);
        cout << "Copied " << src << " to " << dest << endl;
        logAction("Copied file from " + src + " to " + dest);
    } catch (...) {
        cout << "Error copying file.\n";
        logAction("Failed to copy " + src + " to " + dest);
    }
}

void searchFile(string key) {
    cout << "Search Results:\n";
    for (auto &entry : fs::recursive_directory_iterator(fs::current_path())) {
        if (entry.path().filename().string().find(key) != string::npos)
            cout << entry.path().string() << endl;
    }
    logAction("Searched for: " + key);
}

int main() {
    cout << "===== SMART LINUX FILE MANAGER =====\n";
    cout << "Current Directory: " << fs::current_path() << endl;
    logAction("Program started.");

    string cmd, arg1, arg2;

    while (true) {
        cout << "\n>>> ";
        getline(cin, cmd);

        stringstream ss(cmd);
        ss >> cmd >> arg1 >> arg2;

        if (cmd == "ls")
            listFiles();
        else if (cmd == "cd")
            changeDir(arg1.empty() ? "." : arg1);
        else if (cmd == "create")
            createFile(arg1);
        else if (cmd == "delete")
            deleteFile(arg1);
        else if (cmd == "copy")
            copyFile(arg1, arg2);
        else if (cmd == "search")
            searchFile(arg1);
        else if (cmd == "exit") {
            cout << "Goodbye!\n";
            logAction("Program exited.");
            break;
        } else {
            cout << "Invalid command.\n";
        }
    }

    return 0;
}
