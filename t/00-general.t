use strict;
use warnings;
use Data::Dumper;

use Test::More tests => 5;
BEGIN {
    use_ok('TinkerForge::API');
    use_ok('TinkerForge');
    use_ok('TinkerForge::Client');
    use_ok('TinkerForge::Brick');
    use_ok('TinkerForge::Bricklet');
};
