#pragma once

#include<iostream>
#include "TStack.h"

class TextNode 
{
protected:
  TextNode* next;
  TextNode* down;
  char c;
  int level;
public:
  TextNode(int _l = 3, char _c = 0);
  TextNode(const TextNode& node);
  TextNode(char* s, int l);
  ~TextNode();
  TextNode* getNext();
  TextNode* getDown();
  char getC();
  int getLevel();

  void setNext(TextNode* node);
  void setDown(TextNode* node);
  void setC(char _c);
  void setLevel(int _l);

  friend std::ostream& operator<<(std::ostream& stream, const TextNode& node);
};