// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train():first(nullptr), countOp(0) {}

int Train::getOpCount() {
  return countOp;
}

int Train::getLength() {
  int countLen = 0;
  int countStep = 0;
  Cage* item = first;
  item->light = true;
  while (true) {
    item = item->next;
    ++countOp;
    ++countStep;
    while (item->light == false) {
      ++countStep;
      ++countOp;
      item = item->next;
    }
    countLen = countStep;
    item->light = false;
    while (countStep) {
      ++countOp;
      --countStep;
      item = item->prev;
    }
    if (item->light == false) {
      return countLen;
    }
  }
}

void Train::addCage(bool light) {
  Cage* Item = new Cage;
  Item->light = light;
  Item->prev = nullptr;
  Item->next = nullptr;
  if (first == nullptr) {
    first = Item;
    Item->next = Item;
    Item->prev = Item;
  } else {
    Item->next = first;
    Item->prev = first->prev;
    first->prev->next = Item;
    first->prev = Item;
  }
}
