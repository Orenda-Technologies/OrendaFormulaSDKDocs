//
// Created by Semyon Tikhonenko on 9/7/23.
//

#ifndef ORENDAFORMULA_ORENDAFORMULA_H
#define ORENDAFORMULA_ORENDAFORMULA_H

#include "OrendaMeasurement.h"

#ifdef __cplusplus
extern "C" {
#endif
    bool OrendaPrepare(const char* token);

    struct LSIResult {
        double current;
        double desired;
        double phCellingCurrent;
        double phCellingDesired;
        double carbonateAlkalinityCurrent;
        double carbonateAlkalinityDesired;
    };

    struct LSIResult OrendaCalculateLSI(
        double waterTemperatureCurrentF,
        double pHCurrent,
        double totalAlkalinityCurrent,
        double calciumCurrent,
        double cyaCurrent,
        double saltCurrent,
        double boratesCurrent,

        double waterTemperatureDesiredF,
        double pHDesired,
        double totalAlkalinityDesired,
        double calciumDesired,
        double cyaDesired,
        double saltDesired,
        double boratesDesired,

        bool* success
    );

    double OrendaExecutePoolVolumeEstimatorForCircle(
            double radius, double depth, enum OrendaMeasurement measurement);
    double OrendaExecutePoolVolumeEstimatorForRectangle(
            double length, double width,
            double shallowDepth, double deepDepth,
            enum OrendaMeasurement measurement);
    double OrendaExecutePoolVolumeEstimatorForOblong(
            double length, double smallDiameter, double largeDiameter,
            double shallowDepth, double deepDepth,
            enum OrendaMeasurement measurement);
#ifdef __cplusplus
}
#endif

#endif //ORENDAFORMULA_ORENDAFORMULA_H
