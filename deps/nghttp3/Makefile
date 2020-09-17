ROOT=$(abspath .)

BUILD=build
URL=https://github.com/ngtcp2/nghttp3

all: $(BUILD)

$(BUILD):
	[ -d $(BUILD) ] || mkdir -p $(BUILD)
	git clone $(URL) $(BUILD)
	cd $(BUILD) && \
	autoreconf -i && \
	./configure --prefix=$PWD/build --enable-lib-only && \
	make -j$(nproc) check

clean:
	rm -rf $(BUILD)