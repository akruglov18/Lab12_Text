#include "TextNode.h"

TextNode::TextNode(int _l, char _c)
{
  next = nullptr;
  down = nullptr;
  c = _c;
  level = _l;
}

TextNode::TextNode(const TextNode& node)
{
  next = nullptr;
  down = nullptr;
  c = node.c;
  level = node.level;
}

TextNode::TextNode(char* s, int l)
{
  if (l < 1 || l > 3)
    throw std::exception();
  if (l == 1) {
    next = nullptr;
    c = 0;
    level = l;
    int sz = strlen(s);
    if (sz > 0) {
      int start = 0;
      TextNode* wcur = new TextNode(2);
      this->setDown(wcur);
      for (int i = 0; i < sz; i++) {
        if (s[i] == ' ' || i == sz - 1) {
          if (start != 0) {
            wcur->setNext(new TextNode(2));
            wcur = wcur->getNext();
          }
          TextNode* lcur = new TextNode(3, s[start]);
          wcur->setDown(lcur);
          for (int j = start + 1; j <= i; j++) {
            lcur->setNext(new TextNode(3, s[j]));
            lcur = lcur->getNext();
          }
          lcur->setNext(nullptr);
          start = i + 1;
        }
      }
      wcur->setNext(nullptr);
    }
  }
  if (l == 2) {
    next = nullptr;
    c = 0;
    level = l;
    int sz = strlen(s);
    if (sz > 0) {
      TextNode* lcur = new TextNode(3, s[0]);
      this->setDown(lcur);
      for (int i = 1; i < sz; i++) {
        lcur->setNext(new TextNode(3, s[i]));
        lcur = lcur->getNext();
      }
      lcur->setNext(nullptr);
    }
  }
  if (l == 3) {
    c = s[0];
    level = l;
    next = nullptr;
    down = nullptr;
  }
}

TextNode::~TextNode()
{
}

TextNode* TextNode::getNext()
{
  return next;
}

TextNode* TextNode::getDown()
{
  return down;
}

char TextNode::getC()
{
  return c;
}

int TextNode::getLevel()
{
  return level;
}

void TextNode::setNext(TextNode* node)
{
  next = node;
}

void TextNode::setDown(TextNode* node)
{
  down = node;
}

void TextNode::setC(char _c)
{
  c = _c;
}

void TextNode::setLevel(int _l)
{
  if (_l >= 1 && _l <= 3)
    level = _l;
  else
    throw std::exception();
}

std::ostream& operator<<(std::ostream& out, const TextNode& node)
{
  if (node.level == 3) {
    out << node.c;
    if (node.next != nullptr)
      out << *(node.next);
  }
  else {
    if (node.down != nullptr)
      out << *(node.down);
    if (node.next != nullptr)
      out << *(node.next);
  }
  return out;
}