#include <iostream>
#include <map>
#include <string>

int main() {
  std::cout << "Registry" << std::endl;
  std::map<std::string, int> turn;
  const std::string next = "Next";
  std::string command;
  int count = 0;
  do {
    std::cout << "Enter command (Surname/Next)" << std::endl;
    std::cin >> command;
    if (!command.empty() && command != next) {
      count++;
      turn.insert(std::make_pair(command, count));
    } else if (command == next) {
      std::cout << "Gone Surname: " << turn.rbegin()->first << std::endl;
      turn.erase(turn.begin()->first);
      count--;
    }
    for (std::map<std::string, int>::iterator it = turn.begin(); it != turn.end(); it++) {
      std::cout << "Surname: " << it->first << "; Number: " << it->second << std::endl;
    }
  } while (count > 0);

  return 0;
}
