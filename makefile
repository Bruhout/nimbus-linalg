CC = g++
C_FLAGS = -Wall -Wextra -g -lm
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
DOCS_DIR = docs


linalg.a: ${BUILD_DIR}/vec.o ${BUILD_DIR}/mat.o
	ar rcs linalg.a ${BUILD_DIR}/vec.o ${BUILD_DIR}/mat.o

${BUILD_DIR}/vec.o: ${INCLUDE_DIR}/vec.h ${SRC_DIR}/vec.cpp
	${CC} -o ${BUILD_DIR}/vec.o ${SRC_DIR}/vec.cpp -c ${C_FLAGS}

${BUILD_DIR}/mat.o: ${INCLUDE_DIR}/mat.h ${SRC_DIR}/mat.cpp
	${CC} -o ${BUILD_DIR}/mat.o ${SRC_DIR}/mat.cpp -c ${C_FLAGS}

test: ${SRC_DIR}/test.cpp linalg.a
	${CC} -o test ${SRC_DIR}/test.cpp linalg.a ${C_FLAGS}

example: ${DOCS_DIR}/example.cpp linalg.a
	${CC} -o example ${DOCS_DIR}/example.cpp linalg.a ${C_FLAGS}