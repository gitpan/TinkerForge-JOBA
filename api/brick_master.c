/*************************************************************
 * This file was automatically generated on 2012-04-11.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "brick_master.h"

#include <string.h>

#define TYPE_GET_STACK_VOLTAGE 1
#define TYPE_GET_STACK_CURRENT 2
#define TYPE_SET_EXTENSION_TYPE 3
#define TYPE_GET_EXTENSION_TYPE 4
#define TYPE_IS_CHIBI_PRESENT 5
#define TYPE_SET_CHIBI_ADDRESS 6
#define TYPE_GET_CHIBI_ADDRESS 7
#define TYPE_SET_CHIBI_MASTER_ADDRESS 8
#define TYPE_GET_CHIBI_MASTER_ADDRESS 9
#define TYPE_SET_CHIBI_SLAVE_ADDRESS 10
#define TYPE_GET_CHIBI_SLAVE_ADDRESS 11
#define TYPE_GET_CHIBI_SIGNAL_STRENGTH 12
#define TYPE_GET_CHIBI_ERROR_LOG 13
#define TYPE_SET_CHIBI_FREQUENCY 14
#define TYPE_GET_CHIBI_FREQUENCY 15
#define TYPE_SET_CHIBI_CHANNEL 16
#define TYPE_GET_CHIBI_CHANNEL 17


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
} PACKED GetStackVoltage_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t voltage;
} PACKED GetStackVoltageReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetStackCurrent_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t current;
} PACKED GetStackCurrentReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t extension;
	uint32_t exttype;
} PACKED SetExtensionType_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t extension;
} PACKED GetExtensionType_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t exttype;
} PACKED GetExtensionTypeReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED IsChibiPresent_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	bool present;
} PACKED IsChibiPresentReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t address;
} PACKED SetChibiAddress_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetChibiAddress_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t address;
} PACKED GetChibiAddressReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t address;
} PACKED SetChibiMasterAddress_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetChibiMasterAddress_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t address;
} PACKED GetChibiMasterAddressReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t num;
	uint8_t address;
} PACKED SetChibiSlaveAddress_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t num;
} PACKED GetChibiSlaveAddress_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t address;
} PACKED GetChibiSlaveAddressReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetChibiSignalStrength_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t signal_strength;
} PACKED GetChibiSignalStrengthReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetChibiErrorLog_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t underrun;
	uint16_t crc_error;
	uint16_t no_ack;
	uint16_t overflow;
} PACKED GetChibiErrorLogReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t frequency;
} PACKED SetChibiFrequency_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetChibiFrequency_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t frequency;
} PACKED GetChibiFrequencyReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t channel;
} PACKED SetChibiChannel_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetChibiChannel_;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t channel;
} PACKED GetChibiChannelReturn_;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif

int master_get_stack_voltage(Master *master, uint16_t *ret_voltage) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	master->answer.type = TYPE_GET_STACK_VOLTAGE;
	master->answer.length = sizeof(GetStackVoltageReturn_);
	GetStackVoltage_ gsv;
	gsv.stack_id = master->stack_id;
	gsv.type = TYPE_GET_STACK_VOLTAGE;
	gsv.length = sizeof(GetStackVoltage_);

	ipcon_device_write(master, (char *)&gsv, sizeof(GetStackVoltage_));

	if(ipcon_answer_sem_wait_timeout(master) != 0) {
		ipcon_sem_post_write(master);
		return E_TIMEOUT;
	}

	GetStackVoltageReturn_ *gsvr = (GetStackVoltageReturn_ *)master->answer.buffer;
	*ret_voltage = gsvr->voltage;

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_get_stack_current(Master *master, uint16_t *ret_current) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	master->answer.type = TYPE_GET_STACK_CURRENT;
	master->answer.length = sizeof(GetStackCurrentReturn_);
	GetStackCurrent_ gsc;
	gsc.stack_id = master->stack_id;
	gsc.type = TYPE_GET_STACK_CURRENT;
	gsc.length = sizeof(GetStackCurrent_);

	ipcon_device_write(master, (char *)&gsc, sizeof(GetStackCurrent_));

	if(ipcon_answer_sem_wait_timeout(master) != 0) {
		ipcon_sem_post_write(master);
		return E_TIMEOUT;
	}

	GetStackCurrentReturn_ *gscr = (GetStackCurrentReturn_ *)master->answer.buffer;
	*ret_current = gscr->current;

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_set_extension_type(Master *master, uint8_t extension, uint32_t exttype) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	SetExtensionType_ set;
	set.stack_id = master->stack_id;
	set.type = TYPE_SET_EXTENSION_TYPE;
	set.length = sizeof(SetExtensionType_);
	set.extension = extension;
	set.exttype = exttype;

	ipcon_device_write(master, (char *)&set, sizeof(SetExtensionType_));

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_get_extension_type(Master *master, uint8_t extension, uint32_t *ret_exttype) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	master->answer.type = TYPE_GET_EXTENSION_TYPE;
	master->answer.length = sizeof(GetExtensionTypeReturn_);
	GetExtensionType_ get;
	get.stack_id = master->stack_id;
	get.type = TYPE_GET_EXTENSION_TYPE;
	get.length = sizeof(GetExtensionType_);
	get.extension = extension;

	ipcon_device_write(master, (char *)&get, sizeof(GetExtensionType_));

	if(ipcon_answer_sem_wait_timeout(master) != 0) {
		ipcon_sem_post_write(master);
		return E_TIMEOUT;
	}

	GetExtensionTypeReturn_ *getr = (GetExtensionTypeReturn_ *)master->answer.buffer;
	*ret_exttype = getr->exttype;

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_is_chibi_present(Master *master, bool *ret_present) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	master->answer.type = TYPE_IS_CHIBI_PRESENT;
	master->answer.length = sizeof(IsChibiPresentReturn_);
	IsChibiPresent_ icp;
	icp.stack_id = master->stack_id;
	icp.type = TYPE_IS_CHIBI_PRESENT;
	icp.length = sizeof(IsChibiPresent_);

	ipcon_device_write(master, (char *)&icp, sizeof(IsChibiPresent_));

	if(ipcon_answer_sem_wait_timeout(master) != 0) {
		ipcon_sem_post_write(master);
		return E_TIMEOUT;
	}

	IsChibiPresentReturn_ *icpr = (IsChibiPresentReturn_ *)master->answer.buffer;
	*ret_present = icpr->present;

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_set_chibi_address(Master *master, uint8_t address) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	SetChibiAddress_ sca;
	sca.stack_id = master->stack_id;
	sca.type = TYPE_SET_CHIBI_ADDRESS;
	sca.length = sizeof(SetChibiAddress_);
	sca.address = address;

	ipcon_device_write(master, (char *)&sca, sizeof(SetChibiAddress_));

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_get_chibi_address(Master *master, uint8_t *ret_address) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	master->answer.type = TYPE_GET_CHIBI_ADDRESS;
	master->answer.length = sizeof(GetChibiAddressReturn_);
	GetChibiAddress_ gca;
	gca.stack_id = master->stack_id;
	gca.type = TYPE_GET_CHIBI_ADDRESS;
	gca.length = sizeof(GetChibiAddress_);

	ipcon_device_write(master, (char *)&gca, sizeof(GetChibiAddress_));

	if(ipcon_answer_sem_wait_timeout(master) != 0) {
		ipcon_sem_post_write(master);
		return E_TIMEOUT;
	}

	GetChibiAddressReturn_ *gcar = (GetChibiAddressReturn_ *)master->answer.buffer;
	*ret_address = gcar->address;

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_set_chibi_master_address(Master *master, uint8_t address) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	SetChibiMasterAddress_ scma;
	scma.stack_id = master->stack_id;
	scma.type = TYPE_SET_CHIBI_MASTER_ADDRESS;
	scma.length = sizeof(SetChibiMasterAddress_);
	scma.address = address;

	ipcon_device_write(master, (char *)&scma, sizeof(SetChibiMasterAddress_));

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_get_chibi_master_address(Master *master, uint8_t *ret_address) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	master->answer.type = TYPE_GET_CHIBI_MASTER_ADDRESS;
	master->answer.length = sizeof(GetChibiMasterAddressReturn_);
	GetChibiMasterAddress_ gcma;
	gcma.stack_id = master->stack_id;
	gcma.type = TYPE_GET_CHIBI_MASTER_ADDRESS;
	gcma.length = sizeof(GetChibiMasterAddress_);

	ipcon_device_write(master, (char *)&gcma, sizeof(GetChibiMasterAddress_));

	if(ipcon_answer_sem_wait_timeout(master) != 0) {
		ipcon_sem_post_write(master);
		return E_TIMEOUT;
	}

	GetChibiMasterAddressReturn_ *gcmar = (GetChibiMasterAddressReturn_ *)master->answer.buffer;
	*ret_address = gcmar->address;

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_set_chibi_slave_address(Master *master, uint8_t num, uint8_t address) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	SetChibiSlaveAddress_ scsa;
	scsa.stack_id = master->stack_id;
	scsa.type = TYPE_SET_CHIBI_SLAVE_ADDRESS;
	scsa.length = sizeof(SetChibiSlaveAddress_);
	scsa.num = num;
	scsa.address = address;

	ipcon_device_write(master, (char *)&scsa, sizeof(SetChibiSlaveAddress_));

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_get_chibi_slave_address(Master *master, uint8_t num, uint8_t *ret_address) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	master->answer.type = TYPE_GET_CHIBI_SLAVE_ADDRESS;
	master->answer.length = sizeof(GetChibiSlaveAddressReturn_);
	GetChibiSlaveAddress_ gcsa;
	gcsa.stack_id = master->stack_id;
	gcsa.type = TYPE_GET_CHIBI_SLAVE_ADDRESS;
	gcsa.length = sizeof(GetChibiSlaveAddress_);
	gcsa.num = num;

	ipcon_device_write(master, (char *)&gcsa, sizeof(GetChibiSlaveAddress_));

	if(ipcon_answer_sem_wait_timeout(master) != 0) {
		ipcon_sem_post_write(master);
		return E_TIMEOUT;
	}

	GetChibiSlaveAddressReturn_ *gcsar = (GetChibiSlaveAddressReturn_ *)master->answer.buffer;
	*ret_address = gcsar->address;

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_get_chibi_signal_strength(Master *master, uint8_t *ret_signal_strength) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	master->answer.type = TYPE_GET_CHIBI_SIGNAL_STRENGTH;
	master->answer.length = sizeof(GetChibiSignalStrengthReturn_);
	GetChibiSignalStrength_ gcss;
	gcss.stack_id = master->stack_id;
	gcss.type = TYPE_GET_CHIBI_SIGNAL_STRENGTH;
	gcss.length = sizeof(GetChibiSignalStrength_);

	ipcon_device_write(master, (char *)&gcss, sizeof(GetChibiSignalStrength_));

	if(ipcon_answer_sem_wait_timeout(master) != 0) {
		ipcon_sem_post_write(master);
		return E_TIMEOUT;
	}

	GetChibiSignalStrengthReturn_ *gcssr = (GetChibiSignalStrengthReturn_ *)master->answer.buffer;
	*ret_signal_strength = gcssr->signal_strength;

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_get_chibi_error_log(Master *master, uint16_t *ret_underrun, uint16_t *ret_crc_error, uint16_t *ret_no_ack, uint16_t *ret_overflow) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	master->answer.type = TYPE_GET_CHIBI_ERROR_LOG;
	master->answer.length = sizeof(GetChibiErrorLogReturn_);
	GetChibiErrorLog_ gcel;
	gcel.stack_id = master->stack_id;
	gcel.type = TYPE_GET_CHIBI_ERROR_LOG;
	gcel.length = sizeof(GetChibiErrorLog_);

	ipcon_device_write(master, (char *)&gcel, sizeof(GetChibiErrorLog_));

	if(ipcon_answer_sem_wait_timeout(master) != 0) {
		ipcon_sem_post_write(master);
		return E_TIMEOUT;
	}

	GetChibiErrorLogReturn_ *gcelr = (GetChibiErrorLogReturn_ *)master->answer.buffer;
	*ret_underrun = gcelr->underrun;
	*ret_crc_error = gcelr->crc_error;
	*ret_no_ack = gcelr->no_ack;
	*ret_overflow = gcelr->overflow;

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_set_chibi_frequency(Master *master, uint8_t frequency) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	SetChibiFrequency_ scf;
	scf.stack_id = master->stack_id;
	scf.type = TYPE_SET_CHIBI_FREQUENCY;
	scf.length = sizeof(SetChibiFrequency_);
	scf.frequency = frequency;

	ipcon_device_write(master, (char *)&scf, sizeof(SetChibiFrequency_));

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_get_chibi_frequency(Master *master, uint8_t *ret_frequency) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	master->answer.type = TYPE_GET_CHIBI_FREQUENCY;
	master->answer.length = sizeof(GetChibiFrequencyReturn_);
	GetChibiFrequency_ gcf;
	gcf.stack_id = master->stack_id;
	gcf.type = TYPE_GET_CHIBI_FREQUENCY;
	gcf.length = sizeof(GetChibiFrequency_);

	ipcon_device_write(master, (char *)&gcf, sizeof(GetChibiFrequency_));

	if(ipcon_answer_sem_wait_timeout(master) != 0) {
		ipcon_sem_post_write(master);
		return E_TIMEOUT;
	}

	GetChibiFrequencyReturn_ *gcfr = (GetChibiFrequencyReturn_ *)master->answer.buffer;
	*ret_frequency = gcfr->frequency;

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_set_chibi_channel(Master *master, uint8_t channel) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	SetChibiChannel_ scc;
	scc.stack_id = master->stack_id;
	scc.type = TYPE_SET_CHIBI_CHANNEL;
	scc.length = sizeof(SetChibiChannel_);
	scc.channel = channel;

	ipcon_device_write(master, (char *)&scc, sizeof(SetChibiChannel_));

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_get_chibi_channel(Master *master, uint8_t *ret_channel) {
	if(master->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(master);

	master->answer.type = TYPE_GET_CHIBI_CHANNEL;
	master->answer.length = sizeof(GetChibiChannelReturn_);
	GetChibiChannel_ gcc;
	gcc.stack_id = master->stack_id;
	gcc.type = TYPE_GET_CHIBI_CHANNEL;
	gcc.length = sizeof(GetChibiChannel_);

	ipcon_device_write(master, (char *)&gcc, sizeof(GetChibiChannel_));

	if(ipcon_answer_sem_wait_timeout(master) != 0) {
		ipcon_sem_post_write(master);
		return E_TIMEOUT;
	}

	GetChibiChannelReturn_ *gccr = (GetChibiChannelReturn_ *)master->answer.buffer;
	*ret_channel = gccr->channel;

	ipcon_sem_post_write(master);

	return E_OK;
}

int master_get_version(Master *master, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, master->name, 40);

	ret_firmware_version[0] = master->firmware_version[0];
	ret_firmware_version[1] = master->firmware_version[1];
	ret_firmware_version[2] = master->firmware_version[2];

	ret_binding_version[0] = master->binding_version[0];
	ret_binding_version[1] = master->binding_version[1];
	ret_binding_version[2] = master->binding_version[2];

	return E_OK;
}

void master_register_callback(Master *master, uint8_t cb, void *func) {
    master->callbacks[cb] = func;
}

void master_create(Master *master, const char *uid) {
	ipcon_device_create(master, uid);

	master->binding_version[0] = 1;
	master->binding_version[1] = 1;
	master->binding_version[2] = 0;

}
