cd ../test
gcc dnsPackage.c udpServer.c -o s -pthread
./s
cd ../scripts
bash clean.sh
