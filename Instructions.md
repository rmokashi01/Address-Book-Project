Address Book

```markdown
# 📒 Address Book in C

A simple, interactive command-line **Address Book** application in C that allows users to **create**, **search**, **edit**, **delete**, and **list** contacts. The contacts are stored in a CSV file for persistent storage.

## 📂 Project Structure

```

.
├── contact.c         # Core logic for managing contacts (create, edit, delete, etc.)
├── contact.h         # Declarations for contact functions and data structures
├── file.c            # File I/O operations (load/save contacts to CSV)
├── file.h            # Declarations for file operations
├── main.c            # Entry point with menu-driven interface
├── contacts.csv      # Storage file (auto-created if not present)

````


## 🔧 Features

- Add new contacts with **validation**:
  - Name input
  - 10-digit phone number (unique & numeric)
  - Valid lowercase email (must contain `@` and end with `.com`)
- Search contacts by:
  - Name (partial match, case-insensitive)
  - Phone (exact match)
  - Email (partial match, case-insensitive)
- Edit contact fields with re-validation
- Delete contacts with confirmation
- Persistent storage using `contacts.csv`


## 🏁 How to Compile & Run

### 📌 Compile:
```bash
gcc main.c contact.c file.c -o addressbook
````

### ▶️ Run:

```bash
./addressbook
```

---

## 📥 Sample Menu

```
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice:
```

---

## 💾 Data Format (CSV)

Each line in `contacts.csv` contains:

```
Name,Phone,Email
```

Example:

```
John Doe,9876543210,john.doe@example.com
```

---

## 📌 Notes

* Max contacts supported: 100
* CSV safety is handled by replacing commas in names/emails with spaces
* Proper input buffer clearing is handled to avoid `scanf`/`fgets` conflicts

---

## 📁 Author

This project was developed as part of learning C programming and File I/O concepts. Feel free to modify or extend it for advanced features like sorting, exporting, or GUI integration.

---
