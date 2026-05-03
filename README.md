# 🎓 CGPA Calculator - CodeAlpha C++ Internship

Welcome to my first project as part of the **CodeAlpha C++ Programming Internship**. This project is a practical implementation of fundamental programming concepts to solve a real-world academic challenge: calculating the Cumulative Grade Point Average (CGPA)[cite: 2].

## 📝 About the Project
The **CGPA Calculator** is a console-based application designed to help students track their academic performance accurately[cite: 2]. Instead of manual calculations, this tool automates the process by considering the specific weight of each course based on its credit hours[cite: 2].

### Key Features:
*   **Dynamic Course Management:** Enter any number of courses taken during the semester[cite: 2].
*   **Weighted Calculations:** Computes the GPA based on the formula: `(Grade * Credit Hours) / Total Credits`[cite: 2].
*   **Formatted Academic Report:** Generates a clean, tabular summary of all courses and the final result[cite: 2].

## 🛠️ Technical Stack
*   **Language:** C++
*   **Data Structures:** Used `struct` for data modeling and `std::vector` for dynamic memory management[cite: 2].
*   **Formatting:** Leveraged the `<iomanip>` library to create a professional UI in the terminal.
*   **Best Practices:** Implemented **Object-Oriented Programming (OOP)** principles for better code organization and scalability.

## 🏗️ How it Works
1.  **Input Phase:** The program asks for the total number of courses[cite: 2].
2.  **Data Collection:** For each course, the user provides the name, grade points, and credit hours[cite: 2].
3.  **Processing:** The logic iterates through the stored data to calculate the total points and total credits[cite: 2].
4.  **Output:** A detailed report is displayed with the final CGPA rounded to two decimal places[cite: 2].

## 🚀 Getting Started
If you are running this on Linux (like my **Debian** setup), follow these steps:

1. Clone the repository:
   ```bash
   git clone [https://github.com/AR505/CodeAlpha_CGPACalculator.git](https://github.com/AR505/CodeAlpha_CGPACalculator.git)
