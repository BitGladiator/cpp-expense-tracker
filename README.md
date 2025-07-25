# 💰 C++ Expense Tracker with Flask Web Interface

A full-featured personal expense tracker built in C++ with a clean and modern web interface powered by Flask. Track, view, and manage your expenses with both CLI and browser-based access. Includes password protection, file-based persistence, and modular architecture.

---

## 📁 Project Structure

```

Expense Tracker/
├── build/                # Compiled C++ binaries
├── data/                 # Stored data (expenses, password)
│   ├── expenses.csv
│   └── password.txt
├── include/              # C++ header files
│   ├── Expense.h
│   ├── ExpenseManager.h
│   ├── FileHandler.h
│   ├── Menu.h
│   ├── PasswordManager.h
│   ├── picosha2/         # SHA-256 header-only hashing lib
│   └── picosha2.h
├── reports/              # Placeholder for future reporting features
├── src/                  # C++ source files
│   ├── Expense.cpp
│   ├── ExpenseManager.cpp
│   ├── FileHandler.cpp
│   ├── Menu.cpp
│   ├── PasswordManager.cpp
│   └── main.cpp
├── web/                  # Flask-based web interface
│   ├── app.py
│   ├── static/
│   │   └── style.css
│   └── templates/
│       ├── index.html
│       └── edit.html
├── venv/                 # Python virtual environment (excluded from Git)
├── makefile              # For building C++ project
├── requirements.txt      # Python dependencies
└── README.md

````

---

## ✨ Features

### ✅ C++ CLI Core
- Add, view, and delete expenses
- Password-protected login using SHA-256 hashing (via `picosha2`)
- File-based persistence in `expenses.csv`
- Menu-driven command-line interface

### 🌐 Flask Web Interface
- Add and edit expenses via web form
- View full expense history
- Minimal HTML/CSS for clean layout
- Flask routing for expense operations

---

## ⚙️ Build & Run

### 🔧 C++ (CLI)

1. **Compile the project**
   ```bash
   make


2. **Run the CLI app**

   ```bash
   ./build/expense_tracker
   ```

---

### 🌐 Flask Web App

> Python 3.10+ recommended

1. **Activate the virtual environment**

   ```bash
   source venv/bin/activate   # On Windows: venv\Scripts\activate
   ```

2. **Install Flask dependencies**

   ```bash
   pip install -r requirements.txt
   ```

3. **Start the Flask app**

   ```bash
   python web/app.py
   ```

4. **Open in browser**

   ```
   http://127.0.0.1:5000
   ```

---

## 🔒 Security

* Passwords are hashed and stored in `data/password.txt` using SHA-256
* C++ and Flask apps share the same CSV data source

---

## 📌 Dependencies

### C++

* Standard Template Library (STL)
* `picosha2` for SHA-256 password hashing (header-only)

### Python

* Flask
* (Optional) Pandas for advanced features

Install with:

```bash
pip install -r requirements.txt
```

---

## 🚀 Roadmap

* [ ] Add charts and expense summaries
* [ ] Add monthly report generation
* [ ] REST API for full-stack extension
* [ ] User authentication (multi-user support)
* [ ] Dark mode and responsive layout

---

## 👨‍💻 Author

Developed by [BitGladiator](https://github.com/BitGladiator)

---

## 📝 License

This project is licensed under the MIT License.
