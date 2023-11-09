# RailwayReservationSystem

This is a simple train ticket reservation system implemented in C++.

## Description

This program will allow admin to generate user ids ,set Train info and see all Reservations, users and cancellations. 
User can Reserve, Enquire and Cancel Ticket. Ticket fare will be calculated based upon concession category. 
Every data will be written to files in binary form using file Handling. Updation of Seats after reservation and cancellation takes place as well. 
PNR is generated randomly using random function.

## Features

- Adding train details to the database.
- Detailed display of trains in the database.
- User management.
- Show reservations and cancellations.

## Files used

- `id.txt`: this file stores the id’s and passwords of the users.
- `t.txt`: this file stores the available trains name,train no and other details about each train.
- `p.txt`: this file stores the data of every passenger.  
- `cn.txt`: this file stores the details of each cancelled ticket.  
- `temp.txt`: this file is used for temporary storage of data while cancellation of the ticket.


## Usage

1. Compile and run the program using `g++ main.cpp` and `./a.out`.
2. In the main menu, choose the appropriate mode (Admin mode or User mode).
3. Follow the on-screen instructions for each available option.

![](README/ss1.png)
![](README/ss2.png)
![](README/ss3.png)
