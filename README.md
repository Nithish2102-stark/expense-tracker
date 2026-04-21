# Expense Tracker (C Program)

A simple and efficient command-line expense management system built in C. This project demonstrates core programming concepts like structures, pointers, dynamic memory allocation, and modular design while solving a real-world problem.

---

## 🚀 Features

* Add new expenses with ID, name, category, amount, and date
* Ensures **unique expense IDs**
* Displays all stored expenses
* Search expense by ID
* Update existing expense amounts
* Calculates:

  * Total expense
  * Average expense
  * Highest expense
* Dynamic memory handling using `malloc` and `realloc`

---

## 🛠️ Tech Stack

* Language: **C**
* Concepts Used:

  * Structures (`struct`)
  * Pointers
  * Dynamic Memory Allocation
  * Modular Functions
  * Input Validation

---

## 📂 Project Structure

```
Expense Tracker
│── main.c
```

---

## ▶️ How to Run

1. Compile the program:

   ```bash
   gcc main.c -o expense
   ```

2. Run the executable:

   ```bash
   ./expense
   ```

---

## 📋 Menu Options

```
1. Add Expense
2. Display All Expenses
3. Search Expense by ID
4. Update Expense Amount
5. Calculate Total Expense
6. Exit
```

---

## 📊 Example Use Case

* Track daily or startup-related expenses
* Analyze spending patterns
* Maintain simple financial records without external tools

---

## ⚠️ Limitations

* Data is not persistent (resets after program exit)
* No file/database storage
* Basic CLI interface

---

## 🔮 Future Improvements

* File handling for persistent storage
* Category-wise analytics
* Sorting and filtering
* UI-based version (GUI/Web)

---

## 🎯 Learning Outcome

This project helps in understanding how low-level programming can be used to manage structured data and perform meaningful computations efficiently.

---
