# iOS

## Setup 

1) Copy OrendaFormula.xcframework into your project directory
2) In settings -> Build phases of your XCode project add OrendaFormula.xcframework as a dependency
<img width="390" alt="Screenshot 2023-09-21 at 7 48 24 PM" src="https://github.com/Orenda-Technologies/OrendaFormulaSDKDocs/assets/12134914/f0035258-76ab-429e-9775-0da86ae0d086"><br />

3) Before using any methods of OrendaCalculator class you have to initialize the formula. Call `initialize` method of OrendaCalculator and pass your token. 
#### Note:
`initialize` method shoould be called on a BACKGROUND thread.
#### Note:
Internet connection is required to initialize OrendaCalculator for the first time. Then you have to connect to the internet at least once per 2 weeks or per 1 month to update the token. The delay is sepcified in the token, issued to you. SDK does everything autmatically you just have to call initalize all the time before you start working with OrendaCalculator. You can do it in `ApplicationDelegate didFinishLaunchingWithOptions` for example.

#### Example:

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

## OrendaCalculator API
After initialize you are able to call OrendaCalculator methods. Here are the examples

### Calculate LSI
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

### Calculate dosages
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

### Estimate pool volume
If you pass `ORENDA_USA`, result will be in gallons, and parameters are considered to be in feets. If you pass `ORENDA_METRIC` meters and liters will be used.
```Swift
let poolVolume = OrendaCalculator.estimatePoolVolume(shape: .circle(radius: 100, depth: 20), measurement: ORENDA_USA)
```

# Android

## Setup 

1) Copy OrendaFormula.aar to your app/libs folder
2) Add a dependency to your app/build.gradle.kts
```
dependencies {
    ...
    implementation(files("libs/OrendaFormula.aar"))
}
```
3) Before using any methods of OrendaCalculator class you have to initialize the formula. Call `init` method of OrendaCalculator and pass your token. 
#### Note:
`init` method shoould be called on a BACKGROUND thread.
#### Note:
Internet connection is required to initialize OrendaCalculator for the first time. Then you have to connect to the internet at least once per 2 weeks or per 1 month to update the token. The delay is sepcified in the token, issued to you. SDK does everything autmatically you just have to call initalize all the time you start working with OrendaCalculator. You can do it in Application.onCreate for example.

#### Example:
```Kotlin
import com.orenda.formula.OrendaCalculator

suspend fun initOrendaCalculator(): Boolean {
    val token = "GVlzMF808NOR/Hhn6BEgSt8o6iNITqdd0B+2LfHRqHEgu117BzFuCPIDppjJItSn05C8fus1CBJntKSY3NAJ37rT8EPVqCRSsdsglee0Kn9+ma7/r2b47jXYFQka9zq/dsV91xdlAhV7nZGWQpxFkAyC4aR1EaefR8shqiSFW8WGg8mgoAbYBhj4wyWBYaeD3IZjyavaXhO9fYnSuoMjRKEvTfBhmf+Qd+1z1MDU0VkovdDN2y4P2FkBtVnq5M+x"
    return withContext(Dispatchers.IO) {
        OrendaCalculator.init(token)
    }
}
```

## OrendaCalculator API
After initialize you are able to call OrendaCalculator methods. Here are the examples

### Calculate LSI
```Kotlin
val lsi = OrendaCalculator.calculateLSI(
    waterTemperatureCurrent = Temperature.Fahrenheit(80.0),
    waterTemperatureDesired = Temperature.Fahrenheit(80.0),
    pHCurrent = 7.6,
    pHDesired = 8.1,
    totalAlkalinityCurrent = 80.0,
    totalAlkalinityDesired = 90.0,
    calciumCurrent = 320.0,
    calciumDesired = 370.0,
    cyaCurrent = 35.0,
    cyaDesired = 0.0,
    saltCurrent = 400.0,
    saltDesired = 900.0,
    boratesCurrent = 0.0,
    boratesDesired = 0.0
) ?: throw IllegalStateException("Orenda hasn't been initialized")

Log.d("lsi", lsi.toString())
```

### Calculate dosages
`calculateDosages` returns json data, used to render Orenda app's calculation result screen.
You can pass either `Measurement.USA` or `Measurement.METRIC` for different measurement units.
```Kotlin
val dosagesJson = OrendaCalculator.calculateDosages(
    poolVolume = PoolVolume.Gallons(666.0),
    currentTemperature = Temperature.Fahrenheit(87.0),
    pHCurrent = 7.6,
    pHDesired = 8.1,
    totalAlkalinityCurrent = 80.0,
    totalAlkalinityDesired = 90.0,
    calciumCurrent = 320.0,
    calciumDesired = 370.0,
    cyaCurrent = 35.0,
    cyaDesired = 0.0,
    saltCurrent = 400.0,
    saltDesired = 900.0,
    boratesCurrent = 0.0,
    measurement = Measurement.USA,
    chlorineCurrent = 0.0,
    chlorineDesired = 9.5,
    phosphateCurrent = 500.0,
    phosphateDesired = 0.0
)

Log.d("dosages", dosagesJson)
```

