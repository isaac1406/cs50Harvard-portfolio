# Hospital Emergency Queue Management System

#### Video Demo: [URL HERE]

#### Description:

In the fast-paced environment of a hospital emergency room, managing patient queues efficiently is crucial to ensure timely and appropriate medical attention. My project, the Hospital Emergency Queue Management System, addresses this challenge by providing a structured approach to organizing patient queues based on both the order of arrival and the severity of symptoms. This system aims to streamline the process of patient management, ensuring that those in critical condition receive prompt care while maintaining a fair and orderly queue for all patients.

### Project Overview

The core idea behind this project was to create a solution that tackles a common issue in healthcare settings, especially in my country Brazil: the organization of patient queues. By simulating a hospital emergency scenario, my system prioritizes patients based on their arrival time and the severity of their symptoms. This dual-priority approach ensures that the most urgent cases are attended to swiftly, while also respecting the chronological order of patient arrivals.

### Files and Functionality

The project consists of several key files, each contributing to the overall functionality of the system:

- **functions.h**: This header file contains the declarations of all functions and data structures used in the project. It defines the `RECORD`, `PATIENT`, and `LIST` structures, which are essential for storing patient information and managing the queue. The file also declares functions for initializing lists, creating patients, updating positions, inserting patients in order, searching, removing, saving, displaying, and freeing the list.

- **emergency.c**: This is the main file of the project, where the user interacts with the system. It includes the implementation of the user interface, allowing users to add, remove, search, and view patients in the queue. The file handles the initialization of patient lists, processes user inputs, and calls the appropriate functions to manage the queue effectively.

- **functioe contains the implementation of all the functions declared in `functions.h`. It provides the logic for managing the patient queue, including memory allocation, patient insertion and removal, position updates, and file operations for saving and displaying patient data.

### Design Choices

During the development of this project, several design choices were made to enhance the system's efficiency and usability:

1. **Programming Language Choice**: I chose to implement this project as a command-line program using C because it is the language I am most familiar with, thanks to my experience with CS50 and my studies in my university in Brazil. C is known for its high performance, which is an essential characteristic for a system as critical as one used in a hospital setting. The ability to manage memory directly and execute operations swiftly makes C an ideal choice for developing a responsive and efficient queue management system.

2. **Data Structures**: I opted for a linked list structure to manage the patient queue. This choice allows for dynamic memory allocation, making it easier to handle varying numbers of patients without predefining the list size. The linked list also facilitates efficient insertion and removal operations, which are crucial for maintaining an ordered queue.

3. **Priority Management**: The system uses a combination of severity and arrival time to prioritize patients. This decision ensures that critical cases are addressed promptly while maintaining fairness for those who arrived earlier. The insertion function sorts patients based on these criteria, updating positions accordingly.

4. **User Interface**: The user interface in `emergency.c` was designed to be intuitive and straightforward, allowing users to perform essential operations with minimal effort. The menu-driven approach guides users through the available functionalities, ensuring a smooth interaction with the system.

5. **File Operations**: To ensure data persistence, the system includes functions for saving the total list of patients to a binary file specific to each day. This feature allows for the recovery of patient data in case of system restarts, maintaining continuity in patient management.

6. **Linked Lists for Patient Management**: I chose to create two linked lists to store patient information: the total list and the current list. The total list serves as a comprehensive record of all patients who entered the hospital throughout the day, providing a complete overview for administrative purposes. The current list, on the other hand, is used to manage the emergency queue during the day, allowing for real-time updates and efficient handling of patient priorities. This dual-list approach ensures both detailed record-keeping and effective queue management.

### Conclusion

The Hospital Emergency Queue Management System is a comprehensive solution for managing patient queues in emergency settings. By prioritizing patients based on severity and arrival time, the system ensures that critical cases receive immediate attention while maintaining an orderly queue. The project's design choices, including the use of linked lists and a user-friendly interface, contribute to its effectiveness and reliability. I am proud of the outcome and believe it can significantly improve queue management in healthcare environments in Brazil and all around the world. I hope this README provides a clear understanding of my project and its functionalities.
