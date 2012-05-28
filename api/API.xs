#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "ppport.h"

#include "ip_connection.h"
#include "brick_master.h"
#include "bricklet_ambient_light.h"
#include "bricklet_distance_ir.h"
#include "bricklet_humidity.h"
#include "bricklet_rotary_poti.h"
#include "bricklet_temperature.h"
#include "bricklet_temperature_ir.h"
#include "bricklet_voltage.h"


void destroy_void_ptr (void * ptr) {
    if (ptr) free (ptr);
}

MODULE = TinkerForge::API		PACKAGE = TinkerForge::API

void
destroy_void_ptr(ptr)
    void * ptr
  
int
ipcon_create(ipcon, host, port)
	IPConnection *	ipcon = NO_INIT
	char *	host
	int	port
  PREINIT:
    ipcon = malloc(sizeof(IPConnection));
  OUTPUT:
    ipcon
    RETVAL 

void
ipcon_destroy(ipcon)
    IPConnection *  ipcon
  CLEANUP:
    if (ipcon) free(ipcon);

int
ipcon_add_device(ipcon, device)
    IPConnection *  ipcon
    Device *        device

void
ipcon_join_thread(ipcon)
    IPConnection *  ipcon


void
master_create(master, uid)
    Master * master = NO_INIT
    char * uid
  PREINIT:
    master = malloc(sizeof(Master));
  OUTPUT:
    master
  

int
master_get_stack_voltage(master, ret_voltage)
    Master *    master
    uint16_t    &ret_voltage = NO_INIT
  OUTPUT:
    ret_voltage
    RETVAL

int
master_get_stack_current(master, ret_current)
    Master *    master
    uint16_t    &ret_current = NO_INIT
  OUTPUT:
    ret_current
    RETVAL

int
master_get_extension_type(master, extension, ret_exttype)
    Master *    master
    unsigned char extension
    uint32_t    &ret_exttype = NO_INIT
  OUTPUT:
    ret_exttype
    RETVAL

int
master_is_chibi_present(master, ret_present)
    Master *    master
    bool       &ret_present = NO_INIT
  OUTPUT:
    ret_present
    RETVAL

int
master_get_chibi_address(master, ret_address)
    Master *    master
    uint8_t     &ret_address = NO_INIT
  OUTPUT:
    ret_address
    RETVAL

int
master_get_chibi_master_address(master, ret_address)
    Master *    master
    uint8_t     &ret_address = NO_INIT
  OUTPUT:
    ret_address
    RETVAL

int
master_get_chibi_slave_address(master, num, ret_address)
    Master *    master
    uint8_t     num
    uint8_t     &ret_address = NO_INIT
  OUTPUT:
    ret_address
    RETVAL


void
temperature_create(temperature, uid)
    Temperature * temperature = NO_INIT
    char * uid
  PREINIT:
    temperature = malloc(sizeof(Temperature));
  OUTPUT:
    temperature
  

int
temperature_get_temperature(temperature, ret_temperature)
    Temperature *    temperature
    int16_t     &ret_temperature = NO_INIT
  OUTPUT:
    ret_temperature
    RETVAL

void
ambient_light_create(ambient_light, uid)
    AmbientLight * ambient_light = NO_INIT
    char * uid
  PREINIT:
    ambient_light = malloc(sizeof(AmbientLight));
  OUTPUT:
    ambient_light

int 
ambient_light_get_illuminance(ambient_light, ret_illuminance)
    AmbientLight *  ambient_light
    uint16_t       &ret_illuminance = NO_INIT
  OUTPUT:
    ret_illuminance
    RETVAL



void
rotary_poti_create(rotary_poti, uid)
    RotaryPoti * rotary_poti = NO_INIT
    char * uid
  PREINIT:
    rotary_poti = malloc(sizeof(RotaryPoti));
  OUTPUT:
    rotary_poti

int 
rotary_poti_get_position(rotary_poti, ret_position)
    RotaryPoti *  rotary_poti
    int16_t      &ret_position = NO_INIT
  OUTPUT:
    ret_position
    RETVAL



void
distance_ir_create(distance_ir, uid)
    DistanceIR * distance_ir = NO_INIT
    char * uid
  PREINIT:
    distance_ir = malloc(sizeof(DistanceIR));
  OUTPUT:
    distance_ir

int 
distance_ir_get_distance(distance_ir, ret_distance)
    DistanceIR *  distance_ir
    int16_t      &ret_distance = NO_INIT
  OUTPUT:
    ret_distance
    RETVAL



void
voltage_create(voltage, uid)
    Voltage * voltage = NO_INIT
    char * uid
  PREINIT:
    voltage = malloc(sizeof(Voltage));
  OUTPUT:
    voltage

int
voltage_get_voltage(voltage, ret_voltage)
    Voltage * voltage
    int16_t  &ret_voltage = NO_INIT
  OUTPUT:
    ret_voltage 
    RETVAL



void
temperature_ir_create(temperature_ir, uid)
    TemperatureIR * temperature_ir = NO_INIT
    char *uid
  PREINIT:
    temperature_ir = malloc(sizeof(TemperatureIR));
  OUTPUT:
    temperature_ir

int
temperature_ir_get_ambient_temperature(temperature_ir, ret_temperature)
    TemperatureIR * temperature_ir
    int16_t        &ret_temperature = NO_INIT
  OUTPUT:
    ret_temperature
    RETVAL

int
temperature_ir_get_object_temperature(temperature_ir, ret_temperature)
    TemperatureIR * temperature_ir
    int16_t        &ret_temperature = NO_INIT
  OUTPUT:
    ret_temperature
    RETVAL

int
temperature_ir_set_emissivity(temperature_ir, emissivity)
    TemperatureIR * temperature_ir
    int16_t         emissivity
  OUTPUT:
    emissivity
    RETVAL

int
temperature_ir_get_emissivity(temperature_ir, ret_emissivity)
    TemperatureIR * temperature_ir
    int16_t        &ret_emissivity = NO_INIT
  OUTPUT:
    ret_emissivity
    RETVAL


void
humidity_create(humidity, uid)
    Humidity *  humidity = NO_INIT
    char *  uid
  PREINIT:
    humidity = malloc(sizeof(Humidity));
  OUTPUT:
    humidity

int
humidity_get_humidity(humidity, ret_humidity)
    Humidity *  humidity
    uint16_t   &ret_humidity = NO_INIT
  OUTPUT:
    ret_humidity
    RETVAL
