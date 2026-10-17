# 🍽️ Restaurant Management System

A **C-based console application** for managing restaurants and their menus.

This project was developed as an academic project focused on **algorithms and data structures**, with particular emphasis on **doubly linked lists, pointers, and dynamic memory allocation**.

> **Note:** The application's console interface is in French.

## 🎯 Objectives

- Dynamically manage a list of restaurants.
- Manage the menu associated with each restaurant.
- Implement and manipulate doubly linked lists.
- Practice dynamic memory allocation and memory management.
- Implement search, sorting, modification, insertion, and deletion operations.
- Generate statistics based on menu categories.

## ⚙️ Features

### Restaurant Management

- Add a new restaurant with its name, address, specialty, and rating.
- Display all restaurants.
- Search for a restaurant by name.
- Sort restaurants by rating in descending order.

### Menu Management

For each restaurant, the application allows users to:

- Add a dish at the beginning of the menu.
- Add a dish at the end of the menu.
- Insert a dish after a specific dish.
- Delete the first dish.
- Delete the last dish.
- Delete a specific dish.
- Modify a dish's price, description, or category.
- Display the complete menu.

### Search and Filtering

- Search for a dish by name.
- Search for dishes by category.
- Search for dishes within a maximum budget.

### Category Management

- Display the available categories.
- Count the number of dishes in each category.
- Delete a category and all dishes associated with it.

## 🧠 Data Structures

The project uses a **list-of-lists structure**:

```text
Restaurant List
      │
      ├── Restaurant 1
      │      └── Dish List
      │             ├── Dish 1
      │             ├── Dish 2
      │             └── Dish 3
      │
      ├── Restaurant 2
      │      └── Dish List
      │             ├── Dish 1
      │             └── Dish 2
      │
      └── Restaurant 3
             └── Dish List
                    └── ...
```

Both restaurants and dishes are managed using **doubly linked lists**, with `Next` and `Previous` pointers allowing bidirectional traversal and facilitating insertion and deletion operations.

## 🛠️ Technologies & Tools

- **Language:** C
- **Libraries:** `stdio.h`, `stdlib.h`, `string.h`
- **Compiler:** GCC
- **Development environment:** Visual Studio Code / Code::Blocks

The project uses `malloc()` and `free()` for dynamic memory allocation and deallocation.

## 📚 Concepts Practiced

- Structures (`struct`)
- Pointers
- Pointer manipulation
- Doubly linked lists
- Nested linked lists
- Dynamic memory allocation
- Memory deallocation
- Searching and filtering algorithms
- Sorting algorithms
- Data traversal
- Modular programming
- Input validation and error handling

## 🚀 Compilation and Execution

Using GCC:

```bash
gcc restaurant-management-c.c -o restaurant_manager
```

Then run:

```bash
./restaurant_manager
```

On Windows:

```bash
restaurant_manager.exe
```

## 📌 Limitations & Possible Improvements

The application currently runs through a **console interface**, and data is not permanently stored after the program terminates.

Possible future improvements include:

- Adding data persistence using files.
- Developing a graphical user interface.
- Improving input validation.
- Adding additional search and filtering criteria.

## 👩‍💻 Author

**FERDOUSS Nada**

Academic Project — EMSI  
Academic Year 2025–2026
