#!/usr/bin/perl

use strict;
use warnings;

sub clean {
	my $string = shift;
	$string =~ s/[^a-z0-9]//g;
	return $string;
}

print "Enter a string: ";
my $string = <STDIN>;
chomp($string);
$string = lc($string);

$string = clean($string);

my $revstr = reverse($string);

if ($string eq $revstr) {
	print "The string is a palindrome.";
} else {
	print "The string is not a palindrome.";
}
