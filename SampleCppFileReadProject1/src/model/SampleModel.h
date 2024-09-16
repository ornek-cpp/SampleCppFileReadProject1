/*
 * SampleModel.h
 *
 *  Created on: 4 Ağu 2024
 *      Author: ACER
 */
#include <iostream>
#include <string>

#ifndef SRC_SAMPLEMODEL_H_
#define SRC_SAMPLEMODEL_H_


class SampleModel {
private:
    std::string strProperty1;
    std::string strProperty2;
    int intProperty;

public:
    // Constructor
    SampleModel(const std::string& strProperty1, const std::string& strProperty2, int intProperty1);
    SampleModel();

    // Getterlar
    std::string getStrProperty1() const;
    std::string getStrProperty2() const;
    int getIntProperty() const;

    // Yazdırma fonksiyonu
    void display() const;
};


#endif /* SRC_SAMPLEMODEL_H_ */
