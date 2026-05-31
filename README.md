# Library Management System

## 📚 Short Introduction

The Library Management System is a console-based project developed in the C programming language to manage basic library operations efficiently.  
It allows users and administrators to perform tasks such as book management, user authentication, issuing books, and returning books using file handling concepts in C.

---

# 📑 Table of Contents

1. Project Overview  
2. Features  
3. Technologies Used  
4. Project Files  
5. Working Pipeline  
6. Functions Used  
7. How to Run  
8. Data Storage  
9. Future Improvements  
10. Contributors  

---

# 📚 Project Overview

This project is designed to automate the traditional library system using the C programming language.  
The system provides separate functionalities for users and administrators to manage books and user records effectively.

---

# ✨ Features

## User Features
- User Registration
- User Login Authentication
- View Available Books
- Issue Books
- Return Books
- Logout Functionality

## Admin Features
- Admin Login
- Add New Books
- Display All Books
- Manage Library Records

---

# 🛠 Technologies Used

- Programming Language: C
- Concepts Used:
  - Structures
  - File Handling
  - Functions
  - Conditional Statements
  - Loops
  - Authentication System
  - Binary File Operations

---

# 📂 Project Files

| File Name | Description |
|------------|-------------|
| `code.c` | Main source code of the Library Management System |
| `testcode.c` | Testing version of the project |
| `books.txt` | Stores book records |
| `users.txt` | Stores registered user data |

---

# 🔄 Working Pipeline of the Project

```text
Start Program
      ↓
Select User/Admin
      ↓
-------------------------
|                       |
User                  Admin
|                       |
Register/Login       Admin Login
|                       |
View Books           Add Books
Issue Book           Display Books
Return Book
|
Logout
      ↓
Exit Program
```

---

# ⚙ Functions Used in the Project

## Book Management
- `addBook()`
- `displayBooks()`
- `issueBook()`
- `returnBook()`

## User Management
- `registerUser()`
- `loginUser()`

## Admin Management
- `loginAdmin()`

## Utility Functions
- `exitingUser()`

---

# ▶ How to Run the Project

## Step 1: Compile the Program

```bash
gcc code.c -o library
```

## Step 2: Run the Program

```bash
./library
```

---

# 💾 Data Storage

The project uses file handling for permanent storage:
- `books.txt` → Stores book information
- `users.txt` → Stores user login information

---

# 🚀 Future Improvements

- GUI Interface
- Book Search Feature
- Fine Calculation System
- Database Integration
- Password Encryption
- Multi-user Access

---

# 👨‍💻 Contributors

This project has been developed by:

- Dhruv Yadav
- Nayan Patidar
- Pankaj Parmar
-Priyanshu KhedekarM

