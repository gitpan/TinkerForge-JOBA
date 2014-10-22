/*************************************************************
 * This file was automatically generated on 2012-04-11.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_ambient_light.h"

#include <string.h>

#define TYPE_GET_ILLUMINANCE 1
#define TYPE_GET_ANALOG_VALUE 2
#define TYPE_SET_ILLUMINANCE_CALLBACK_PERIOD 3
#define TYPE_GET_ILLUMINANCE_CALLBACK_PERIOD 4
#define TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD 5
#define TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD 6
#define TYPE_SET_ILLUMINANCE_CALLBACK_THRESHOLD 7
#define TYPE_GET_ILLUMINANCE_CALLBACK_THRESHOLD 8
#define TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD 9
#define TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD 10
#define TYPE_SET_DEBOUNCE_PERIOD 11
#define TYPE_GET_DEBOUNCE_PERIOD 12
#define TYPE_ILLUMINANCE 13
#define TYPE_ANALOG_VALUE 14
#define TYPE_ILLUMINANCE_REACHED 15
#define TYPE_ANALOG_VALUE_REACHED 16

typedef void (*illuminance_func_t)(uint16_t);
typedef void (*analog_value_func_t)(uint16_t);
typedef void (*illuminance_reached_func_t)(uint16_t);
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
} PACKED GetIlluminance_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t illuminance;
} PACKED GetIlluminanceReturn_;

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
} PACKED SetIlluminanceCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetIlluminanceCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetIlluminanceCallbackPeriodReturn_;

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
} PACKED SetIlluminanceCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetIlluminanceCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED GetIlluminanceCallbackThresholdReturn_;

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
	uint16_t illuminance;
} PACKED IlluminanceCallback_;

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
	uint16_t illuminance;
} PACKED IlluminanceReachedCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED AnalogValueReachedCallback_;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif

int ambient_light_get_illuminance(AmbientLight *ambient_light, uint16_t *ret_illuminance) {
	if(ambient_light->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(ambient_light);

	ambient_light->answer.type = TYPE_GET_ILLUMINANCE;
	ambient_light->answer.length = sizeof(GetIlluminanceReturn_);
	GetIlluminance_ gi;
	gi.stack_id = ambient_light->stack_id;
	gi.type = TYPE_GET_ILLUMINANCE;
	gi.length = sizeof(GetIlluminance_);

	ipcon_device_write(ambient_light, (char *)&gi, sizeof(GetIlluminance_));

	if(ipcon_answer_sem_wait_timeout(ambient_light) != 0) {
		ipcon_sem_post_write(ambient_light);
		return E_TIMEOUT;
	}

	GetIlluminanceReturn_ *gir = (GetIlluminanceReturn_ *)ambient_light->answer.buffer;
	*ret_illuminance = gir->illuminance;

	ipcon_sem_post_write(ambient_light);

	return E_OK;
}

int ambient_light_get_analog_value(AmbientLight *ambient_light, uint16_t *ret_value) {
	if(ambient_light->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(ambient_light);

	ambient_light->answer.type = TYPE_GET_ANALOG_VALUE;
	ambient_light->answer.length = sizeof(GetAnalogValueReturn_);
	GetAnalogValue_ gav;
	gav.stack_id = ambient_light->stack_id;
	gav.type = TYPE_GET_ANALOG_VALUE;
	gav.length = sizeof(GetAnalogValue_);

	ipcon_device_write(ambient_light, (char *)&gav, sizeof(GetAnalogValue_));

	if(ipcon_answer_sem_wait_timeout(ambient_light) != 0) {
		ipcon_sem_post_write(ambient_light);
		return E_TIMEOUT;
	}

	GetAnalogValueReturn_ *gavr = (GetAnalogValueReturn_ *)ambient_light->answer.buffer;
	*ret_value = gavr->value;

	ipcon_sem_post_write(ambient_light);

	return E_OK;
}

int ambient_light_set_illuminance_callback_period(AmbientLight *ambient_light, uint32_t period) {
	if(ambient_light->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(ambient_light);

	SetIlluminanceCallbackPeriod_ sicp;
	sicp.stack_id = ambient_light->stack_id;
	sicp.type = TYPE_SET_ILLUMINANCE_CALLBACK_PERIOD;
	sicp.length = sizeof(SetIlluminanceCallbackPeriod_);
	sicp.period = period;

	ipcon_device_write(ambient_light, (char *)&sicp, sizeof(SetIlluminanceCallbackPeriod_));

	ipcon_sem_post_write(ambient_light);

	return E_OK;
}

int ambient_light_get_illuminance_callback_period(AmbientLight *ambient_light, uint32_t *ret_period) {
	if(ambient_light->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(ambient_light);

	ambient_light->answer.type = TYPE_GET_ILLUMINANCE_CALLBACK_PERIOD;
	ambient_light->answer.length = sizeof(GetIlluminanceCallbackPeriodReturn_);
	GetIlluminanceCallbackPeriod_ gicp;
	gicp.stack_id = ambient_light->stack_id;
	gicp.type = TYPE_GET_ILLUMINANCE_CALLBACK_PERIOD;
	gicp.length = sizeof(GetIlluminanceCallbackPeriod_);

	ipcon_device_write(ambient_light, (char *)&gicp, sizeof(GetIlluminanceCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(ambient_light) != 0) {
		ipcon_sem_post_write(ambient_light);
		return E_TIMEOUT;
	}

	GetIlluminanceCallbackPeriodReturn_ *gicpr = (GetIlluminanceCallbackPeriodReturn_ *)ambient_light->answer.buffer;
	*ret_period = gicpr->period;

	ipcon_sem_post_write(ambient_light);

	return E_OK;
}

int ambient_light_set_analog_value_callback_period(AmbientLight *ambient_light, uint32_t period) {
	if(ambient_light->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(ambient_light);

	SetAnalogValueCallbackPeriod_ savcp;
	savcp.stack_id = ambient_light->stack_id;
	savcp.type = TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD;
	savcp.length = sizeof(SetAnalogValueCallbackPeriod_);
	savcp.period = period;

	ipcon_device_write(ambient_light, (char *)&savcp, sizeof(SetAnalogValueCallbackPeriod_));

	ipcon_sem_post_write(ambient_light);

	return E_OK;
}

int ambient_light_get_analog_value_callback_period(AmbientLight *ambient_light, uint32_t *ret_period) {
	if(ambient_light->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(ambient_light);

	ambient_light->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	ambient_light->answer.length = sizeof(GetAnalogValueCallbackPeriodReturn_);
	GetAnalogValueCallbackPeriod_ gavcp;
	gavcp.stack_id = ambient_light->stack_id;
	gavcp.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	gavcp.length = sizeof(GetAnalogValueCallbackPeriod_);

	ipcon_device_write(ambient_light, (char *)&gavcp, sizeof(GetAnalogValueCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(ambient_light) != 0) {
		ipcon_sem_post_write(ambient_light);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackPeriodReturn_ *gavcpr = (GetAnalogValueCallbackPeriodReturn_ *)ambient_light->answer.buffer;
	*ret_period = gavcpr->period;

	ipcon_sem_post_write(ambient_light);

	return E_OK;
}

int ambient_light_set_illuminance_callback_threshold(AmbientLight *ambient_light, char option, int16_t min, int16_t max) {
	if(ambient_light->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(ambient_light);

	SetIlluminanceCallbackThreshold_ sict;
	sict.stack_id = ambient_light->stack_id;
	sict.type = TYPE_SET_ILLUMINANCE_CALLBACK_THRESHOLD;
	sict.length = sizeof(SetIlluminanceCallbackThreshold_);
	sict.option = option;
	sict.min = min;
	sict.max = max;

	ipcon_device_write(ambient_light, (char *)&sict, sizeof(SetIlluminanceCallbackThreshold_));

	ipcon_sem_post_write(ambient_light);

	return E_OK;
}

int ambient_light_get_illuminance_callback_threshold(AmbientLight *ambient_light, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	if(ambient_light->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(ambient_light);

	ambient_light->answer.type = TYPE_GET_ILLUMINANCE_CALLBACK_THRESHOLD;
	ambient_light->answer.length = sizeof(GetIlluminanceCallbackThresholdReturn_);
	GetIlluminanceCallbackThreshold_ gict;
	gict.stack_id = ambient_light->stack_id;
	gict.type = TYPE_GET_ILLUMINANCE_CALLBACK_THRESHOLD;
	gict.length = sizeof(GetIlluminanceCallbackThreshold_);

	ipcon_device_write(ambient_light, (char *)&gict, sizeof(GetIlluminanceCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(ambient_light) != 0) {
		ipcon_sem_post_write(ambient_light);
		return E_TIMEOUT;
	}

	GetIlluminanceCallbackThresholdReturn_ *gictr = (GetIlluminanceCallbackThresholdReturn_ *)ambient_light->answer.buffer;
	*ret_option = gictr->option;
	*ret_min = gictr->min;
	*ret_max = gictr->max;

	ipcon_sem_post_write(ambient_light);

	return E_OK;
}

int ambient_light_set_analog_value_callback_threshold(AmbientLight *ambient_light, char option, uint16_t min, uint16_t max) {
	if(ambient_light->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(ambient_light);

	SetAnalogValueCallbackThreshold_ savct;
	savct.stack_id = ambient_light->stack_id;
	savct.type = TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	savct.length = sizeof(SetAnalogValueCallbackThreshold_);
	savct.option = option;
	savct.min = min;
	savct.max = max;

	ipcon_device_write(ambient_light, (char *)&savct, sizeof(SetAnalogValueCallbackThreshold_));

	ipcon_sem_post_write(ambient_light);

	return E_OK;
}

int ambient_light_get_analog_value_callback_threshold(AmbientLight *ambient_light, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
	if(ambient_light->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(ambient_light);

	ambient_light->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	ambient_light->answer.length = sizeof(GetAnalogValueCallbackThresholdReturn_);
	GetAnalogValueCallbackThreshold_ gavct;
	gavct.stack_id = ambient_light->stack_id;
	gavct.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	gavct.length = sizeof(GetAnalogValueCallbackThreshold_);

	ipcon_device_write(ambient_light, (char *)&gavct, sizeof(GetAnalogValueCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(ambient_light) != 0) {
		ipcon_sem_post_write(ambient_light);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackThresholdReturn_ *gavctr = (GetAnalogValueCallbackThresholdReturn_ *)ambient_light->answer.buffer;
	*ret_option = gavctr->option;
	*ret_min = gavctr->min;
	*ret_max = gavctr->max;

	ipcon_sem_post_write(ambient_light);

	return E_OK;
}

int ambient_light_set_debounce_period(AmbientLight *ambient_light, uint32_t debounce) {
	if(ambient_light->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(ambient_light);

	SetDebouncePeriod_ sdp;
	sdp.stack_id = ambient_light->stack_id;
	sdp.type = TYPE_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod_);
	sdp.debounce = debounce;

	ipcon_device_write(ambient_light, (char *)&sdp, sizeof(SetDebouncePeriod_));

	ipcon_sem_post_write(ambient_light);

	return E_OK;
}

int ambient_light_get_debounce_period(AmbientLight *ambient_light, uint32_t *ret_debounce) {
	if(ambient_light->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(ambient_light);

	ambient_light->answer.type = TYPE_GET_DEBOUNCE_PERIOD;
	ambient_light->answer.length = sizeof(GetDebouncePeriodReturn_);
	GetDebouncePeriod_ gdp;
	gdp.stack_id = ambient_light->stack_id;
	gdp.type = TYPE_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod_);

	ipcon_device_write(ambient_light, (char *)&gdp, sizeof(GetDebouncePeriod_));

	if(ipcon_answer_sem_wait_timeout(ambient_light) != 0) {
		ipcon_sem_post_write(ambient_light);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn_ *gdpr = (GetDebouncePeriodReturn_ *)ambient_light->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(ambient_light);

	return E_OK;
}

int ambient_light_get_version(AmbientLight *ambient_light, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, ambient_light->name, 40);

	ret_firmware_version[0] = ambient_light->firmware_version[0];
	ret_firmware_version[1] = ambient_light->firmware_version[1];
	ret_firmware_version[2] = ambient_light->firmware_version[2];

	ret_binding_version[0] = ambient_light->binding_version[0];
	ret_binding_version[1] = ambient_light->binding_version[1];
	ret_binding_version[2] = ambient_light->binding_version[2];

	return E_OK;
}

int ambient_light_callback_illuminance(AmbientLight *ambient_light, const unsigned char *buffer) {
	IlluminanceCallback_ *ic = (IlluminanceCallback_ *)buffer;
	((illuminance_func_t)ambient_light->callbacks[ic->type])(ic->illuminance);
	return sizeof(IlluminanceCallback_);
}

int ambient_light_callback_analog_value(AmbientLight *ambient_light, const unsigned char *buffer) {
	AnalogValueCallback_ *avc = (AnalogValueCallback_ *)buffer;
	((analog_value_func_t)ambient_light->callbacks[avc->type])(avc->value);
	return sizeof(AnalogValueCallback_);
}

int ambient_light_callback_illuminance_reached(AmbientLight *ambient_light, const unsigned char *buffer) {
	IlluminanceReachedCallback_ *irc = (IlluminanceReachedCallback_ *)buffer;
	((illuminance_reached_func_t)ambient_light->callbacks[irc->type])(irc->illuminance);
	return sizeof(IlluminanceReachedCallback_);
}

int ambient_light_callback_analog_value_reached(AmbientLight *ambient_light, const unsigned char *buffer) {
	AnalogValueReachedCallback_ *avrc = (AnalogValueReachedCallback_ *)buffer;
	((analog_value_reached_func_t)ambient_light->callbacks[avrc->type])(avrc->value);
	return sizeof(AnalogValueReachedCallback_);
}

void ambient_light_register_callback(AmbientLight *ambient_light, uint8_t cb, void *func) {
    ambient_light->callbacks[cb] = func;
}

void ambient_light_create(AmbientLight *ambient_light, const char *uid) {
	ipcon_device_create(ambient_light, uid);

	ambient_light->binding_version[0] = 1;
	ambient_light->binding_version[1] = 0;
	ambient_light->binding_version[2] = 0;

	ambient_light->device_callbacks[TYPE_ILLUMINANCE] = ambient_light_callback_illuminance;
	ambient_light->device_callbacks[TYPE_ANALOG_VALUE] = ambient_light_callback_analog_value;
	ambient_light->device_callbacks[TYPE_ILLUMINANCE_REACHED] = ambient_light_callback_illuminance_reached;
	ambient_light->device_callbacks[TYPE_ANALOG_VALUE_REACHED] = ambient_light_callback_analog_value_reached;
}
