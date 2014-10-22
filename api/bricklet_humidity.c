/*************************************************************
 * This file was automatically generated on 2012-04-11.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_humidity.h"

#include <string.h>

#define TYPE_GET_HUMIDITY 1
#define TYPE_GET_ANALOG_VALUE 2
#define TYPE_SET_HUMIDITY_CALLBACK_PERIOD 3
#define TYPE_GET_HUMIDITY_CALLBACK_PERIOD 4
#define TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD 5
#define TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD 6
#define TYPE_SET_HUMIDITY_CALLBACK_THRESHOLD 7
#define TYPE_GET_HUMIDITY_CALLBACK_THRESHOLD 8
#define TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD 9
#define TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD 10
#define TYPE_SET_DEBOUNCE_PERIOD 11
#define TYPE_GET_DEBOUNCE_PERIOD 12
#define TYPE_HUMIDITY 13
#define TYPE_ANALOG_VALUE 14
#define TYPE_HUMIDITY_REACHED 15
#define TYPE_ANALOG_VALUE_REACHED 16

typedef void (*humidity_func_t)(uint16_t);
typedef void (*analog_value_func_t)(uint16_t);
typedef void (*humidity_reached_func_t)(uint16_t);
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
} PACKED GetHumidity_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t humidity;
} PACKED GetHumidityReturn_;

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
} PACKED SetHumidityCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetHumidityCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetHumidityCallbackPeriodReturn_;

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
} PACKED SetHumidityCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetHumidityCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED GetHumidityCallbackThresholdReturn_;

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
	uint16_t humidity;
} PACKED HumidityCallback_;

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
	uint16_t humidity;
} PACKED HumidityReachedCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED AnalogValueReachedCallback_;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif

int humidity_get_humidity(Humidity *humidity, uint16_t *ret_humidity) {
	if(humidity->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(humidity);

	humidity->answer.type = TYPE_GET_HUMIDITY;
	humidity->answer.length = sizeof(GetHumidityReturn_);
	GetHumidity_ gh;
	gh.stack_id = humidity->stack_id;
	gh.type = TYPE_GET_HUMIDITY;
	gh.length = sizeof(GetHumidity_);

	ipcon_device_write(humidity, (char *)&gh, sizeof(GetHumidity_));

	if(ipcon_answer_sem_wait_timeout(humidity) != 0) {
		ipcon_sem_post_write(humidity);
		return E_TIMEOUT;
	}

	GetHumidityReturn_ *ghr = (GetHumidityReturn_ *)humidity->answer.buffer;
	*ret_humidity = ghr->humidity;

	ipcon_sem_post_write(humidity);

	return E_OK;
}

int humidity_get_analog_value(Humidity *humidity, uint16_t *ret_value) {
	if(humidity->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(humidity);

	humidity->answer.type = TYPE_GET_ANALOG_VALUE;
	humidity->answer.length = sizeof(GetAnalogValueReturn_);
	GetAnalogValue_ gav;
	gav.stack_id = humidity->stack_id;
	gav.type = TYPE_GET_ANALOG_VALUE;
	gav.length = sizeof(GetAnalogValue_);

	ipcon_device_write(humidity, (char *)&gav, sizeof(GetAnalogValue_));

	if(ipcon_answer_sem_wait_timeout(humidity) != 0) {
		ipcon_sem_post_write(humidity);
		return E_TIMEOUT;
	}

	GetAnalogValueReturn_ *gavr = (GetAnalogValueReturn_ *)humidity->answer.buffer;
	*ret_value = gavr->value;

	ipcon_sem_post_write(humidity);

	return E_OK;
}

int humidity_set_humidity_callback_period(Humidity *humidity, uint32_t period) {
	if(humidity->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(humidity);

	SetHumidityCallbackPeriod_ shcp;
	shcp.stack_id = humidity->stack_id;
	shcp.type = TYPE_SET_HUMIDITY_CALLBACK_PERIOD;
	shcp.length = sizeof(SetHumidityCallbackPeriod_);
	shcp.period = period;

	ipcon_device_write(humidity, (char *)&shcp, sizeof(SetHumidityCallbackPeriod_));

	ipcon_sem_post_write(humidity);

	return E_OK;
}

int humidity_get_humidity_callback_period(Humidity *humidity, uint32_t *ret_period) {
	if(humidity->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(humidity);

	humidity->answer.type = TYPE_GET_HUMIDITY_CALLBACK_PERIOD;
	humidity->answer.length = sizeof(GetHumidityCallbackPeriodReturn_);
	GetHumidityCallbackPeriod_ ghcp;
	ghcp.stack_id = humidity->stack_id;
	ghcp.type = TYPE_GET_HUMIDITY_CALLBACK_PERIOD;
	ghcp.length = sizeof(GetHumidityCallbackPeriod_);

	ipcon_device_write(humidity, (char *)&ghcp, sizeof(GetHumidityCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(humidity) != 0) {
		ipcon_sem_post_write(humidity);
		return E_TIMEOUT;
	}

	GetHumidityCallbackPeriodReturn_ *ghcpr = (GetHumidityCallbackPeriodReturn_ *)humidity->answer.buffer;
	*ret_period = ghcpr->period;

	ipcon_sem_post_write(humidity);

	return E_OK;
}

int humidity_set_analog_value_callback_period(Humidity *humidity, uint32_t period) {
	if(humidity->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(humidity);

	SetAnalogValueCallbackPeriod_ savcp;
	savcp.stack_id = humidity->stack_id;
	savcp.type = TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD;
	savcp.length = sizeof(SetAnalogValueCallbackPeriod_);
	savcp.period = period;

	ipcon_device_write(humidity, (char *)&savcp, sizeof(SetAnalogValueCallbackPeriod_));

	ipcon_sem_post_write(humidity);

	return E_OK;
}

int humidity_get_analog_value_callback_period(Humidity *humidity, uint32_t *ret_period) {
	if(humidity->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(humidity);

	humidity->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	humidity->answer.length = sizeof(GetAnalogValueCallbackPeriodReturn_);
	GetAnalogValueCallbackPeriod_ gavcp;
	gavcp.stack_id = humidity->stack_id;
	gavcp.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	gavcp.length = sizeof(GetAnalogValueCallbackPeriod_);

	ipcon_device_write(humidity, (char *)&gavcp, sizeof(GetAnalogValueCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(humidity) != 0) {
		ipcon_sem_post_write(humidity);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackPeriodReturn_ *gavcpr = (GetAnalogValueCallbackPeriodReturn_ *)humidity->answer.buffer;
	*ret_period = gavcpr->period;

	ipcon_sem_post_write(humidity);

	return E_OK;
}

int humidity_set_humidity_callback_threshold(Humidity *humidity, char option, int16_t min, int16_t max) {
	if(humidity->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(humidity);

	SetHumidityCallbackThreshold_ shct;
	shct.stack_id = humidity->stack_id;
	shct.type = TYPE_SET_HUMIDITY_CALLBACK_THRESHOLD;
	shct.length = sizeof(SetHumidityCallbackThreshold_);
	shct.option = option;
	shct.min = min;
	shct.max = max;

	ipcon_device_write(humidity, (char *)&shct, sizeof(SetHumidityCallbackThreshold_));

	ipcon_sem_post_write(humidity);

	return E_OK;
}

int humidity_get_humidity_callback_threshold(Humidity *humidity, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	if(humidity->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(humidity);

	humidity->answer.type = TYPE_GET_HUMIDITY_CALLBACK_THRESHOLD;
	humidity->answer.length = sizeof(GetHumidityCallbackThresholdReturn_);
	GetHumidityCallbackThreshold_ ghct;
	ghct.stack_id = humidity->stack_id;
	ghct.type = TYPE_GET_HUMIDITY_CALLBACK_THRESHOLD;
	ghct.length = sizeof(GetHumidityCallbackThreshold_);

	ipcon_device_write(humidity, (char *)&ghct, sizeof(GetHumidityCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(humidity) != 0) {
		ipcon_sem_post_write(humidity);
		return E_TIMEOUT;
	}

	GetHumidityCallbackThresholdReturn_ *ghctr = (GetHumidityCallbackThresholdReturn_ *)humidity->answer.buffer;
	*ret_option = ghctr->option;
	*ret_min = ghctr->min;
	*ret_max = ghctr->max;

	ipcon_sem_post_write(humidity);

	return E_OK;
}

int humidity_set_analog_value_callback_threshold(Humidity *humidity, char option, uint16_t min, uint16_t max) {
	if(humidity->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(humidity);

	SetAnalogValueCallbackThreshold_ savct;
	savct.stack_id = humidity->stack_id;
	savct.type = TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	savct.length = sizeof(SetAnalogValueCallbackThreshold_);
	savct.option = option;
	savct.min = min;
	savct.max = max;

	ipcon_device_write(humidity, (char *)&savct, sizeof(SetAnalogValueCallbackThreshold_));

	ipcon_sem_post_write(humidity);

	return E_OK;
}

int humidity_get_analog_value_callback_threshold(Humidity *humidity, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
	if(humidity->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(humidity);

	humidity->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	humidity->answer.length = sizeof(GetAnalogValueCallbackThresholdReturn_);
	GetAnalogValueCallbackThreshold_ gavct;
	gavct.stack_id = humidity->stack_id;
	gavct.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	gavct.length = sizeof(GetAnalogValueCallbackThreshold_);

	ipcon_device_write(humidity, (char *)&gavct, sizeof(GetAnalogValueCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(humidity) != 0) {
		ipcon_sem_post_write(humidity);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackThresholdReturn_ *gavctr = (GetAnalogValueCallbackThresholdReturn_ *)humidity->answer.buffer;
	*ret_option = gavctr->option;
	*ret_min = gavctr->min;
	*ret_max = gavctr->max;

	ipcon_sem_post_write(humidity);

	return E_OK;
}

int humidity_set_debounce_period(Humidity *humidity, uint32_t debounce) {
	if(humidity->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(humidity);

	SetDebouncePeriod_ sdp;
	sdp.stack_id = humidity->stack_id;
	sdp.type = TYPE_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod_);
	sdp.debounce = debounce;

	ipcon_device_write(humidity, (char *)&sdp, sizeof(SetDebouncePeriod_));

	ipcon_sem_post_write(humidity);

	return E_OK;
}

int humidity_get_debounce_period(Humidity *humidity, uint32_t *ret_debounce) {
	if(humidity->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(humidity);

	humidity->answer.type = TYPE_GET_DEBOUNCE_PERIOD;
	humidity->answer.length = sizeof(GetDebouncePeriodReturn_);
	GetDebouncePeriod_ gdp;
	gdp.stack_id = humidity->stack_id;
	gdp.type = TYPE_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod_);

	ipcon_device_write(humidity, (char *)&gdp, sizeof(GetDebouncePeriod_));

	if(ipcon_answer_sem_wait_timeout(humidity) != 0) {
		ipcon_sem_post_write(humidity);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn_ *gdpr = (GetDebouncePeriodReturn_ *)humidity->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(humidity);

	return E_OK;
}

int humidity_get_version(Humidity *humidity, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, humidity->name, 40);

	ret_firmware_version[0] = humidity->firmware_version[0];
	ret_firmware_version[1] = humidity->firmware_version[1];
	ret_firmware_version[2] = humidity->firmware_version[2];

	ret_binding_version[0] = humidity->binding_version[0];
	ret_binding_version[1] = humidity->binding_version[1];
	ret_binding_version[2] = humidity->binding_version[2];

	return E_OK;
}

int humidity_callback_humidity(Humidity *humidity, const unsigned char *buffer) {
	HumidityCallback_ *hc = (HumidityCallback_ *)buffer;
	((humidity_func_t)humidity->callbacks[hc->type])(hc->humidity);
	return sizeof(HumidityCallback_);
}

int humidity_callback_analog_value(Humidity *humidity, const unsigned char *buffer) {
	AnalogValueCallback_ *avc = (AnalogValueCallback_ *)buffer;
	((analog_value_func_t)humidity->callbacks[avc->type])(avc->value);
	return sizeof(AnalogValueCallback_);
}

int humidity_callback_humidity_reached(Humidity *humidity, const unsigned char *buffer) {
	HumidityReachedCallback_ *hrc = (HumidityReachedCallback_ *)buffer;
	((humidity_reached_func_t)humidity->callbacks[hrc->type])(hrc->humidity);
	return sizeof(HumidityReachedCallback_);
}

int humidity_callback_analog_value_reached(Humidity *humidity, const unsigned char *buffer) {
	AnalogValueReachedCallback_ *avrc = (AnalogValueReachedCallback_ *)buffer;
	((analog_value_reached_func_t)humidity->callbacks[avrc->type])(avrc->value);
	return sizeof(AnalogValueReachedCallback_);
}

void humidity_register_callback(Humidity *humidity, uint8_t cb, void *func) {
    humidity->callbacks[cb] = func;
}

void humidity_create(Humidity *humidity, const char *uid) {
	ipcon_device_create(humidity, uid);

	humidity->binding_version[0] = 1;
	humidity->binding_version[1] = 0;
	humidity->binding_version[2] = 0;

	humidity->device_callbacks[TYPE_HUMIDITY] = humidity_callback_humidity;
	humidity->device_callbacks[TYPE_ANALOG_VALUE] = humidity_callback_analog_value;
	humidity->device_callbacks[TYPE_HUMIDITY_REACHED] = humidity_callback_humidity_reached;
	humidity->device_callbacks[TYPE_ANALOG_VALUE_REACHED] = humidity_callback_analog_value_reached;
}
