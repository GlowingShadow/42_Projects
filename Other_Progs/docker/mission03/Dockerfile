FROM	ubuntu:latest

ENV		USER REDACTED
ENV		HOSTNAME 42born2code

RUN		apt-get update &&														\
		apt-get upgrade -y &&													\
		useradd -s "/bin/bash" $USER &&											\
RUN		mkdir -p /home/$USER/docker_volume

# VOLUME	["/home/$USER/docker_volume"]
CMD		/bin/bash