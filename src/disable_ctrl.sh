#!/bin/sh

# This bash script ensures that the sterm shell takes 
# control of the key strokes through stdin.

# To launch this script type: . ./disable_ctrl.sh

# This sources the script, importing the commands into 
# the parent, rather than invoking them in a child script.
# This script should be sourced to properly disable certain
# shell features.

set +m
old="$(stty -g)"
trap '' 2
trap "stty $(stty -g)" EXIT

stty  -echo -icanon -isig || exit $?
./320sh $@

# Clean up
set -m
stty "$old"