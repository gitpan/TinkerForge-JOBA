package TinkerForge::API;

use 5.010000;
use strict;
use warnings;
use Carp;
our $VERSION = '0.01';

require Exporter;

our @ISA = qw(Exporter);

our @EXPORT = ();

our %EXPORT_TAGS = ( 'all' => [ qw(
    destroy_void_ptr
	ipcon_create
	ipcon_destroy
    ipcon_add_device
    master_create
    master_get_stack_voltage
    master_get_stack_current
    master_get_extension_type
    master_is_chibi_present
    master_get_chibi_address
    master_get_chibi_master_address
    master_get_chibi_slave_address
    temperature_create
    temperature_get_temperature
    ambient_light_create
    ambient_light_get_illuminance
    rotary_poti_create
    rotary_poti_get_position
    distance_ir_create
    distance_ir_get_distance
    voltage_create
    voltage_get_voltage
    temperature_ir_create
    temperature_ir_get_ambient_temperature
    temperature_ir_get_object_temperature
    temperature_ir_set_emissivity
    temperature_ir_get_emissivity
    humidity_create
    humidity_get_humidity
) ] );

our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );

require XSLoader;
XSLoader::load('TinkerForge::API', $VERSION);

