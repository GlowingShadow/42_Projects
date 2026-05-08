#!/bin/sh
sudo docker build -t volume1 /home/REDACTED/Bureau/projects/lemipc/
sudo docker run --name lemipc -dt -v /home/REDACTED/Bureau/projects/lemipc:/lemipc volume1
