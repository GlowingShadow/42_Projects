FROM ubuntu:14.04
MAINTAINER <REDACTED@student.42.fr>
RUN echo 'PS1="REDACTED@42born2code:/# "' >> /root/.bashrc

RUN mkdir /home/REDACTED
ADD launch.sh /home/REDACTED/launch.sh
RUN chmod 755 /home/REDACTED/launch.sh

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y -q python-all python-pip 
ADD ./webapp/requirements.txt /tmp/requirements.txt
RUN pip install -qr /tmp/requirements.txt
ADD ./webapp /opt/webapp/
WORKDIR /opt/webapp
EXPOSE 5000

ENTRYPOINT ["/home/REDACTED/launch.sh"]
CMD ["bash"]