### Estimate pool volume
If you pass `Measurement.USA`, result will be in gallons, and parameters are considered to be in feets. If you pass `Measurement.METRIC` meters and liters will be used.
```Swift
val poolVolume = OrendaCalculator.estimatePoolVolume(
    poolShape = PoolShape.Rectangle(
        width = 100.0,
        length = 100.0,
        shallowDepth = 10.0,
        deepDepth = 10.0
    ),
    measurement = Measurement.USA
)
```

# Web API

## Authentication

In order to use the API you need to authenticate first.
For authentication use this method.
```
https://orendatechapi.com/auth
POST
```
And pass the token, issued to you as its body.
<img width="1442" alt="Screenshot 2023-02-25 at 7 24 50 PM (1)" src="https://github.com/Orenda-Technologies/OrendaFormulaSDKDocs/assets/12134914/08b64919-ca3e-483d-b253-25e3e78d7439">
You will get another token. And you pass that token to `calculateLSI` and `dosageRecommendations` calls as Bearer token.
![unnamed (1) (1)](https://github.com/Orenda-Technologies/OrendaFormulaSDKDocs/assets/12134914/65d70d00-82e2-49a3-a2e7-e26fb237253d)

### Token expiration

When the token returned from `/auth` POST call is expired you will receive 401 error while calling API methods. To renew the token call `/auth` again.

## Calculate LSI

**Here is the example link:**

GET https://orendatechapi.com/calculateLSI?waterTemperatureCurrentF=80&phCurrent=7.6&totalAlkalinityCurrent=80&calciumCurrent=300&cyaCurrent=145&saltCurrent=400&boratesCurrent=80&waterTemperatureDesiredF=77&phDesired=8.2&totalAlkalinityDesired=15&calciumDesired=220&cyaDesired=5&saltDesired=0&boratesDesired=0

The API Call returns currend and desired LSI

All the parameters are required and necessary, because all of them affect the result. For water temperature you can pass waterTemperatureCurrentF/waterTemperatureDesiredF for temperature in Fahrenheit or waterTemperatureCurrentC/waterTemperatureDesiredC for temperature in Celsius. 

## Get dosage recommendations

**Here is the example link:**

GET https://orendatechapi.com/dosageRecommendations?gallons=1000&measurement=usa&waterTemperatureCurrentF=80&phCurrent=7.6&totalAlkalinityCurrent=80&calciumCurrent=300&cyaCurrent=145&saltCurrent=400&boratesCurrent=80&chlorineCurrent=6.5&phosphateCurrent=2000&phDesired=8.2&totalAlkalinityDesired=15&calciumDesired=220&cyaDesired=5&saltDesired=0&chlorineDesired=9.5&phosphateDesired=1100

As measurement you can pass `usa` or `metric`. All parameters are required, however not all of them are necessary. It means you can skip several values by passing the same values for current and desired. However note that proper temperature is required to calculate pH and futureAlkalinity.

The API call returns dosage recommendations to achieve the desired result from the passed current values as well as dosage recommendations for pool maintenance using Orenda products.

## Calculate LSI Batch

With this API call you could calculate several LSI results using a single call.

POST https://orendatechapi.com/calculateLSIBatch

Example JSON body:

```JSON
[
  {
    "waterTemperatureCurrentF": 80,
    "phCurrent": 6.6,
    "totalAlkalinityCurrent": 80,
    "calciumCurrent":  300,
    "cyaCurrent": 145,
    "saltCurrent": 400,
    "boratesCurrent": 80,
    "waterTemperatureDesiredF": 77,
    "phDesired": 8.2,
    "totalAlkalinityDesired": 15,
    "calciumDesired": 220,
    "cyaDesired": 5,
    "saltDesired": 0,
    "boratesDesired": 0
  },
  {
    "waterTemperatureCurrentF": 80,
    "phCurrent": 9.6,
    "totalAlkalinityCurrent": 80,
    "calciumCurrent":  300,
    "cyaCurrent": 145,
    "saltCurrent": 400,
    "boratesCurrent": 80,
    "waterTemperatureDesiredF": 77,
    "phDesired": 8.2,
    "totalAlkalinityDesired": 15,
    "calciumDesired": 220,
    "cyaDesired": 5,
    "saltDesired": 0,
    "boratesDesired": 0
  },
  {
    "waterTemperatureCurrentF": 80,
    "phCurrent": 7.6,
    "totalAlkalinityCurrent": 80,
    "calciumCurrent":  300,
    "cyaCurrent": 145,
    "saltCurrent": 400,
    "boratesCurrent": 80,
    "waterTemperatureDesiredF": 77,
    "phDesired": 4.2,
    "totalAlkalinityDesired": 15,
    "calciumDesired": 220,
    "cyaDesired": 5,
    "saltDesired": 0,
    "boratesDesired": 0
  }
]
```

The call returns an array of LSI results for each parameters set.


