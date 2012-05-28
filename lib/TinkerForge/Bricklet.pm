=head1 NAME

TinkerForge::Bricklet

=head1 SYNOPSIS

This is the base class for all bricklets. The add_*_bricklet methods
of TinkerForge::Client will return an instance of a corresponding
TinkerForge::Bricklet::* class.

=head1 SUBCLASSES

=cut

use strict;
use warnings;

#=head2 TinkerForge::Bricklet
#
#This is just the base class of all bricklets
#
#=cut
#
package TinkerForge::Bricklet;
use TinkerForge::API 'destroy_void_ptr';
our $VERSION = '0.01';

sub new {
    my $class = shift;
    my $tinkerforge = shift;
    my $uid   = shift;
    my $self = {};

    $self->{'UID'} = $uid;
    $self->{'IPCON'} = $tinkerforge->{'IPCON'};

    bless($self, $class);
    return $self;
}

sub DESTROY {
    my $self = shift;
    destroy_void_ptr($self->{'DEVICE'}) if $self->{'DEVICE'};
}

1;


=head2 TinkerForge::Bricklet::AmbientLight

This class implemets the routines for an ambient light bricklet.

=cut 
package TinkerForge::Bricklet::AmbientLight;
use parent 'TinkerForge::Bricklet';
use TinkerForge::API ':all';

sub new {
    my $class = shift;
    my $self  = $class->SUPER::new(@_);

    ambient_light_create($self->{'DEVICE'}, $self->{'UID'});
    return undef unless $self->{'DEVICE'} and $self->{'IPCON'};

    ipcon_add_device($self->{'IPCON'}, $self->{'DEVICE'});

    bless ($self, $class);
    return $self;
}

=over

=item illuminance

Returns the illuminance of the ambient light sensor. The value has a range vom 0 to 900Lux.

=back
=cut

sub illuminance {
    my $self = shift;
    my $r;

    ambient_light_get_illuminance($self->{'DEVICE'}, $r);
    return undef unless defined $r;
    return $r / 10;
}

1;


=head2 TinkerForge::Bricklet::DistanceIR

This class implemets the routines for an infrared distance bricklet.

=cut 
package TinkerForge::Bricklet::DistanceIR;
use parent 'TinkerForge::Bricklet';
use TinkerForge::API ':all';

sub new {
    my $class = shift;
    my $self  = $class->SUPER::new(@_);

    distance_ir_create($self->{'DEVICE'}, $self->{'UID'});
    return undef unless $self->{'DEVICE'} and $self->{'IPCON'};

    ipcon_add_device($self->{'IPCON'}, $self->{'DEVICE'});

    bless ($self, $class);
    return $self;
}

=over

=item distance

Returns the distance measured by the sensor. The range of the value depends on
the connected IR sensor. Possible ranges are 40 - 300mm, 100 - 800mm and 200 -
1500mm.

=back
=cut
sub distance {
    my $self = shift;
    my $r;

    distance_ir_get_distance($self->{'DEVICE'}, $r);

    return $r;
}

1;


=head2 TinkerForge::Bricklet::Humidity

This class implemets the routines for a humidity bricklet.

=cut 
package TinkerForge::Bricklet::Humidity;
use parent 'TinkerForge::Bricklet';
use TinkerForge::API ':all';

sub new {
    my $class = shift;
    my $self  = $class->SUPER::new(@_);

    humidity_create($self->{'DEVICE'}, $self->{'UID'});
    return undef unless $self->{'DEVICE'} and $self->{'IPCON'};

    ipcon_add_device($self->{'IPCON'}, $self->{'DEVICE'});

    bless ($self, $class);
    return $self;
}

=over

=item humidity

Returns the humidity of the sensors. The value has a range of 0 to 100%RH
(relative humidity).

=back
=cut
sub humidity {
    my $self = shift;
    my $r;

    humidity_get_humidity($self->{'DEVICE'}, $r);
    return undef unless defined $r;
    return $r / 10;
}

1;


=head2 TinkerForge::Bricklet::RotariPoti

This class implemets the routines for a rotary poti bricklet.

=cut 
package TinkerForge::Bricklet::RotaryPoti;
use parent 'TinkerForge::Bricklet';
use TinkerForge::API ':all';

sub new {
    my $class = shift;
    my $self  = $class->SUPER::new(@_);

    rotary_poti_create($self->{'DEVICE'}, $self->{'UID'});
    return undef unless $self->{'DEVICE'} and $self->{'IPCON'};
    
    ipcon_add_device($self->{'IPCON'}, $self->{'DEVICE'});

    bless ($self, $class);
    return $self;
}

