/*
 * PsychroLib (version 2.5.0) (https://github.com/psychrometrics/psychrolib).
 * Copyright (c) 2018-2020 The PsychroLib Contributors for the current library implementation.
 * Copyright (c) 2017 ASHRAE Handbook — Fundamentals for ASHRAE equations and coefficients.
 * Licensed under the MIT License.
*/

/******************************************************************************************************
 * Helper functions
 *****************************************************************************************************/

enum UnitSystem { UNDEFINED, IP, SI };

void SetUnitSystem
  ( enum UnitSystem Units       // (i) System of units (IP or SI)
  );

enum UnitSystem GetUnitSystem  // (o) System of units (SI or IP)
  (
  );


/******************************************************************************************************
 * Conversion between temperature units
 *****************************************************************************************************/

float GetTRankineFromTFahrenheit(float T_F);

float GetTFahrenheitFromTRankine(float T_R);

float GetTKelvinFromTCelsius(float T_C);

float GetTCelsiusFromTKelvin(float T_K);


/******************************************************************************************************
 * Conversions between dew point, wet bulb, and relative humidity
 *****************************************************************************************************/

float GetTWetBulbFromTDewPoint // (o) Wet bulb temperature in °F [IP] or °C [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float TDewPoint            // (i) Dew point temperature in °F [IP] or °C [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );

float GetTWetBulbFromRelHum    // (o) Wet bulb temperature in °F [IP] or °C [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float RelHum               // (i) Relative humidity [0-1]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );

float GetRelHumFromTDewPoint   // (o) Relative humidity [0-1]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float TDewPoint            // (i) Dew point temperature in °F [IP] or °C [SI]
  );

float GetRelHumFromTWetBulb    // (o) Relative humidity [0-1]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float TWetBulb             // (i) Wet bulb temperature in °F [IP] or °C [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );

float GetTDewPointFromRelHum   // (o) Dew Point temperature in °F [IP] or °C [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float RelHum               // (i) Relative humidity [0-1]
  );

float GetTDewPointFromTWetBulb // (o) Dew Point temperature in °F [IP] or °C [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float TWetBulb             // (i) Wet bulb temperature in °F [IP] or °C [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );


/******************************************************************************************************
 * Conversions between dew point, or relative humidity and vapor pressure
 *****************************************************************************************************/

float GetVapPresFromRelHum     // (o) Partial pressure of water vapor in moist air in Psi [IP] or Pa [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float RelHum               // (i) Relative humidity [0-1]
  );

float GetRelHumFromVapPres     // (o) Relative humidity [0-1]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float VapPres              // (i) Partial pressure of water vapor in moist air in Psi [IP] or Pa [SI]
  );

float GetTDewPointFromVapPres  // (o) Dew Point temperature in °F [IP] or °C [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float VapPres              // (i) Partial pressure of water vapor in moist air in Psi [IP] or Pa [SI]
  );

float GetVapPresFromTDewPoint  // (o) Partial pressure of water vapor in moist air in Psi [IP] or Pa [SI]
  ( float TDewPoint            // (i) Dew point temperature in °F [IP] or °C [SI]
  );


/******************************************************************************************************
 * Conversions from wet-bulb temperature, dew-point temperature, or relative humidity to humidity ratio
 *****************************************************************************************************/

float GetTWetBulbFromHumRatio  // (o) Wet bulb temperature in °F [IP] or °C [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float HumRatio             // (i) Humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );

float GetHumRatioFromTWetBulb  // (o) Humidity Ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float TWetBulb             // (i) Wet bulb temperature in °F [IP] or °C [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );

float GetHumRatioFromRelHum    // (o) Humidity Ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float RelHum               // (i) Relative humidity [0-1]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );

float GetRelHumFromHumRatio    // (o) Relative humidity [0-1]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float HumRatio             // (i) Humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );

float GetHumRatioFromTDewPoint // (o) Humidity Ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  ( float TDewPoint            // (i) Dew point temperature in °F [IP] or °C [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );

float GetTDewPointFromHumRatio // (o) Dew Point temperature in °F [IP] or °C [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float HumRatio             // (i) Humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );


/******************************************************************************************************
 * Conversions between humidity ratio and vapor pressure
 *****************************************************************************************************/

