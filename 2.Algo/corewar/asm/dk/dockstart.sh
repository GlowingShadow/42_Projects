#!/bin/sh
docker build -t volume1 /Users/42_projects/corewar/corewar/asm
docker run --name cw -dt -v /Users/42_projects/:/cw volume1
