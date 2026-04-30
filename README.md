# Producer-Consumer (POSIX Threads)

This project implements a multi-threaded solution to the classic **Producer-Consumer Problem** using the POSIX Threads (`pthreads`) library. It was developed as part of the **Operating Systems course** at the Federal University of Ceará (UFC) - Quixadá Campus.

The system simulates a **centralized retail cashier manager**, where multiple producers (representing cashiers/sales) and consumers (representing processing units) coordinate access to a shared circular buffer.

---

## 🚀 Overview

The simulation handles synchronization between multiple threads to ensure data integrity and avoid race conditions.

It utilizes:

- **Semaphores** → Manage buffer empty/full slots  
- **Mutexes** → Protect critical sections (shared buffer and global counters)  
- **Condition Variables** → Coordinate the termination sequence between producers and consumers  

---

## 🛠️ Technical Stack

- **Language:** C  
- **Standard:** POSIX Threads (`pthreads`)  
- **Build System:** GCC / Makefile  

---

## 🏗️ Architecture

The project is divided into modular components for better organization:

- **prodcon.h:** Global definitions, shared variables, and synchronization primitives.

- **produtor.c:** Logic for generating items and inserting them into the buffer.

- **consumidor.c:** Logic for removing items, calculating averages, and handling the shutdown signal.

- **main.c:** Entry point responsible for initializing resources and managing the thread lifecycle


---

## 🔧 How to Run

### Clone the repository

```bash
git clone https://github.com/GuilhermeMarques18/Producer-Consumer-Posix.git
cd Producer-Consumer-Posix/Produto_Consumidor
```

### Compile the project

```bash
gcc main.c produtor.c consumidor.c -o prodcon -lpthread
```

Or simply run:

```bash
make
```

Execute

```bash
Execute
```

## 📝 Problem Constraints

- **Buffer Size:** 5 items  
- **Producers:** 6 threads  
- **Consumers:** 2 threads  
- **Production:** Each producer generates 20 items  

---

## 🧠 Concepts Covered

- Thread creation and management  
- Synchronization using mutexes and semaphores  
- Inter-thread communication  
- Circular buffer implementation  
- Deadlock and race condition avoidance  

---

## 📌 Notes

- Designed for academic purposes  
- Focused on clarity and correct synchronization rather than performance optimization  

---

## 👤 Author

**Guilherme Marques Ramos de Souza**  
Software Engineering Student at UFC - Quixadá Campus  
