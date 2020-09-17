ROOT=$(abspath .)

BUILD=build
URL=https://github.com/tatsuhiro-t/openssl

all: $(BUILD)

$(BUILD):
	[ -d $(BUILD) ] || mkdir -p $(BUILD)
	git clone --depth 1 -b OpenSSL_1_1_1g-quic-draft-30 $(URL) $(BUILD)
	cd $(BUILD) && \
	./config enable-tls1_3 --prefix=$(PWD)/build && \
	make -j$(nproc)

clean:
	rm -rf $(BUILD)