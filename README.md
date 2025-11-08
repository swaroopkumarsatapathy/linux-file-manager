# 🧭 Smart Linux File Explorer with Activity Logger

A terminal-based File Explorer developed in **C++17**, enhanced with a **logging feature** that records every user action such as file creation, deletion, copy, search, and directory navigation.  
The project demonstrates system-level programming in Linux using the modern `<filesystem>` library.

---

## 🚀 Features

- 📂 List files and directories  
- 🔁 Change directories  
- ✨ Create new files  
- ❌ Delete existing files  
- 📑 Copy files  
- 🔍 Search files by name  
- 🧾 **Activity Logger**: Automatically records every operation in `activity_log.txt` with timestamps  

---

## ⚙️ Setup and Execution

### 1. Clone the Repository
```bash
git clone https://github.com/<your-username>/linux-file-manager.git
cd linux-file-explorer


---

🧰 Tech Stack
Component	Description
Language	C++ (C++17)
Libraries	<filesystem>, <fstream>, <sstream>, <ctime>
Platform	Linux / Ubuntu / macOS (M2 Compatible)
IDE	Visual Studio Code / g++
Version Control	Git & GitHub

---

## 🚀 How to Run

```bash
compile the code 
g++ file_explorer.cpp -o explorer -lstdc++fs
Run the Application
./explorer



🔮 Future Enhancements
Add folder creation and deletion commands (mkdir, rmdir)
Introduce a menu-based interface
Implement file compression (.zip/.tar)
Develop GUI using Qt framework
Real-time activity viewer

linux-file-explorer/
│
├── file_explorer.cpp      # Main Source Code
├── activity_log.txt       # Generated Log File
└── README.md

            # Documentation
Project Design
Architecture Overview
The project follows a simple modular design:
User Interface Layer: Handles terminal-based user interaction and command input.
Core Logic Layer: Interprets commands and calls respective file handling functions.
Logging Module: Records every user action with timestamps for audit purposes.

Flow of Execution

Start Program
   ↓
Display Current Directory
   ↓
User Enters Command
   ↓
Command Parsed (using stringstream)
   ↓
Perform Operation (list, create, delete, etc.)
   ↓
Log Activity into activity_log.txt
   ↓
Display Result to User
   ↓
Repeat Until Exit


