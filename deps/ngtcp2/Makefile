ROOT=$(abspath .)

BUILD=build
URL=https://github.com/ngtcp2/ngtcp2

all: $(BUILD)

$(BUILD):
	[ -d $(BUILD) ] || mkdir -p $(BUILD)
	git clone $(URL) $(BUILD)
	cd $(BUILD) && \
	autoreconf -i && \
	make -j$(nproc) check

clean:
	rm -rf $(BUILD)