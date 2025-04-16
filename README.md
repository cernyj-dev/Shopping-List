# Smart Shopping List Optimizer

> 🛒 **A tool to streamline supermarket shopping by organizing and optimizing item lists based on store layout.**

---

## Project Overview

This program is designed to **optimize shopping trips in supermarkets** by reorganizing shopping lists based on the layout of store shelves. The goal is to reduce time spent wandering between aisles and improve overall shopping efficiency.

People approach shopping differently — while *shopaholics* enjoy exploring store shelves and discovering new products, *shopaphobics* prefer to follow a strict list and complete the trip as quickly as possible. This tool caters especially to the latter by minimizing unnecessary backtracking in the store.

---

## Functionality

The program takes two inputs:
1. **Shelf Layout** – a list of shelves numbered from `0` to `N`, each containing a set of items (e.g., `"tomato"`, `"milk"`, `"cheese"`).
2. **Shopping List** – a list of items the user wishes to purchase (e.g., `"tomato"`).

### Matching Logic:
- The program attempts to **match each shopping list item** with items on the shelves.
- If an **exact match** is not found, it searches for a **partial match** (i.e., the item appears as a case-insensitive substring in a shelf item, such as `"red tomato"` for `"tomato"`).
- If no match is found, the item is placed at the **end of the final list**.

### Output:
After processing, the shopping list is reordered based on:
- **Shelf number (ascending)**.
- If multiple items are on the **same shelf**, their **original order is preserved**.
- If an item exists on **multiple shelves**, the **first match** is used.
- **Unavailable items** are placed at the **end** of the list.

---

## Input Validation

The program includes input validation and reports errors in the following cases:
- Missing shelf number when defining shelf items (shelf `0` must appear first).
- Invalid shelf numbering or incorrect sequence (shelves must follow the order `0, 1, 2, ...`).
- Missing empty line separating the shelf layout from the shopping list.

---

## Purpose and Use Cases

The tool is primarily intended to:
- **Reduce shopping time** by organizing lists efficiently.
- **Improve comfort** for users who prefer fast and structured shopping.
- Serve as a base for **business applications** where quick item retrieval is critical (e.g., inventory picking, logistics optimization).

---

## Implementation Notes

- The program is expected to pass basic functionality tests with a **simple algorithm**.
- For **bonus functionality**, a more **efficient algorithm** is required to handle long shopping lists and complex layouts.

---

## Example Use Case

Imagine entering a supermarket with a shopping list of 15 items spread across 10 aisles. Rather than walking back and forth between shelves, the optimized list guides the shopper through the store in a logical sequence, improving both **speed** and **convenience**.

---

## License

This project is intended for educational and demonstration purposes.

