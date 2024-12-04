#include "invoice.h"
#include <string>

int main() {
  Invoice invoice;

  std::string str = "Test item";
  invoice.SetName(str);
  invoice.Print();
}
