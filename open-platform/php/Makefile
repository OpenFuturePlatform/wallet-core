CPP             = g++
RM              = rm -f
CPP_FLAGS       = -Wall -c -O2 -std=c++17

PREFIX			= /usr

PHP_CONFIG      = php-config
LIBRARY_DIR		= $(shell ${PHP_CONFIG} --extension-dir)
#Edit these lines to correspond with your own directories
PHP_CONFIG_DIR	= /etc/php/7.4/cli/conf.d/

OPEN_DIR        = -I../core-cpp
OPEN_LINK       = -L../core-cpp

LD              = g++
LD_FLAGS        = -Wall -shared -O2
LD_DEPENDENCY   = -lphpcpp -lOpenWallet
RESULT          = walletgenerate.so

PHPINIFILE		= 30-walletgenerate.ini

SOURCES			= $(wildcard *.cpp)
OBJECTS         = $(SOURCES:%.cpp=%.o)

all:	${OBJECTS} ${RESULT}

${RESULT}: ${OBJECTS}
		${LD} ${LD_FLAGS} ${OPEN_LINK} -o $@ ${OBJECTS} ${LD_DEPENDENCY}

clean:
		${RM} *.obj *~* ${OBJECTS} ${RESULT}

${OBJECTS}: 
		${CPP} ${CPP_FLAGS} ${OPEN_DIR} -fpic -o $@ ${@:%.o=%.cpp}

install:
		cp -f ${RESULT} ${LIBRARY_DIR}
		cp -f ${PHPINIFILE}	${PHP_CONFIG_DIR}