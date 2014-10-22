/*************************************************************
 * This file was automatically generated on 2012-04-11.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_voltage.h"

#include <string.h>

#define TYPE_GET_VOLTAGE 1
#define TYPE_GET_ANALOG_VALUE 2
#define TYPE_SET_VOLTAGE_CALLBACK_PERIOD 3
#define TYPE_GET_VOLTAGE_CALLBACK_PERIOD 4
#define TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD 5
#define TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD 6
#define TYPE_SET_VOLTAGE_CALLBACK_THRESHOLD 7
#define TYPE_GET_VOLTAGE_CALLBACK_THRESHOLD 8
#define TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD 9
#define TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD 10
#define TYPE_SET_DEBOUNCE_PERIOD 11
#define TYPE_GET_DEBOUNCE_PERIOD 12
#define TYPE_VOLTAGE 13
#define TYPE_ANALOG_VALUE 14
#define TYPE_VOLTAGE_REACHED 15
#define TYPE_ANALOG_VALUE_REACHED 16

typedef void (*voltage_func_t)(uint16_t);
typedef void (*analog_value_func_t)(uint16_t);
typedef void (*voltage_reached_func_t)(uint16_t);
typedef void (*analog_value_reached_func_t)(uint16_t);

#ifdef _MSC_VER
	#pragma pack(push)
	#pragma pack(1)

	#define PACKED
#else
	#define PACKED __attribute__((packed))
#endif

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetVoltage_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t voltage;
} PACKED GetVoltageReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValue_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED GetAnalogValueReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED SetVoltageCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetVoltageCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetVoltageCallbackPeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED SetAnalogValueCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValueCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetAnalogValueCallbackPeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED SetVoltageCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetVoltageCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED GetVoltageCallbackThresholdReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	uint16_t min;
	uint16_t max;
} PACKED SetAnalogValueCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValueCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	uint16_t min;
	uint16_t max;
} PACKED GetAnalogValueCallbackThresholdReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t debounce;
} PACKED SetDebouncePeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetDebouncePeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t debounce;
} PACKED GetDebouncePeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t voltage;
} PACKED VoltageCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED AnalogValueCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t voltage;
} PACKED VoltageReachedCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED AnalogValueReachedCallback_;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif

int voltage_get_voltage(Voltage *voltage, uint16_t *ret_voltage) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	voltage->answer.type = TYPE_GET_VOLTAGE;
	voltage->answer.length = sizeof(GetVoltageReturn_);
	GetVoltage_ gv;
	gv.stack_id = voltage->stack_id;
	gv.type = TYPE_GET_VOLTAGE;
	gv.length = sizeof(GetVoltage_);

	ipcon_device_write(voltage, (char *)&gv, sizeof(GetVoltage_));

	if(ipcon_answer_sem_wait_timeout(voltage) != 0) {
		ipcon_sem_post_write(voltage);
		return E_TIMEOUT;
	}

	GetVoltageReturn_ *gvr = (GetVoltageReturn_ *)voltage->answer.buffer;
	*ret_voltage = gvr->voltage;

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_get_analog_value(Voltage *voltage, uint16_t *ret_value) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	voltage->answer.type = TYPE_GET_ANALOG_VALUE;
	voltage->answer.length = sizeof(GetAnalogValueReturn_);
	GetAnalogValue_ gav;
	gav.stack_id = voltage->stack_id;
	gav.type = TYPE_GET_ANALOG_VALUE;
	gav.length = sizeof(GetAnalogValue_);

	ipcon_device_write(voltage, (char *)&gav, sizeof(GetAnalogValue_));

	if(ipcon_answer_sem_wait_timeout(voltage) != 0) {
		ipcon_sem_post_write(voltage);
		return E_TIMEOUT;
	}

	GetAnalogValueReturn_ *gavr = (GetAnalogValueReturn_ *)voltage->answer.buffer;
	*ret_value = gavr->value;

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_set_voltage_callback_period(Voltage *voltage, uint32_t period) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	SetVoltageCallbackPeriod_ svcp;
	svcp.stack_id = voltage->stack_id;
	svcp.type = TYPE_SET_VOLTAGE_CALLBACK_PERIOD;
	svcp.length = sizeof(SetVoltageCallbackPeriod_);
	svcp.period = period;

	ipcon_device_write(voltage, (char *)&svcp, sizeof(SetVoltageCallbackPeriod_));

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_get_voltage_callback_period(Voltage *voltage, uint32_t *ret_period) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	voltage->answer.type = TYPE_GET_VOLTAGE_CALLBACK_PERIOD;
	voltage->answer.length = sizeof(GetVoltageCallbackPeriodReturn_);
	GetVoltageCallbackPeriod_ gvcp;
	gvcp.stack_id = voltage->stack_id;
	gvcp.type = TYPE_GET_VOLTAGE_CALLBACK_PERIOD;
	gvcp.length = sizeof(GetVoltageCallbackPeriod_);

	ipcon_device_write(voltage, (char *)&gvcp, sizeof(GetVoltageCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(voltage) != 0) {
		ipcon_sem_post_write(voltage);
		return E_TIMEOUT;
	}

	GetVoltageCallbackPeriodReturn_ *gvcpr = (GetVoltageCallbackPeriodReturn_ *)voltage->answer.buffer;
	*ret_period = gvcpr->period;

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_set_analog_value_callback_period(Voltage *voltage, uint32_t period) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	SetAnalogValueCallbackPeriod_ savcp;
	savcp.stack_id = voltage->stack_id;
	savcp.type = TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD;
	savcp.length = sizeof(SetAnalogValueCallbackPeriod_);
	savcp.period = period;

	ipcon_device_write(voltage, (char *)&savcp, sizeof(SetAnalogValueCallbackPeriod_));

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_get_analog_value_callback_period(Voltage *voltage, uint32_t *ret_period) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	voltage->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	voltage->answer.length = sizeof(GetAnalogValueCallbackPeriodReturn_);
	GetAnalogValueCallbackPeriod_ gavcp;
	gavcp.stack_id = voltage->stack_id;
	gavcp.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	gavcp.length = sizeof(GetAnalogValueCallbackPeriod_);

	ipcon_device_write(voltage, (char *)&gavcp, sizeof(GetAnalogValueCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(voltage) != 0) {
		ipcon_sem_post_write(voltage);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackPeriodReturn_ *gavcpr = (GetAnalogValueCallbackPeriodReturn_ *)voltage->answer.buffer;
	*ret_period = gavcpr->period;

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_set_voltage_callback_threshold(Voltage *voltage, char option, int16_t min, int16_t max) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	SetVoltageCallbackThreshold_ svct;
	svct.stack_id = voltage->stack_id;
	svct.type = TYPE_SET_VOLTAGE_CALLBACK_THRESHOLD;
	svct.length = sizeof(SetVoltageCallbackThreshold_);
	svct.option = option;
	svct.min = min;
	svct.max = max;

	ipcon_device_write(voltage, (char *)&svct, sizeof(SetVoltageCallbackThreshold_));

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_get_voltage_callback_threshold(Voltage *voltage, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	voltage->answer.type = TYPE_GET_VOLTAGE_CALLBACK_THRESHOLD;
	voltage->answer.length = sizeof(GetVoltageCallbackThresholdReturn_);
	GetVoltageCallbackThreshold_ gvct;
	gvct.stack_id = voltage->stack_id;
	gvct.type = TYPE_GET_VOLTAGE_CALLBACK_THRESHOLD;
	gvct.length = sizeof(GetVoltageCallbackThreshold_);

	ipcon_device_write(voltage, (char *)&gvct, sizeof(GetVoltageCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(voltage) != 0) {
		ipcon_sem_post_write(voltage);
		return E_TIMEOUT;
	}

	GetVoltageCallbackThresholdReturn_ *gvctr = (GetVoltageCallbackThresholdReturn_ *)voltage->answer.buffer;
	*ret_option = gvctr->option;
	*ret_min = gvctr->min;
	*ret_max = gvctr->max;

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_set_analog_value_callback_threshold(Voltage *voltage, char option, uint16_t min, uint16_t max) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	SetAnalogValueCallbackThreshold_ savct;
	savct.stack_id = voltage->stack_id;
	savct.type = TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	savct.length = sizeof(SetAnalogValueCallbackThreshold_);
	savct.option = option;
	savct.min = min;
	savct.max = max;

	ipcon_device_write(voltage, (char *)&savct, sizeof(SetAnalogValueCallbackThreshold_));

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_get_analog_value_callback_threshold(Voltage *voltage, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	voltage->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	voltage->answer.length = sizeof(GetAnalogValueCallbackThresholdReturn_);
	GetAnalogValueCallbackThreshold_ gavct;
	gavct.stack_id = voltage->stack_id;
	gavct.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	gavct.length = sizeof(GetAnalogValueCallbackThreshold_);

	ipcon_device_write(voltage, (char *)&gavct, sizeof(GetAnalogValueCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(voltage) != 0) {
		ipcon_sem_post_write(voltage);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackThresholdReturn_ *gavctr = (GetAnalogValueCallbackThresholdReturn_ *)voltage->answer.buffer;
	*ret_option = gavctr->option;
	*ret_min = gavctr->min;
	*ret_max = gavctr->max;

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_set_debounce_period(Voltage *voltage, uint32_t debounce) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	SetDebouncePeriod_ sdp;
	sdp.stack_id = voltage->stack_id;
	sdp.type = TYPE_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod_);
	sdp.debounce = debounce;

	ipcon_device_write(voltage, (char *)&sdp, sizeof(SetDebouncePeriod_));

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_get_debounce_period(Voltage *voltage, uint32_t *ret_debounce) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	voltage->answer.type = TYPE_GET_DEBOUNCE_PERIOD;
	voltage->answer.length = sizeof(GetDebouncePeriodReturn_);
	GetDebouncePeriod_ gdp;
	gdp.stack_id = voltage->stack_id;
	gdp.type = TYPE_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod_);

	ipcon_device_write(voltage, (char *)&gdp, sizeof(GetDebouncePeriod_));

	if(ipcon_answer_sem_wait_timeout(voltage) != 0) {
		ipcon_sem_post_write(voltage);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn_ *gdpr = (GetDebouncePeriodReturn_ *)voltage->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_get_version(Voltage *voltage, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, voltage->name, 40);

	ret_firmware_version[0] = voltage->firmware_version[0];
	ret_firmware_version[1] = voltage->firmware_version[1];
	ret_firmware_version[2] = voltage->firmware_version[2];

	ret_binding_version[0] = voltage->binding_version[0];
	ret_binding_version[1] = voltage->binding_version[1];
	ret_binding_version[2] = voltage->binding_version[2];

	return E_OK;
}

int voltage_callback_voltage(Voltage *voltage, const unsigned char *buffer) {
	VoltageCallback_ *vc = (VoltageCallback_ *)buffer;
	((voltage_func_t)voltage->callbacks[vc->type])(vc->voltage);
	return sizeof(VoltageCallback_);
}

int voltage_callback_analog_value(Voltage *voltage, const unsigned char *buffer) {
	AnalogValueCallback_ *avc = (AnalogValueCallback_ *)buffer;
	((analog_value_func_t)voltage->callbacks[avc->type])(avc->value);
	return sizeof(AnalogValueCallback_);
}

int voltage_callback_voltage_reached(Voltage *voltage, const unsigned char *buffer) {
	VoltageReachedCallback_ *vrc = (VoltageReachedCallback_ *)buffer;
	((voltage_reached_func_t)voltage->callbacks[vrc->type])(vrc->voltage);
	return sizeof(VoltageReachedCallback_);
}

int voltage_callback_analog_value_reached(Voltage *voltage, const unsigned char *buffer) {
	AnalogValueReachedCallback_ *avrc = (AnalogValueReachedCallback_ *)buffer;
	((analog_value_reached_func_t)voltage->callbacks[avrc->type])(avrc->value);
	return sizeof(AnalogValueReachedCallback_);
}

void voltage_register_callback(Voltage *voltage, uint8_t cb, void *func) {
    voltage->callbacks[cb] = func;
}

void voltage_create(Voltage *voltage, const char *uid) {
	ipcon_device_create(voltage, uid);

	voltage->binding_version[0] = 1;
	voltage->binding_version[1] = 0;
	voltage->binding_version[2] = 0;

	voltage->device_callbacks[TYPE_VOLTAGE] = voltage_callback_voltage;
	voltage->device_callbacks[TYPE_ANALOG_VALUE] = voltage_callback_analog_value;
	voltage->device_callbacks[TYPE_VOLTAGE_REACHED] = voltage_callback_voltage_reached;
	voltage->device_callbacks[TYPE_ANALOG_VALUE_REACHED] = voltage_callback_analog_value_reached;
}
