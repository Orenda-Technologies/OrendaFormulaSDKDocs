//
// Created by Semyon Tikhonenko on 9/7/23.
//

#ifndef ORENDAFORMULA_ORENDAFORMULA_H
#define ORENDAFORMULA_ORENDAFORMULA_H

#ifdef __cplusplus
extern "C" {
#endif
    bool OrendaPrepare(const char* token);

    bool OrendaCalculateLSI(
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

        double* lsiCurrent,
        double* lsiDesired
    );

    enum OrendaMeasurement {
        ORENDA_USA, ORENDA_METRIC
    };

    double OrendaExecutePoolVolumeEstimatorForCircle(
            double radius, double depth, OrendaMeasurement measurement);
    double OrendaExecutePoolVolumeEstimatorForRectangle(
            double length, double width,
            double shallowDepth, double deepDepth,
            OrendaMeasurement measurement);
    double OrendaExecutePoolVolumeEstimatorForOblong(
            double length, double smallDiameter, double largeDiameter,
            double shallowDepth, double deepDepth,
            OrendaMeasurement measurement);
#ifdef __cplusplus
}
#endif

#endif //ORENDAFORMULA_ORENDAFORMULA_H
