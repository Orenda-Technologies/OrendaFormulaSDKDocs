#import "OrendaMeasurement.h"
#import <Foundation/Foundation.h>

@interface OrendaCalculatorBridge : NSObject

+ (NSString *)calculateDosages:(double)gallons
                   measurement:(enum OrendaMeasurement)measurement
                     pHCurrent:(double)pHCurrent
           currentTemperatureF:(double)currentTemperatureF
        totalAlkalinityCurrent:(double)totalAlkalinityCurrent
                calciumCurrent:(double)calciumCurrent
                    cyaCurrent:(double)cyaCurrent
                   saltCurrent:(double)saltCurrent
                boratesCurrent:(double)boratesCurrent
               chlorineCurrent:(double)chlorineCurrent
              phosphateCurrent:(double)phosphateCurrent
                     pHDesired:(double)pHDesired
        totalAlkalinityDesired:(double)totalAlkalinityDesired
                calciumDesired:(double)calciumDesired
                    cyaDesired:(double)cyaDesired
                   saltDesired:(double)saltDesired
               chlorineDesired:(double)chlorineDesired
              phosphateDesired:(double)phosphateDesired;

@end

