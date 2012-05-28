#use 5.010000;
use ExtUtils::MakeMaker;
use Config;

# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    NAME              => 'TinkerForge',
    VERSION_FROM      => 'lib/TinkerForge.pm', # finds $VERSION
    PREREQ_PM         => {}, # e.g., Module::Name => 1.1
    ($] >= 5.005 ?     ## Add these new keywords supported since 5.005
      (ABSTRACT_FROM  => 'lib/TinkerForge.pm', # retrieve abstract from module
       AUTHOR         => 'Andreas Jobs <joba@cpan.org>') : ()),
    LIBS              => ['-lpthread'], # e.g., '-lm'
    DEFINE            => '', # e.g., '-DHAVE_SOMETHING'
    INC               => '-I.', # e.g., '-I. -I/usr/include/other'
    DIR               => ['api'],
);

