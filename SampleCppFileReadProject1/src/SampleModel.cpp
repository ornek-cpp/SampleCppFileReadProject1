/*
 * SampleModel.cpp
 *
 *  Created on: 4 Ağu 2024
 *      Author: ACER
 */

#include "SampleModel.h"

// Constructor'ı tanımlama
SampleModel::SampleModel(const std::string& strValue1, const std::string& strValue2, int intValue)
    : strProperty1(strValue1), strProperty2(strValue2), intProperty(intValue) {}

// Getter'ları tanımlama
std::string SampleModel::getStrProperty1() const {
    return strProperty1;
}

std::string SampleModel::getStrProperty2() const {
    return strProperty2;
}

int SampleModel::getIntProperty() const {
    return intProperty;
}

void SampleModel::display() const {
    std::cout << "StrProperty1: " << strProperty1 << ", StrProperty2: " << strProperty2
              << ", IntProperty: " << intProperty << std::endl;
}

