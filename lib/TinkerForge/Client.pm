=head1 NAME

TinkerForge::Client - Perl bindings for TinkerForge 

=head1 SYNOPSIS

  use v5.10;
  use TinkerForge;

  my $tc = new TinkerForge::Client(Hostname => 'localhost', Port => 4223 );
  my $tb = $tf->add_temperature_bricklet('myuidofthebricklet');
  
  say $tb->temperature . '°C';

=head1 DESCRIPTION

This module manages the client side of the TinkerForge stuff. 

=head1 METHODS

=cut

package TinkerForge::Client;

use 5.010000;
use strict;
use warnings;
use Carp;
our $VERSION = '0.01';

use TinkerForge::API ':all';
use TinkerForge::Brick;
use TinkerForge::Bricklet;


sub new {
    my ($class, %args) = @_;

    my $self = {};
    my $error;

    $self->{'HOST'}    = $args{'Hostname'} || 'localhost';
    $self->{'PORT'}    = $args{'Port'}     || 4223;
    $self->{'ENUM_CB'} = $args{'Enumerate_CB'} || undef;
    $self->{'IPCON'}   = undef;

    $error = ipcon_create($self->{'IPCON'}, $self->{'HOST'}, $self->{'PORT'});
    if ($error) {
        carp "Cannot create connetion to brick daemon: $error";
        return undef;
    }

    bless($self, $class);
    return $self;
}

sub DESTROY {
    my $self = shift;

    if ($self->{'IPCON'}) {
        ipcon_destroy($self->{'IPCON'}) if $self->{'IPCON'};
    }
}

=head2 Bricks

=over 

=item add_master_brick

Add a Master brick to your TinkerForge setup. Returns an instance of
TinkerForge::Brick::Master or undef.

=cut
sub add_master_brick {
    my ($self, $uid) = @_;

    my $brick = new TinkerForge::Brick::Master($self, $uid);
    return $brick;
}

=back

=head2 Bricklets

=over 

=item add_ambient_light_bricklet

Add a AmbientLight bricklet to your TinkerForge setup. Returns an instance of
TinkerForge::Bricklet::AmbientLight or undef.

=cut
sub add_ambient_light_bricklet {
    my ($self, $uid) = @_;

    my $brick = new TinkerForge::Bricklet::AmbientLight($self, $uid);
    return $brick;
}

=item add_distance_ir_bricklet

Add a DistanceIR bricklet to your TinkerForge setup. Returns an instance of
TinkerForge::Bricklet::DistanceIR or undef.

=cut
sub add_distance_ir_bricklet {
    my ($self, $uid) = @_;

    my $brick = new TinkerForge::Bricklet::DistanceIR($self, $uid);
    return $brick;
}

=item add_humidity_bricklet

Add a Humidity bricklet to your TinkerForge setup. Returns an instance of
TinkerForge::Bricklet::Humidity or undef.

=cut
sub add_humidity_bricklet {
    my ($self, $uid) = @_;

    my $bricklet = new TinkerForge::Bricklet::Humidity($self, $uid);
    return $bricklet;
}

=item add_rotary_poti_bricklet

Add a RotaryPoti bricklet to your TinkerForge setup. Returns an instance of
TinkerForge::Bricklet::RotaryPoti or undef.

=cut
sub add_rotary_poti_bricklet {
    my ($self, $uid) = @_;

    my $brick = new TinkerForge::Bricklet::RotaryPoti($self, $uid);
    return $brick;
}

=item add_temperature_bricklet

Add a Temperature bricklet to your TinkerForge setup. Returns an instance of
TinkerForge::Bricklet::Temperature or undef.

=cut
sub add_temperature_bricklet {
    my ($self, $uid) = @_;

    my $brick = new TinkerForge::Bricklet::Temperature($self, $uid);
    return $brick;
}

=item add_temperature_ir_bricklet

Add a TemperatureIR bricklet to your TinkerForge setup. Returns an instance of
TinkerForge::Bricklet::TemperatureIR or undef.

=cut
sub add_temperature_ir_bricklet {
    my ($self, $uid) = @_;

    my $bricklet = new TinkerForge::Bricklet::TemperatureIR($self, $uid);
    return $bricklet;
}

1;

__END__
=back

=head1 AUTHOR

Andreas Jobs, E<lt>joba@cpan.orgE<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2012 by Andreas Jobs

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.10 or,
at your option, any later version of Perl 5 you may have available.

=cut
