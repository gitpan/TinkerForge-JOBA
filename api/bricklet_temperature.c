/*************************************************************
 * This file was automatically generated on 2012-04-11.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_temperature.h"

#include <string.h>

#define TYPE_GET_TEMPERATURE 1
#define TYPE_SET_TEMPERATURE_CALLBACK_PERIOD 2
#define TYPE_GET_TEMPERATURE_CALLBACK_PERIOD 3
#define TYPE_SET_TEMPERATURE_CALLBACK_THRESHOLD 4
#define TYPE_GET_TEMPERATURE_CALLBACK_THRESHOLD 5
#define TYPE_SET_DEBOUNCE_PERIOD 6
#define TYPE_GET_DEBOUNCE_PERIOD 7
#define TYPE_TEMPERATURE 8
#define TYPE_TEMPERATURE_REACHED 9

typedef void (*temperature_func_t)(int16_t);
typedef void (*temperature_reached_func_t)(int16_t);

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
} PACKED GetTemperature_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t temperature;
} PACKED GetTemperatureReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED SetTemperatureCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetTemperatureCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetTemperatureCallbackPeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED SetTemperatureCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetTemperatureCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED GetTemperatureCallbackThresholdReturn_;

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
	int16_t temperature;
} PACKED TemperatureCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t temperature;
} PACKED TemperatureReachedCallback_;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif

int temperature_get_temperature(Temperature *temperature, int16_t *ret_temperature) {
	if(temperature->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature);

	temperature->answer.type = TYPE_GET_TEMPERATURE;
	temperature->answer.length = sizeof(GetTemperatureReturn_);
	GetTemperature_ gt;
	gt.stack_id = temperature->stack_id;
	gt.type = TYPE_GET_TEMPERATURE;
	gt.length = sizeof(GetTemperature_);

	ipcon_device_write(temperature, (char *)&gt, sizeof(GetTemperature_));

	if(ipcon_answer_sem_wait_timeout(temperature) != 0) {
		ipcon_sem_post_write(temperature);
		return E_TIMEOUT;
	}

	GetTemperatureReturn_ *gtr = (GetTemperatureReturn_ *)temperature->answer.buffer;
	*ret_temperature = gtr->temperature;

	ipcon_sem_post_write(temperature);

	return E_OK;
}

int temperature_set_temperature_callback_period(Temperature *temperature, uint32_t period) {
	if(temperature->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature);

	SetTemperatureCallbackPeriod_ stcp;
	stcp.stack_id = temperature->stack_id;
	stcp.type = TYPE_SET_TEMPERATURE_CALLBACK_PERIOD;
	stcp.length = sizeof(SetTemperatureCallbackPeriod_);
	stcp.period = period;

	ipcon_device_write(temperature, (char *)&stcp, sizeof(SetTemperatureCallbackPeriod_));

	ipcon_sem_post_write(temperature);

	return E_OK;
}

int temperature_get_temperature_callback_period(Temperature *temperature, uint32_t *ret_period) {
	if(temperature->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature);

	temperature->answer.type = TYPE_GET_TEMPERATURE_CALLBACK_PERIOD;
	temperature->answer.length = sizeof(GetTemperatureCallbackPeriodReturn_);
	GetTemperatureCallbackPeriod_ gtcp;
	gtcp.stack_id = temperature->stack_id;
	gtcp.type = TYPE_GET_TEMPERATURE_CALLBACK_PERIOD;
	gtcp.length = sizeof(GetTemperatureCallbackPeriod_);

	ipcon_device_write(temperature, (char *)&gtcp, sizeof(GetTemperatureCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(temperature) != 0) {
		ipcon_sem_post_write(temperature);
		return E_TIMEOUT;
	}

	GetTemperatureCallbackPeriodReturn_ *gtcpr = (GetTemperatureCallbackPeriodReturn_ *)temperature->answer.buffer;
	*ret_period = gtcpr->period;

	ipcon_sem_post_write(temperature);

	return E_OK;
}

int temperature_set_temperature_callback_threshold(Temperature *temperature, char option, int16_t min, int16_t max) {
	if(temperature->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature);

	SetTemperatureCallbackThreshold_ stct;
	stct.stack_id = temperature->stack_id;
	stct.type = TYPE_SET_TEMPERATURE_CALLBACK_THRESHOLD;
	stct.length = sizeof(SetTemperatureCallbackThreshold_);
	stct.option = option;
	stct.min = min;
	stct.max = max;

	ipcon_device_write(temperature, (char *)&stct, sizeof(SetTemperatureCallbackThreshold_));

	ipcon_sem_post_write(temperature);

	return E_OK;
}

int temperature_get_temperature_callback_threshold(Temperature *temperature, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	if(temperature->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature);

	temperature->answer.type = TYPE_GET_TEMPERATURE_CALLBACK_THRESHOLD;
	temperature->answer.length = sizeof(GetTemperatureCallbackThresholdReturn_);
	GetTemperatureCallbackThreshold_ gtct;
	gtct.stack_id = temperature->stack_id;
	gtct.type = TYPE_GET_TEMPERATURE_CALLBACK_THRESHOLD;
	gtct.length = sizeof(GetTemperatureCallbackThreshold_);

	ipcon_device_write(temperature, (char *)&gtct, sizeof(GetTemperatureCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(temperature) != 0) {
		ipcon_sem_post_write(temperature);
		return E_TIMEOUT;
	}

	GetTemperatureCallbackThresholdReturn_ *gtctr = (GetTemperatureCallbackThresholdReturn_ *)temperature->answer.buffer;
	*ret_option = gtctr->option;
	*ret_min = gtctr->min;
	*ret_max = gtctr->max;

	ipcon_sem_post_write(temperature);

	return E_OK;
}

int temperature_set_debounce_period(Temperature *temperature, uint32_t debounce) {
	if(temperature->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature);

	SetDebouncePeriod_ sdp;
	sdp.stack_id = temperature->stack_id;
	sdp.type = TYPE_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod_);
	sdp.debounce = debounce;

	ipcon_device_write(temperature, (char *)&sdp, sizeof(SetDebouncePeriod_));

	ipcon_sem_post_write(temperature);

	return E_OK;
}

int temperature_get_debounce_period(Temperature *temperature, uint32_t *ret_debounce) {
	if(temperature->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature);

	temperature->answer.type = TYPE_GET_DEBOUNCE_PERIOD;
	temperature->answer.length = sizeof(GetDebouncePeriodReturn_);
	GetDebouncePeriod_ gdp;
	gdp.stack_id = temperature->stack_id;
	gdp.type = TYPE_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod_);

	ipcon_device_write(temperature, (char *)&gdp, sizeof(GetDebouncePeriod_));

	if(ipcon_answer_sem_wait_timeout(temperature) != 0) {
		ipcon_sem_post_write(temperature);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn_ *gdpr = (GetDebouncePeriodReturn_ *)temperature->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(temperature);

	return E_OK;
}

int temperature_get_version(Temperature *temperature, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, temperature->name, 40);

	ret_firmware_version[0] = temperature->firmware_version[0];
	ret_firmware_version[1] = temperature->firmware_version[1];
	ret_firmware_version[2] = temperature->firmware_version[2];

	ret_binding_version[0] = temperature->binding_version[0];
	ret_binding_version[1] = temperature->binding_version[1];
	ret_binding_version[2] = temperature->binding_version[2];

	return E_OK;
}

int temperature_callback_temperature(Temperature *temperature, const unsigned char *buffer) {
	TemperatureCallback_ *tc = (TemperatureCallback_ *)buffer;
	((temperature_func_t)temperature->callbacks[tc->type])(tc->temperature);
	return sizeof(TemperatureCallback_);
}

int temperature_callback_temperature_reached(Temperature *temperature, const unsigned char *buffer) {
	TemperatureReachedCallback_ *trc = (TemperatureReachedCallback_ *)buffer;
	((temperature_reached_func_t)temperature->callbacks[trc->type])(trc->temperature);
	return sizeof(TemperatureReachedCallback_);
}

void temperature_register_callback(Temperature *temperature, uint8_t cb, void *func) {
    temperature->callbacks[cb] = func;
}

void temperature_create(Temperature *temperature, const char *uid) {
	ipcon_device_create(temperature, uid);

	temperature->binding_version[0] = 1;
	temperature->binding_version[1] = 0;
	temperature->binding_version[2] = 0;

	temperature->device_callbacks[TYPE_TEMPERATURE] = temperature_callback_temperature;
	temperature->device_callbacks[TYPE_TEMPERATURE_REACHED] = temperature_callback_temperature_reached;
}
