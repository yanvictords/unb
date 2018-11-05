# This makefile runs all necessary files to filter a package traffic in the local area
# To run, enter in a shell the follow commands::
# make
# ./OUTFILE_NAME_HERE

CC=gcc
CFLAGS=-pthread
OUTPUTFLAG=-o
OUTFILE=api
EXE=${OUTPUTFLAG} ${OUTFILE}
API=src/Api/api_main.o src/Api/Network/api_server.o src/Api/Network/socket.o
DETECTOR_TOOL=src/DetectorTool/analyzer.o src/DetectorTool/identifier.o src/DetectorTool/decoder.o src/DetectorTool/record.o src/DetectorTool/ui.o

detector: ${API} ${DETECTOR_TOOL} 
	${CC} ${API} ${DETECTOR_TOOL} ${CFLAGS} ${EXE}

