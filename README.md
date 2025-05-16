# Operating-System-Simulator

# 🖥️ Operating System Simulation in C++

This project is a comprehensive Operating System simulation developed in C++ that demonstrates the implementation of multitasking, process management, and resource handling through a modular process-based architecture. It simulates core functionalities typically managed by an OS using a set of 15+ individual executable programs.

## 🚀 Features

- 💻 Simulated OS Environment with multiple utilities
- 🧵 Thread-based execution for the main process
- 🗂️ Process management for:
  - Calculator
  - Calendar
  - Clock
  - File operations: Create, Delete, Move, Copy, Rename
  - File properties viewer
  - Games: Tic-Tac-Toe, Rock-Paper-Scissors
  - Notepad
  - Media: Music Player, Video Player
  - Tower of Hanoi visualization
- 🛠️ Modular codebase with each task as a separate `.cpp` file
- 📄 Batch compilation script for building all modules

## 🧠 Purpose

This simulation was developed as a final project for the Operating Systems Lab (Spring 2025). It aims to provide practical exposure to:
- Multitasking and threading
- Process creation and control
- System calls simulation in user space
- OS-level utility replication

## 🧾 Structure

- `AllRun.cpp`: Compiles all task modules
- `main.cpp`: Entry point using `pthread` for multitasking
- `*.cpp`: Each representing a separate user-level process
- `a.out`, `*.o`, and other binaries: Generated executables

## 🛠️ Technologies Used

- Language: C++
- Compiler: `g++` with POSIX threads
- OS: Linux-based for thread and system-level command compatibility

## 📷 Screenshots / Demo (Optional)
![image](https://github.com/user-attachments/assets/8a3b792f-98ed-4b96-8e5f-6848383220ae)


## 🧑‍💻 Contributors

- **Asad Asghar** – B.S. Computer Science
- **Alisha** - B.S. Computer Science

## 📄 License

This project is for academic purposes. Free to use and modify with attribution.

---
