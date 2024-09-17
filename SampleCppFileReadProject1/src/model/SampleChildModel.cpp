/*
 * SampleChildModel.cpp
 *
 *  Created on: 16 Eyl 2024
 *      Author: ACER
 */

#include "SampleChildModel.h"


SampleChildModel::SampleChildModel() {
	// TODO Auto-generated constructor stub
	intProperty = -1;
}

SampleChildModel::SampleChildModel(const std::string& strValue1, const std::string& strValue2, int intValue)
    : strProperty1(strValue1), strProperty2(strValue2), intProperty(intValue) {}

SampleChildModel::~SampleChildModel() {
	// TODO Auto-generated destructor stub
}



void SampleChildModel::display() const {
    std::cout << "- SampleChildModel::display(): StrProperty1 = " << strProperty1 << ", StrProperty2 = " << strProperty2
              << ", IntProperty = " << intProperty << std::endl;
}

