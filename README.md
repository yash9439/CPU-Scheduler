# CPU Scheduler Simulator

This program simulates different CPU scheduling algorithms to demonstrate how they manage process execution and resource allocation.

## Features

- **Algorithms:**
    - First-Come, First-Served (FCFS)
    - Shortest-Job-First (SJF)
    - Priority Scheduling
    - Round Robin (RR)
- **Process Definition:**
    - Use pre-defined processes.
    - Introduce custom processes with:
        - Burst time (duration)
        - Priority 
- **Visual Simulation:** Provides a graphical representation of the scheduling process for SJF and Priority algorithms.
- **Performance Metrics:** Calculates and displays:
    - Average waiting time
    - Average turnaround time (for Round Robin)

## Project Structure

The project is organized into multiple files and folders:

- **headers:** Contains header files for function declarations and data structures.
    - `process.h`: Defines the `process` structure and related functions.
    - `schedulers.h`: Declares the scheduling algorithm functions.
    - `utils.h`: Declares utility functions like the menu, input prompts, etc.
- **src:** Contains the source code files.
    - `main.c`: The main program file handling user interaction and algorithm execution.
    - `process.c`: Implements functions related to process creation and management.
    - `utils/`: Contains utility function implementations.
        - `list_processes.c`:  Implements functions for displaying process lists.
    - `schedulers/`: Contains implementations of the CPU scheduling algorithms.
        - `fcfs.c`: Implements the FCFS algorithm.
        - `sjf.c`: Implements the SJF algorithm.
        - `priority.c`: Implements the Priority scheduling algorithm.
        - `round_robin.c`: Implements the Round Robin algorithm.

## How to Compile and Run

1. **Compile:**
   ```bash
   gcc -o cpu_scheduler src/*.c src/**/*.c -Iheaders/
   ```

2. **Run:**
   ```bash
   ./cpu_scheduler
   ```

## Usage

1. **Choose Process Definition:** Select whether to use pre-defined processes or create your own.
2. **Choose Scheduling Algorithm:** Select the algorithm you want to simulate.
3. **(Optional) Enter Quantum:** For Round Robin scheduling, specify the time quantum.
4. **View Results:** The program will display the scheduling order, waiting times, and other relevant metrics.
