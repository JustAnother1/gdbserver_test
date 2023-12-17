#!/bin/bash
arm-none-eabi-gdb --nh --nx --eval-command="target extended-remote localhost:54321" /home/lars/prj/nomagic_probe/bin/nomagic_probe.elf
