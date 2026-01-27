BOARDCPPSRC =  $(BOARD_DIR)/board_configuration.cpp \


BOARDINC += $(BOARD_DIR)/generated/controllers/generated

# defines SHORT_BOARD_NAME
include $(BOARD_DIR)/meta-info.env

DDEFS += -DEFI_SOFTWARE_KNOCK=FALSE
DDEFS += -DDIAG_5VP_PIN=Gpio::MM100_SPI3_MOSI
DDEFS += -DEFI_ELECTRONIC_THROTTLE_BODY=FALSE
DDEFS += -DEFI_TCU=FALSE
DDEFS += -DEEFI_ONBOARD_MEMS=TRUE
DDEFS += -DEEFI_STORAGE_MFS=TRUE

# this is usually used by Bluetooth
DDEFS += $(PRIMARY_COMMUNICATION_PORT_USART2)

# this includes knock and mux control settings
include $(BOARDS_DIR)/hellen/hellen-common100.mk
