docker build -t volume1 .
docker run --name d3 -dt -p 42:42 -v /nfs/zfs-student-4/users/2014/REDACTED/projects/docker/mission03/hostdir:/home/REDACTED/docker_volume volume1

