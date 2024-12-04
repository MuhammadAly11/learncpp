#include "invoice.h"
#include <iostream>
#include <string>

std::string &Invoice::GetName() { return name; }

void Invoice::SetName(std::string &name) { this->name = name; }

int Invoice::GetPrice() { return price; }

void Invoice::SetPrice(int price) { this->price = price; }

int Invoice::GetItemNumber() { return price; }

void Invoice::SetItemNumber(int item_number) {
  this->item_number = item_number;
}

int Invoice::GetQuantity() { return quantity; }

void Invoice::SetQuantity(int quantity) { this->quantity = quantity; }

int Invoice::GetTotalPrice() { return GetQuantity() * GetPrice(); }

void Invoice::Print() {
  std::cout << "Name: " << name << "\n"
            << "Item number: " << item_number << "\n"
            << "Price: " << price << "\n"
            << "Quantity: " << quantity << "\n";
}

std::string Invoice::ToString() {
  std::string str;
  str = name + ", " + std::to_string(GetItemNumber()) + ", " +
        std::to_string(GetPrice()) + ", " + std::to_string(GetQuantity());
  return str;
}
