CPP             = g++
RM              = rm -f
CPP_FLAGS       = -Wall -c -I. -I/opt/homebrew/Cellar/php/8.2.6/include/php -O2 -std=c++11

PREFIX			= /opt/homebrew/Cellar/php/8.2.6/

#Edit these lines to correspond with your own directories
LIBRARY_DIR		= /opt/homebrew/lib/php/pecl/20220829/

PHP_CONFIG_DIR = /opt/homebrew/etc/php/8.2/conf.d/

LD              = g++
LD_FLAGS        = -Wall -Wl,-rpath,/opt/homebrew/Cellar/php/8.2.6/lib -shared -O2 -L/opt/homebrew/Cellar/php/8.2.6/lib
RESULT          = hardcore.so

PHPINIFILE		= hardcore.ini

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
