#!/bin/sh

which gnome-autogen.sh || {
    echo "Could not find 'gnome-autgen.sh'. Is gnome-common installed?"
    exit 1
}

. gnome-autogen.sh

