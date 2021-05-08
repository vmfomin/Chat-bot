/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     TCP/IP server
 * @version   0.1
 * @date      07-05-2021
 * @copyright Copyright (c) 2021
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <regex>

std::map<std::string, std::string> knowledge{
    {"hello", "Hey, dude"},
    {"what is your name", "TCP/IP server"},
    {"what is your purpose", "Simple TCP/IP server on C++"},
};

std::string exitPhrases[]{"bye", "exit", "good bye", "have a nice day"};

void toLower(std::string&);
void botSay(const std::string&);
void botAnswer(const std::string&);
bool isExit(const std::string&);
std::string userQuestion();

void toLower(std::string& text) {
  std::transform(text.begin(), text.end(), text.begin(), ::tolower);
}

void botSay(const std::string& text) {
  std::cout << "[BOT]: " << text << std::endl;
}

void botAnswer(const std::string& question) {
  bool foundAnswer{};
  for (const auto& entry : knowledge) {
    std::regex expression(".*" + entry.first + ".*");
    if (std::regex_match(question, expression)) {
      botSay(entry.second);
      foundAnswer = true;
    }
  }
  if (!foundAnswer) botSay("I don't understand");
}

bool isExit(const std::string& text) {
  for (const auto& phrase : exitPhrases) {
    std::regex expression(".*" + phrase + ".*");
    if (std::regex_match(text, expression)) {
      botSay("Bye...");
      return true;
    }
  }
  return false;
}

std::string userQuestion() {
  std::string question;
  std::cout << "[USER]: ";
  std::getline(std::cin, question);
  toLower(question);
  return question;
}

int main() {
  system("cls");
  std::string question;
  while (true) {
    question = userQuestion();
    if (isExit(question)) break;

    botAnswer(question);
  }

  return 0;
}
