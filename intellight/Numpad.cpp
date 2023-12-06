//
// Created by maxim on 06/12/2023.
//

#include "Numpad.h"

Numpad::Numpad() {
    data = 0;
    Rx = 0;
    Tx = 0;
    serial = nullptr;
}

Numpad::Numpad(short tx, short rx, SoftwareSerial& s) {
    data = 0;
    Rx = rx;
    Tx = tx;
    serial = s;
}

uint8_t Numpad::getData() {
    return data;
}

short Numpad::getRx() {
    return Rx;
}

short Numpad::getTx() {
    return Tx;
}

void Numpad::setRx(short rx) {
    Rx = rx;
}

void Numpad::setTx(short tx) {
    Tx = tx;
}

void Numpad::updateData() {
    data = serial->read();
}
