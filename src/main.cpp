#include <iostream>
#include <map>
#include <string>

int main() {
  std::cout << "Registry" << std::endl;
  std::map<std::string, int> turn;
  const std::string next = "Next";
  bool restart = false;
  std::string command;
  int count = 0;
  do {
    std::cout << "Enter command (Surname/Next)" << std::endl;
    std::cin >> command;
    if (command == next) {
      if (turn.empty()) {
        std::cout << "The queue is empty" << std::endl;
        restart = true;
      } else {
        std::cout << "Gone Surname: " << turn.begin()->first << std::endl;
        turn.erase(turn.begin()->first);
        count--;
      }
    } else if (!command.empty()) {
      count++;
      turn.insert(std::make_pair(command, count));
    }
    for (std::map<std::string, int>::iterator it = turn.begin(); it != turn.end(); it++) {
      std::cout << "Surname: " << it->first << "; Number: " << it->second << std::endl;
    }
  } while (count > 0 || restart);

  return 0;
}
