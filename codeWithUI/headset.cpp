#include <iostream>
#include <iomanip>

#include "headset.h"

Headset::Headset() {
    eegs = new EEGArray();
    headsetStatus = true;
}

Headset::~Headset() {
    delete eegs;
}


int Headset::getEEGBaseline() {
    int average = 0;
    int total = 0;
    EEG* temp;

    for(int i = 0; i < 21; i++) {
        temp = eegs->get(i);
        total += temp->getFrequency();
    }

    average = total / 21;


    return average;
}

void Headset::getEEGAverages() {
    int average = 0;
    int total = 0;
    EEG* temp;

    for(int i = 0; i < 21; i++) {
        temp = eegs->get(i);
        for(int j = 0; j < 20; j++) {
            total += temp->getFrequency();
        }
        average = total / 20;
        cout << "EEG " << i << " average: " << average << endl;
        average = 0;
        total = 0;
    }
}


void Headset::applyTreatment() {
    EEG* temp;

    for(int i = 0; i < 21; i++) {
        temp = eegs->get(i);
        temp->createTreatmentHZ();
    }
}

