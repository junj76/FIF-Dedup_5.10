#!/bin/bash

sudo dmsetup remove FIF-Dedup

sudo modprobe -r dm-dedup
