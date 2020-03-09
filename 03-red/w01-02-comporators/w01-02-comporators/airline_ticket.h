//
//  AirlineTickets.h
//  w01-02-comporators
//
//  Created by Sergey Gordeev on 09.03.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef AirlineTickets_h
#define AirlineTickets_h

#pragma once

#include <string>
using namespace std;

struct Date {
  int year, month, day;
};

struct Time {
  int hours, minutes;
};

struct AirlineTicket {
  string from;
  string to;
  string airline;
  Date departure_date;
  Time departure_time;
  Date arrival_date;
  Time arrival_time;
  int price;
};
#endif /* AirlineTickets_h */
