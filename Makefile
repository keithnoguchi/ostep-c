# SDPX-License-Identifier: GPL-2.0
CHAPTERS := ch05

all:
%:
	$(foreach CHAPTER, $(CHAPTERS), $(MAKE) -C $(CHAPTER) $@;)
