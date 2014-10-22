/*************************************************************
 * This file was automatically generated on 2012-04-11.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_temperature_ir.h"

#include <string.h>

#define TYPE_GET_AMBIENT_TEMPERATURE 1
#define TYPE_GET_OBJECT_TEMPERATURE 2
#define TYPE_SET_EMISSIVITY 3
#define TYPE_GET_EMISSIVITY 4
#define TYPE_SET_AMBIENT_TEMPERATURE_CALLBACK_PERIOD 5
#define TYPE_GET_AMBIENT_TEMPERATURE_CALLBACK_PERIOD 6
#define TYPE_SET_OBJECT_TEMPERATURE_CALLBACK_PERIOD 7
#define TYPE_GET_OBJECT_TEMPERATURE_CALLBACK_PERIOD 8
#define TYPE_SET_AMBIENT_TEMPERATURE_CALLBACK_THRESHOLD 9
#define TYPE_GET_AMBIENT_TEMPERATURE_CALLBACK_THRESHOLD 10
#define TYPE_SET_OBJECT_TEMPERATURE_CALLBACK_THRESHOLD 11
#define TYPE_GET_OBJECT_TEMPERATURE_CALLBACK_THRESHOLD 12
#define TYPE_SET_DEBOUNCE_PERIOD 13
#define TYPE_GET_DEBOUNCE_PERIOD 14
#define TYPE_AMBIENT_TEMPERATURE 15
#define TYPE_OBJECT_TEMPERATURE 16
#define TYPE_AMBIENT_TEMPERATURE_REACHED 17
#define TYPE_OBJECT_TEMPERATURE_REACHED 18

typedef void (*ambient_temperature_func_t)(int16_t);
typedef void (*object_temperature_func_t)(int16_t);
typedef void (*ambient_temperature_reached_func_t)(int16_t);
typedef void (*object_temperature_reached_func_t)(int16_t);

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
} PACKED GetAmbientTemperature_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t temperature;
} PACKED GetAmbientTemperatureReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetObjectTemperature_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t temperature;
} PACKED GetObjectTemperatureReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t emissivity;
} PACKED SetEmissivity_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetEmissivity_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t emissivity;
} PACKED GetEmissivityReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED SetAmbientTemperatureCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAmbientTemperatureCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetAmbientTemperatureCallbackPeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED SetObjectTemperatureCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetObjectTemperatureCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetObjectTemperatureCallbackPeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED SetAmbientTemperatureCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAmbientTemperatureCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED GetAmbientTemperatureCallbackThresholdReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED SetObjectTemperatureCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetObjectTemperatureCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED GetObjectTemperatureCallbackThresholdReturn_;

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
} PACKED AmbientTemperatureCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t temperature;
} PACKED ObjectTemperatureCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t temperature;
} PACKED AmbientTemperatureReachedCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t temperature;
} PACKED ObjectTemperatureReachedCallback_;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif

int temperature_ir_get_ambient_temperature(TemperatureIR *temperature_ir, int16_t *ret_temperature) {
	if(temperature_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature_ir);

	temperature_ir->answer.type = TYPE_GET_AMBIENT_TEMPERATURE;
	temperature_ir->answer.length = sizeof(GetAmbientTemperatureReturn_);
	GetAmbientTemperature_ gat;
	gat.stack_id = temperature_ir->stack_id;
	gat.type = TYPE_GET_AMBIENT_TEMPERATURE;
	gat.length = sizeof(GetAmbientTemperature_);

	ipcon_device_write(temperature_ir, (char *)&gat, sizeof(GetAmbientTemperature_));

	if(ipcon_answer_sem_wait_timeout(temperature_ir) != 0) {
		ipcon_sem_post_write(temperature_ir);
		return E_TIMEOUT;
	}

	GetAmbientTemperatureReturn_ *gatr = (GetAmbientTemperatureReturn_ *)temperature_ir->answer.buffer;
	*ret_temperature = gatr->temperature;

	ipcon_sem_post_write(temperature_ir);

	return E_OK;
}

int temperature_ir_get_object_temperature(TemperatureIR *temperature_ir, int16_t *ret_temperature) {
	if(temperature_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature_ir);

	temperature_ir->answer.type = TYPE_GET_OBJECT_TEMPERATURE;
	temperature_ir->answer.length = sizeof(GetObjectTemperatureReturn_);
	GetObjectTemperature_ got;
	got.stack_id = temperature_ir->stack_id;
	got.type = TYPE_GET_OBJECT_TEMPERATURE;
	got.length = sizeof(GetObjectTemperature_);

	ipcon_device_write(temperature_ir, (char *)&got, sizeof(GetObjectTemperature_));

	if(ipcon_answer_sem_wait_timeout(temperature_ir) != 0) {
		ipcon_sem_post_write(temperature_ir);
		return E_TIMEOUT;
	}

	GetObjectTemperatureReturn_ *gotr = (GetObjectTemperatureReturn_ *)temperature_ir->answer.buffer;
	*ret_temperature = gotr->temperature;

	ipcon_sem_post_write(temperature_ir);

	return E_OK;
}

int temperature_ir_set_emissivity(TemperatureIR *temperature_ir, uint16_t emissivity) {
	if(temperature_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature_ir);

	SetEmissivity_ se;
	se.stack_id = temperature_ir->stack_id;
	se.type = TYPE_SET_EMISSIVITY;
	se.length = sizeof(SetEmissivity_);
	se.emissivity = emissivity;

	ipcon_device_write(temperature_ir, (char *)&se, sizeof(SetEmissivity_));

	ipcon_sem_post_write(temperature_ir);

	return E_OK;
}

int temperature_ir_get_emissivity(TemperatureIR *temperature_ir, uint16_t *ret_emissivity) {
	if(temperature_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature_ir);

	temperature_ir->answer.type = TYPE_GET_EMISSIVITY;
	temperature_ir->answer.length = sizeof(GetEmissivityReturn_);
	GetEmissivity_ ge;
	ge.stack_id = temperature_ir->stack_id;
	ge.type = TYPE_GET_EMISSIVITY;
	ge.length = sizeof(GetEmissivity_);

	ipcon_device_write(temperature_ir, (char *)&ge, sizeof(GetEmissivity_));

	if(ipcon_answer_sem_wait_timeout(temperature_ir) != 0) {
		ipcon_sem_post_write(temperature_ir);
		return E_TIMEOUT;
	}

	GetEmissivityReturn_ *ger = (GetEmissivityReturn_ *)temperature_ir->answer.buffer;
	*ret_emissivity = ger->emissivity;

	ipcon_sem_post_write(temperature_ir);

	return E_OK;
}

int temperature_ir_set_ambient_temperature_callback_period(TemperatureIR *temperature_ir, uint32_t period) {
	if(temperature_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature_ir);

	SetAmbientTemperatureCallbackPeriod_ satcp;
	satcp.stack_id = temperature_ir->stack_id;
	satcp.type = TYPE_SET_AMBIENT_TEMPERATURE_CALLBACK_PERIOD;
	satcp.length = sizeof(SetAmbientTemperatureCallbackPeriod_);
	satcp.period = period;

	ipcon_device_write(temperature_ir, (char *)&satcp, sizeof(SetAmbientTemperatureCallbackPeriod_));

	ipcon_sem_post_write(temperature_ir);

	return E_OK;
}

int temperature_ir_get_ambient_temperature_callback_period(TemperatureIR *temperature_ir, uint32_t *ret_period) {
	if(temperature_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature_ir);

	temperature_ir->answer.type = TYPE_GET_AMBIENT_TEMPERATURE_CALLBACK_PERIOD;
	temperature_ir->answer.length = sizeof(GetAmbientTemperatureCallbackPeriodReturn_);
	GetAmbientTemperatureCallbackPeriod_ gatcp;
	gatcp.stack_id = temperature_ir->stack_id;
	gatcp.type = TYPE_GET_AMBIENT_TEMPERATURE_CALLBACK_PERIOD;
	gatcp.length = sizeof(GetAmbientTemperatureCallbackPeriod_);

	ipcon_device_write(temperature_ir, (char *)&gatcp, sizeof(GetAmbientTemperatureCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(temperature_ir) != 0) {
		ipcon_sem_post_write(temperature_ir);
		return E_TIMEOUT;
	}

	GetAmbientTemperatureCallbackPeriodReturn_ *gatcpr = (GetAmbientTemperatureCallbackPeriodReturn_ *)temperature_ir->answer.buffer;
	*ret_period = gatcpr->period;

	ipcon_sem_post_write(temperature_ir);

	return E_OK;
}

int temperature_ir_set_object_temperature_callback_period(TemperatureIR *temperature_ir, uint32_t period) {
	if(temperature_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature_ir);

	SetObjectTemperatureCallbackPeriod_ sotcp;
	sotcp.stack_id = temperature_ir->stack_id;
	sotcp.type = TYPE_SET_OBJECT_TEMPERATURE_CALLBACK_PERIOD;
	sotcp.length = sizeof(SetObjectTemperatureCallbackPeriod_);
	sotcp.period = period;

	ipcon_device_write(temperature_ir, (char *)&sotcp, sizeof(SetObjectTemperatureCallbackPeriod_));

	ipcon_sem_post_write(temperature_ir);

	return E_OK;
}

int temperature_ir_get_object_temperature_callback_period(TemperatureIR *temperature_ir, uint32_t *ret_period) {
	if(temperature_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature_ir);

	temperature_ir->answer.type = TYPE_GET_OBJECT_TEMPERATURE_CALLBACK_PERIOD;
	temperature_ir->answer.length = sizeof(GetObjectTemperatureCallbackPeriodReturn_);
	GetObjectTemperatureCallbackPeriod_ gotcp;
	gotcp.stack_id = temperature_ir->stack_id;
	gotcp.type = TYPE_GET_OBJECT_TEMPERATURE_CALLBACK_PERIOD;
	gotcp.length = sizeof(GetObjectTemperatureCallbackPeriod_);

	ipcon_device_write(temperature_ir, (char *)&gotcp, sizeof(GetObjectTemperatureCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(temperature_ir) != 0) {
		ipcon_sem_post_write(temperature_ir);
		return E_TIMEOUT;
	}

	GetObjectTemperatureCallbackPeriodReturn_ *gotcpr = (GetObjectTemperatureCallbackPeriodReturn_ *)temperature_ir->answer.buffer;
	*ret_period = gotcpr->period;

	ipcon_sem_post_write(temperature_ir);

	return E_OK;
}

int temperature_ir_set_ambient_temperature_callback_threshold(TemperatureIR *temperature_ir, char option, int16_t min, int16_t max) {
	if(temperature_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature_ir);

	SetAmbientTemperatureCallbackThreshold_ satct;
	satct.stack_id = temperature_ir->stack_id;
	satct.type = TYPE_SET_AMBIENT_TEMPERATURE_CALLBACK_THRESHOLD;
	satct.length = sizeof(SetAmbientTemperatureCallbackThreshold_);
	satct.option = option;
	satct.min = min;
	satct.max = max;

	ipcon_device_write(temperature_ir, (char *)&satct, sizeof(SetAmbientTemperatureCallbackThreshold_));

	ipcon_sem_post_write(temperature_ir);

	return E_OK;
}

int temperature_ir_get_ambient_temperature_callback_threshold(TemperatureIR *temperature_ir, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	if(temperature_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature_ir);

	temperature_ir->answer.type = TYPE_GET_AMBIENT_TEMPERATURE_CALLBACK_THRESHOLD;
	temperature_ir->answer.length = sizeof(GetAmbientTemperatureCallbackThresholdReturn_);
	GetAmbientTemperatureCallbackThreshold_ gatct;
	gatct.stack_id = temperature_ir->stack_id;
	gatct.type = TYPE_GET_AMBIENT_TEMPERATURE_CALLBACK_THRESHOLD;
	gatct.length = sizeof(GetAmbientTemperatureCallbackThreshold_);

	ipcon_device_write(temperature_ir, (char *)&gatct, sizeof(GetAmbientTemperatureCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(temperature_ir) != 0) {
		ipcon_sem_post_write(temperature_ir);
		return E_TIMEOUT;
	}

	GetAmbientTemperatureCallbackThresholdReturn_ *gatctr = (GetAmbientTemperatureCallbackThresholdReturn_ *)temperature_ir->answer.buffer;
	*ret_option = gatctr->option;
	*ret_min = gatctr->min;
	*ret_max = gatctr->max;

	ipcon_sem_post_write(temperature_ir);

	return E_OK;
}

int temperature_ir_set_object_temperature_callback_threshold(TemperatureIR *temperature_ir, char option, int16_t min, int16_t max) {
	if(temperature_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature_ir);

	SetObjectTemperatureCallbackThreshold_ sotct;
	sotct.stack_id = temperature_ir->stack_id;
	sotct.type = TYPE_SET_OBJECT_TEMPERATURE_CALLBACK_THRESHOLD;
	sotct.length = sizeof(SetObjectTemperatureCallbackThreshold_);
	sotct.option = option;
	sotct.min = min;
	sotct.max = max;

	ipcon_device_write(temperature_ir, (char *)&sotct, sizeof(SetObjectTemperatureCallbackThreshold_));

	ipcon_sem_post_write(temperature_ir);

	return E_OK;
}

int temperature_ir_get_object_temperature_callback_threshold(TemperatureIR *temperature_ir, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	if(temperature_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature_ir);

	temperature_ir->answer.type = TYPE_GET_OBJECT_TEMPERATURE_CALLBACK_THRESHOLD;
	temperature_ir->answer.length = sizeof(GetObjectTemperatureCallbackThresholdReturn_);
	GetObjectTemperatureCallbackThreshold_ gotct;
	gotct.stack_id = temperature_ir->stack_id;
	gotct.type = TYPE_GET_OBJECT_TEMPERATURE_CALLBACK_THRESHOLD;
	gotct.length = sizeof(GetObjectTemperatureCallbackThreshold_);

	ipcon_device_write(temperature_ir, (char *)&gotct, sizeof(GetObjectTemperatureCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(temperature_ir) != 0) {
		ipcon_sem_post_write(temperature_ir);
		return E_TIMEOUT;
	}

	GetObjectTemperatureCallbackThresholdReturn_ *gotctr = (GetObjectTemperatureCallbackThresholdReturn_ *)temperature_ir->answer.buffer;
	*ret_option = gotctr->option;
	*ret_min = gotctr->min;
	*ret_max = gotctr->max;

	ipcon_sem_post_write(temperature_ir);

	return E_OK;
}

int temperature_ir_set_debounce_period(TemperatureIR *temperature_ir, uint32_t debounce) {
	if(temperature_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature_ir);

	SetDebouncePeriod_ sdp;
	sdp.stack_id = temperature_ir->stack_id;
	sdp.type = TYPE_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod_);
	sdp.debounce = debounce;

	ipcon_device_write(temperature_ir, (char *)&sdp, sizeof(SetDebouncePeriod_));

	ipcon_sem_post_write(temperature_ir);

	return E_OK;
}

int temperature_ir_get_debounce_period(TemperatureIR *temperature_ir, uint32_t *ret_debounce) {
	if(temperature_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(temperature_ir);

	temperature_ir->answer.type = TYPE_GET_DEBOUNCE_PERIOD;
	temperature_ir->answer.length = sizeof(GetDebouncePeriodReturn_);
	GetDebouncePeriod_ gdp;
	gdp.stack_id = temperature_ir->stack_id;
	gdp.type = TYPE_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod_);

	ipcon_device_write(temperature_ir, (char *)&gdp, sizeof(GetDebouncePeriod_));

	if(ipcon_answer_sem_wait_timeout(temperature_ir) != 0) {
		ipcon_sem_post_write(temperature_ir);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn_ *gdpr = (GetDebouncePeriodReturn_ *)temperature_ir->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(temperature_ir);

	return E_OK;
}

int temperature_ir_get_version(TemperatureIR *temperature_ir, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, temperature_ir->name, 40);

	ret_firmware_version[0] = temperature_ir->firmware_version[0];
	ret_firmware_version[1] = temperature_ir->firmware_version[1];
	ret_firmware_version[2] = temperature_ir->firmware_version[2];

	ret_binding_version[0] = temperature_ir->binding_version[0];
	ret_binding_version[1] = temperature_ir->binding_version[1];
	ret_binding_version[2] = temperature_ir->binding_version[2];

	return E_OK;
}

int temperature_ir_callback_ambient_temperature(TemperatureIR *temperature_ir, const unsigned char *buffer) {
	AmbientTemperatureCallback_ *atc = (AmbientTemperatureCallback_ *)buffer;
	((ambient_temperature_func_t)temperature_ir->callbacks[atc->type])(atc->temperature);
	return sizeof(AmbientTemperatureCallback_);
}

int temperature_ir_callback_object_temperature(TemperatureIR *temperature_ir, const unsigned char *buffer) {
	ObjectTemperatureCallback_ *otc = (ObjectTemperatureCallback_ *)buffer;
	((object_temperature_func_t)temperature_ir->callbacks[otc->type])(otc->temperature);
	return sizeof(ObjectTemperatureCallback_);
}

int temperature_ir_callback_ambient_temperature_reached(TemperatureIR *temperature_ir, const unsigned char *buffer) {
	AmbientTemperatureReachedCallback_ *atrc = (AmbientTemperatureReachedCallback_ *)buffer;
	((ambient_temperature_reached_func_t)temperature_ir->callbacks[atrc->type])(atrc->temperature);
	return sizeof(AmbientTemperatureReachedCallback_);
}

int temperature_ir_callback_object_temperature_reached(TemperatureIR *temperature_ir, const unsigned char *buffer) {
	ObjectTemperatureReachedCallback_ *otrc = (ObjectTemperatureReachedCallback_ *)buffer;
	((object_temperature_reached_func_t)temperature_ir->callbacks[otrc->type])(otrc->temperature);
	return sizeof(ObjectTemperatureReachedCallback_);
}

void temperature_ir_register_callback(TemperatureIR *temperature_ir, uint8_t cb, void *func) {
    temperature_ir->callbacks[cb] = func;
}

void temperature_ir_create(TemperatureIR *temperature_ir, const char *uid) {
	ipcon_device_create(temperature_ir, uid);

	temperature_ir->binding_version[0] = 1;
	temperature_ir->binding_version[1] = 0;
	temperature_ir->binding_version[2] = 0;

	temperature_ir->device_callbacks[TYPE_AMBIENT_TEMPERATURE] = temperature_ir_callback_ambient_temperature;
	temperature_ir->device_callbacks[TYPE_OBJECT_TEMPERATURE] = temperature_ir_callback_object_temperature;
	temperature_ir->device_callbacks[TYPE_AMBIENT_TEMPERATURE_REACHED] = temperature_ir_callback_ambient_temperature_reached;
	temperature_ir->device_callbacks[TYPE_OBJECT_TEMPERATURE_REACHED] = temperature_ir_callback_object_temperature_reached;
}