=over

=item position

Returns the position of the rotary potentiometer. The value is in degree and
between -150° (most left postition) and 150° (most right position).

=back
=cut
sub position {
    my $self = shift;
    my $r;

    rotary_poti_get_position($self->{'DEVICE'}, $r);
    return undef unless defined$r;
    return $r;
}

1;


=head2 TinkerForge::Bricklet::Temperature

This class implemets the routines for a temperature bricklet.

=cut 
package TinkerForge::Bricklet::Temperature;
use parent 'TinkerForge::Bricklet';
use TinkerForge::API ':all';

sub new {
    my $class = shift;
    my $self  = $class->SUPER::new(@_);

    temperature_create($self->{'DEVICE'}, $self->{'UID'});
    return undef unless $self->{'DEVICE'} and $self->{'IPCON'};

    ipcon_add_device($self->{'IPCON'}, $self->{'DEVICE'});
    bless ($self, $class);
    return $self;
}

=over

=item temperature

Returns the temperature of the sensor. The value has a range from -25°C to
85°C. 

=back
=cut
sub temperature {
    my $self = shift;
    my $r;

    temperature_get_temperature($self->{'DEVICE'}, $r);

    return undef unless defined $r;
    return $r / 100;
}

1;


=head2 TinkerForge::Bricklet::TemperatureIR

This class implemets the routines for an infrared temperature bricklet.

=cut 
package TinkerForge::Bricklet::TemperatureIR;
use parent 'TinkerForge::Bricklet';
use TinkerForge::API ':all';

sub new {
    my $class = shift;
    my $self  = $class->SUPER::new(@_);

    temperature_ir_create($self->{'DEVICE'}, $self->{'UID'});
    return undef unless $self->{'DEVICE'} and $self->{'IPCON'};

    ipcon_add_device($self->{'IPCON'}, $self->{'DEVICE'});

    bless ($self, $class);
    return $self;
}

=over

=item ambient_temperature

Returns the ambient temperature of the sensor. The value has a range of -40° to
125°C.

=cut
sub ambient_temperature {
    my $self = shift;
    my $r;

    temperature_ir_get_ambient_temperature($self->{'DEVICE'}, $r);
    return undef unless defined $r;
    return $r / 100;
}

=item object_temperature

Returns the temperature of the object the sensor is aimed at. The value has a
range of -7°C to 380°C. The temperature of different materials is dependet on
their emissivity. The emissivity of the material can be set with the
L</emissivity> method.

=cut
sub object_temperature {
    my $self = shift;
    my $r;

    temperature_ir_get_object_temperature($self->{'DEVICE'}, $r);
    return undef unless defined $r;
    return $r / 100;
}

=item emissivity([$new_value])

Returns or sets the emmissivity that is used to calculate the surface
temperature returned by L</object_temperature>. The emissivity is usually given
as a value between 0.0 and 1.0. A list of emissivities of different materials
can be found at L<http://www.infrared-thermography.com/material.htm>.

=back
=cut
sub emissivity {
    my ($self, $value) = @_;

    if (defined $value) {
        $value = 1.0 if $value > 1.0;
        $value = 0   if $value < 0.0;
        $value = int($value * 65535);
        temperature_ir_set_emissivity($self->{'DEVICE'}, $value);
    }
    else {
        temperature_ir_get_emissivity($self->{'DEVICE'}, $value);
        return $value / 65535 if defined $value;
    }
    return undef;
}

1;


=head2 TinkerForge::Bricklet::Voltage

This class implemets the routines for a voltage bricklet.

=cut 
package TinkerForge::Bricklet::Voltage;
use parent 'TinkerForge::Bricklet';
use TinkerForge::API ':all';

sub new {
    my $class = shift;
    my $self  = $class->SUPER::new(@_);

    voltage_create($self->{'DEVICE'}, $self->{'UID'});
    return undef unless $self->{'DEVICE'} and $self->{'IPCON'};

    ipcon_add_device($self->{'IPCON'}, $self->{'DEVICE'});

    bless ($self, $class);
    return $self;
}

=over

=item voltage

Returns the voltage of the sensor. The value is in mV and between 0 and
50_000mV.

=back
=cut
sub voltage {
    my $self = shift;
    my $r;

    voltage_get_voltage($self->{'DEVICE'}, $r);

    return $r;
}

1;

=head1 AUTHOR

Andreas Jobs, E<lt>joba@cpan.orgE<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2012 by Andreas Jobs

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.10 or,
at your option, any later version of Perl 5 you may have available.

=cut