float GetHumRatioFromVapPres   // (o) Humidity Ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  ( float VapPres              // (i) Partial pressure of water vapor in moist air in Psi [IP] or Pa [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );

float GetVapPresFromHumRatio   // (o) Partial pressure of water vapor in moist air in Psi [IP] or Pa [SI]
  ( float HumRatio             // (i) Humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );


/******************************************************************************************************
 * Conversions between humidity ratio and specific humidity
 *****************************************************************************************************/

float GetSpecificHumFromHumRatio // (o) Specific humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  ( float HumRatio               // (i) Humidity ratio in lb_H₂O lb_Dry_Air⁻¹ [IP] or kg_H₂O kg_Dry_Air⁻¹ [SI]
  );

float GetHumRatioFromSpecificHum // (o) Humidity ratio in lb_H₂O lb_Dry_Air⁻¹ [IP] or kg_H₂O kg_Dry_Air⁻¹ [SI]
  ( float SpecificHum            // (i) Specific humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  );


/******************************************************************************************************
 * Dry Air Calculations
 *****************************************************************************************************/

float GetDryAirEnthalpy                  // (o) Dry air enthalpy in Btu lb⁻¹ [IP] or J kg⁻¹ [SI]
  ( float TDryBulb                       // (i) Dry bulb temperature in °F [IP] or °C [SI]
  );

float GetDryAirDensity                   // (o) Dry air density in lb ft⁻³ [IP] or kg m⁻³ [SI]
  ( float TDryBulb                       // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float Pressure                       // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );

float GetDryAirVolume                    // (o) Dry air volume ft³ lb⁻¹ [IP] or in m³ kg⁻¹ [SI]
  ( float TDryBulb                       // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float Pressure                       // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );

float GetTDryBulbFromEnthalpyAndHumRatio    // (o) Dry-bulb temperature in °F [IP] or °C [SI]
  ( float MoistAirEnthalpy                  // (i) Moist air enthalpy in Btu lb⁻¹ [IP] or J kg⁻¹
  , float HumRatio                          // (i) Humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  );

float GetHumRatioFromEnthalpyAndTDryBulb  // (o) Humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  ( float MoistAirEnthalpy                // (i) Moist air enthalpy in Btu lb⁻¹ [IP] or J kg⁻¹
  , float TDryBulb                        // (i) Dry-bulb temperature in °F [IP] or °C [SI]
  );


/******************************************************************************************************
 * Saturated Air Calculations
 *****************************************************************************************************/

float GetSatVapPres            // (o) Vapor Pressure of saturated air in Psi [IP] or Pa [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  );

float GetSatHumRatio           // (o) Humidity ratio of saturated air in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );

float GetSatAirEnthalpy        // (o) Saturated air enthalpy in Btu lb⁻¹ [IP] or J kg⁻¹ [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );


/******************************************************************************************************
 * Moist Air Calculations
 *****************************************************************************************************/
float GetVaporPressureDeficit  // (o) Vapor pressure deficit in Psi [IP] or Pa [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float HumRatio             // (i) Humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );

float GetDegreeOfSaturation    // (o) Degree of saturation []
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float HumRatio             // (i) Humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );

float GetMoistAirEnthalpy      // (o) Moist Air Enthalpy in Btu lb⁻¹ [IP] or J kg⁻¹ [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float HumRatio             // (i) Humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  );

float GetMoistAirVolume        // (o) Specific Volume ft³ lb⁻¹ [IP] or in m³ kg⁻¹ [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float HumRatio             // (i) Humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );

float GetTDryBulbFromMoistAirVolumeAndHumRatio   // (o) Dry-bulb temperature in °F [IP] or °C [SI]
  ( float MoistAirVolume                         // (i) Specific volume of moist air in ft³ lb⁻¹ of dry air [IP] or in m³ kg⁻¹ of dry air [SI]
  , float HumRatio                               // (i) Humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  , float Pressure                               // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );

float GetMoistAirDensity       // (o) Moist air density in lb ft⁻³ [IP] or kg m⁻³ [SI]
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float HumRatio             // (i) Humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  );


/******************************************************************************************************
 * Standard atmosphere
 *****************************************************************************************************/

float GetStandardAtmPressure   // (o) Standard atmosphere barometric pressure in Psi [IP] or Pa [SI]
  ( float Altitude             // (i) Altitude in ft [IP] or m [SI]
  );

float GetStandardAtmTemperature // (o) Standard atmosphere dry bulb temperature in °F [IP] or °C [SI]
  ( float Altitude              // (i) Altitude in ft [IP] or m [SI]
  );

float GetSeaLevelPressure   // (o) Sea level barometric pressure in Psi [IP] or Pa [SI]
  ( float StnPressure       // (i) Observed station pressure in Psi [IP] or Pa [SI]
  , float Altitude          // (i) Altitude above sea level in ft [IP] or m [SI]
  , float TDryBulb          // (i) Dry bulb temperature ft³ lb⁻¹ [IP] or in m³ kg⁻¹ [SI]
  );

float GetStationPressure    // (o) Station pressure in Psi [IP] or Pa [SI]
  ( float SeaLevelPressure  // (i) Sea level barometric pressure in Psi [IP] or Pa [SI]
  , float Altitude          // (i) Altitude above sea level in ft [IP] or m [SI]
  , float TDryBulb          // (i) Dry bulb temperature in °F [IP] or °C [SI]
  );


/******************************************************************************************************
 * Functions to set all psychrometric values
 *****************************************************************************************************/

void CalcPsychrometricsFromTWetBulb
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float TWetBulb             // (i) Wet bulb temperature in °F [IP] or °C [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  , float *HumRatio            // (o) Humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  , float *TDewPoint           // (o) Dew point temperature in °F [IP] or °C [SI]
  , float *RelHum              // (o) Relative humidity [0-1]
  , float *VapPres             // (o) Partial pressure of water vapor in moist air in Psi [IP] or Pa [SI]
  , float *MoistAirEnthalpy    // (o) Moist air enthalpy in Btu lb⁻¹ [IP] or J kg⁻¹ [SI]
  , float *MoistAirVolume      // (o) Specific volume ft³ lb⁻¹ [IP] or in m³ kg⁻¹ [SI]
  , float *DegreeOfSaturation  // (o) Degree of saturation [unitless]
  );

void CalcPsychrometricsFromTDewPoint
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float TDewPoint            // (i) Dew point temperature in °F [IP] or °C [SI]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  , float *HumRatio            // (o) Humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  , float *TWetBulb            // (o) Wet bulb temperature in °F [IP] or °C [SI]
  , float *RelHum              // (o) Relative humidity [0-1]
  , float *VapPres             // (o) Partial pressure of water vapor in moist air in Psi [IP] or Pa [SI]
  , float *MoistAirEnthalpy    // (o) Moist air enthalpy in Btu lb⁻¹ [IP] or J kg⁻¹ [SI]
  , float *MoistAirVolume      // (o) Specific volume ft³ lb⁻¹ [IP] or in m³ kg⁻¹ [SI]
  , float *DegreeOfSaturation  // (o) Degree of saturation [unitless]
  );

void CalcPsychrometricsFromRelHum
  ( float TDryBulb             // (i) Dry bulb temperature in °F [IP] or °C [SI]
  , float RelHum               // (i) Relative humidity [0-1]
  , float Pressure             // (i) Atmospheric pressure in Psi [IP] or Pa [SI]
  , float *HumRatio            // (o) Humidity ratio in lb_H₂O lb_Air⁻¹ [IP] or kg_H₂O kg_Air⁻¹ [SI]
  , float *TWetBulb            // (o) Wet bulb temperature in °F [IP] or °C [SI]
  , float *TDewPoint           // (o) Dew point temperature in °F [IP] or °C [SI]
  , float *VapPres             // (o) Partial pressure of water vapor in moist air in Psi [IP] or Pa [SI]
  , float *MoistAirEnthalpy    // (o) Moist air enthalpy in Btu lb⁻¹ [IP] or J kg⁻¹ [SI]
  , float *MoistAirVolume      // (o) Specific volume ft³ lb⁻¹ [IP] or in m³ kg⁻¹ [SI]
  , float *DegreeOfSaturation  // (o) Degree of saturation [unitless]
  );
