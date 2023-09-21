## iOS

### Setup 

1) Copy OrendaFormula.xcframework into your project directory
2) In settings -> Build phases of your XCode project add OrendaFormula.xcframework as a dependency
<img width="390" alt="Screenshot 2023-09-21 at 7 48 24 PM" src="https://github.com/Orenda-Technologies/OrendaFormulaSDKDocs/assets/12134914/f0035258-76ab-429e-9775-0da86ae0d086"><br />

3) Before using any methods of OrendaCalculator class you have to initialize the formula. Call initialize method of OrendaCalculator and pass your token. 
##### Note:
Initialize method shoould be called from a BACKGROUND thread.

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
