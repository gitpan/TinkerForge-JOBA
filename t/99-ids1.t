use strict;
use warnings;
use Data::Dumper;
use TinkerForge::Client;

use Test::More tests => 18;
SKIP: {
    skip 'maintainer tests', 18 unless $ENV{'MAINTAINERTEST'};

    my $t = new TinkerForge::Client(Hostname => 'ids.homeunix.net', Port => 4223);
    my $d = undef;
    my $v = undef;
    ok ( $t, 'Object creation' );

    # Master brick
    $d = $t->add_master_brick('9JnhKJsHMKp');
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
    $d = $t->add_temperature_bricklet('7CY');
    ok ( defined $d, 'temperature bricklet' );
    $v=$d->temperature;
    ok ( defined $v, 'temperature' );
    print "# temperature is $v\n";
    $d = undef;

    # Humidity bricklet
    $d = $t->add_humidity_bricklet('7RU');
    ok ( defined $d, 'humidity bricklet' );
    $v = $d->humidity;
    ok ( defined $v, 'humidity' );
    print "# humidity is $v\n";
    $d = undef;

    # DistanceIR bricklet
    $d = $t->add_distance_ir_bricklet('7co');
    ok ( defined $d, 'distance_ir bricklet' );
    $v = $d->distance;
    ok ( defined $v, 'distance' );
    print "# distance is $v\n";
    $d = undef;

    # RotaryPoti bricklet
    $d = $t->add_rotary_poti_bricklet('6Nd');
    ok ( defined $d, 'rotary_poti bricklet' );
    $v = $d->position;
    ok ( defined $v, 'position' );
    print "# position is $v\n";
    $d = undef;

    $t = undef;
}
