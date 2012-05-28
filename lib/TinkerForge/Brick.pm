=head1 NAME

TinkerForge::Brick

=head1 SYNOPSIS

This is the base class for all brick. The add_*_brick methods
of TinkerForge::Client will return an instance of a corresponding
TinkerForge::Brick::* class.

=head1 SUBCLASSES

=cut

#=head2 TinkerForge::Brick
#
#This is just the base class of all bricks
#
#=cut
package TinkerForge::Brick;
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


#
# master brick
#
=head2 TinkerForge::Bricklet::Master

This class implemets the routines for a master brick.

=cut 
package TinkerForge::Brick::Master;
use parent 'TinkerForge::Brick';
use TinkerForge::API ':all';

sub new {
    my $class = shift;
    my $self  = $class->SUPER::new(@_);

    master_create($self->{'DEVICE'}, $self->{'UID'});

    return undef unless $self->{'DEVICE'};
    return undef unless $self->{'IPCON'};
    ipcon_add_device($self->{'IPCON'}, $self->{'DEVICE'});

    bless($self, $class);
    return $self;
}

=over

=item voltage

Returns the stack voltage in mV. 

=cut
sub voltage {
    my $self = shift;
    my $r;

    master_get_stack_voltage($self->{'DEVICE'}, $r);
    
    return $r;
}

=item current

Returns the stack current in mA.

=cut
sub current {
    my $self = shift;
    my $r;

    master_get_stack_current($self->{'DEVICE'}, $r);

    return $r;
}

=item stack

Returns stack L<current> and L<voltage> in a hashref.

=cut
sub stack {
    my $self = shift;
    my %r;

    master_get_stack_voltage($self->{'DEVICE'}, $r{'voltage'});
    master_get_stack_current($self->{'DEVICE'}, $r{'current'});

    return \%r;
}

=item extenstion_type($extension)

Returns type of $extentioni. The extension is either 0 (for the bottom
extension) or 1 (for the top one). If only one extension is present use 0.

=cut
sub extension_type {
    my ($self, $ext) = @_;
    my $type;

    master_get_extension_type($self->{'DEVICE'}, $ext, $type);

    return $type;
}

=item is_chibi_present

Returns true if a chibi extension is available.

=cut
sub is_chibi_present {
    my $self = shift;
    my $present;

    master_is_chibi_present($self->{'DEVICE'}, $present);

    return $present ? 1 : 0;
}

=item chibi_address

Returns the address that belongs to the chibi extension. The address must be in
the range between 1 and 255.

=cut
sub chibi_address {
    my $self = shift;
    my $address;

    master_get_chibi_address($self->{'DEVICE'}, $address);

    return $address;
}

=item chibi_master_address

Returns the address of the chibi master. The address must be in the range
between 1 and 255.

=cut
sub chibi_master_address {
    my $self = shift;
    my $address;

    master_get_chibi_master_address($self->{'DEVICE'}, $address);

    return $address;
}

=item chibi_slave_address($num)

Returns the address of the slave $num.

=cut
sub get_chibi_slave_address {
    my ($self, $num) = @_;
    my $address;

    master_get_chibi_slave_address($self->{'DEVICE'}, $num, $address);

    return $address;
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
