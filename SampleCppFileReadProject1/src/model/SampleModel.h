/*
 * SampleModel.h
 *
 *  Created on: 4 Ağu 2024
 *      Author: ACER
 */
#include <iostream>
#include <string>
#include "SampleChildModel.h"
#include <vector>

#ifndef SRC_SAMPLEMODEL_H_
#define SRC_SAMPLEMODEL_H_


class SampleModel {
private:
    std::string strProperty1;
    std::string strProperty2;
    int intProperty;

    std::vector<SampleChildModel> sampleChildModels;

public:
    // Constructor
    SampleModel(const std::string& strProperty1, const std::string& strProperty2, int intProperty1);
    SampleModel();

    // Getters
    std::string getStrProperty1() const;
    std::string getStrProperty2() const;
    int getIntProperty() const;
    std::vector<SampleChildModel> getSampleChildModels();

    // Helper functions
    void display() const;
};


#endif /* SRC_SAMPLEMODEL_H_ */
