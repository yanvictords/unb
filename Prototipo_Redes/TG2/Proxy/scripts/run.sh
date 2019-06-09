gcc ../proxy.c -o ../proxy
clear
sudo ../proxy
sudo iptables -F
