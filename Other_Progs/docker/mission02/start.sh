docker build -t thessh .
ssh-keygen -t rsa
docker run --name d2 -d -P thessh
var=$(docker ps | cut -d ':' -f2 | cut -d '-' -f1 | grep -v IMAGE)
~/Downloads/ssh-copy-id -i ~/.ssh/id_rsa.pub "-p $var root@192.168.59.103"
