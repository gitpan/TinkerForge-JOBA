/*************************************************************
 * This file was automatically generated on 2012-04-11.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_rotary_poti.h"

#include <string.h>

#define TYPE_GET_POSITION 1
#define TYPE_GET_ANALOG_VALUE 2
#define TYPE_SET_POSITION_CALLBACK_PERIOD 3
#define TYPE_GET_POSITION_CALLBACK_PERIOD 4
#define TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD 5
#define TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD 6
#define TYPE_SET_POSITION_CALLBACK_THRESHOLD 7
#define TYPE_GET_POSITION_CALLBACK_THRESHOLD 8
#define TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD 9
#define TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD 10
#define TYPE_SET_DEBOUNCE_PERIOD 11
#define TYPE_GET_DEBOUNCE_PERIOD 12
#define TYPE_POSITION 13
#define TYPE_ANALOG_VALUE 14
#define TYPE_POSITION_REACHED 15
#define TYPE_ANALOG_VALUE_REACHED 16

typedef void (*position_func_t)(int16_t);
typedef void (*analog_value_func_t)(uint16_t);
typedef void (*position_reached_func_t)(int16_t);
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
} PACKED GetPosition_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t position;
} PACKED GetPositionReturn_;

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
} PACKED SetPositionCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetPositionCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetPositionCallbackPeriodReturn_;

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
} PACKED SetPositionCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetPositionCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED GetPositionCallbackThresholdReturn_;

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
	int16_t position;
} PACKED PositionCallback_;

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
	int16_t position;
} PACKED PositionReachedCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED AnalogValueReachedCallback_;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif

int rotary_poti_get_position(RotaryPoti *rotary_poti, int16_t *ret_position) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	rotary_poti->answer.type = TYPE_GET_POSITION;
	rotary_poti->answer.length = sizeof(GetPositionReturn_);
	GetPosition_ gp;
	gp.stack_id = rotary_poti->stack_id;
	gp.type = TYPE_GET_POSITION;
	gp.length = sizeof(GetPosition_);

	ipcon_device_write(rotary_poti, (char *)&gp, sizeof(GetPosition_));

	if(ipcon_answer_sem_wait_timeout(rotary_poti) != 0) {
		ipcon_sem_post_write(rotary_poti);
		return E_TIMEOUT;
	}

	GetPositionReturn_ *gpr = (GetPositionReturn_ *)rotary_poti->answer.buffer;
	*ret_position = gpr->position;

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_get_analog_value(RotaryPoti *rotary_poti, uint16_t *ret_value) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	rotary_poti->answer.type = TYPE_GET_ANALOG_VALUE;
	rotary_poti->answer.length = sizeof(GetAnalogValueReturn_);
	GetAnalogValue_ gav;
	gav.stack_id = rotary_poti->stack_id;
	gav.type = TYPE_GET_ANALOG_VALUE;
	gav.length = sizeof(GetAnalogValue_);

	ipcon_device_write(rotary_poti, (char *)&gav, sizeof(GetAnalogValue_));

	if(ipcon_answer_sem_wait_timeout(rotary_poti) != 0) {
		ipcon_sem_post_write(rotary_poti);
		return E_TIMEOUT;
	}

	GetAnalogValueReturn_ *gavr = (GetAnalogValueReturn_ *)rotary_poti->answer.buffer;
	*ret_value = gavr->value;

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_set_position_callback_period(RotaryPoti *rotary_poti, uint32_t period) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	SetPositionCallbackPeriod_ spcp;
	spcp.stack_id = rotary_poti->stack_id;
	spcp.type = TYPE_SET_POSITION_CALLBACK_PERIOD;
	spcp.length = sizeof(SetPositionCallbackPeriod_);
	spcp.period = period;

	ipcon_device_write(rotary_poti, (char *)&spcp, sizeof(SetPositionCallbackPeriod_));

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_get_position_callback_period(RotaryPoti *rotary_poti, uint32_t *ret_period) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	rotary_poti->answer.type = TYPE_GET_POSITION_CALLBACK_PERIOD;
	rotary_poti->answer.length = sizeof(GetPositionCallbackPeriodReturn_);
	GetPositionCallbackPeriod_ gpcp;
	gpcp.stack_id = rotary_poti->stack_id;
	gpcp.type = TYPE_GET_POSITION_CALLBACK_PERIOD;
	gpcp.length = sizeof(GetPositionCallbackPeriod_);

	ipcon_device_write(rotary_poti, (char *)&gpcp, sizeof(GetPositionCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(rotary_poti) != 0) {
		ipcon_sem_post_write(rotary_poti);
		return E_TIMEOUT;
	}

	GetPositionCallbackPeriodReturn_ *gpcpr = (GetPositionCallbackPeriodReturn_ *)rotary_poti->answer.buffer;
	*ret_period = gpcpr->period;

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_set_analog_value_callback_period(RotaryPoti *rotary_poti, uint32_t period) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	SetAnalogValueCallbackPeriod_ savcp;
	savcp.stack_id = rotary_poti->stack_id;
	savcp.type = TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD;
	savcp.length = sizeof(SetAnalogValueCallbackPeriod_);
	savcp.period = period;

	ipcon_device_write(rotary_poti, (char *)&savcp, sizeof(SetAnalogValueCallbackPeriod_));

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_get_analog_value_callback_period(RotaryPoti *rotary_poti, uint32_t *ret_period) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	rotary_poti->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	rotary_poti->answer.length = sizeof(GetAnalogValueCallbackPeriodReturn_);
	GetAnalogValueCallbackPeriod_ gavcp;
	gavcp.stack_id = rotary_poti->stack_id;
	gavcp.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	gavcp.length = sizeof(GetAnalogValueCallbackPeriod_);

	ipcon_device_write(rotary_poti, (char *)&gavcp, sizeof(GetAnalogValueCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(rotary_poti) != 0) {
		ipcon_sem_post_write(rotary_poti);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackPeriodReturn_ *gavcpr = (GetAnalogValueCallbackPeriodReturn_ *)rotary_poti->answer.buffer;
	*ret_period = gavcpr->period;

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_set_position_callback_threshold(RotaryPoti *rotary_poti, char option, int16_t min, int16_t max) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	SetPositionCallbackThreshold_ spct;
	spct.stack_id = rotary_poti->stack_id;
	spct.type = TYPE_SET_POSITION_CALLBACK_THRESHOLD;
	spct.length = sizeof(SetPositionCallbackThreshold_);
	spct.option = option;
	spct.min = min;
	spct.max = max;

	ipcon_device_write(rotary_poti, (char *)&spct, sizeof(SetPositionCallbackThreshold_));

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_get_position_callback_threshold(RotaryPoti *rotary_poti, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	rotary_poti->answer.type = TYPE_GET_POSITION_CALLBACK_THRESHOLD;
	rotary_poti->answer.length = sizeof(GetPositionCallbackThresholdReturn_);
	GetPositionCallbackThreshold_ gpct;
	gpct.stack_id = rotary_poti->stack_id;
	gpct.type = TYPE_GET_POSITION_CALLBACK_THRESHOLD;
	gpct.length = sizeof(GetPositionCallbackThreshold_);

	ipcon_device_write(rotary_poti, (char *)&gpct, sizeof(GetPositionCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(rotary_poti) != 0) {
		ipcon_sem_post_write(rotary_poti);
		return E_TIMEOUT;
	}

	GetPositionCallbackThresholdReturn_ *gpctr = (GetPositionCallbackThresholdReturn_ *)rotary_poti->answer.buffer;
	*ret_option = gpctr->option;
	*ret_min = gpctr->min;
	*ret_max = gpctr->max;

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_set_analog_value_callback_threshold(RotaryPoti *rotary_poti, char option, uint16_t min, uint16_t max) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	SetAnalogValueCallbackThreshold_ savct;
	savct.stack_id = rotary_poti->stack_id;
	savct.type = TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	savct.length = sizeof(SetAnalogValueCallbackThreshold_);
	savct.option = option;
	savct.min = min;
	savct.max = max;

	ipcon_device_write(rotary_poti, (char *)&savct, sizeof(SetAnalogValueCallbackThreshold_));

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_get_analog_value_callback_threshold(RotaryPoti *rotary_poti, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	rotary_poti->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	rotary_poti->answer.length = sizeof(GetAnalogValueCallbackThresholdReturn_);
	GetAnalogValueCallbackThreshold_ gavct;
	gavct.stack_id = rotary_poti->stack_id;
	gavct.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	gavct.length = sizeof(GetAnalogValueCallbackThreshold_);

	ipcon_device_write(rotary_poti, (char *)&gavct, sizeof(GetAnalogValueCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(rotary_poti) != 0) {
		ipcon_sem_post_write(rotary_poti);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackThresholdReturn_ *gavctr = (GetAnalogValueCallbackThresholdReturn_ *)rotary_poti->answer.buffer;
	*ret_option = gavctr->option;
	*ret_min = gavctr->min;
	*ret_max = gavctr->max;

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_set_debounce_period(RotaryPoti *rotary_poti, uint32_t debounce) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	SetDebouncePeriod_ sdp;
	sdp.stack_id = rotary_poti->stack_id;
	sdp.type = TYPE_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod_);
	sdp.debounce = debounce;

	ipcon_device_write(rotary_poti, (char *)&sdp, sizeof(SetDebouncePeriod_));

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_get_debounce_period(RotaryPoti *rotary_poti, uint32_t *ret_debounce) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	rotary_poti->answer.type = TYPE_GET_DEBOUNCE_PERIOD;
	rotary_poti->answer.length = sizeof(GetDebouncePeriodReturn_);
	GetDebouncePeriod_ gdp;
	gdp.stack_id = rotary_poti->stack_id;
	gdp.type = TYPE_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod_);

	ipcon_device_write(rotary_poti, (char *)&gdp, sizeof(GetDebouncePeriod_));

	if(ipcon_answer_sem_wait_timeout(rotary_poti) != 0) {
		ipcon_sem_post_write(rotary_poti);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn_ *gdpr = (GetDebouncePeriodReturn_ *)rotary_poti->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_get_version(RotaryPoti *rotary_poti, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, rotary_poti->name, 40);

	ret_firmware_version[0] = rotary_poti->firmware_version[0];
	ret_firmware_version[1] = rotary_poti->firmware_version[1];
	ret_firmware_version[2] = rotary_poti->firmware_version[2];

	ret_binding_version[0] = rotary_poti->binding_version[0];
	ret_binding_version[1] = rotary_poti->binding_version[1];
	ret_binding_version[2] = rotary_poti->binding_version[2];

	return E_OK;
}

int rotary_poti_callback_position(RotaryPoti *rotary_poti, const unsigned char *buffer) {
	PositionCallback_ *pc = (PositionCallback_ *)buffer;
	((position_func_t)rotary_poti->callbacks[pc->type])(pc->position);
	return sizeof(PositionCallback_);
}

int rotary_poti_callback_analog_value(RotaryPoti *rotary_poti, const unsigned char *buffer) {
	AnalogValueCallback_ *avc = (AnalogValueCallback_ *)buffer;
	((analog_value_func_t)rotary_poti->callbacks[avc->type])(avc->value);
	return sizeof(AnalogValueCallback_);
}

int rotary_poti_callback_position_reached(RotaryPoti *rotary_poti, const unsigned char *buffer) {
	PositionReachedCallback_ *prc = (PositionReachedCallback_ *)buffer;
	((position_reached_func_t)rotary_poti->callbacks[prc->type])(prc->position);
	return sizeof(PositionReachedCallback_);
}

int rotary_poti_callback_analog_value_reached(RotaryPoti *rotary_poti, const unsigned char *buffer) {
	AnalogValueReachedCallback_ *avrc = (AnalogValueReachedCallback_ *)buffer;
	((analog_value_reached_func_t)rotary_poti->callbacks[avrc->type])(avrc->value);
	return sizeof(AnalogValueReachedCallback_);
}

void rotary_poti_register_callback(RotaryPoti *rotary_poti, uint8_t cb, void *func) {
    rotary_poti->callbacks[cb] = func;
}

void rotary_poti_create(RotaryPoti *rotary_poti, const char *uid) {
	ipcon_device_create(rotary_poti, uid);

	rotary_poti->binding_version[0] = 1;
	rotary_poti->binding_version[1] = 0;
	rotary_poti->binding_version[2] = 0;

	rotary_poti->device_callbacks[TYPE_POSITION] = rotary_poti_callback_position;
	rotary_poti->device_callbacks[TYPE_ANALOG_VALUE] = rotary_poti_callback_analog_value;
	rotary_poti->device_callbacks[TYPE_POSITION_REACHED] = rotary_poti_callback_position_reached;
	rotary_poti->device_callbacks[TYPE_ANALOG_VALUE_REACHED] = rotary_poti_callback_analog_value_reached;
}
