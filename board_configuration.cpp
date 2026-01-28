#include "pch.h"
#include "hellen_meta.h"
#include "defaults.h"
#include "board_overrides.h"
#include "hellen_leds_100.cpp"

static void customBoardDefaultConfiguration() {
    setHellenVbatt();
    setHellenCan();
    setDefaultHellenAtPullUps();
    //hellenMegaSdWithAccelerometer();
    setHellenMegaEnPin();
    setHellenMMbaro();

    engineConfiguration->displayLogicLevelsInEngineSniffer = true;
	engineConfiguration->globalTriggerAngleOffset = 0;
	engineConfiguration->canTxPin = Gpio::MM100_CAN_TX;
	engineConfiguration->canRxPin = Gpio::MM100_CAN_RX;
	engineConfiguration->fanPin = Gpio::MM100_OUT_PWM1;
	engineConfiguration->fuelPumpPin = Gpio::MM100_OUT_PWM2;
	engineConfiguration->tachOutputPin = Gpio::MM100_INJ5;
    
    engineConfiguration->injectionPins[0] = Gpio::MM100_INJ1;
	engineConfiguration->injectionPins[1] = Gpio::MM100_INJ2;
	engineConfiguration->injectionPins[2] = Gpio::MM100_INJ3;
    engineConfiguration->injectionPins[3] = Gpio::MM100_INJ4;

    engineConfiguration->ignitionPins[0] = Gpio::MM100_IGN1;
	engineConfiguration->ignitionPins[1] = Gpio::MM100_IGN2;
	engineConfiguration->ignitionPins[2] = Gpio::MM100_IGN3;

    engineConfiguration->tps1_1AdcChannel = MM100_IN_TPS_ANALOG;
	engineConfiguration->map.sensor.hwChannel = MM100_IN_MAP1_ANALOG;
	engineConfiguration->clt.adcChannel = MM100_IN_CLT_ANALOG;
	engineConfiguration->iat.adcChannel = MM100_IN_IAT_ANALOG;

	engineConfiguration->triggerInputPins[0] = Gpio::MM100_UART8_TX; // VR2 max9924 is the safer default
	engineConfiguration->camInputs[0] = Gpio::MM100_IN_D1;

    // PWM pin
	engineConfiguration->stepperDcIo[0].controlPin = Gpio::MM100_OUT_PWM3;
	// DIR pin
	engineConfiguration->stepperDcIo[0].directionPin1 = Gpio::MM100_OUT_PWM4;
	// Disable pin
	engineConfiguration->stepperDcIo[0].disablePin = Gpio::MM100_SPI2_MISO;
	// PWM pin
	engineConfiguration->stepperDcIo[1].controlPin = Gpio::MM100_OUT_PWM5;
	// DIR pin
	engineConfiguration->stepperDcIo[1].directionPin1 = Gpio::MM100_SPI2_MOSI;
	// Disable pin
	engineConfiguration->stepperDcIo[1].disablePin = Gpio::MM100_USB1ID;

    engineConfiguration->enableVerboseCanTx = true;
	engineConfiguration->injectionMode = IM_BATCH;
	engineConfiguration->etbFunctions[0] = DC_None;

    setCrankOperationMode();

    setCommonNTCSensor(&engineConfiguration->clt, HELLEN_DEFAULT_AT_PULLUP);
	setCommonNTCSensor(&engineConfiguration->iat, HELLEN_DEFAULT_AT_PULLUP);

	setTPS1Calibration(100, 650);

}


void setup_custom_board_overrides() {
	custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
}