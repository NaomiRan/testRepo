/***********************************************************************
// Final project Milestone 1
// Module: Utils
// File: Utils.h
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: Dongqin Ran
// email: dran@myseneca.ca
// Student ID : 128601226
// section : NCC
// Date: Nov.9
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <ctime>
#include "Utils.h"

namespace sdds {
   Utils ut;
   void Utils::testMode(bool testmode) {
      m_testMode = testmode;
   }
   void Utils::getSystemDate(int* year, int* mon, int* day) {
      if (m_testMode) {
         if(day) *day = sdds_testDay;
         if(mon) *mon = sdds_testMon;
         if(year) *year = sdds_testYear;
      }
      else {
         time_t t = std::time(NULL);
         tm lt = *localtime(&t);
         if (day) *day = lt.tm_mday;
         if (mon) *mon = lt.tm_mon + 1;
         if (year) *year = lt.tm_year + 1900;
      }
   }
   int Utils::daysOfMon(int month, int year)const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = (month >= 1 && month <= 12 ? month : 13)-1;
      return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
   }

   void Utils::alocpy(char*& destination, const char* source) {
       
       if (destination !=source) {
           if (destination != nullptr) {
               delete[] destination;
               destination = nullptr;
           }
           if (source != nullptr) {
               destination = new char[strlen(source) + 1];
               strcpy(destination, source);
           }
           
       }
   }

 
   int Utils::getint(const char* prompt) {
       int num = 0;
       bool flag = true;
       if (prompt != nullptr) {
           do {
               std::cout << prompt;
               if (std::cin >> num) flag = false;
               else {
                   std::cout << "Invalid Integer, retry: ";
                   std::cin.clear();
               }
           } while (flag);
       }
       return num;
   }

   int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
       int numValid;
       do {
           numValid = getint(prompt);
           if (numValid<min || numValid>max) {
               if (errMes != nullptr) std::cout << ", retry: ";
               else std::cout << "Value out of range [" << min << "<=" << numValid << "<=" << max << "]: ";
           }
       } while (numValid<min || numValid>max);
       return numValid;
   }


   }

