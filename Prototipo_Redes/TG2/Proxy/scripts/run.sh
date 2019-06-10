sudo echo 1 > /proc/sys/net/ipv4/ip_forward
gcc ../proxy.c -o ../proxy
clear
sudo ../proxy
sudo iptables -F
