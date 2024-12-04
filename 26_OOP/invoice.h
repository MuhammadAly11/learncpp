#ifndef INVOICE_H
#define INVOICE_H

#include <string>
class Invoice {
private:
  std::string name;
  int item_number, price, quantity;
public:
  std::string& GetName();
  int GetItemNumber();
  int GetPrice();
  int GetQuantity();

  void SetName(std::string& name);
  void SetItemNumber(int item_number);
  void SetPrice(int price);
  void SetQuantity(int quantity);

  int GetTotalPrice();
  void Print();
  std::string ToString();
};

#endif
