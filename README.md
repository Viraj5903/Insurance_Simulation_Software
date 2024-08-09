# Insurance Simulation Software

## Overview
The **Insurance Simulation Software** is a C++ console application designed to model the operations of an insurance company. This application enables users to manage insurance agreements, track financial transactions, handle insurance claims, and process cancellations. It features an interactive menu system for managing insurance data and user information, providing a realistic simulation of an insurance company's operations.

Key features include:
- Management of insurance agreements with random values.
- Interactive menus for various user functions.
- Ability to advance time, affecting all insurance agreements.

## Description

### Features
- **Insurance Agreements Management:** 
  - Store and manage up to 20 insurance agreements.
  - Each agreement includes client details, yearly fee, risk percentage, and insurance amount.
  - Agreements are generated with random values for a realistic simulation.

- **Interactive Menus:**
  - **Main Menu:** 
    - Display the current year and total money made by the company.
    - Create new users and manage insurance agreements.
    - View financial breakdowns and advance time by one year.
  
  - **User Menu:**
    - View total money collected by specific users.
    - Process new insurance applications and manage existing agreements.
    - Display financial details and handle agreement cancellations with penalties.

- **Time Management:**
  - Move time forward by one year to affect insurance agreements.
  - Collect annual fees and handle claims based on risk values.
  - Display claims and payouts for transparency.

### Core Components
- **Insurance_Simulation_Software.cpp:** 
  - Contains the main program logic, user interactions, and menu system.
  
- **Header Files:**
  - **Client.h:** Defines the `Client` class with client information and random name generation.
  - **InsuranceAgreement.h:** Defines the `InsuranceAgreement` class including details such as yearly fee and payout management.
  - **Person.h:** Base class for `User` and `Client`, including basic personal information.
  - **User.h:** Manages user-specific operations and interactions.

## Technology Used
- **C++:** Programming language used for application development.
- **Visual Studio:** IDE used for development and testing.
- **Standard Library:** Includes headers like `<iostream>`, `<ctime>`, and `<vector>` for core functionalities and data handling.
- **Object-Oriented Programming (OOP):** Used for designing and managing core functionalities.

## Setup Instructions

1. **Install Visual Studio:**
   - Download and install [Visual Studio](https://visualstudio.microsoft.com/) or any compatible IDE.
   - During installation, select the "Desktop development with C++" workload to ensure that you have the necessary tools for C++ development.

2. **Clone the Repository:**
    ```
    git clone https://github.com/Viraj5903/Insurance_Simulation_Software.git
    ```

3. **Open in Visual Studio:**
   - Open the `Insurance_Simulation_Software.sln` solution file located in the cloned repository.

4. **Build the Project:**
   - Use the "Build" menu in Visual Studio and select "Build Solution" to compile the application.

5. **Run the Application:**
   - Execute the program directly from Visual Studio by pressing `F5` or navigate to the output directory and run the compiled executable.

## File Structure
- `Insurance_Simulation_Software/`: Contains the main application files and headers.
  - `Insurance_Simulation_Software.cpp`: Entry point and main logic.
  - `Client.h`: Class definition for clients.
  - `InsuranceAgreement.h`: Class definition for insurance agreements.
  - `Person.h`: Base class for `User` and `Client`.
  - `User.h`: Class definition for users.
  - `Insurance_Simulation_Software.vcxproj.filters`: Contains information about the file organization and filter settings used in the Visual Studio project. This file helps Visual Studio manage and display files in the Solution Explorer, grouping them according to their types and categories.

- `README.md`: This README file.

## Author
[Viraj Patel \(@Viraj5903\)](https://github.com/Viraj5903)
- Creator and maintainer of the Insurance Simulation Software. Responsible for designing and implementing the core functionalities, including insurance management, financial tracking, and user interaction.
