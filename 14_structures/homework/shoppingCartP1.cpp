#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct item {
  string name;
  int price{};
};

struct shopping_cart {
  item items[MAX_SIZE]{};
  int len{};

  void add(string name, int price) {
    if (len >= MAX_SIZE) {
      cout << "Shopping cart is full.\n";
      return;
    }
    items[len].name = name;
    items[len].price = price;
    len++;
  }

  void remove(string name, int price) {
    for (int i = 0; i < len; i++) {
      if (name == items[i].name && price == items[i].price) {
        items[len].name = "";
        items[len].price = {};
        len--;
        return;
      }
    }
    cout << "Sorry, this item isn't in your shopping cart\n";
  }

  void print() {
    if (len == 0) {
      cout << "There's nothing in the shopping cart\n";
      return;
    }
    for (int i = 0; i < len; i++) {
      cout << i << ". " << items[i].name << " ==> " << items[i].price << endl;
    }
    cout << "******************************\n";
  }
};

int main() {
  shopping_cart cart;

  cart.add("car", 1800);
  cart.print();

  cart.add("TV", 18);
  cart.print();

  cart.add("Phone", 178);
  cart.print();

  cart.remove("Phone", 178);
  cart.print();

  cart.remove("TV", 18);
  cart.print();

  cart.remove("car", 1800);
  cart.print();

  return 0;
}
