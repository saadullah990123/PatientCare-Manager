# 🏥 PatientCare-Manager

A console-based **Patient & Medicine Tracking System** built in **C++** using Object-Oriented Programming principles.

<p align="center">
  <img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++" />
  <img src="https://img.shields.io/badge/OOP-Concepts-blue?style=for-the-badge" alt="OOP" />
</p>

<p align="center">
  <img src="https://img.shields.io/github/stars/saadullah990123/PatientCare-Manager?style=flat-square" alt="Stars" />
  <img src="https://img.shields.io/github/forks/saadullah990123/PatientCare-Manager?style=flat-square" alt="Forks" />
  <img src="https://img.shields.io/github/issues/saadullah990123/PatientCare-Manager?style=flat-square" alt="Issues" />
  <img src="https://img.shields.io/github/license/saadullah990123/PatientCare-Manager?style=flat-square" alt="License" />
</p>

---

## 📖 Overview

**PatientCare-Manager** is a command-line application written in C++ that helps track patient information and medication schedules. The project is built around core **Object-Oriented Programming (OOP)** concepts — classes, encapsulation, and structured data handling — making it a clean example of applying OOP fundamentals to a real-world style problem.

## ✨ Features

- 👤 **Patient Records Management** — Add, view, and manage patient details
- 💊 **Medicine Tracking** — Keep track of medicines assigned to patients
- 🧱 **OOP Design** — Built using classes with public/private access specifiers for clean encapsulation
- 🖥️ **Console-Based Interface** — Simple, lightweight, and dependency-free
- ⚙️ **Precompiled Executable Included** — Run it instantly on Windows via `medicaretracker.exe`

## 🛠️ Built With

- **C++** — Core language
- **Object-Oriented Programming (OOP)** — Classes, encapsulation, and modular design
- Standard C++ Library (`<iostream>`, etc.)

## 📂 Project Structure

```
PatientCare-Manager/
├── medicaretracker.cpp      # Main source file — all program logic and classes
├── medicaretracker.exe        # Precompiled Windows executable
├── README.md
└── status                      # Project/build notes
```

> ℹ️ Rename `tatus` to `status` (or whatever it's meant to be) if that was a typo when the file was created — update this section to match.

## 🚀 Getting Started

### Prerequisites

- A C++ compiler (e.g. **g++**, **MinGW**, or **MSVC**) if you want to build from source
- Or simply run the included `medicaretracker.exe` on Windows

### Option 1: Run the Precompiled Executable (Windows)

```bash
./medicaretracker.exe
```

### Option 2: Compile from Source

1. **Clone the repository**
   ```bash
   git clone https://github.com/saadullah990123/PatientCare-Manager.git
   cd PatientCare-Manager
   ```

2. **Compile the program**
   ```bash
   g++ medicaretracker.cpp -o medicaretracker
   ```

3. **Run it**
   ```bash
   ./medicaretracker        # Linux/macOS
   medicaretracker.exe      # Windows
   ```

## 🖥️ Usage

Once running, follow the on-screen console menu to:

1. Add a new patient record
2. View existing patient/medicine details
3. Update or manage medicine tracking info
4. Exit the program

> ℹ️ Update this list with your program's actual menu options once confirmed.

## 🧱 Code Structure (OOP Design)

The program is organized around C++ classes with clear separation between:

- **Private members** — internal data (e.g. patient details, medicine info) protected from direct outside access
- **Public members** — methods exposed to interact with the class (add, display, update records)

This keeps the data encapsulated and the program easy to extend with new features (e.g. additional patient fields, medicine categories, or file storage).

## 🗺️ Roadmap

- [ ] Add file-based persistence (save/load patient records)
- [ ] Add search/filter functionality
- [ ] Add input validation and error handling
- [ ] Add a simple text-based menu with better formatting

## 🤝 Contributing

Contributions, issues, and feature requests are welcome!

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.

## 👤 Author

**Saadullah**
- GitHub: [@saadullah990123](https://github.com/saadullah990123)

## ⭐ Show Your Support

If you found this project helpful, give it a ⭐ on GitHub!
