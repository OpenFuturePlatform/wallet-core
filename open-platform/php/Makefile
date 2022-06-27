CPP             = g++
RM              = rm -f
CPP_FLAGS       = -Wall -c -I../../src -I../../include -I../../build/local/include -O2 -std=c++17

PREFIX			= /usr
#Edit these lines to correspond with your own directories
PHP_CONFIG              = php-config
LIBRARY_DIR		= $(shell ${PHP_CONFIG} --extension-dir)
PHP_CONFIG_DIR	= /etc/php/7.4/cli/conf.d/

LD              = g++
LD_FLAGS        = -Wall -shared -O2 
RESULT          = walletgenerate.so

PHPINIFILE		= 30-walletgenerate.ini

SOURCES			= $(wildcard *.cpp)
OBJECTS         = $(SOURCES:%.cpp=%.o)

all:	${OBJECTS} ${RESULT}

${RESULT}: ${OBJECTS}
		${LD} ${LD_FLAGS} -o $@ ${OBJECTS} -lphpcpp

clean:
		${RM} *.obj *~* ${OBJECTS} ${RESULT}

${OBJECTS}: 
		${CPP} ${CPP_FLAGS} -fpic -o $@ ${@:%.o=%.cpp}

install:
		cp -f ${RESULT} ${LIBRARY_DIR}
		cp -f ${PHPINIFILE}	${PHP_CONFIG_DIR}
