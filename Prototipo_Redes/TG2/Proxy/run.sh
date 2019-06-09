gcc proxy.c -o proxy
clear
sudo ./proxy
rm -r proxy
sudo iptables -F
