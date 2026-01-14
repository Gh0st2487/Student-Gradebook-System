# Student Gradebook System

The **Student Gradebook System** is a **C++ console-based application** developed as part of a **Data Structures course project**. The project focuses on applying core data structure concepts such as **hash tables**, **stacks**, and **maps** to manage student academic records efficiently.

This system emphasizes **data storage, retrieval, and manipulation using data structures**, combined with basic C++ classes for organization.

---

## 🎯 Project Objective

The main objective of this project is to demonstrate how **data structures** can be used to:

* Store and manage student records
* Perform fast searching using hashing
* Handle delete and undo operations using stacks
* Maintain attendance records using associative containers
* Calculate GPA and class averages efficiently

This project was implemented as part of a **Data Structures & Algorithms** course project.

---

## 🧠 Data Structures Used

* **Hash Table (Array + Hash Function)**
  Used to store student records and enable fast search by student name.

* **Stack**
  Used to implement **undo delete functionality**, allowing recovery of recently deleted records.

* **Map (STL)**
  Used to store **attendance records**, mapping dates to present/absent status.

* **Arrays**
  Used for storing grades for multiple courses.

---

## ✨ Features

✔️ Insert student data (name, ID, grades)
✔️ Calculate individual GPA automatically
✔️ Search student records using hashing
✔️ Display all student records
✔️ Mark and display attendance by date
✔️ Delete student records
✔️ Undo delete operation using stack
✔️ Calculate average GPA of the class
✔️ Admin login system using file handling

---

## 🔐 Admin Authentication

* Admin credentials are stored in **text files**
* Login is required before accessing the system
* Basic file handling (`fstream`) is used for authentication

---

## ⚙️ How the System Works

1. Admin logs in using stored credentials
2. A menu-driven interface allows interaction with the system
3. Student data is inserted into a hash table
4. GPA is calculated based on letter grades
5. Attendance is recorded using date-based mapping
6. Deleted records can be restored using stack-based undo

---

## 🚀 How to Run

1. **Clone the repository**

   ```bash
   git clone https://github.com/Gh0st2487/Student-Gradebook-System.git
   ```

2. **Open the project** in any C++ IDE (Code::Blocks, Dev-C++, Visual Studio, etc.)

3. **Compile and run** the program

4. **Login as admin** and use the menu options

---

## 📚 Learning Outcomes

Through this project, you will gain experience in:

* Implementing **hashing techniques**
* Using **stack-based undo operations**
* Applying **STL containers (map, stack)**
* Designing menu-driven console applications
* Managing files using `fstream`
* Applying data structures in a real-world inspired scenario

---

## 📌 Notes

* This is an **academic Data Structures project**
* No GUI or database is used
* Focus is on logic, efficiency, and correct use of data structures
* The system can be extended with:

  * Collision handling improvements
  * Dynamic resizing
  * Database integration
  * GUI interface
