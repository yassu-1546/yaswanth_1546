Transport Management System – README
1. Abstract

The Transport Management System (TMS) is a C-based application designed to manage transport records efficiently using binary file handling. The system maintains essential information such as Transport ID, Driver Name, Route, and Distance. It allows the user to add, view, search, update, and delete records while ensuring data persistence through a binary file (transport.dat). The project uses a menu-driven interface for easy interaction and provides essential transport management operations suitable for logistics hubs, transport companies, and fleet management environments.

2. Functional Requirements
Core Features

Add Transport Record

Add a new vehicle/transport entry.

Stores ID, Driver Name, Route, and Distance.

Saves to transport.dat.

Display Transport Records

Shows all transport entries in a readable tabular format.

Search Transport by ID

Allows searching for a specific transport record by its ID.

Update Route / Distance

Modify route details or travel distance of an existing entry.

Delete Transport Record

Removes a transport entry by ID using a temporary file replacement method.

Exit Program

Safely terminates execution.

3. Technical Requirements
Hardware Requirements

A computer with basic specifications:

Minimum 1GHz processor

1GB RAM or above

10MB free storage

Software Requirements

Operating System: Windows / Linux

Compiler: GCC, MinGW, Turbo C, or any C compiler

Editor/IDE: CodeBlocks, Dev-C++, VS Code, etc.

Executable: transport.exe

Programming Requirements

C Programming Language

File Handling (Binary mode)

Use of fwrite(), fread(), fopen(), fclose()

Menu-driven program using loops and switches

4. Screenshots (Insert your images here)

(Place your screenshots in the project folder and reference them here.)

✔ Main Menu

<img width="461" height="187" alt="Screenshot 2025-12-10 102256" src="https://github.com/user-attachments/assets/e39b6874-6c6e-46e7-a44d-61d6f243ad96" />


✔ Add Transport

<img width="422" height="342" alt="Screenshot 2025-12-10 102336" src="https://github.com/user-attachments/assets/32e4cc70-e626-42fe-86c4-9f8e4e783766" />


✔ Display Records

<img width="862" height="147" alt="Screenshot 2025-12-10 102349" src="https://github.com/user-attachments/assets/6029d522-6585-49d3-96b9-e56154592180" />


✔ Search by ID

<img width="520" height="221" alt="Screenshot 2025-12-10 102417" src="https://github.com/user-attachments/assets/81065aa2-6b6d-47c5-9370-e8e447d77dc7" />


✔ Update Record

<img width="398" height="145" alt="Screenshot 2025-12-10 102452" src="https://github.com/user-attachments/assets/4a76b26e-173e-4abd-96b3-07deb798e156" />


✔ Delete Record

<img width="391" height="86" alt="Screenshot 2025-12-10 102507" src="https://github.com/user-attachments/assets/54da08dd-5546-48c9-a755-02a5eaf4fba3" />


