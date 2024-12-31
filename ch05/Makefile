# SPDX-License-Identifier: GPL-2.0
.PHONY: all c clean

TARGET := p2
CFLAGS := -Wall -Werror -O2

all: $(TARGET)
%: %.o
	$(CC) $(CFLAGS) -o $@ $^
c clean:
	$(RM) $(TARGET)
