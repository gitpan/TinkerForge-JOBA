package TinkerForge;

use 5.010000;
use strict;
use warnings;
use Carp;
our $VERSION = '0.01';

use TinkerForge::Client;


sub new {
    my ($class, %args) = @_;

    carp ('Use of TinkerForge is deprecated. Use TinkerForge::Client instead.');

    return new TinkerForge::Client(%args);
}

1;

__END__
=head1 NAME

TinkerForge - A perl binding for the TinkerForge hard-/software

=head1 DESCRIPTION

This module is a perl binding to the TinkerForge API. It mostly
wraps the C bindings of the TinkerForge API.

Use L<TinkerForge::Client> for object creation. You can find details of the
usable bricks and bricklets in L<TinkerForge::Brick> and
L<TinkerForge::Bricklet>.

=head1 AUTHOR

Andreas Jobs, E<lt>joba@cpan.orgE<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2012 by Andreas Jobs

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.10 or,
at your option, any later version of Perl 5 you may have available.

=cut
