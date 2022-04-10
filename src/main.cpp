#include <algorithm>
#include <iostream>
#include <map>
#include <string>

void sort(std::map<int, std::string> turn) {
  std::cout << "[sort]" << std::endl;
}

int main() {
  std::cout << "Registry" << std::endl;
  std::map<int, std::string> turn;
  const std::string next = "Next";
  std::string command;
  int count = 0;
  do {
    std::cout << "Enter command (Surname/Next)" << std::endl;
    std::cin >> command;
    if (command == next) {
      turn.erase(count);
      count--;
    } else if (!command.empty() && command != next) {
      count++;
      turn.insert(std::make_pair(count, command));
      sort(turn);
    }
    for (std::map<int, std::string>::iterator it = turn.begin(); it != turn.end(); it++) {
      std::cout << "Number: " << it->first << "; Surname: " << it->second << std::endl;
    }
  } while (count > 0);

  return 0;
}
