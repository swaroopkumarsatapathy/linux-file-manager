#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
using namespace std;
namespace fs = filesystem;

void listFiles() {
    cout << "\nFiles and Directories:\n";
    for (auto &entry : fs::directory_iterator(fs::current_path())) {
        if (entry.is_directory())
            cout << "[DIR]  " << entry.path().filename().string() << endl;
        else
            cout << "       " << entry.path().filename().string() << endl;
    }
}

void changeDirectory(string folder) {
    try {
        if (folder == "..")
            fs::current_path(fs::current_path().parent_path());
        else if (!folder.empty())
            fs::current_path(folder);
    } catch (...) {
        cout << "Directory not found.\n";
    }
}

void createFile(string name) {
    ofstream file(name);
    if (file)
        cout << "File created successfully.\n";
    else
        cout << "Error creating file.\n";
}

void deleteFile(string name) {
    if (fs::remove(name))
        cout << "File deleted successfully.\n";
    else
        cout << "Error deleting file.\n";
}

void copyFile(string src, string dest) {
    try {
        if (src.empty() || dest.empty()) {
            cout << "Usage: copy <source> <destination>\n";
            return;
        }
        fs::copy_file(src, dest, fs::copy_options::overwrite_existing);
        cout << "File copied successfully.\n";
    } catch (...) {
        cout << "Error copying file.\n";
    }
}

void searchFile(string keyword) {
    if (keyword.empty()) {
        cout << "Please enter a keyword.\n";
        return;
    }
    cout << "Search Results:\n";
    for (auto &entry : fs::recursive_directory_iterator(fs::current_path())) {
        if (entry.path().filename().string().find(keyword) != string::npos)
            cout << entry.path().string() << endl;
    }
}

int main() {
    cout << "SWAROOP KUMAR SATAPATHY\n";
    cout << "REGD NO. 2241019345\n";
    cout << "==============================\n";
    cout << "     LINUX FILE MANAGER\n";
    cout << "==============================\n";
    cout << "Current Directory: " << fs::current_path() << endl;

    string input, cmd, arg1, arg2;
    while (true) {
        cout << "\n>>> ";
        getline(cin, input);

        stringstream ss(input);
        ss >> cmd >> arg1 >> arg2;

        if (cmd == "ls")
            listFiles();
        else if (cmd == "cd")
            changeDirectory(arg1);
        else if (cmd == "create")
            createFile(arg1);
        else if (cmd == "delete")
            deleteFile(arg1);
        else if (cmd == "copy")
            copyFile(arg1, arg2);
        else if (cmd == "search")
            searchFile(arg1);
        else if (cmd == "exit")
            break;
        else
            cout << "Invalid command.\n";
    }
    return 0;
}
