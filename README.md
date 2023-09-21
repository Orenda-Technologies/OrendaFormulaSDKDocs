## iOS

### Setup 

1) Copy OrendaFormula.xcframework into your project directory
2) In settings -> Build phases of your XCode project add OrendaFormula.xcframework as a dependency
<img width="390" alt="Screenshot 2023-09-21 at 7 48 24 PM" src="https://github.com/Orenda-Technologies/OrendaFormulaSDKDocs/assets/12134914/f0035258-76ab-429e-9775-0da86ae0d086"><br />

3) Before using any methods of OrendaCalculator class you have to initialize the formula. Call initialize method of OrendaCalculator and pass your token. 
##### Note:
Initialize method shoould be called from a BACKGROUND thread.
##### Note:
Internet connection is required to initialize OrendaCalculator for the first time. Then you have to connect to the internet at least once per 2 weeks or per 1 month to update the token. The delay is sepcified in the token, issued to you. SDK does everything autmatically you just have to call initalize all the time you start working with OrendaCalculator

##### Example:

```Swift
import OrendaFormulaiOS

DispatchQueue.global().async {
    let result = OrendaCalculator.initialize(token: "GVlzMF808NOR/Hhn6BEgSAt64rR+Vy0o1D6U97ZnylUm7w7MT1hCMcQRbi6v2Zl3RCK6s71/O3A0RbpNInOC87UlswfIAfXICxmApN8YNNgkteoUHMDYtOresjEtaR3UtaKV5T/9wZ0OP4mFN+T0MKeVHLX2Dr04ysNx/qcL0BBVDT6op8eGpQ6LLCorXalm1WKARrCCB/n4uUpb24vfxVXQ5LzLLu34gt1TwBowgbIkW0DAddLZDR+bcaB0u0Z9m")
    if (!result) {
        print("Error")
    } else {
        print("Success")
    }
}
```

### OrendaCalculator API
After initialize you are able to call OrendaCalculator methods. Here are the examples
```Swift
import OrendaFormulaiOS

if let lsi: LSIResult = OrendaCalculator.calculateLSI(
    waterTemperatureCurrent: .fahrenheit(87), 
    pHCurrent: 7.6, 
    totalAlkalinityCurrent: 80, 
    calciumCurrent: 320, 
    cyaCurrent: 35, 
    saltCurrent: 400, 
    boratesCurrent: 0,
    
    waterTemperatureDesired: .fahrenheit(87), 
    pHDesired: 8.1, 
    totalAlkalinityDesired: 90, 
    calciumDesired: 370, 
    cyaDesired: 0, 
    saltDesired: 900, 
    boratesDesired: 0
) {
    print("current=", lsi.current)
    print("desired=", lsi.desired)
    print("phCellingCurrent=", lsi.phCellingCurrent)
    print("phCellingDesired=", lsi.phCellingDesired)
    print("carbonateAlkalinityCurrent=", lsi.carbonateAlkalinityCurrent)
    print("carbonateAlkalinityDesired=", lsi.carbonateAlkalinityDesired)
}
```

`calculateDosages` returns json data, used to render Orenda app's calculation result screen.
You can pass either `ORENDA_USA` or `ORENDA_METRIC` for different measurement units.
```Swift
let dosagesJson: String = OrendaCalculator.calculateDosages(
    poolVolume: .gallons(1000),
    measurement: ORENDA_USA,
    pHCurrent: 7.6,
    currentTemperature: .fahrenheit(80),
    totalAlkalinityCurrent: 80,
    calciumCurrent: 400,
    cyaCurrent: 35,
    saltCurrent: 400,
    boratesCurrent: 0,
    chlorineCurrent: 0.5,
    phosphateCurrent: 500,
    pHDesired: 8.2,
    totalAlkalinityDesired: 120,
    calciumDesired: 370,
    cyaDesired: 300,
    saltDesired: 900,
    chlorineDesired: 9.5,
    phosphateDesired: 0
)

print(dosagesJson)
```
