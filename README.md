# Greemines ATM - Banking System CLI

A terminal-based Banking Management System implemented in C++ that simulates real-world ATM operations. The application handles user accounts dynamically through local file storage, featuring masked password inputs, custom terminal styling, input validation, and simulated two-factor authentication (OTP).

---

## 🚀 Features

* **Visual ASCII Interface:** Clean, bordered console user interfaces for a structured terminal experience, including customized console text/background coloring.
* **Dynamic Account Creation:** Automatically generates a local database file named after the user's chosen username to keep persistent data tracking.
* **Masked PIN Typing:** Leverages `conio.h` to listen for real-time keystrokes, masking your 4-digit security PIN behind asterisks (`****`) during creation.
* **Simulated Two-Factor Authentication (OTP):** Enhances deposit security by prompting a simulated 4-digit mobile OTP verification code (`1234`) with a maximum of 3 entry attempts.
* **Core ATM Operations:**
  * **Balance Inquiry:** Fetch current balances dynamically parsed from text storage.
  * **Secure Cash Withdrawal:** Prevents negative withdrawals and blocks attempts exceeding the current balance limit.
  * **Secure Cash Deposit:** Appends newly deposited cash after a successful OTP confirmation.
  * **PIN Amendment:** Verifies old credentials before updating account parameters with a secondary confirmation step.
* **Robust Input Validation:** Extensively uses stream manipulation (`cin.clear()` and `cin.ignore()`) to capture runtime type mismatches (e.g., strings input where integers are expected), preventing terminal infinite loops.

---

## 🛠️ Technical Overview & Concepts

* **Language:** C++
* **File I/O Streams (`<fstream>`):** Handled using `ofstream` and `ifstream` to write, parse, and continually rewrite persistent banking file variables.
* **String Processing (`<sstream>`):** Uses `stringstream` parsing mechanics to translate file-based balances back into functional arithmetic integer units (`intbalance`).
* **Input Interception:** Employs `_getch()` from `<conio.h>` to read keyboard inputs directly for advanced UI handling.

---

## 📂 File Architecture Structure

When a user registers an account, the program dynamically generates a clean data structure mapped line-by-line within a file named exactly after their **Username**:

```text
[Your_Username] (File Name)
├── Line 1: Saved 4-Digit Security PIN
└── Line 2: Account Balance String (e.g., 5000.Rs)
