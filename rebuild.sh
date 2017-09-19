#!/bin/sh
set -x
#gcc test_thpool_expand.c thpool.c -D THPOOL_DEBUG -pthread -o test_thpool_expand.o -Iinclude
gcc test_thpool_expand.c thpool.c -pthread -o test_thpool_expand.o -Iinclude
set +x
