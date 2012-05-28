use strict;
use warnings;
use Data::Dumper;
use TinkerForge::Client;

use Test::More tests => 16;
SKIP: {
    skip 'maintainer tests', 16 unless $ENV{'MAINTAINERTEST'};

    my $t = new TinkerForge::Client(Hostname => 'ids.homeunix.net', Port => 4224);
    my $d = undef;
    my $v = undef;
    ok ( $t, 'Object creation' );

    # Master brick
    $d = $t->add_master_brick('a4GePQcCQYR');
    ok ( defined $d, 'master brick' );

    my $stack = $d->stack;

    ok ( defined $stack, 'stack' );
    ok ( defined $stack->{'voltage'}, 'voltage' );
    ok ( defined $stack->{'current'}, 'current' );

    $v = $d->extension_type(0);
    ok ( $v >= 0, 'extension 0 type');
    print "# extension 0 is $v\n";
    $v = $d->extension_type(1);
    ok ( $v >= 0, 'extension 1 type');
    print "# extension 1 id $v\n";

    SKIP: {
        if ( $d->is_chibi_present() ) {
            print "# a chibi is preset\n";
            ok ( $d->chibi_address >= 0, 'chibi address');
            #warn ("chibi address is " . $d->get_chibi_address);
            ok ( $d->chibi_master_address >= 0, 'chibi master_address');
            #warn ("chibi master_address is " . $d->get_chibi_master_address);
            ok ( $d->chibi_slave_address(0) >= 0, 'chibi slave_address');
            #warn ("chibi slave_address 0 is " . $d->get_chibi_slave_address(0));
        }
        else {
            skip 'no chibi present', 3;
        }
    }
    $d = undef;

    # now the connected bricklets

    # Temperature bricklet
    $d = $t->add_temperature_bricklet('6Eo');
    ok ( defined $d, 'temperature bricklet' );
    $v=$d->temperature;
    ok ( defined $v, 'temperature' );
    print "# temperature is $v\n";
    $d = undef;

    # Humidity bricklet
    $d = $t->add_humidity_bricklet('7S1');
    ok ( defined $d, 'humidity bricklet' );
    $v = $d->humidity;
    ok ( defined $v, 'humidity' );
    print "# humidity is $v\n";
    $d = undef;

    # AmbientLight bricklet
    $d = $t->add_ambient_light_bricklet('7S1');
    ok ( defined $d, 'ambient_light bricklet' );
    $v = $d->illuminance;
    ok ( defined $v, 'illuminance' );
    print "# illuminance is $v\n";
    $d = undef;

    $t = undef;
}
