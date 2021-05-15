#!/bin/bash	

glib-compile-resources --target=part1Resource.c --generate-source resource.xml

gcc -Wno-format -o part1-bin main.c part1Resource.c -Wno-deprecated-declarations -Wno-format-security -lm `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
