# Movie Ticket Booking System

## Overview

The Movie Ticket Booking System is a software application built in C that automates the process of movie ticket booking, viewing movies, canceling tickets, and viewing past transactions. The system helps users to efficiently manage movie tickets, and supports movie insertion, booking, and cancellation.

## Features

- **Insert Movie:** Allows the user to insert a new movie with details like code, name, release date, and ticket price.
- **View All Movies:** Displays a list of all available movies.
- **Book Ticket:** Enables users to book tickets for a chosen movie.
- **Cancel Ticket:** Provides the functionality to cancel a booked ticket.
- **View All Transactions:** Displays a history of all ticket booking transactions.
- **Password Protection:** Ensures only authorized users can add new movies.

## Project Requirements

### Software Requirements:
- C Compiler (e.g., Dev C++)
- Operating System: Windows 10 or later

### Hardware Requirements:
- RAM: 8GB
- Processor: i5

## Installation

1. Download the project files to your local machine.
2. Install a C compiler like Dev C++ if you don't have it already.
3. Open the project files in your C compiler and run the program.

## Usage

### Main Menu:

The following options are available in the main menu:
1. **Insert Movie** - Add a new movie (Password required).
2. **View All Movies** - Displays all movies.
3. **Book Ticket** - Book a ticket for a selected movie.
4. **Cancel Ticket** - Cancel an existing ticket.
5. **View All Transactions** - View historical booking data.
6. **Exit** - Exit the program.

### Password for Movie Insertion:

A predefined password (`12345`) is required to insert new movies. This ensures that only authorized users can add movies.

### File Storage:

The system uses a text file (`data.txt`) to store movie records and bookings.

## Code Structure

- **Main Function**: Displays the menu and handles user input.
- **insert_details()**: Adds new movie records to the `data.txt` file.
- **viewAll()**: Displays the list of movies available for booking.
- **book_ticket()**: Handles the ticket booking process.
- **cancel_ticket()**: Allows users to cancel previously booked tickets.
- **old_record()**: Displays previous booking transactions.

## License

This project is open-source and free to use. Feel free to modify it for personal or educational purposes.
