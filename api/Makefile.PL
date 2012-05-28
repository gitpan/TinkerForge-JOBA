#use 5.010000;
use ExtUtils::MakeMaker;
use Config;

# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    NAME              => 'TinkerForge::API',
    VERSION_FROM      => '../lib/TinkerForge/API.pm', #lib/TinkerForge.pm', # finds $VERSION
    PREREQ_PM         => {}, # e.g., Module::Name => 1.1
    ($] >= 5.005 ?     ## Add these new keywords supported since 5.005
      (ABSTRACT_FROM  => '', #lib/TinkerForge.pm', # retrieve abstract from module
       AUTHOR         => 'Andreas Jobs <Andreas.Jobs@ruhr-uni-bochum.de>') : ()),
    LIBS              => ['-lpthread'], # e.g., '-lm'
    DEFINE            => '', # e.g., '-DHAVE_SOMETHING'
    INC               => '', # e.g., '-I. -I/usr/include/other'
    OBJECT            => 'API.o 
                          ip_connection.o 
                          brick_master.o
                          bricklet_ambient_light.o
                          bricklet_distance_ir.o
                          bricklet_humidity.o
                          bricklet_rotary_poti.o
                          bricklet_temperature.o
                          bricklet_temperature_ir.o
                          bricklet_voltage.o
                         ',
);

